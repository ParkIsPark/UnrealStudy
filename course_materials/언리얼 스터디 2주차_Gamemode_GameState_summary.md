# 언리얼 스터디 2주차 — GameMode / GameState 요약

## 실습 환경 안내

- **엔진 버전**: UE 5.4.4 권장 (버전이 높다고 무조건 좋지 않음)
- **IDE**: Visual Studio, Rider(맥 필수), VS Code 중 선택
- **원격 조종**: 노트북 사양 부족 시 Parsec 사용 가능
- **참고 문서**: [Game Mode and Game State — Epic Dev](https://dev.epicgames.com/documentation/en-us/unreal-engine/game-mode-and-game-state-in-unreal-engine)

---

## 1. 문제 정의: 게임 요소를 어떻게 통제하나

게임은 Sound, Network, Cheat Guard, Character, Player Stat, Game Money, Quest, Raid 등 수많은 기능 요소로 이루어진다.

### Problem 1 — 누가 통제하는가?

- 게임 내 요소들은 **서로 상호작용**한다 (Input → Character, Cheat Guard → Game Money 등)
- C++에서는 **아무도 참조하지 않는 객체는 가비지 컬렉터가 수거**해간다
- 게임에 필수적인 기능이어도 아무도 참조하지 않으면 사라질 수 있음

### Problem 2 — God Object(GameManager)

초기 해결책: 모든 기능을 한 `GameManager`가 참조하도록 만들기

**문제점:**
- 기능이 늘어날 때마다 GameManager에 계속 추가
- 모든 변수와 통신이 GameManager를 통하게 됨
- **객체지향 설계 파괴** — God Object 안티패턴

### Problem 3 — 매번 새로 만들어야 하나?

- 프로젝트마다 GameManager를 새로 설계하는 낭비 발생
- 유니티: 관리 주체에 자율성 부여
- **언리얼의 철학: "모두가 통일된 프레임워크로!"**
  - 게임이 거대해질수록 검증된 구조가 중요하기 때문

---

## 2. 월드 스폰 순서

```
엔진 시작
  → GameInstance 생성       (시작 시간, 맵 정보, 오디오/NetDriver 등)
    → UWorld 초기화         (GameInstance → UWorld)
      → GameMode 생성       ← 유저가 쓰는 것 중 가장 먼저 생성
        → GameState 생성
        → 기타 오브젝트 스폰
          → GameMode에게 "시작해도 됩니까?" 확인
            → 게임 시작
```

---

## 3. GameMode — Modern GameManager

GameMode는 게임 시작 시 UWorld가 생성하는 **첫 번째 유저 객체**다.

### GameMode가 하는 일

| 역할 | 설명 |
|---|---|
| 월드 기본 오브젝트 결정 | DefaultPawn, PlayerController, PlayerState, GameState, HUD 클래스를 지정 |
| 플레이어 접속 관리 | 플레이어가 들어올 때 처리 담당 |
| 게임 룰 감시 | 승/패 기준, 부정행위 처벌 기준 등 |

### GameMode에 담을 수 있는 것 (원칙)

> **게임의 룰** 및 **구성에 관련된 정보**에 한정

```cpp
// 엔진 소스 주석
// GameMode defines the rules and mechanics of the game.
// It is only instanced on the server and will never exist on the client.
```

**핵심: GameMode는 서버에만 존재한다.**

---

## 4. 멀티플레이 문제와 해결책

### 서버 / 클라이언트 개념

- **서버**: 게임 월드를 연 주인, 관리 권한 보유
- **클라이언트**: 서버 월드에 참여한 참가자, 데이터를 받는 입장

### Replication (복제)

언리얼은 **tick 기반 리플리케이션** 방식을 사용한다.

```
클라이언트 A → (변경 요청) → 서버 → (복제 데이터) → 클라이언트 B
```

- **진본(Authority)** 은 항상 서버가 보유
- 클라이언트는 서버로부터 데이터를 **복제**받는다

### 잘못된 해결책들

| 방식 | 문제 |
|---|---|
| 서버가 모두 통제 | 클라이언트가 상태를 알려면 매번 요청 → 대역폭 병목 |
| 모두 공유 | 보안 정보, 확률 데이터 등이 노출 → 치트/해킹 취약 |

### Smart Solution — 룰과 상태를 분리

| 분류 | 역할 | 위치 |
|---|---|---|
| **GameMode (룰)** | 게임 규칙, 보안 정보, 확률 등 민감 데이터 | **서버 전용** |
| **GameState (상태)** | 클라이언트도 알아야 하는 공유 상태 | **서버 + 클라이언트 복제** |

---

## 5. GameState — 상태를 보유하는 클래스

GameState는 **정보를 가지고 있는 것**에 초점을 둔 클래스다.

### 핵심 특성

- `bReplicates = true` — 기본적으로 복제됨
- `NetPriority = 10.f` — 복제 우선순위 최상위
- `bAlwaysRelevant = true` — 항상 모든 클라이언트에 관련됨

### GameState를 통해 얻을 수 있는 정보

- 게임이 시작했는가? (`HasBegunPlay()`, `HasMatchStarted()`, `HasMatchEnded()`)
- 이 플레이어는 서버인가, 클라이언트인가?
- 다른 Manager 클래스들의 참조 (`PlayerArray`, `GameModeClass` 등)
- 서버 시간 (`GetServerWorldTimeSeconds()`)
- 현재 접속한 플레이어 목록

### 최종 구조

```
서버                          클라이언트
┌─────────────────────┐       ┌──────────────────────────┐
│ Gamemode (룰)       │       │ GameState (복제)          │
│ GameState (원본)    │ ─── → │ 캐릭터 상태               │
│ 보안 관련 데이터    │       │ 맵 / 오브젝트 데이터      │
│ 확률 / 개인정보     │       │ 게임 진행 상태 등         │
└─────────────────────┘       └──────────────────────────┘
```

> **민감한 정보는 GameMode(서버 전용)**, **공유해야 하는 상태는 GameState(복제)**

---

## 6. 다음 주차 예고

- Actors와 Players — Actor가 움직이는 것, 플레이어가 움직이는 것
- **실습**: 룰이 있고, 플레이어가 움직이는 게임 직접 제작

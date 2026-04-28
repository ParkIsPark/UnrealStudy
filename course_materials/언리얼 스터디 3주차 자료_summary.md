# 언리얼 스터디 3주차 요약

## 지난 주 복습 (Summary)

- **엔진 기동 흐름**: Launch Engine → Spawn World
  - `GameInstance` → `UWorld` → `GameMode` 순으로 생성
- **GameMode / GameState**
  - `GameMode`: 게임의 규칙을 관장하는 역할
  - `GameState`: 여러 플레이어가 접근해서 게임 상의 정보를 확인

---

## 1. 플레이어와 컨트롤

### Player란?
- 게임 맥락에서 "게임을 플레이하는 사람(게이머)"을 의미
- 핵심 개념: **Control** — 플레이어는 무언가를 "조종(빙의)"하여 게임을 플레이

### Control의 두 가지 의미
| 구분 | 설명 |
|------|------|
| 물리적 Controller | 실제 입력 장치 (게임패드, 키보드 등) |
| 기능적 Control | 게임 내 구현된 동작을 발동시키는 것 |

### 컨트롤의 핵심 두 가지 주제
1. **What we Can Control?** — 개발자가 구현해둔 게임 내 요소들
2. **Control Rule?** — 입력이 어떤 규칙에 따라 어떻게 발동되는가

---

## 2. 게임 월드 안의 데이터

### 두 가지 존재 방식
- **In Scene (Map)**: 월드에 배치되어 실제로 보이는 오브젝트
- **In Data**: 메모리 상에만 존재하는 데이터 (렌더링 X)

> **중요**: 실제로는 게임의 모든 것이 메모리에 존재한다. 차이는 그래픽으로 표현되는지 여부.

---

## 3. UObject — 언리얼의 기본 오브젝트

### 정의
- 메모리 공간을 차지하고 데이터를 가지는 것
- 언리얼 엔진의 **가장 기초적인 단위**
- 엔진 레벨(`GUObjectArray`)에서 관리됨

### UObject가 제공하는 기능
- 가비지 컬렉션 (GC)
- 레퍼런스 업데이트
- 리플렉션 (런타임 타입 정보)
- 직렬화
- 디폴트 프로퍼티 자동 업데이트
- 자동 에디터 통합
- 네트워크 리플리케이션

### 핵심 내부 구조
```cpp
// UObjectBase 핵심 멤버
int32    InternalIndex;   // 전역 Array에서 이 오브젝트의 위치
FName    NamePrivate;     // 해당 오브젝트 식별용 이름
```

### UObject 생성 과정 (NewObject() 기준)
1. Engine에 새 오브젝트 등록 요청
2. 이름(FName) 결정
3. `GUObjectArray.AllocateUObjectIndex()` — 전역 배열에 인덱스 할당
4. `HashObject()` — 해시 테이블 등록
5. GC가 오브젝트 수명 관리

### 이름 충돌 에러 케이스
- **같은 클래스 + 같은 이름**: 새 내용으로 덮어쓰기
- **다른 클래스 + 같은 이름**: 에러 발생

### 중요 특성
- **월드에 종속되지 않는다** — UWorld는 GameInstance 이후에 생성되는 것이므로, UObject 기본 타입은 어떤 것에도 종속되도록 선언하면 안 됨
- 필요 시 사용자가 직접 어딘가에 종속시키는 것

---

## 4. AActor — 월드에 배치 가능한 오브젝트

### 정의
- `class AActor : public UObject`
- **월드에 배치되거나 스폰될 수 있는 오브젝트**
- 위치(Transform)를 가질 수 있음 (RootComponent를 통해)

### UObject와의 차이
| | UObject | AActor |
|--|---------|--------|
| 관리 주체 | 엔진, GUObjectArray | ULevel (UWorld) |
| 월드 종속 | X | O |
| 위치 보유 | X | O (RootComponent) |
| 렌더링 가능 | X | O |

### 주요 프로퍼티
- `bReplicateMovement`: 움직임을 서버→클라이언트로 송신 여부
- `bHidden`: 에디터에서만 보이기 옵션
- `RayTracingGroupId`: 레이 트레이싱 그룹 (렌더링)

### AActor 스폰 과정 (UWorld::SpawnActor)
1. 스폰될 레벨(ULevel) 확인
2. `NewObject<AActor>()` — UObject 생성
3. `LevelToSpawnIn->Actors.Add(Actor)` — 스테이지에 정보 추가
4. `LevelToSpawnIn->ActorsForGC.Add(Actor)` — GC 대상 등록

### ULevel
- AActor가 스폰되는 스테이지
- `TArray<TObjectPtr<AActor>> Actors` — 레벨 내 모든 액터 목록
- `TArray<TObjectPtr<AActor>> ActorsForGC` — GC 노출 액터 목록

---

## 5. APawn / ACharacter — 빙의 가능한 유닛

### APawn
- `APawn`은 플레이어나 AI가 **빙의(Possess)** 할 수 있는 모든 액터의 기반 클래스
- 실제 플레이어의 입력을 받아 동작하는 존재
- 게임 내 플레이어의 물리적 표현체

### Possess(빙의)란?
- 플레이어가 입력을 넣어 조종하는 "분신"
- 게임은 현실이 아니므로 플레이어의 입력을 받아 그대로 움직여줄 대상이 필요

### ACharacter — 인간형 유닛
- `APawn`을 상속받은 **인간형 캐릭터 전용 클래스**
- 아래 요소들을 기본으로 내장:

| 컴포넌트 | 역할 |
|----------|------|
| `CapsuleComponent` | 충돌 판정 (CollisionCylinder) |
| `SkeletalMesh` | 캐릭터 모델링 (마네킹) |
| `Camera Root + CameraComponent` | 카메라 뷰 담당 |
| `CharacterMovementComponent (CMC)` | 물리적인 자연스러운 움직임 |

### CharacterMovementComponent (CMC)
- 멀티플레이 + 물리 엔진을 **모두 고려한** 자연스러운 움직임 구현
- 걷기, 점프, 비행, 수영 등 지원
- 언리얼의 CMC는 업계에서도 잘 만들어진 것으로 유명 → **직접 만들지 말고 그냥 쓸 것**

---

## 6. 클래스 계층 구조 요약

```
UObject
└── AActor                    (위치를 가질 수 있는 오브젝트, World 소유)
    └── APawn                 (실제 플레이어의 입력을 받을 수 있는 AActor)
        └── ACharacter        (인간형 캐릭터, CMC 내장)
            └── 내 캐릭터 클래스
```

| 클래스 | 특징 |
|--------|------|
| `UObject` | 엔진 레벨 관리, 메모리 할당, 월드 비종속 |
| `AActor` | 위치 보유, World 소유·관리, 렌더링 가능 |
| `APawn` | 플레이어/AI 빙의 가능, 입력 수신 |
| `ACharacter` | CMC 내장, 인간형 이동 로직 완비 |

---

## 7. GameMode가 관리하는 클래스들

GameMode의 World Settings에서 아래 클래스들을 지정:

| 항목 | 기본값 |
|------|--------|
| Default Pawn Class | BP_ThirdPersonCharacter |
| HUD Class | HUD |
| Player Controller Class | PlayerController |
| Game State Class | GameStateBase |
| Player State Class | PlayerState |
| Spectator Class | SpectatorPawn |

---

## 8. 이번 주 다룬 것 / 다루지 않은 것

### 다룬 것
- 언리얼 엔진의 가장 기초적인 단위 (UObject)
- 게임 시작 시 가장 먼저 생기는 매니저 (GameMode / GameState)
- 월드에 배치된 오브젝트 → 입력을 받을 수 있는 오브젝트 → 자연스럽게 움직이는 오브젝트

### 다루지 않은 것 (이후 예정)
- UI를 만드는 법
- 객체들끼리 서로 통신하는 법
- 새로운 기능의 유지보수 가능한 설계 방법
- 게임의 규모를 키우는 방법

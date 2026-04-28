# 4주차 PPT 강화 제작 계획서

**강의:** 언리얼 엔진 스터디 4주차 — PlayerController & Enhanced Input 심화
**대상:** 대학원생/학부생, UE 입문자
**분량:** 53슬라이드 (90분 강의)
**작성 기준:** 기존 요약서(48p) + 프로젝트 커리큘럼 맥락 + 실습 0 신규 추가

---

## 제작 방향 총론

### 강화 전략 3원칙

1. **"왜"를 먼저, "어떻게"는 그 다음** — 모든 이론 슬라이드는 "이걸 왜 쓰는가?"로 시작한다. UE 초심자는 개념 자체보다 *필요성*을 먼저 납득해야 동기가 생긴다.
2. **흐름도 우선, 코드 나중** — 개념은 다이어그램·시퀀스 다이어그램으로 먼저 제시하고, 코드는 다이어그램이 이해된 뒤에 등장시킨다.
3. **실습은 체크포인트 단위로 가시화** — 단계마다 "현재 이 위치" 진행 바를 삽입해 학생들이 전체 실습 구조를 놓치지 않게 한다.

### 슬라이드 레이아웃 유형 정의

| 유형 코드 | 용도 | 특징 |
|-----------|------|------|
| `TITLE` | 섹션 구분 표지 | 대형 제목 + 아이콘, 배경 그라디언트 |
| `CONCEPT` | 개념 설명 | 왼쪽 텍스트 + 오른쪽 다이어그램 (50/50) |
| `CODE` | 코드 예제 | 다크 배경 코드 블록 + 라인 하이라이트 |
| `FLOW` | 흐름·순서 설명 | 풀스크린 플로우차트/시퀀스 다이어그램 |
| `COMPARE` | 비교 대조 | 좌우 대비 레이아웃 |
| `PRACTICE` | 실습 안내 | 단계 번호 + 코드 목표 + 체크포인트 바 |
| `CHECKPOINT` | 중간 확인 | 녹색 체크 아이콘 + 기대 결과 스크린샷 영역 |
| `SUMMARY` | 정리 | 핵심 키워드 카드 3–5개 |

---

## 섹션 1: 강의 도입 (p.1–4)

### p.1 — 타이틀 슬라이드
**레이아웃:** `TITLE`

**핵심 메시지:** "오늘은 플레이어와 게임 세계가 어떻게 연결되는지 그 중간 다리를 이해한다."

**구성 요소:**
- 메인 제목: `4주차: PlayerController & Enhanced Input`
- 부제: `플레이어와 게임 세계를 잇는 다리`
- 날짜: 2026-04-27 | 시간: 18:30–20:00
- 강사명: 박준건

**시각 자료 제안:**
- 배경: UE5 블루프린트 에디터 화면을 흐릿하게 처리한 그라디언트 오버레이
- 아이콘 그룹: Gamepad(입력) → 화살표 → Controller(PC) → 화살표 → Pawn(캐릭터) 3단 흐름 아이콘을 타이틀 아래에 작게 배치
- 색상 테마: UE5 공식 다크 블루(`#0E1821`) + 형광 주황(`#F7931E`) 강조색

---

### p.2 — 오늘의 강의 목표
**레이아웃:** `CONCEPT`

**핵심 메시지:** "3가지 이론 + 4가지 실습으로 PlayerController를 내 손으로 직접 다뤄본다."

**구성 요소:**
- 목표 리스트 (아이콘 포함):
  - 🎮 PlayerController의 역할과 Possess 흐름 이해
  - 🗂 PlayerState로 게임 데이터 분리하는 법
  - ⌨️ Enhanced Input 심화 — 런타임 IMC 교체
  - 🔎 **실습 0: Possess를 직접 경험해서 PlayerController가 무엇인지 깨닫기**
  - 🏃 실습 1: 스프린트 구현
  - ❤️ 실습 2: UMG HP 바 위젯
  - 💥 실습 3: PlayerState HP + 데미지 처리
- 하단에 "오늘의 핵심 질문" 박스: *"버튼을 누르면 캐릭터가 달리기까지, 정확히 어떤 클래스가 어떤 순서로 호출되는가?"*

**시각 자료 제안:**
- 왼쪽: 번호 매긴 목표 카드 스택 (아이콘 + 한 줄 설명), 실습 0 카드를 강조색으로 구분
- 오른쪽: 90분 시간 배분 파이차트 (이론 39% / 실습 45% / 기타 16%)

---

### p.3 — 시간 배분 계획표
**레이아웃:** `CONCEPT`

**핵심 메시지:** "90분을 어떻게 쓸지 미리 알고 진행하면 길을 잃지 않는다."

**구성 요소:**
- 타임라인 표 (수평 간트 차트 스타일):

| 시간 | 내용 | 슬라이드 |
|------|------|----------|
| 18:30–18:40 | 에디터 기초 복습 (10분) | p.5–10 |
| 18:40–18:55 | 이론 A: PlayerController (15분) | p.11–16 |
| 18:55–19:05 | **실습 0: Possess 직접 체험 (10분)** | p.17–21 |
| 19:05–19:15 | 이론 B: PlayerState (10분) | p.22–25 |
| 19:15–19:25 | 이론 C: Enhanced Input 심화 (10분) | p.26–30 |
| 19:25–19:42 | 실습 1: 스프린트 (17분) | p.31–36 |
| 19:42–19:55 | 실습 2+3: UMG HP / PlayerState HP (13분) | p.37–48 |
| 19:55–20:00 | 정리 및 Q&A (5분) | p.51–53 |

**시각 자료 제안:**
- 수평 타임라인 바 (색상 코드: 이론=파랑, 실습=주황, 실습0=강조 보라, 기타=회색)
- 실습 0 구간을 살짝 다른 색으로 강조 ("이론 직후 바로 체험"임을 시각적으로 표현)

---

### p.4 — 지난주 복습 연결고리
**레이아웃:** `COMPARE`

**핵심 메시지:** "지난주에 배운 Pawn/Character 계층이 오늘 PlayerController와 어떻게 연결되는가."

**구성 요소:**
- 좌측 "지난주": Pawn → ACharacter 계층도 (간단 트리)
- 우측 "오늘": APlayerController → Possess → APawn/ACharacter 흐름
- 중앙 연결 화살표: "이 관계를 오늘 완성한다"
- 하단 한 줄 브릿지: *"Character는 몸이다. Controller는 의지다."*

**시각 자료 제안:**
- 좌우 패널을 점선 구분선으로 나누고 중앙에 큰 화살표 → 아이콘
- 지난주 내용은 흐릿한 그레이스케일, 오늘 내용은 풀 컬러로 대비 강조

---

## 섹션 2: 에디터 기초 (p.5–10)

### p.5 — 섹션 표지: 에디터 기초
**레이아웃:** `TITLE`

**핵심 메시지:** "실습 전에 에디터 조작을 손에 익혀 둔다."

**구성 요소:**
- 섹션 번호: `WARM-UP`
- 제목: "에디터 기초 복습"
- 예상 소요: 10분

**시각 자료 제안:**
- 배경: UE5 뷰포트 스크린샷 (레벨 에디터 전경)
- 상단 우측에 타이머 아이콘 + "10 min"

---

### p.6 — 뷰포트 단축키
**레이아웃:** `CONCEPT`

**핵심 메시지:** "뷰포트 이동 6가지 단축키를 외우면 실습 속도가 3배 빨라진다."

**구성 요소:**
- 단축키 카드 그리드 (2×3):
  - `Alt + 좌클릭드래그` → 회전
  - `Alt + 우클릭드래그` → 줌
  - `Alt + 중클릭드래그` → 패닝
  - `F` → 선택 오브젝트 포커스
  - `W/E/R` → 이동/회전/스케일 기즈모 전환
  - `G` → 게임 뷰 토글
- 하단 팁 박스: "마우스 우클릭 홀드 + WASD = FPS 스타일 이동"

**시각 자료 제안:**
- 각 단축키 카드에 키캡 이미지 스타일 아이콘 사용
- 우측에 뷰포트 스크린샷 + 각 동작 결과를 화살표로 주석 표시

---

### p.7 — 기즈모(Gizmo) 조작
**레이아웃:** `CONCEPT`

**핵심 메시지:** "기즈모의 3가지 모드(이동/회전/스케일)와 좌표계(월드/로컬)를 구분할 수 있다."

**구성 요소:**
- 기즈모 3모드 아이콘 + 설명 (W/E/R 대응)
- 좌표계 토글: 월드(Global) vs 로컬(Local) — 언제 어느 걸 쓰는가
- 스냅(Snap) 설정 간단 소개 (그리드 스냅, 각도 스냅)

**시각 자료 제안:**
- 뷰포트에서 기즈모 세 모드를 나란히 보여주는 스크린샷 3장 (세로 나열)
- 월드/로컬 차이: 오브젝트가 기울어진 상태에서 두 좌표계의 기즈모 방향 대비 사진

---

### p.8 — 플레이 모드 3종
**레이아웃:** `COMPARE`

**핵심 메시지:** "Play, Simulate, Eject — 상황에 따라 올바른 플레이 모드를 선택해야 디버깅이 쉬워진다."

**구성 요소:**
- 3열 비교표:

| 모드 | 단축키 | 용도 | 특징 |
|------|--------|------|------|
| Play | Alt+P | 일반 플레이 | 입력 캡처, 게임 완전 실행 |
| Simulate | Alt+S | 월드 탐색 | 입력 없이 Actor 시뮬레이션 |
| Eject | F8 | Play 중 분리 | 캐릭터 해방, 에디터 조작 가능 |

- 실습 팁: "디버깅할 때는 Play → F8(Eject) → 문제 Actor 클릭 → 디테일 패널 확인"

**시각 자료 제안:**
- 3열 카드 레이아웃, 각 카드에 모드별 UI 상태 스크린샷
- Eject 사용 시나리오를 4칸 만화 형식(스크린샷 시퀀스)으로 표현

---

### p.9 — 블루프린트 에디터 레이아웃
**레이아웃:** `CONCEPT`

**핵심 메시지:** "블루프린트 에디터의 5개 패널 이름을 알아야 다음 실습에서 길을 잃지 않는다."

**구성 요소:**
- 패널 주석 다이어그램:
  1. 컴포넌트 패널 (좌상단) — 오브젝트 계층
  2. 이벤트 그래프 (중앙) — 로직 노드
  3. 디테일 패널 (우측) — 프로퍼티
  4. 내 블루프린트 패널 (좌하단) — 변수·함수 목록
  5. 툴바 (상단) — 컴파일·저장·플레이

**시각 자료 제안:**
- 블루프린트 에디터 풀스크린 스크린샷에 번호 달린 컬러 박스로 각 패널 하이라이트
- 우측에 패널별 한 줄 설명 범례

---

### p.10 — 에디터 기초 체크포인트
**레이아웃:** `CHECKPOINT`

**핵심 메시지:** "여기까지 따라왔다면 실습 준비 완료."

**구성 요소:**
- 체크리스트:
  - [ ] 뷰포트에서 오브젝트를 찾아 포커스(F)할 수 있다
  - [ ] Play / Simulate / Eject 모드를 전환할 수 있다
  - [ ] 블루프린트 에디터를 열어 이벤트 그래프를 볼 수 있다
- 하단 전환 멘트: "준비됐으면 — 이론으로 넘어갑니다."

**시각 자료 제안:**
- 체크리스트 항목에 초록 체크 아이콘 (완료 상태로 미리 표시해서 자신감 부여)
- 배경을 살짝 밝은 그린 틴트로 처리

---

## 섹션 3: 이론 A — PlayerController (p.11–16)

### p.11 — 섹션 표지: PlayerController
**레이아웃:** `TITLE`

**핵심 메시지:** "UE에서 '플레이어의 의지'를 담당하는 클래스가 무엇인지 오늘 명확히 정의한다."

**구성 요소:**
- 섹션 라벨: `이론 A`
- 제목: "PlayerController"
- 한 줄 훅: *"키보드를 누르면 캐릭터가 달린다 — 그 사이에 무엇이 있는가?"*
- 예상 소요: 15분 (이후 실습 0에서 직접 체험)

**시각 자료 제안:**
- 배경: 추상적 회로 패턴 (입력 신호 흐름 암시)
- 중앙에 물음표 아이콘 + "Input → ? → Pawn" 도식

---

### p.12 — PlayerController의 역할 정의
**레이아웃:** `CONCEPT`

**핵심 메시지:** "PlayerController는 플레이어 한 명을 대표하는 영속적 객체다 — Pawn이 죽어도 Controller는 살아있다."

**구성 요소:**
- 정의 박스: `APlayerController : AController`
  - 입력 처리의 관문 (Input → Controller → Pawn)
  - 플레이어의 '영혼' — Pawn/Character는 '몸'
  - 멀티플레이: 서버에도 존재, 클라이언트에도 존재
- 핵심 대비: **Pawn** (교체 가능, 죽으면 사라짐) vs **PlayerController** (게임 내내 유지)
- UE 클래스 계층: `AActor → AController → APlayerController`

**시각 자료 제안:**
- 우측: '영혼(Controller) + 몸(Pawn)' 은유 아이콘 다이어그램
- Pawn 사망 시나리오: 몸은 사라지지만 Controller는 유지되는 흐름 (3단계 미니 다이어그램)

---

### p.13 — Possess / UnPossess 흐름
**레이아웃:** `FLOW`

**핵심 메시지:** "Possess가 호출되는 순간 Controller와 Pawn이 연결되고, 이때부터 입력이 전달된다."

**구성 요소:**
- 시퀀스 다이어그램 (수직 흐름):
  1. `GameMode::SpawnDefaultPawnFor()` — Pawn 생성
  2. `PlayerController::Possess(Pawn)` 호출
  3. `Pawn::PossessedBy(Controller)` 콜백
  4. `SetupPlayerInputComponent()` 호출됨
  5. 입력 바인딩 완료 → 조작 가능
- 역방향: UnPossess → 입력 끊김 → Pawn 독립 or 소멸
- 하단 예고 박스: *"이 흐름을 실습 0에서 직접 호출해본다"*

**시각 자료 제안:**
- 풀스크린 수직 시퀀스 다이어그램 (UML 스타일)
- 각 단계 박스를 색상 코드: GameMode(보라), PlayerController(파랑), Pawn(주황)
- 실습 0과 연결되는 `Possess(Pawn)` 단계에 별표 + "→ 실습 0"

---

### p.14 — PlayerController의 핵심 규칙
**레이아웃:** `CONCEPT`

**핵심 메시지:** "컨트롤러에서 직접 움직임을 처리하지 말고, 반드시 Pawn에 위임하라."

**구성 요소:**
- 규칙 카드 3개:
  1. **소유 관계**: 하나의 PlayerController는 항상 하나의 Pawn만 Possess
  2. **위임 원칙**: 이동/점프 로직은 Pawn/Character에, Controller는 입력 수신만
  3. **카메라 관리**: `PlayerCameraManager`를 통해 뷰 컨트롤
- 안티패턴 박스: "Controller에 직접 `AddMovementInput` 쓰지 말 것 — 왜?"
- 올바른 패턴: `GetPawn()->AddMovementInput(...)`

**시각 자료 제안:**
- 좌측: ❌ 잘못된 패턴 코드 (빨간 배경)
- 우측: ✅ 올바른 패턴 코드 (초록 배경)
- 하단: "책임 분리 원칙" 다이어그램 — 레이어별 역할 블록

---

### p.15 — GetPlayerController / GetPawn 접근 패턴
**레이아웃:** `CODE`

**핵심 메시지:** "다른 클래스에서 PlayerController와 Pawn에 접근하는 표준 방법을 외워라."

**구성 요소:**
- 코드 예제 3종:
  ```cpp
  // 1. Character에서 자신의 Controller 얻기
  APlayerController* PC = Cast<APlayerController>(GetController());

  // 2. 어디서든 첫 번째 플레이어 Controller 얻기
  APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);

  // 3. Controller에서 빙의 중인 Pawn 얻기
  APawn* MyPawn = GetPawn();
  AWeek3Character* Char = Cast<AWeek3Character>(GetPawn());
  ```
- 각 패턴의 사용 시나리오 한 줄 설명
- Cast 실패 가능성 언급: "nullptr 체크 필수"

**시각 자료 제안:**
- 다크 배경 코드 블록 (VS Code 테마 스타일)
- `Cast<>` 부분 노란색 하이라이트
- 우측 여백에 "언제 쓰나?" 말풍선 주석

---

### p.16 — PlayerController 소결
**레이아웃:** `SUMMARY`

**핵심 메시지:** "PlayerController = 플레이어의 영속적 대리인. 이제 직접 Possess를 호출해서 확인해보자."

**구성 요소:**
- 키워드 카드 4개:
  - `Possess` / `UnPossess`
  - `SetupPlayerInputComponent`
  - `GetPawn()` / `GetController()`
  - 책임 분리 (Controller ≠ 이동 로직)
- 다음 섹션 예고 (강조 박스): *"말로 배웠다 — 이제 손으로 확인할 차례"* → 실습 0

**시각 자료 제안:**
- 4개 카드를 2×2 그리드로 배치, 각 카드에 아이콘
- 하단 화살표: `이론 A 완료 → [실습 0] → 이론 B`로 표시 (실습 0을 이론과 이론 사이의 브릿지로 시각화)

---

## 섹션 3.5: 실습 0 — PlayerController Possess 직접 체험 (p.17–21)

> **교육적 의도:** 이론으로 들은 "Possess" 개념을 손으로 확인하는 순간을 만든다.
> 코드 한 줄 바꾸지 않고, 에디터 변수 하나만 바꿔서 전혀 다른 캐릭터가 움직이는 경험을 통해
> "Controller는 몸이 아니다"라는 사실을 직관적으로 체득한다.
> 이 실습에서 만드는 `AWeek3PlayerController`는 이후 실습 2(HUD)와 실습 3(PlayerState)의 기반이 된다.

---

### p.17 — 실습 0 소개
**레이아웃:** `TITLE`

**핵심 메시지:** "코드를 바꾸지 말고, 에디터 변수 하나만 바꿔라. 그런데 전혀 다른 캐릭터가 움직인다."

**구성 요소:**
- 섹션 라벨: `실습 0`
- 제목: "PlayerController를 직접 경험하다"
- 한 줄 훅: *"두 개의 몸이 있다. 어떤 몸에 들어갈지 우리가 결정한다."*
- 목표 요약:
  - 맵에 캐릭터 두 개 배치
  - `EditAnywhere` 변수로 어느 캐릭터를 조종할지 선택
  - 런타임에 PlayerController가 선택된 캐릭터를 Possess
- 예상 소요: 10분
- 진행 바: `[🔎 실습0 ←] [🏃 실습1] [❤️ 실습2] [💥 실습3]`

**시각 자료 제안:**
- 배경: 같은 레벨에 두 캐릭터가 서 있는 스크린샷 (하나는 밝게, 하나는 어둡게 처리해서 "선택" 개념 암시)
- 중앙에 물음표 화살표: "Controller → ? → 어느 쪽?"

---

### p.18 — 맵 준비: 두 캐릭터 배치
**레이아웃:** `PRACTICE`

**핵심 메시지:** "먼저 무대를 만든다. 두 개의 몸을 레벨에 배치하고, GameMode가 자동으로 빙의하지 않도록 설정한다."

**구성 요소:**
- 진행 바: `[🔎 실습0 · 준비] [🏃 실습1] [❤️ 실습2] [💥 실습3]`
- **Step 준비 / 3**
- 지시사항:
  1. 레벨 뷰포트에 `BP_ThirdPersonCharacter`를 두 개 드래그하여 배치
  2. 각각 이름 변경: World Outliner → F2 → `Character_A`, `Character_B`
  3. 두 캐릭터를 서로 다른 위치에 놓는다 (구분이 명확하게)
  4. `BP_Gamemode` 열기 → Defaults → **Default Pawn Class = None** 으로 변경
  5. 컴파일 & 저장
- 왜 None?: "우리가 직접 어떤 Pawn을 Possess할지 고를 것이기 때문에, 엔진이 자동으로 빙의하지 않도록 막는다."

**시각 자료 제안:**
- 좌측: World Outliner 스크린샷 — Character_A, Character_B 이름 표시
- 우측: BP_Gamemode 디테일 패널 — Default Pawn Class = None 상태 클로즈업
- 하단 경고 박스: "Default Pawn Class를 None으로 바꾸면 플레이 시 자동으로 캐릭터에 들어가지 않는다 — 의도된 것이다"

---

### p.19 — AWeek3PossessSelector 생성
**레이아웃:** `CODE`

**핵심 메시지:** "`EditAnywhere` 변수 하나를 가진 단순한 Actor를 만들어 레벨에 배치한다. 이 Actor의 변수가 '어느 캐릭터를 조종할지'를 결정한다."

**구성 요소:**
- **Step 1 / 3**
- 진행 바: `[🔎 실습0 · 1/3] [🏃 실습1] [❤️ 실습2] [💥 실습3]`
- C++ 클래스 생성: Tools → New C++ Class → Actor → 이름: `Week3PossessSelector`
- 헤더 코드:
  ```cpp
  UCLASS()
  class WEEK3_API AWeek3PossessSelector : public AActor
  {
      GENERATED_BODY()
  public:
      // 맵에서 드래그로 어느 캐릭터를 조종할지 선택
      UPROPERTY(EditAnywhere, Category="Possess Test")
      APawn* CharacterToControl;
  };
  ```
- 빌드 후 레벨에 배치:
  1. 빌드 완료 후 Place Actors 패널 또는 Content Browser에서 `AWeek3PossessSelector` 검색
  2. 레벨에 드래그하여 배치 (위치는 임의)
  3. 배치된 Actor 선택 → 디테일 패널 → **CharacterToControl** 슬롯에 `Character_A` 드래그

**시각 자료 제안:**
- 좌측: C++ 코드 블록 (`EditAnywhere` 하이라이트, `APawn*` 하이라이트)
- 우측 상단: Place Actors 검색 결과 스크린샷
- 우측 하단: 디테일 패널 스크린샷 — CharacterToControl 슬롯에 Character_A 연결된 상태
- 핵심 주석 말풍선: "`EditAnywhere` = 레벨 에디터 디테일 패널에서 레벨 인스턴스를 직접 참조 가능"

---

### p.20 — AWeek3PlayerController 생성 + Possess 구현
**레이아웃:** `CODE`

**핵심 메시지:** "PlayerController가 BeginPlay에서 PossessSelector를 찾아 지정된 Pawn을 Possess한다."

**구성 요소:**
- **Step 2 / 3**
- 진행 바: `[🔎 실습0 · 2/3] [🏃 실습1] [❤️ 실습2] [💥 실습3]`
- C++ 클래스 생성: Tools → New C++ Class → **PlayerController** → 이름: `Week3PlayerController`
- 헤더 (최소한):
  ```cpp
  UCLASS()
  class WEEK3_API AWeek3PlayerController : public APlayerController
  {
      GENERATED_BODY()
  protected:
      virtual void BeginPlay() override;
  };
  ```
- CPP 구현:
  ```cpp
  #include "Week3PlayerController.h"
  #include "Week3PossessSelector.h"
  #include "Kismet/GameplayStatics.h"

  void AWeek3PlayerController::BeginPlay()
  {
      Super::BeginPlay();

      TArray<AActor*> Selectors;
      UGameplayStatics::GetAllActorsOfClass(
          this, AWeek3PossessSelector::StaticClass(), Selectors);

      if (Selectors.Num() > 0)
      {
          AWeek3PossessSelector* Selector =
              Cast<AWeek3PossessSelector>(Selectors[0]);

          if (Selector && Selector->CharacterToControl)
              Possess(Selector->CharacterToControl);
      }
  }
  ```
- 빌드 후 BP_Gamemode 설정: **Player Controller Class = BP_Week3PlayerController** (Blueprint child)
  - BP_Week3PlayerController: BP_Gamemode에서 사용할 Blueprint Child를 생성하거나, C++ 클래스 직접 지정

**시각 자료 제안:**
- 다크 배경 코드 블록
- `Possess(Selector->CharacterToControl)` 한 줄을 노란색 박스로 강조 + 말풍선: "이 한 줄이 오늘 강의의 핵심"
- 하단 플로우: `BeginPlay → GetAllActorsOfClass → Cast → Possess(target)`
- 우측: BP_Gamemode Player Controller Class 슬롯 스크린샷

---

### p.21 — 실습 0 체크포인트 + AHA 인사이트
**레이아웃:** `CHECKPOINT`

**핵심 메시지:** "코드를 바꾸지 않았다. 변수 하나만 바꿨을 뿐인데 다른 몸으로 들어갔다. — 이것이 PlayerController다."

**구성 요소:**
- **Step 3 / 3 — 체험**
- 진행 바: `[🔎 실습0 · 3/3] [🏃 실습1] [❤️ 실습2] [💥 실습3]`
- 체험 순서:
  1. CharacterToControl = `Character_A` → **Play** → A를 조작, B는 그 자리에 고정
  2. **Stop** → CharacterToControl = `Character_B` → **Play** → B를 조작, A는 고정
  3. 다시 A로 되돌리기 → 확인
- 체크리스트:
  - [ ] 선택한 캐릭터만 플레이어 입력을 받는다
  - [ ] 선택하지 않은 캐릭터는 처음 배치한 위치에 그대로 서 있다
  - [ ] 코드 수정 없이 에디터 변수만 바꿔서 전환이 가능하다
- 트러블슈팅:
  - 아무 캐릭터도 움직이지 않음 → PlayerControllerClass가 Week3PlayerController인지 확인
  - 둘 다 움직임 → Default Pawn Class가 None인지 확인
- **AHA 박스** (강조 디자인, 다른 슬라이드와 차별화된 레이아웃):
  > "PlayerController는 몸이 아니다. 의지다."
  > "Possess() 하나로 어떤 몸이든 선택할 수 있다."
  > "이 분리 덕분에 리스폰, 관전 모드, 캐릭터 교체가 모두 가능해진다."
  > "지금 만든 `AWeek3PlayerController`는 이후 실습 2(HUD), 실습 3(HP 관리)의 기반이 된다."

**시각 자료 제안:**
- 좌우 비교 스크린샷 2장:
  - 왼쪽: CharacterToControl=A 상태 (A 주변에 플레이어 카메라, B는 멀리서 정지)
  - 오른쪽: CharacterToControl=B 상태 (B 주변에 카메라, A는 멀리서 정지)
- AHA 박스는 골든 배경 + 굵은 폰트로 눈에 띄게 처리

---

## 섹션 4: 이론 B — PlayerState (p.22–25)

### p.22 — 섹션 표지: PlayerState
**레이아웃:** `TITLE`

**핵심 메시지:** "플레이어의 '데이터(점수, HP, 팀)'는 어디에 저장해야 설계가 깨끗한가?"

**구성 요소:**
- 섹션 라벨: `이론 B`
- 제목: "PlayerState"
- 한 줄 훅: *"캐릭터가 죽어도 킬 카운트는 유지된다 — 어떻게?"*
- 예상 소요: 10분

**시각 자료 제안:**
- 배경: 게임 스코어보드 스타일 (추상적 표 형태)
- 중앙에 "HP: 80 / Score: 1240 / Team: Red" 텍스트를 카드 형태로

---

### p.23 — PlayerState 개념과 위치
**레이아웃:** `CONCEPT`

**핵심 메시지:** "PlayerState는 서버와 모든 클라이언트에 자동 복제되는 플레이어 데이터 저장소다."

**구성 요소:**
- 정의: `APlayerState : AActor` — 플레이어별 데이터 컨테이너
- 기본 제공 데이터: `PlayerName`, `Score`, `Ping`, `PlayerId`
- 생명주기: PlayerController가 생성될 때 같이 생성, 게임이 끝날 때 소멸
- 접근법: `PlayerController::GetPlayerState<T>()`

**시각 자료 제안:**
- 우측: 네트워크 복제 다이어그램 — 서버 PlayerState → 클라이언트1, 클라이언트2 동기화
- 하단: 클래스 계층 `AActor → APlayerState → AWeek3PlayerState`

---

### p.24 — PlayerState vs GameState 비교
**레이아웃:** `COMPARE`

**핵심 메시지:** "플레이어 단위 데이터는 PlayerState, 게임 전체 데이터는 GameState — 위치가 틀리면 설계가 망가진다."

**구성 요소:**
- 비교 표:

| | PlayerState | GameState |
|---|---|---|
| 범위 | 플레이어 1명 | 게임 전체 |
| 수량 | 플레이어 수만큼 | 1개 |
| 저장 예 | HP, 킬카운트, 팀 | 라운드 시간, 팀 점수 |
| 접근 | `GetPlayerState<>()` | `GetGameState<>()` |

- 설계 오류 예시: "GameState에 HP를 넣으면 어떤 일이 생기는가?"

**시각 자료 제안:**
- 좌우 분리 패널 (PlayerState=파랑, GameState=보라)
- 중앙에 "어디에 넣을까?" 결정 플로우차트 (HP → 플레이어별? Y → PlayerState)

---

### p.25 — PlayerState 실습 연결 예고
**레이아웃:** `PRACTICE`

**핵심 메시지:** "오늘 실습 3에서 AWeek3PlayerState를 직접 만들고 HP를 여기에 옮긴다."

**구성 요소:**
- 실습 3 미리보기:
  - `AWeek3PlayerState` 클래스 생성
  - HP 변수를 Character에서 PlayerState로 이동
  - TakeDamage 처리 흐름
- 왜 이렇게 하는가: "나중에 멀티플레이 확장 시 HP 동기화가 자동으로 됨"

**시각 자료 제안:**
- 이전(Before) / 이후(After) 클래스 다이어그램 비교
  - Before: `AWeek3Character` 내에 `float HP`
  - After: `AWeek3PlayerState` 내에 `float HP`, Character는 참조만

---

## 섹션 5: 이론 C — Enhanced Input 심화 (p.26–30)

### p.26 — 섹션 표지: Enhanced Input 심화
**레이아웃:** `TITLE`

**핵심 메시지:** "Enhanced Input의 3가지 에셋 구조를 완전히 이해하면 어떤 입력 시나리오도 설계할 수 있다."

**구성 요소:**
- 섹션 라벨: `이론 C`
- 제목: "Enhanced Input 심화"
- 예상 소요: 10분

**시각 자료 제안:**
- 배경: 키보드/게임패드 윤곽선 추상 이미지
- 중앙에 `InputAction → Modifier → Trigger → Binding` 4단 파이프라인 미니 도식

---

### p.27 — 3가지 에셋 구조
**레이아웃:** `FLOW`

**핵심 메시지:** "InputAction(무엇), InputMappingContext(어떤 키), SetupPlayerInputComponent(어떻게 반응) — 이 세 겹이 분리된 이유가 있다."

**구성 요소:**
- 3단 레이어 다이어그램:
  1. **InputAction** (`.uasset`) — 행동 추상화 ("Jump", "Move", "Sprint")
  2. **InputMappingContext** (`.uasset`) — 물리 키 → InputAction 매핑 (Space→Jump, WASD→Move)
  3. **SetupPlayerInputComponent** (C++) — InputAction 발동 시 호출할 함수 바인딩
- 분리의 이점: "키 리매핑, 다중 입력 장치, 컨텍스트 전환이 에셋 교체만으로 가능"

**시각 자료 제안:**
- 풀스크린 3층 레이어 다이어그램 (각 층 색상 구분)
- 오른쪽 예시 컬럼: 실제 에셋 이름(`IA_Jump`, `IMC_Default`)으로 구체화

---

### p.28 — Trigger와 Modifier
**레이아웃:** `CONCEPT`

**핵심 메시지:** "Trigger는 '언제 발동할지', Modifier는 '값을 어떻게 변환할지' — 이 두 개가 Enhanced Input의 강력함이다."

**구성 요소:**
- **Trigger 종류** (주요 4가지):
  - `Pressed` — 키 누른 순간 1회
  - `Released` — 키 뗀 순간 1회
  - `Hold` — 일정 시간 이상 누름
  - `Tap` — 짧게 눌렀다 뗌
- **Modifier 종류** (주요 3가지):
  - `Negate` — 값 반전 (왼쪽 이동에 사용)
  - `Swizzle Input Axis Values` — 축 순서 교체
  - `Dead Zone` — 스틱 데드존 처리
- 스프린트 구현에서 사용할 것: `Hold Trigger` 예고

**시각 자료 제안:**
- Trigger 타임라인 그래프: X=시간, 각 Trigger 유형별 발동 구간 시각화
- Modifier 적용 전/후 입력값 비교 표

---

### p.29 — 런타임 IMC 교체 패턴
**레이아웃:** `CODE`

**핵심 메시지:** "AddMappingContext / RemoveMappingContext로 게임 상태에 따라 입력 체계를 동적으로 전환할 수 있다."

**구성 요소:**
- 사용 시나리오: 전투 모드 ↔ UI 모드 ↔ 차량 탑승 모드
- 코드 예제:
  ```cpp
  // Controller에서 IMC 추가
  if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
      ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
  {
      Subsystem->AddMappingContext(CombatIMC, 1);      // 우선순위 1
      Subsystem->RemoveMappingContext(DefaultIMC);
  }
  ```
- Priority 개념 설명: 숫자가 높을수록 우선 처리

**시각 자료 제안:**
- 다크 코드 블록 + `AddMappingContext` 메서드 하이라이트
- 우측에 IMC 교체 시나리오 순서도 (Default → Combat → Vehicle 전환)

---

### p.30 — Enhanced Input 바인딩 패턴 정리
**레이아웃:** `CODE`

**핵심 메시지:** "ETriggerEvent를 올바르게 선택하면 '누르는 동안'과 '누른 순간'을 명확히 분리할 수 있다."

**구성 요소:**
- 바인딩 패턴 3종 코드 비교:
  ```cpp
  // 누른 순간 한 번
  EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &AWeek3Character::Jump);

  // 누르는 동안 매 프레임
  EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AWeek3Character::Move);

  // 뗀 순간
  EnhancedInput->BindAction(SprintAction, ETriggerEvent::Completed, this, &AWeek3Character::StopSprint);
  ```
- 스프린트 구현 예고: Started + Completed 조합

**시각 자료 제안:**
- 3개 코드 블록을 세로로 나열, `ETriggerEvent::XXX` 부분 색상 하이라이트
- 각 블록 왼쪽에 "언제 발동?" 아이콘 (클릭/홀드/릴리즈)

---

## 섹션 6: 실습 1 — 스프린트 구현 (p.31–36)

### p.31 — 실습 1 소개
**레이아웃:** `PRACTICE`

**핵심 메시지:** "Shift를 누르는 동안 캐릭터가 달리고, 떼면 걷기 속도로 복귀한다."

**구성 요소:**
- 목표: `Shift 홀드 → MaxWalkSpeed 600 → 해제 → 300`
- 사용 기술: `ETriggerEvent::Started`, `Completed`, `CharacterMovementComponent`
- 진행 바: `[✅ 실습0] [🏃 실습1 ←] [❤️ 실습2] [💥 실습3]`
- 예상 소요: 17분

**시각 자료 제안:**
- 완성 시 결과 GIF/스크린샷 영역 (우측): 스프린트 중인 캐릭터
- 진행 바를 상단 고정 UI 요소로 모든 실습 슬라이드에 표시

---

### p.32 — 실습 1 Step 1: InputAction 생성
**레이아웃:** `PRACTICE`

**핵심 메시지:** "`IA_Sprint` InputAction 에셋을 만들고 Bool 타입으로 설정한다."

**구성 요소:**
- 단계 번호: `Step 1 / 4`
- 지시사항:
  1. Content Browser → 우클릭 → Input → InputAction 생성
  2. 이름: `IA_Sprint`
  3. Value Type: `Digital (bool)` 선택
  4. 저장
- 체크포인트: Content Browser에 `IA_Sprint` 에셋이 보이면 성공

**시각 자료 제안:**
- 에디터 스크린샷 시퀀스 (3장): 우클릭 메뉴 → 에셋 이름 입력 → 설정 완료
- 각 스크린샷에 빨간 원으로 클릭 위치 표시

---

### p.33 — 실습 1 Step 2: IMC에 Sprint 매핑 추가
**레이아웃:** `PRACTICE`

**핵심 메시지:** "기존 `IMC_Default`를 열어 `Shift → IA_Sprint (Hold Trigger)` 매핑을 추가한다."

**구성 요소:**
- 단계 번호: `Step 2 / 4`
- 지시사항:
  1. `IMC_Default` 에셋 열기
  2. Mappings + 버튼 클릭 → `IA_Sprint` 선택
  3. 키 바인딩: `Left Shift`
  4. Triggers: `Hold` 추가 (Hold Threshold: 0.0)
- 주의: Hold Threshold를 0으로 해야 즉시 발동

**시각 자료 제안:**
- IMC 에디터 스크린샷 (Mappings 항목에 Hold Trigger 설정 완료 상태)
- Trigger 설정 패널 확대 이미지

---

### p.34 — 실습 1 Step 3: C++ 바인딩 및 함수 구현
**레이아웃:** `CODE`

**핵심 메시지:** "SetupPlayerInputComponent에 Sprint 바인딩 추가, StartSprint/StopSprint 함수 구현."

**구성 요소:**
- 단계 번호: `Step 3 / 4`
- 헤더 추가 코드:
  ```cpp
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
  UInputAction* SprintAction;

  void StartSprint();
  void StopSprint();
  ```
- 구현 코드:
  ```cpp
  // SetupPlayerInputComponent 내부
  EnhancedInput->BindAction(SprintAction, ETriggerEvent::Started, this, &AWeek3Character::StartSprint);
  EnhancedInput->BindAction(SprintAction, ETriggerEvent::Completed, this, &AWeek3Character::StopSprint);

  // 구현
  void AWeek3Character::StartSprint()
  {
      GetCharacterMovement()->MaxWalkSpeed = 600.f;
  }
  void AWeek3Character::StopSprint()
  {
      GetCharacterMovement()->MaxWalkSpeed = 300.f;
  }
  ```

**시각 자료 제안:**
- 헤더/CPP 탭 구분 (상단 탭 UI 스타일)
- `MaxWalkSpeed` 값 하이라이트 (나중에 변수로 추출 권장 주석)

---

### p.35 — 실습 1 Step 4: Blueprint에서 SprintAction 에셋 연결
**레이아웃:** `PRACTICE`

**핵심 메시지:** "빌드 후 Blueprint 디테일 패널에서 SprintAction 슬롯에 IA_Sprint를 드래그해 넣는다."

**구성 요소:**
- 단계 번호: `Step 4 / 4`
- 지시사항:
  1. 에디터에서 빌드 (Ctrl+Alt+F11 또는 Build 버튼)
  2. `BP_ThirdPersonCharacter` 열기
  3. 디테일 패널 → Input 카테고리 → SprintAction 슬롯
  4. `IA_Sprint` 드래그 or 드롭다운 선택
  5. 컴파일 & 저장
- 흔한 실수: 빌드 없이 Blueprint 열면 슬롯이 없음

**시각 자료 제안:**
- Blueprint 디테일 패널 스크린샷 (SprintAction 슬롯에 IA_Sprint 연결된 상태)
- 흔한 실수 박스 (노란 배경): "빌드 먼저, Blueprint 나중!"

---

### p.36 — 실습 1 체크포인트
**레이아웃:** `CHECKPOINT`

**핵심 메시지:** "Shift를 누르면 빠르게, 떼면 느리게 달리면 실습 1 완료."

**구성 요소:**
- 진행 바: `[✅ 실습0] [✅ 실습1] [❤️ 실습2 ←] [💥 실습3]`
- 체크리스트:
  - [ ] Shift 누르는 동안 캐릭터가 빠르게 이동
  - [ ] Shift 떼면 일반 속도로 복귀
  - [ ] 컴파일 에러 없음
- 트러블슈팅 박스:
  - 속도 변화 없음 → SprintAction 에셋 연결 확인
  - 컴파일 에러 → `GetCharacterMovement()` include 확인
- 다음: "이제 화면에 HP를 표시해보자 → 실습 2"

**시각 자료 제안:**
- 완성 결과 스크린샷 (빠른 이동 중인 캐릭터 + CharacterMovement 디버그 오버레이)
- 트러블슈팅 항목에 🔧 아이콘

---

## 섹션 7: 실습 2 — UMG HP 바 위젯 (p.37–41)

### p.37 — 실습 2 소개
**레이아웃:** `PRACTICE`

**핵심 메시지:** "UMG Widget Blueprint로 화면에 HP 바를 만들고, PlayerController(실습 0에서 만든 것!)가 이를 뷰포트에 추가한다."

**구성 요소:**
- 목표: 화면 좌상단에 HP 바 표시, 데미지를 받으면 감소
- 사용 기술: `UUserWidget`, `UProgressBar`, `CreateWidget`, `AddToViewport`
- 연결 포인트: "실습 0에서 만든 `AWeek3PlayerController`를 이번 실습에서 확장한다"
- 진행 바: `[✅ 실습0] [✅ 실습1] [❤️ 실습2 ←] [💥 실습3]`
- 예상 소요: 13분 (실습 3과 합산)

**시각 자료 제안:**
- 우측: 완성된 HP 바 UI 스크린샷 (게임 뷰포트에 오버레이된 상태)

---

### p.38 — 실습 2 Step 1: Widget Blueprint 생성
**레이아웃:** `PRACTICE`

**핵심 메시지:** "`WBP_HUD` Widget Blueprint를 만들고 ProgressBar를 배치한다."

**구성 요소:**
- 단계 번호: `Step 1 / 3`
- 지시사항:
  1. Content Browser → 우클릭 → User Interface → Widget Blueprint
  2. 이름: `WBP_HUD`
  3. 더블클릭 → Widget Designer 열기
  4. Palette에서 `ProgressBar` 드래그 → 캔버스 좌상단 배치
  5. ProgressBar 이름: `HPBar`, 크기: 200×20
  6. Is Variable 체크 (코드에서 접근하기 위해)
- 디자인 팁: Anchors를 좌상단으로 설정해 해상도 대응

**시각 자료 제안:**
- Widget Designer 스크린샷 시퀀스 (빈 캔버스 → ProgressBar 배치 완료)
- Anchors 설정 확대 이미지

---

### p.39 — 실습 2 Step 2: Widget C++ 연동
**레이아웃:** `CODE`

**핵심 메시지:** "C++ UserWidget 클래스를 만들고 HPBar를 BindWidget으로 연결한다."

**구성 요소:**
- 단계 번호: `Step 2 / 3`
- 헤더:
  ```cpp
  UCLASS()
  class WEEK3_API UWeek3HUDWidget : public UUserWidget
  {
      GENERATED_BODY()
  public:
      UPROPERTY(meta=(BindWidget))
      UProgressBar* HPBar;

      void UpdateHP(float CurrentHP, float MaxHP);
  };
  ```
- 구현:
  ```cpp
  void UWeek3HUDWidget::UpdateHP(float CurrentHP, float MaxHP)
  {
      if (HPBar)
          HPBar->SetPercent(CurrentHP / MaxHP);
  }
  ```
- `BindWidget` 설명: 이름이 같은 위젯을 자동으로 연결해주는 매직 메타

**시각 자료 제안:**
- `meta=(BindWidget)` 부분 특별 하이라이트 + 말풍선: "이름이 'HPBar'여야 연결됨"

---

### p.40 — 실습 2 Step 3: PlayerController에서 Widget 생성 및 표시
**레이아웃:** `CODE`

**핵심 메시지:** "실습 0에서 만든 AWeek3PlayerController의 BeginPlay를 확장해서 Widget을 생성하고 뷰포트에 추가한다."

**구성 요소:**
- 단계 번호: `Step 3 / 3`
- 코드:
  ```cpp
  // AWeek3PlayerController.h 에 추가
  UPROPERTY(EditAnywhere, Category=UI)
  TSubclassOf<UWeek3HUDWidget> HUDWidgetClass;

  UPROPERTY()
  UWeek3HUDWidget* HUDWidget;

  // AWeek3PlayerController.cpp BeginPlay (기존 Possess 코드 아래에 추가)
  if (HUDWidgetClass)
  {
      HUDWidget = CreateWidget<UWeek3HUDWidget>(this, HUDWidgetClass);
      HUDWidget->AddToViewport();
  }
  ```
- Blueprint에서 HUDWidgetClass에 WBP_HUD 연결 필요
- 연결 강조: "이 PlayerController는 실습 0에서 만든 것 — Possess 코드 바로 아래에 이어서 작성"

**시각 자료 제안:**
- `CreateWidget` + `AddToViewport` 두 줄 노란색 박스 강조
- 우측에 생명주기 흐름: PlayerController::BeginPlay → (Possess) → Widget 생성 → Viewport

---

### p.41 — 실습 2 체크포인트
**레이아웃:** `CHECKPOINT`

**핵심 메시지:** "게임 시작 시 화면에 HP 바가 보이면 실습 2 완료."

**구성 요소:**
- 체크리스트:
  - [ ] 게임 플레이 시 좌상단에 ProgressBar 표시
  - [ ] WBP_HUD의 Parent Class가 `UWeek3HUDWidget`으로 설정됨
  - [ ] 컴파일 에러 없음
- 트러블슈팅:
  - 위젯 안 보임 → HUDWidgetClass에 WBP_HUD 연결 확인
  - BindWidget 에러 → HPBar 이름 대소문자 정확히 일치 확인

**시각 자료 제안:**
- 완성 결과: 게임 뷰 + 좌상단 HP 바 오버레이 스크린샷

---

## 섹션 8: 실습 3 — PlayerState HP + 데미지 처리 (p.42–48)

### p.42 — 실습 3 소개
**레이아웃:** `PRACTICE`

**핵심 메시지:** "HP를 Character에서 PlayerState로 이동하고, TakeDamage 오버라이드로 데미지를 처리한다."

**구성 요소:**
- 목표: `AWeek3PlayerState` 생성 → HP 이전 → 데미지 처리 → HUD 연동
- 진행 바: `[✅ 실습0] [✅ 실습1] [✅ 실습2] [💥 실습3 ←]`
- 예상 소요: 13분 내 (실습 2와 합산)

**시각 자료 제안:**
- Before/After 아키텍처 다이어그램 (이론 B p.25에서 예고한 것의 실체화)

---

### p.43 — 실습 3 Step 1: AWeek3PlayerState 생성
**레이아웃:** `CODE`

**핵심 메시지:** "Tools → New C++ Class로 PlayerState를 상속한 `AWeek3PlayerState`를 만든다."

**구성 요소:**
- 단계 번호: `Step 1 / 5`
- 코드:
  ```cpp
  UCLASS()
  class WEEK3_API AWeek3PlayerState : public APlayerState
  {
      GENERATED_BODY()
  public:
      UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Stats)
      float MaxHP = 100.f;

      UPROPERTY(BlueprintReadOnly, Category=Stats)
      float CurrentHP;

      virtual void BeginPlay() override;
  };
  ```
- 주의: 반드시 Editor의 New C++ Class 메뉴로 생성할 것 (직접 파일 생성 금지)

**시각 자료 제안:**
- New C++ Class 마법사 스크린샷 (PlayerState 선택 화면)
- 경고 박스: "파일 탐색기에서 직접 만들면 UBT가 인식 못 함"

---

### p.44 — 실습 3 Step 2: BeginPlay에서 HP 초기화
**레이아웃:** `CODE`

**핵심 메시지:** "BeginPlay에서 CurrentHP를 MaxHP로 초기화한다."

**구성 요소:**
- 단계 번호: `Step 2 / 5`
- 구현:
  ```cpp
  void AWeek3PlayerState::BeginPlay()
  {
      Super::BeginPlay();
      CurrentHP = MaxHP;
  }
  ```
- Character에서 HP 관련 코드 제거 안내

**시각 자료 제안:**
- 이전 Character 코드와 새 PlayerState 코드를 나란히 (이동 화살표 포함)

---

### p.45 — 실습 3 Step 3: GameMode에서 PlayerState 등록
**레이아웃:** `CODE`

**핵심 메시지:** "GameMode의 PlayerStateClass를 AWeek3PlayerState로 설정한다."

**구성 요소:**
- 단계 번호: `Step 3 / 5`
- C++ 방식:
  ```cpp
  // AWeek3GameMode 생성자
  PlayerStateClass = AWeek3PlayerState::StaticClass();
  ```
- Blueprint 방식 (대안): BP_Gamemode 디테일 패널 → Player State Class 슬롯
- 둘 중 하나만 선택 (C++이 권장)

**시각 자료 제안:**
- C++ 방식 vs Blueprint 방식 병렬 스크린샷

---

### p.46 — 실습 3 Step 4: TakeDamage 구현
**레이아웃:** `CODE`

**핵심 메시지:** "Character의 TakeDamage를 오버라이드하여 PlayerState의 HP를 감소시킨다."

**구성 요소:**
- 단계 번호: `Step 4 / 5`
- 코드:
  ```cpp
  float AWeek3Character::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent,
      AController* EventInstigator, AActor* DamageCauser)
  {
      float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

      if (AWeek3PlayerState* PS = GetPlayerState<AWeek3PlayerState>())
      {
          PS->CurrentHP = FMath::Max(0.f, PS->CurrentHP - ActualDamage);
      }
      return ActualDamage;
  }
  ```
- `GetPlayerState<T>()` 패턴 강조

**시각 자료 제안:**
- `GetPlayerState<AWeek3PlayerState>()` 하이라이트
- 데미지 흐름 다이어그램: ApplyDamage 호출 → TakeDamage → PlayerState HP 감소

---

### p.47 — 실습 3 Step 5: HUD 연동
**레이아웃:** `CODE`

**핵심 메시지:** "데미지를 받을 때마다 PlayerController를 통해 HUD에 HP 변경을 알린다."

**구성 요소:**
- 단계 번호: `Step 5 / 5`
- TakeDamage에 HUD 업데이트 추가:
  ```cpp
  // TakeDamage 내부, PS->CurrentHP 갱신 이후
  if (AWeek3PlayerController* PC = Cast<AWeek3PlayerController>(GetController()))
  {
      PC->UpdateHUD(PS->CurrentHP, PS->MaxHP);
  }
  ```
- PlayerController에 UpdateHUD 함수 추가:
  ```cpp
  void AWeek3PlayerController::UpdateHUD(float CurrentHP, float MaxHP)
  {
      if (HUDWidget)
          HUDWidget->UpdateHP(CurrentHP, MaxHP);
  }
  ```

**시각 자료 제안:**
- 전체 데이터 흐름 요약 다이어그램:
  `TakeDamage → PlayerState HP 갱신 → PlayerController::UpdateHUD → HUDWidget::UpdateHP → ProgressBar`

---

### p.48 — 실습 3 체크포인트
**레이아웃:** `CHECKPOINT`

**핵심 메시지:** "키 입력으로 데미지를 적용했을 때 화면 HP 바가 줄어들면 전체 실습 완료."

**구성 요소:**
- 테스트 방법: 레벨 블루프린트에서 T 키 → `ApplyDamage` 노드 → Self(캐릭터), 데미지 10
- 체크리스트:
  - [ ] 게임 시작 시 HP 바 100% 표시
  - [ ] 데미지 적용 시 HP 바 감소
  - [ ] HP 0 이하가 되어도 크래시 없음
- 트러블슈팅:
  - HP 변화 없음 → GameMode PlayerStateClass 확인
  - HUD 업데이트 안 됨 → PC Cast 결과 nullptr 확인

**시각 자료 제안:**
- 완성 데모 스크린샷: HP 바 부분 감소 상태

---

## 섹션 9: 보너스 (p.49–50)

### p.49 — 보너스: 탑다운 카메라 전환 — 개요
**레이아웃:** `CONCEPT`

**핵심 메시지:** "IMC 런타임 교체 패턴을 활용해 3인칭 ↔ 탑다운 카메라를 버튼 하나로 전환할 수 있다."

**구성 요소:**
- 전제 조건: 기본 실습 4개 완료
- 핵심 아이디어:
  - 카메라 암 길이/각도 변경 (SpringArm 조작)
  - IMC 교체로 탑다운 전용 입력 체계 적용
- 대략적 단계 요약 (상세는 다음 슬라이드):
  1. TopDown IMC + IA 생성
  2. SpringArm 설정 변경
  3. 전환 트리거 키 바인딩

**시각 자료 제안:**
- 좌우 비교: 3인칭 뷰 vs 탑다운 뷰 스크린샷

---

### p.50 — 보너스: 탑다운 카메라 전환 — 구현
**레이아웃:** `CODE`

**핵심 메시지:** "V 키를 누를 때마다 카메라 모드를 토글하는 30줄 미만의 코드로 구현 가능하다."

**구성 요소:**
- 핵심 코드:
  ```cpp
  void AWeek3Character::ToggleCameraMode()
  {
      bIsTopDown = !bIsTopDown;
      if (bIsTopDown)
      {
          CameraBoom->TargetArmLength = 1200.f;
          CameraBoom->SetRelativeRotation(FRotator(-70.f, 0.f, 0.f));
          // TopDown IMC 교체 (IMC 교체 코드 생략)
      }
      else
      {
          CameraBoom->TargetArmLength = 300.f;
          CameraBoom->SetRelativeRotation(FRotator(-20.f, 0.f, 0.f));
          // Default IMC 복귀
      }
  }
  ```
- 추가 도전: 전환 시 부드러운 블렌딩 (FInterpTo 활용)

**시각 자료 제안:**
- 이전 슬라이드의 비교 뷰 재활용 + 전환 화살표
- 도전 박스: `FMath::FInterpTo` 힌트

---

## 섹션 10: 정리 및 5주차 예고 (p.51–53)

### p.51 — 오늘 배운 것 총정리
**레이아웃:** `SUMMARY`

**핵심 메시지:** "실습 0에서 체험한 Possess 위에, PlayerState + Enhanced Input이 어떻게 협력하는지 한 장으로 요약."

**구성 요소:**
- 통합 아키텍처 다이어그램 (오늘 전체 흐름):
  ```
  키 입력
    ↓ InputMappingContext
  InputAction
    ↓ BindAction
  PlayerController ──→ Possess(Pawn)  ← 실습 0에서 직접 체험
    ├→ PlayerState (HP 관리)
    └→ Pawn/Character (이동·애니메이션)
              ↓
           HUDWidget (화면 표시)
  ```
- 핵심 클래스 요약 카드:
  - `APlayerController` — 입력의 관문, Possess로 몸과 연결
  - `AWeek3PossessSelector` — 실습 0에서 만든 맵 배치 설정 액터
  - `APlayerState` — 플레이어 데이터 저장소
  - `UEnhancedInputComponent` — 고급 입력 처리
  - `UUserWidget` — UI 표시

**시각 자료 제안:**
- 풀스크린 통합 다이어그램 (색상 코드 통일: 파랑=컨트롤러, 주황=입력, 초록=UI)
- 실습 0의 Possess 경로를 별도 강조 (점선 박스 또는 배지)

---

### p.52 — 이번 주 실습 달성 요약
**레이아웃:** `CHECKPOINT`

**핵심 메시지:** "4가지 실습을 완료하며 PlayerController 기반 게임 프레임워크의 기초를 완성했다."

**구성 요소:**
- 달성 체크리스트:
  - [x] **Possess 직접 체험** — Controller와 Pawn의 분리를 손으로 확인 (실습 0)
  - [x] 스프린트 — Enhanced Input Hold Trigger (실습 1)
  - [x] HP 바 위젯 — UMG + BindWidget (실습 2)
  - [x] PlayerState HP + 데미지 처리 (실습 3)
- 누적 프로젝트 현황:
  - 기본 이동/점프 (Week 3)
  - **AWeek3PlayerController 클래스** (오늘, 실습 0 — 이후 실습의 기반)
  - 스프린트 (오늘, 실습 1)
  - HP 시스템 (오늘, 실습 3)
  - HUD (오늘, 실습 2)

**시각 자료 제안:**
- 누적 기능 목록을 레고 블록 쌓기 형태로 시각화 (아래서부터 쌓여가는 구조)
- 실습 0 블록을 "기반(Foundation)" 색상으로 구분

---

### p.53 — 5주차 예고 및 Q&A
**레이아웃:** `TITLE`

**핵심 메시지:** "다음 주에는 UMG를 더 깊게 파고, Blueprint와 C++ 연동 패턴을 배운다."

**구성 요소:**
- 5주차 예고:
  - UMG/Widget Blueprint 심화
  - HUD 구성 요소 확장 (스킬 쿨타임 UI, 미니맵 기초)
  - Blueprint와 C++ 통신 패턴 (이벤트 디스패처)
- 사전 준비 권고:
  - BP_ThirdPersonCharacter 현재 상태 백업
  - UMG 공식 문서 한 번 훑어보기
- Q&A 시간: "오늘 막힌 부분 있으면 지금 질문하세요"

**시각 자료 제안:**
- 5주차 기능 미리보기 스크린샷 (스킬 아이콘 + 쿨타임 원형 UI 예시)
- 대형 물음표 아이콘 + "질문 있으신 분?"

---

## 시각 자료 제작 우선순위

강화 효과가 가장 큰 시각 자료 TOP 6 (제작 시간 대비 교육 효과 기준):

| 순위 | 슬라이드 | 자료 유형 | 제작 난이도 | 교육 효과 |
|------|----------|-----------|-------------|-----------|
| 1 | p.21 | 실습 0 Before/After 비교 스크린샷 + AHA 박스 | 낮 | **최고** |
| 2 | p.13 | Possess 시퀀스 다이어그램 | 중 | 매우 높음 |
| 3 | p.27 | Enhanced Input 3레이어 다이어그램 | 중 | 높음 |
| 4 | p.51 | 통합 아키텍처 다이어그램 (Possess 경로 포함) | 중 | 매우 높음 |
| 5 | p.24 | PlayerState vs GameState 비교 | 낮 | 높음 |
| 6 | p.47 | 데미지 흐름 다이어그램 | 낮 | 높음 |

---

## 슬라이드 레이아웃 분포

| 레이아웃 유형 | 슬라이드 수 | 해당 페이지 |
|---------------|-------------|-------------|
| TITLE | 9 | 1, 5, 11, 17, 22, 26, 31, 37, 42, 53 |
| CONCEPT | 10 | 2, 7, 9, 12, 14, 23, 28, 29, 38, 49 |
| CODE | 13 | 15, 19, 20, 29, 30, 34, 39, 40, 43~47, 50 |
| FLOW | 3 | 13, 27, 51 |
| COMPARE | 5 | 4, 8, 16, 24, 30 |
| PRACTICE | 9 | 18, 25, 31~35, 37, 38, 42 |
| CHECKPOINT | 6 | 10, 21, 36, 41, 48, 52 |
| SUMMARY | 3 | 3, 16, 51 |

> **실습 0 신규 추가 슬라이드:** p.17(TITLE), p.18(PRACTICE), p.19(CODE), p.20(CODE), p.21(CHECKPOINT) — 5장
> 이에 따라 이후 모든 섹션 페이지 번호가 +5 이동됨.

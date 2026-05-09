# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

**UnrealStudy** is an Unreal Engine 5.4 third-person game project (module `Study`, project file `Study.uproject` — note the parent folder is still named `Week3` from the initial template, but the Unreal module/classes use `Study` prefix as of the Week 5 rename) used as a study/teaching repository for a university-level Unreal Engine study group (스터디). It is based on the standard UE5 third-person template with Enhanced Input.

**Study context:**
- Instructor: 박준건
- Every Monday 18:30–20:00 (90 min), targeting students new to Unreal Engine
- Engine version: UE 5.4 (`EngineAssociation: "5.4"`), IDE: Visual Studio (recommended), Rider, VSCode
- Enabled plugins: `ModelingToolsEditorMode` (Editor only)
- Current progress: Weeks 1–3 complete (theory-heavy; mid-term break 4/13 and 4/20)
- Next session: 2026-04-27 — PlayerController & Enhanced Input hands-on
- Course materials and syllabi live in `course_materials/`

**Lecture goals** (from Week 1):
1. Understand UE's structure and design rationale
2. Learn UE coding conventions
3. Use engine-provided features effectively
4. Read official samples and engine source code
5. Read UE-based code written by others

## Directory Structure

```
Week3/                     # parent folder (kept from template; module is "Study")
├── Source/Study/          # C++ source — single runtime module
│   ├── Study.h/.cpp       # Module entry point (boilerplate)
│   ├── StudyGameMode.h/.cpp
│   ├── StudyGameInstance.h/.cpp
│   ├── StudyGameState.h/.cpp
│   ├── StudyPlayerController.h/.cpp
│   ├── StudyPlayerState.h/.cpp
│   ├── StudyCharacter.h/.cpp
│   └── StudyPossessSelector.h/.cpp
├── Content/               # UE binary assets (.uasset)
│   ├── BP_Gamemode.uasset
│   ├── BP_JustPawn.uasset
│   └── BP_ThirdPersonCharacter.uasset
├── Config/                # Engine/Editor/Input INI files
├── course_materials/      # Study documents (Markdown, PDFs)
│   ├── 강의_계획_수정본.md     # Revised syllabus (Weeks 1–9, concise)
│   ├── 강의_계획_수정본_v2.md  # Updated concise syllabus
│   ├── 강의_계획_수정본_v3.md  # Latest concise syllabus
│   ├── revised_syllabus.md    # Comprehensive revised syllabus with detailed plans
│   └── cache/                 # Temporary cache for task outputs
└── Study.uproject         # UE5.4 project descriptor (EngineAssociation: "5.4")
```

## Build & Compile

Build from within Unreal Editor using the **Build** button, or use UnrealBuildTool from the command line:

```bash
# Game build
UnrealBuildTool Study Win64 Development -Project="<path>/Study.uproject"

# Editor build
UnrealBuildTool StudyEditor Win64 Development -Project="<path>/Study.uproject"
```

To regenerate Visual Studio project files, right-click `Study.uproject` → "Generate Visual Studio project files", or:
```bash
UnrealVersionSelector -projectfiles "<path>/Study.uproject"
```

Open `Study.sln` in Visual Studio 2022.

## Code Architecture

**Module:** `Source/Study/` — single runtime module named `Study`.

**Key classes:**
- `AStudyCharacter` (`StudyCharacter.h/.cpp`) — Player character extending `ACharacter`. Third-person camera setup (SpringArm + Camera). Uses Enhanced Input for Move/Look/Jump/Sprint. Input assets are assigned in the Blueprint child class (`BP_ThirdPersonCharacter`). On 1-second tick applies damage to PlayerState; on death notifies PlayerController via `HandlePlayerDeath()` (does NOT destroy itself — PC is responsible).
- `AStudyGameMode` (`StudyGameMode.h/.cpp`) — Game rules. `MaxRespawnCount` (EditAnywhere). Constructor maps `GameStateClass`/`PlayerControllerClass`/`PlayerStateClass`. Blueprint variant: `BP_Gamemode`.
- `UStudyGameInstance` (`StudyGameInstance.h/.cpp`) — Persistent across levels/PIE: `TotalPlayCount` (++ in `Init()`), `BestStageReached`. Registered via `Config/DefaultEngine.ini` `GameInstanceClass=...`.
- `AStudyGameState` (`StudyGameState.h/.cpp`) — Replicated shared state: `CurrentStage`, `CurrentWave`, `TimeUntilNextWave`. Tick-based wave countdown.
- `AStudyPlayerController` (`StudyPlayerController.h/.cpp`) — Public entry point `HandlePlayerDeath()`. `ScheduleRespawn`/`RespawnCharacter` are private helpers. Owns the HUD widget (`DefaultHUDWidgetClass`).
- `AStudyPlayerState` (`StudyPlayerState.h/.cpp`) — `MaxHP`/`CurrentHP`/`RemainingRespawns`. `BeginPlay` copies `GameMode->MaxRespawnCount` into `RemainingRespawns` (rule → state).
- `Study.h/.cpp` — Module entry point (boilerplate).

**Blueprint assets (Content/):**
- `BP_Gamemode` — Blueprint child of `AStudyGameMode`
- `BP_ThirdPersonCharacter` — Blueprint child of `AStudyCharacter`; holds all input asset references
- `BP_JustPawn` — Standalone Pawn Blueprint (used for Pawn vs Character comparison in Week 3 practical)

**Input system:** UE5 Enhanced Input (`EnhancedInput` module). `SetupPlayerInputComponent` binds actions via `UEnhancedInputComponent`. `UInputMappingContext` and `UInputAction` assets assigned in Blueprint.

**Module dependencies** (`Study.Build.cs`): `Core`, `CoreUObject`, `Engine`, `InputCore`, `EnhancedInput`, `UMG`.

**Class redirects:** `Config/DefaultEngine.ini` includes `+ActiveClassRedirects` for the historical `TP_ThirdPerson*` and `Week3*` names so existing `.uasset` references continue to resolve to the current `Study*` classes.

## UE5 Conventions

- Generated header (`*.generated.h`) must be the **last** `#include` in every header.
- Use `UPROPERTY`, `UFUNCTION`, `UCLASS` macros for reflection.
- `GENERATED_BODY()` is required in all `UCLASS` / `USTRUCT` declarations.
- New C++ classes must be added via Unreal Editor (Tools → New C++ Class) or manually registered — do not create `.cpp`/`.h` files without updating the build system.
- After any header change, rebuild in the Editor or via UBT to regenerate reflection data.
- Naming: classes prefixed with type letter (`A` for Actor, `U` for UObject, `F` for structs, `E` for enums, `I` for interfaces).

## Study Curriculum Summary

| Week | Date | Topic | Status |
|------|------|--------|--------|
| 1 | 3/23 | Engine philosophy, Modern OOP concepts | ✅ Done |
| 2 | 3/30 | World creation, GameMode/GameState, Replication basics | ✅ Done |
| 3 | 4/6 | UObject→AActor→APawn→ACharacter hierarchy; Pawn vs Character practical | ✅ Done |
| — | 4/13 | Mid-term break | — |
| — | 4/20 | Mid-term break | — |
| 4 | 4/27 | PlayerController & Enhanced Input deep-dive + practical | 🔲 Upcoming |
| 5 | 5/4 | UMG/Widget Blueprints, HUD, Blueprint basics + practical | 🔲 |
| 6 | 5/11 | UE C++ deep: GC, Reflection, Coding conventions + practical | 🔲 |
| 7 | 5/18 | Delegates, Component-based design + practical | 🔲 |
| 8 | 5/25 | Asset management + Data-driven design (integrated) + practical | 🔲 |
| 9 | 6/1 | Capstone practical project & wrap-up | 🔲 |

**Topics pending coverage:** PlayerState, PlayerController details, UI, inter-object communication, scalable architecture, game scope expansion.

**Instructor-identified gaps from Week 3:** (1) How to build UI, (2) How objects communicate, (3) Maintainable feature design, (4) Scaling game scope.

**Cumulative practical project (Weeks 4–9):** Each week's practical builds on the previous — Week 4: character input extension → Week 5: add HUD → Week 6: code refactoring → Week 7: interaction system → Week 8: DataAsset data layer → Week 9: complete mini-game.

## Course Materials

All study documents live in `course_materials/`:
- `강의_계획_수정본.md` — Concise revised syllabus with week-by-week breakdown and teaching methodology
- `강의_계획_수정본_v2.md` — Updated version of the concise revised syllabus
- `강의_계획_수정본_v3.md` — Latest version of the concise revised syllabus
- `revised_syllabus.md` — Comprehensive revised syllabus: detailed 1–3 week analysis, full 4–9 week plans, pedagogical recommendations
- `cache/` — Temporary cache directory for task outputs
- PDFs of weekly lecture slides (Weeks 1–3) are provided externally by the instructor

# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is an Unreal Engine 5.4 third-person game project (`Week3`) created as part of a study curriculum. It uses the standard UE5 third-person template with Enhanced Input.

## Build & Compile

Build from within Unreal Editor using the **Build** button, or use UnrealBuildTool from the command line:

```
# Game build
UnrealBuildTool Week3 Win64 Development -Project="<path>/Week3.uproject"

# Editor build
UnrealBuildTool Week3Editor Win64 Development -Project="<path>/Week3.uproject"
```

To regenerate Visual Studio project files, right-click `Week3.uproject` → "Generate Visual Studio project files", or use:
```
UnrealVersionSelector -projectfiles "<path>/Week3.uproject"
```

The solution is `Week3.sln` — open in Visual Studio 2022.

## Code Architecture

**Module:** `Source/Week3/` — single runtime module named `Week3`.

**Key classes:**
- `AWeek3Character` (`Week3Character.h/.cpp`) — the player character. Extends `ACharacter` with a third-person camera setup (SpringArm + Camera). Uses Enhanced Input for Move/Look/Jump actions. Input assets (`DefaultMappingContext`, `JumpAction`, `MoveAction`, `LookAction`) are assigned via Blueprint derived from this class.
- `AWeek3GameMode` (`Week3GameMode.h/.cpp`) — minimal game mode, sets the default pawn class.
- `Week3.h/.cpp` — module entry point (boilerplate).

**Input system:** Uses UE5 Enhanced Input (`EnhancedInput` module dependency). `SetupPlayerInputComponent` binds actions via `UEnhancedInputComponent`. The `UInputMappingContext` and `UInputAction` assets are expected to be assigned in the Blueprint child class, not in C++.

**Module dependencies** (`Week3.Build.cs`): `Core`, `CoreUObject`, `Engine`, `InputCore`, `EnhancedInput`.

## UE5 Conventions

- Generated header (`*.generated.h`) must be the last include in headers.
- Use `UPROPERTY`, `UFUNCTION`, `UCLASS` macros for reflection.
- `GENERATED_BODY()` is required in all `UCLASS` / `USTRUCT` declarations.
- New C++ classes must be added via Unreal Editor (Tools → New C++ Class) or manually registered — do not just create `.cpp`/`.h` files without updating the build system.
- After any header changes, rebuild in the Editor or via UBT to regenerate reflection data.

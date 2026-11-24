# Jungle Marble Blast

A 2D marble-shooter arcade desktop game built in **C++** and **SDL2** (`SDL2_image`, `SDL2_ttf`, `SDL2_gfx`, `SDL2_mixer`).

Developed as the course project for **Fundamentals of Programming (Fall 2022 – Winter 2023)** in the Department of Electrical Engineering at Sharif University of Technology.

## Key Features
- **Procedural Parametric Track Generator:** Synthesizes 3 smooth curved marble paths using second-order angular numerical integration (`d2t`, `dt`, `t`) with automatic viewport bounding-box normalization across a `1280x800` window.
- **Level & Theme Selection:** Combine 3 distinct track geometries with 4 visual themes (12 playable combinations).
- **Real-Time 2D Gameplay Engine:**
  - Vector-based mouse aiming and projectile firing
  - Projectile swapping via `Space`
  - Collision detection and contiguous color-matching chain elimination with rollback shifting
  - 3 special power-up projectiles: **Fireball**, **Bomb (AoE blast)**, and **Wildcard (color-clear)**
- **Interactive Multi-Screen GUI:** Custom Login and Registration menus with `SDL_TEXTINPUT` text fields, `SDL_ttf` font rendering, hover-state buttons, Help screen, and file-backed user persistence (`users.txt`).

## Controls
- **Mouse Move:** Aim shooter toward cursor
- **Left Click:** Shoot marble / navigate menus
- **Spacebar:** Swap current projectile

## Tech Stack
- **Language:** C++
- **Graphics & Multimedia:** SDL2, SDL2_image, SDL2_ttf, SDL2_gfx, SDL2_mixer
- **Storage:** Standard C++ File I/O (`fstream`)

## Project Structure
```text
Jungle-Marble-Blast/
├── main.cpp                  # Game loop, procedural track generator, menus & gameplay logic
├── Jungle-Marble-Blast.cbp   # Code::Blocks project file
├── users.txt                 # Local account persistence file
├── pic/                      # Sprites, backgrounds, UI buttons, and TTF fonts
├── leaderboard.png
└── pause.png
```

## Building & Running

### Linux / macOS (g++)
Ensure the SDL2 development libraries (`SDL2`, `SDL2_image`, `SDL2_ttf`, `SDL2_gfx`, `SDL2_mixer`) are installed, then run:
```bash
g++ main.cpp -o Jungle-Marble-Blast -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_gfx -lSDL2_mixer
./Jungle-Marble-Blast
```

### Windows (MinGW / Code::Blocks)
1. Open `Jungle-Marble-Blast.cbp` in **Code::Blocks** with MinGW and SDL2 configured.
2. Ensure the SDL2 runtime DLLs are available in your PATH or build output directory.
3. Build and run from the project root directory so the relative `pic/` asset paths resolve properly.

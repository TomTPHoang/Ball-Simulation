# Bouncing Ball Simulation (Raylib C++)

This project simulates a bouncing ball inside a resizable window using the Raylib graphics library. It demonstrates a proper game loop with frame-rate independence, FPS capping, and debug information.

## Features

- Ball moves smoothly and bounces off window edges
- Real-time FPS cap switching (keys 1-4 and arrow keys)
- Delta time clamping to maintain simulation stability
- Debug overlay displays FPS, frame time, and elapsed time
- Resizable window with continuous simulation during resizing
- Randomized initial ball velocity

## Controls

| Key | Action |
|---|---|
| 1 | Cap FPS to 60 |
| 2 | Cap FPS to 120 |
| 3 | Cap FPS to 144 |
| R | Restart the program |
| ESC | Exit the simulation |

## How to Build and Run

### Prerequisites

- Windows OS
- Visual Studio 2019 or 2022
- Raylib library (Included locally in the `Raylib` folder)

### Build Instructions

1. Open the `.sln` file in Visual Studio.
2. Set the platform to `x64`.
3. Build and run the project using `Ctrl + F5`.

> Raylib is included locally in the `Raylib` folder, so no global installation is necessary.

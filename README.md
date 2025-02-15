# Pac-Man Clone (C, Windows API)

## Overview
This is a console-based Pac-Man clone developed in C using the Windows API for real-time input handling. The game features player movement, randomized ghost AI, a structured game grid, and interactive gameplay mechanics.

## Features
- **Real-time player movement** using keyboard inputs
- **Randomized ghost AI** that chases the player
- **Structured game grid** for movement and collision detection
- **Score tracking** based on collected pellets
- **Color-coded rendering** for an enhanced console experience

## Requirements
- Windows OS
- GCC Compiler (MinGW recommended) or any C compiler that supports Windows API

## Installation & Running the Game
1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/pacman-clone.git
   cd pacman-clone
   ```
2. Compile the code using GCC (MinGW):
   ```bash
   gcc pacman.c -o pacman.exe -Wall
   ```
3. Run the game:
   ```bash
   ./pacman.exe
   ```

## Controls
- **Arrow Keys**: Move Pac-Man up, down, left, or right
- **ESC**: Exit the game

## Game Rules
- Collect all pellets to win
- Avoid ghosts to stay alive
- Gain points by eating pellets
- Survive as long as possible

## Future Improvements
- Adding power-ups for Pac-Man to eat ghosts
- Enhancing ghost AI for more challenging gameplay
- Implementing a graphical UI instead of a console-based interface

## License
This project is open-source and available under the MIT License.

---


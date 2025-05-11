# Tic Tac Toe
 
*Classic two-player game built with C++ and VCL*

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![Platform: Windows](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Screenshots](#screenshots)
- [Requirements](#requirements)
- [Installation](#installation)
- [How to Play](#how-to-play)
- [Files](#files)
- [Contributing](#contributing)
- [License](#license)
- [Author](#author)

## Overview
"Tic Tac Toe" is a classic two-player game implemented in C++ using the VCL framework. Players alternate placing 'X' or 'O' on a 3x3 grid, aiming to align three symbols horizontally, vertically, or diagonally. The game features a graphical interface with BMP images, a turn indicator, and robust win detection.

## Features
- **Graphical Interface**: Displays 'X', 'O', and empty fields using BMP images for a polished look.
- **Turn Indicator**: Shows the current player's turn with a small 'X' or 'O' image.
- **Win Detection**: Automatically checks 8 possible winning combinations after each move.
- **Reset Functionality**: Restart the game with a single click to play again.

## Screenshots
*Coming soon!*  
Add screenshots of the game interface to the `screenshots/` folder and update this section.

## Requirements
- **Compiler**: C++ compiler with VCL support (e.g., Embarcadero C++ Builder)
- **Operating System**: Windows
- **Image Files**: Place the following BMP files in an `img/` folder:
  - `nic.bmp` (empty field)
  - `x.bmp` (cross)
  - `o.bmp` (circle)
  - `xsmall.bmp` (small cross for turn indicator)
  - `osmall.bmp` (small circle for turn indicator)

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/tic-tac-toe.git
   ```
2. Ensure the `img/` folder with required BMP files is in the project directory.  
3. Open the project in Embarcadero C++ Builder.  
4. Build and run the application.

## How to Play
1. Launch the game; the circle ('O') starts.  
2. Click an empty square to place your symbol ('X' or 'O').  
3. The turn indicator shows whose turn is next.  
4. The game ends when a player aligns three symbols or the grid is full.  
5. Click the **Reset** button to start a new game.

## Files
- `Unit1.cpp`: Contains the main game logic and event handlers.  
- `Unit1.h`: Defines the form and component declarations.  
- `img/`: Directory containing BMP images for game visuals.

## Contributing
Contributions are welcome! To contribute:

1. Fork the repository.  
2. Create a new branch:  
   ```bash
   git checkout -b feature/your-feature
   ```
3. Make your changes and commit:  
   ```bash
   git commit -m "Add your feature"
   ```
4. Push to the branch:  
   ```bash
   git push origin feature/your-feature
   ```
5. Open a pull request.

Please ensure your code follows the existing style and includes comments.

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

## Author
**Adrian Lesniak**


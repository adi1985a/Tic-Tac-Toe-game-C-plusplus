# ❌⭕ Tic Tac Toe

Classic two-player game built with **C++** and **VCL**.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform: Windows](https://img.shields.io/badge/Platform-Windows-blue.svg)](https://www.embarcadero.com/products/cbuilder)
[![Language: C++](https://img.shields.io/badge/Language-C++-lightgrey.svg)](https://isocpp.org/)

---

## 📑 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Screenshots](#-screenshots)
- [Requirements](#-requirements)
- [Installation](#-installation)
- [How to Play](#-how-to-play)
- [Files](#-files)
- [Contributing](#-contributing)
- [License](#-license)
- [Author](#-author)

---

## 🧠 Overview

**Tic Tac Toe** is a classic two-player game implemented in **C++** using the **VCL framework**. Players take turns placing `'X'` or `'O'` on a 3×3 grid, trying to align three identical symbols in a row, column, or diagonal. The game features a polished graphical interface, visual turn indicators, and automatic win detection.

![Demo GIF](screenshots/1.gif)
---

## ✨ Features

- 🎨 **Graphical Interface**: Uses BMP images for `X`, `O`, and empty tiles.
- 🔄 **Turn Indicator**: Shows current player with a mini-icon.
- 🧠 **Win Detection**: Automatically checks for 8 possible winning conditions.
- ♻️ **Reset Function**: Easily restart the game with one click.

---

## 🖼️ Screenshots

<p align="center">
  <img src="screenshots\1.jpg" width="300"/>
  <img src="screenshots\2.jpg" width="300"/>
  <img src="screenshots\3.jpg" width="300"/>
</p>

---

## ⚙️ Requirements

- 💻 **Compiler**: C++ Compiler with **VCL** support (e.g. *Embarcadero C++ Builder*)
- 🖥️ **Platform**: Windows OS
- 🖼️ **Images** (place in `img/` directory):
  - `nic.bmp` – Empty field
  - `x.bmp` – X symbol
  - `o.bmp` – O symbol
  - `xsmall.bmp` – Small X for turn indicator
  - `osmall.bmp` – Small O for turn indicator

---

## ▶️ Installation

### 📥 Clone the repository:

```bash
git clone https://github.com/yourusername/tic-tac-toe.git
```

### 🗂️ Ensure image assets are in place:

Make sure the `img/` folder contains all required BMP files.

### 🛠️ Build the project:

- Open the `.cpp` project in **Embarcadero C++ Builder**.
- Compile and run the application.

---

## 🎮 How to Play

1. Launch the game. The circle (`O`) starts first.
2. Click on any empty square to place your symbol.
3. A small icon shows whose turn it is.
4. The game ends when:
   - A player aligns three symbols
   - The board is full (draw)
5. Click the **Reset** button to play again.

---

## 📁 Files

```
tic-tac-toe/
├── Unit1.cpp           # Main game logic and event handlers
├── Unit1.h             # Form and UI component declarations
├── img/                # BMP images (game visuals)
└── README.md           # Project documentation
```

---

## 🤝 Contributing

Contributions are welcome! Follow these steps to contribute:

```bash
# 1. Fork the repository
# 2. Create a feature branch
git checkout -b feature/your-feature

# 3. Make your changes and commit
git commit -m "Add your feature"

# 4. Push the branch
git push origin feature/your-feature

# 5. Open a pull request on GitHub
```

Please keep code style consistent and add comments where necessary.

---

## 📃 License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).  
See the `LICENSE` file for full legal text.

---

## 👤 Author

**Adrian Lesniak**  
C++ & GUI Developer

---

> 💡 A fun project to revisit the classics with a modern C++ VCL twist.




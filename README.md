# 🕹️ XO Game Variants Collection

Welcome to the **XO Game Variants** project — a C++ collection of different versions of the classic **Tic Tac Toe** game, implemented using object-oriented programming principles and interactive console interfaces.

## 🧠 Overview

This project includes three unique implementations of XO games, each with its own set of rules and board layout:

- 🔳 **5x5 XO**: A larger, more strategic 5x5 board version.
- 🟨 **Connect 4 XO**: Inspired by the classic Connect 4 game.
- 🔺 **Pyramid XO**: A uniquely shaped board laid out like a pyramid.

All games are built upon a reusable base class structure to demonstrate clean modular design, reusability, and encapsulation using C++.

---
## 🎮 Game Descriptions

### 1. 5x5 XO

- A 5x5 grid-based game.
- Players take turns placing **X** or **O**.
- Winner is determined by who has more completed sequences (rows, columns, diagonals of 3) at the end.
- Game ends after 24 moves (excluding one center cell).

### 2. Connect 4 XO

- A 6x7 grid similar to classic Connect 4.
- Players drop pieces into columns.
- The first to connect **4 consecutive pieces** (vertically, horizontally, or diagonally) wins.
- Total of 42 moves allowed before draw.

### 3. Pyramid XO

- A 3-layered pyramid-shaped board (non-rectangular).
- Players aim to align 3 symbols.
- Fewer valid positions; suitable for quicker matches.
- Game ends after 9 valid moves or when a player wins.

---

## 🛠️ Features

- Console-based game interaction.
- Supports multiple board shapes.
- Uses OOP: base class abstraction, method overriding.
- Code structured for easy future expansion.

---

## 🧩 Requirements

- C++ compiler (e.g., `g++`)
- A terminal/console to run the compiled executables

---

## 🚀 How to Run

1. **Clone the repo:**

```bash
git clone https://github.com/your-username/XO-Game-Variants.git
cd XO-Game-Variants


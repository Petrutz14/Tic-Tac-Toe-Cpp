# 🎮 Tic-Tac-Toe Variants Game | C++ Console Implementation

A comprehensive C++ implementation of various Tic-Tac-Toe game variants with a polished console interface.

## ✨ Features

### 🎯Game Modes
- ❌⭕️ **Classic X and O** - Standard Tic-Tac-Toe rules
- ⭕️❌ **O and X** - O player starts first  
- 🚫 **Anti X and O** - Lose by making 3 in a row  
- 🎲 **Random Turn Order** - Turn order randomized after each move  
- ➗ **Liniute** - Special variant using "/" symbols  
- ✖️ **X and X** - Both players use X symbols  

### 💻Technical Features
- 🖥️ Terminal-based UI with animations  
- 🎨 16-color text customization  
- 📊 Score tracking and file output  
- 🔄 Rematch functionality  

## 🛠️ Technical Specifications
- Language: C++17
- Dependencies: Windows.h, <bits/stdc++.h>
- Platform: Windows (due to Windows.h dependencies)
- File Output: rezultate.txt (match history)
## 💾 Code Structure
```
├── main.cpp            # Program entry point
├── functii.h           # Core game logic
│   ├── Board rendering
│   ├── Win conditions
│   ├── 6 game variants
│   └── File I/O
```
## 🕹️ Inputs
- **1-9**: Board positions (1=top-left, 9=bottom-right)
- **Menu #s**: Navigate interface options


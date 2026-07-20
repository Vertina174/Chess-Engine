# ♟️ Chess-Engine

A lightweight, and Minimilistic chess engine crafted in **C** using the **Raylib** graphics pipeline. Featuring modular state isolation, clean coordinate structures, and a performance-driven architecture.

---

## 🚀 Features


---

## 📁 Repository Map

```text
├── move.h              #
├── piece.h             #
├── board.h             # decleration of Game state models, piece definitions, and enums
├── renderer.h          # Functions Prototypes for renderer.cpp
├── main.cpp            # Window initialization, and main game loop
├── move.cpp            #
├── piece.cpp           #
├── renderer.cpp        # Native Raylib drawing implementations and grid rendering
├── assets/             # Game graphics (pieces.png, textures)
└── src/
    ├── include/        # Raylib development header dependencies
    └── lib/            # Target platform pre-compiled Raylib binaries (.lib / .a)

g++ main.cpp board.cpp renderer.cpp -Isrc/include -Lsrc/lib -lraylib -o ChessEngine
./ChessEngine
# ♟️ Chess-Engine

A sleek, lightweight, and modern minimal chess engine crafted in **C++** using the **Raylib** graphics pipeline. Featuring modular state isolation, clean coordinate structures, and a performance-driven architecture.

---

## 🚀 Features

* **Pixel-Perfect Rendering:** Beautiful, clean 2D graphics modeled after modern chess UI layouts.
* **Fully Object-Oriented:** Zero spaghetti globals—game states, renderers, and calculations are kept safely isolated.
* **Dynamic Matrix Flipping:** Translates computer-graphic screen space coordinates smoothly into true Chess Ranks ($0$ representing Rank 1 up to $7$ representing Rank 8).
* **Optimized Resource Management:** Leverages explicit RAII-compliant constructors and destructors to completely prevent GPU memory leaks during asset management.

---

## 📁 Repository Map

```text
├── main.cpp            # The turn cycle, window initialization, and main game loop
├── board.h             # Game state models, piece definitions, and enums
├── board.cpp           # Game initialization logic and rule matrices
├── renderer.h          # Visual pipeline blueprints and texture hooks
├── renderer.cpp        # Native Raylib drawing implementations and grid rendering
├── assets/             # Game graphics (pieces.png, textures, and sprites)
└── src/
    ├── include/        # Raylib development header dependencies
    └── lib/            # Target platform pre-compiled Raylib binaries (.lib / .a)

    Build via Command Line (GCC/MinGW Example)
    
g++ main.cpp board.cpp renderer.cpp -Isrc/include -Lsrc/lib -lraylib -o ChessEngine
./ChessEngine
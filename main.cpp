// g++ main.cpp board.cpp renderer.cpp -o a -I "src/include" -L "src/lib" -lraylib -lopengl32 -lgdi32 -lwinmm -lshell32 && ./a
#include"renderer.h"
#include"board.h"
#include"src/include/raylib.h"
#include<iostream>
#define width 800
#define height 700
using namespace std;
const Color GREY = {48,46,43,255};
int main(){
InitWindow(width,height,"asdfadsf");
SetTargetFPS(15);
system("cls");
Board board;
while(!WindowShouldClose()){
BeginDrawing();
DrawFPS(3,3);
ClearBackground(GREY);
board.draw();

EndDrawing();
}
}
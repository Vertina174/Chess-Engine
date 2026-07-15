// g++ main.cpp renderer.cpp piece.cpp move.cpp -o a -I "src/include" -L "src/lib" -lraylib -lopengl32 -lgdi32 -lwinmm -lshell32 && ./a
#include"src/include/raylib.h"
#include<iostream>
#include"board.h"
#include"renderer.h"
#include"piece.h"
using namespace std;
int main(){
InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT,"Chess Engine");
SetTargetFPS(15);
Board board;
Load_Texture();
system("cls");
while(!WindowShouldClose()){
    system("cls");
BeginDrawing();
DrawFPS(3,3);
ClearBackground(BLACK);
draw(board);
int x = GetMouseX()-OFFSET_x;
int y = GetMouseY()-OFFSET_y;
if(x>0 && x<BOARD_SIZE){
    if(y>0 && y<BOARD_SIZE){
        cout<<"\nInside Board\n";
        cout<<"Row: "<<(y)/SQUARE_SIZE;
        cout<<" Column: "<<(x)/SQUARE_SIZE;
        updatepositions(board);
    }
}
EndDrawing();
}
Unload_Texture();
system("cls");
}
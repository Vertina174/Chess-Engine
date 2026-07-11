// g++ main.cpp board.cpp renderer.cpp piece.cpp -o a -I "src/include" -L "src/lib" -lraylib -lopengl32 -lgdi32 -lwinmm -lshell32 && ./a
#include"renderer.h"
#include"board.h"
#include"src/include/raylib.h"// cross platform
#include<iostream>
#define width 800
#define height 700
using namespace std;
const Color GREY = {48,46,43,255};

int main(){
InitWindow(width,height,"asdfadsf");
SetTargetFPS(10);
system("cls");
Board board;
Load_Texture();
while(!WindowShouldClose()){
system("cls");    
BeginDrawing();
DrawFPS(3,3);
ClearBackground(GREY);

// Inside Board
int x = GetMouseX();
int y = GetMouseY();
Draw(board);
    if(x>board.offsetX && x<board.screen_width - board.offsetX){
        if(y>board.offsetY && y< board.screen_height - board.offsetY){
            cout<<"Inside Board\n";
            int col = ((GetMouseX())/board.squaresize);
            int row = ((GetMouseY()+ board.offsetY)/board.squaresize);
            cout<<"\nRow: "<<row<<",Column: "<<col;

            if(board.pieceinfo.selected_piece==0)
                select_a_piece(board);
            else
                move_selected_piece(board);
            
        show_selected_piece(board);
        }
    }
EndDrawing();
    }
Unload_Texture();
}
#include"src/include/raylib.h"
#include"board.h"

void Board::draw(){
    const int squaresize= 80;
    const int boardsize=  80*8;
    const int width = 800;
    const int height = 700;
    const int offsetX =(width -(boardsize))/2;
    const int offsetY =(height -(boardsize))/2;
    
// Drawing Empty Board
    for(int row=0; row<8; ++row){
        for(int col=0; col<8; ++col){
            Color color;
            if((row+col)%2==0)
                color = {238,238,210,255};
            else
                color={118,150,86,255};

        int x = offsetX + (col*squaresize);
        int y = offsetY + (row*squaresize);
    DrawRectangle(x,y,squaresize,squaresize,color);

        }
    }
}
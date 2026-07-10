#include"renderer.h"
#include"board.h"
#include"src/include/raylib.h"
#include<iostream>

    Texture2D wpawn, wknight, wbishop, wrook, wqueen, wking;
    Texture2D bpawn, bknight, bbishop, brook, bqueen, bking;
    
Board::Board(){
    Image whitepawn = LoadImage("assets/wpawn.png");
    Image whiterook = LoadImage("assets/wrook.png");
    Image whiteknight = LoadImage("assets/wknight.png");
    Image whitebishop = LoadImage("assets/wbishop.png");
    Image whitequeen = LoadImage("assets/wqueen.png");
    Image whiteking = LoadImage("assets/wking.png");

    Image blackpawn = LoadImage("assets/bpawn.png");
    Image blackrook = LoadImage("assets/brook.png");
    Image blackknight = LoadImage("assets/bknight.png");
    Image blackbishop = LoadImage("assets/bbishop.png");
    Image blackqueen = LoadImage("assets/bqueen.png");
    Image blackking = LoadImage("assets/bking.png");

    ImageResize(&whitepawn,  90,90);
    ImageResize(&whiteknight,75,75);
    ImageResize(&whitebishop,75,75);
    ImageResize(&whiterook,  75,75);
    ImageResize(&whiteking,  75,75);
    ImageResize(&whitequeen, 75,75);

    ImageResize(&blackpawn,  90,90);
    ImageResize(&blackknight,75,75);
    ImageResize(&blackbishop,75,75);
    ImageResize(&blackrook,  75,75);
    ImageResize(&blackking,  75,75);
    ImageResize(&blackqueen, 75,75);

    
    wpawn   = LoadTextureFromImage(whitepawn);
    wknight = LoadTextureFromImage(whiteknight);
    wbishop = LoadTextureFromImage(whitebishop);
    wking   = LoadTextureFromImage(whiteking);
    wqueen  = LoadTextureFromImage(whitequeen);
    wrook   = LoadTextureFromImage(whiterook);

    bpawn   = LoadTextureFromImage(blackpawn);
    bking   = LoadTextureFromImage(blackking);
    bqueen  = LoadTextureFromImage(blackqueen);
    bknight = LoadTextureFromImage(blackknight);
    bbishop = LoadTextureFromImage(blackbishop);
    brook   = LoadTextureFromImage(blackrook);

    UnloadImage(whitepawn);
    UnloadImage(whitequeen);
    UnloadImage(whiteking);
    UnloadImage(whiterook);
    UnloadImage(whitebishop);
    UnloadImage(whiteknight);

    UnloadImage(blackrook);
    UnloadImage(blackbishop);
    UnloadImage(blackking);
    UnloadImage(blackpawn);
    UnloadImage(blackqueen);
    UnloadImage(blackknight);
    
system("cls");
}
Board::~Board(){
        UnloadTexture(wpawn);
        UnloadTexture(wrook);
        UnloadTexture(wking);
        UnloadTexture(wknight);
        UnloadTexture(wqueen);
        UnloadTexture(wbishop);

        UnloadTexture(bpawn);
        UnloadTexture(bqueen);
        UnloadTexture(bking);
        UnloadTexture(brook);
        UnloadTexture(bbishop);
        UnloadTexture(bknight);
system("cls");
    }

void Board::draw(){
    const int squaresize  = 80;
    const int boardsize  =  80*8;
    const int width     = 800;
    const int height    = 700;
    const int offsetX   =(width -(boardsize))/2;
    const int offsetY   =(height -(boardsize))/2;
    
// Drawing Empty Board
    for(int row=0; row<8; ++row){
        for(int col=0; col<8; ++col){
            Color color;
            if((row+col)%2==0)
                color = {238,238,210,255};
            else
                color = {118,150,86,255};

        int x = offsetX + (col*squaresize);
        int y = offsetY + (row*squaresize);
        DrawRectangle(x,y,squaresize,squaresize,color);

        }
    }
// Drawing Pieces
    //Drawing Pawn
 
    
for(int row=0; row<8; ++row){
    for(int col=0; col<8; ++col){

        switch(board[row][col]){
        case WPAWN:{
            int x = offsetX + (col*squaresize);
            int y = offsetY + (row*squaresize);

            DrawTexture(wpawn,x-5,y-3
                ,WHITE);
            break;
        }
        case WROOK:{
            int x = offsetX + (col*squaresize);
            int y = offsetY + (row*squaresize);

            DrawTexture(wrook,x+3,y+5,WHITE);
            break;
        }
        case WKNIGHT:{
            int x = offsetX + (col*squaresize);
            int y = offsetY + (row*squaresize);

            DrawTexture(wknight,x+3,y+5,WHITE);
            break;
        }
        case WBISHOP:{
            int x = offsetX + (col*squaresize);
            int y = offsetY + (row*squaresize);

            DrawTexture(wbishop,x+3,y+5,WHITE);
            break;
        }
        case WQUEEN:{
            int x = offsetX + (col*squaresize);
            int y = offsetY + (row*squaresize);

            DrawTexture(wqueen,x+3,y+5,WHITE);
            break;
        }
        case WKING:{
            int x = offsetX + (col*squaresize);
            int y = offsetY + (row*squaresize);

            DrawTexture(wking,x+3,y+5,WHITE);
            break;
        }
        case BPAWN:{
            int x = offsetX + (col*squaresize);
            int y = offsetY + (row*squaresize);

            DrawTexture(bpawn,x-5,y-3,WHITE);
            break;
        }
        case BROOK:{
            int x = offsetX + (col*squaresize);
            int y = offsetY + (row*squaresize);

            DrawTexture(brook,x+3,y+5,WHITE);
            break;
        }
        case BKNIGHT:{
int x = offsetX + (col*squaresize);
            int y = offsetY + (row*squaresize);

            DrawTexture(bknight,x+3,y+5,WHITE);
            break;
        }
        case BBISHOP:{
            int x = offsetX + (col*squaresize);
            int y = offsetY + (row*squaresize);

            DrawTexture(bbishop,x+3,y+5,WHITE);
            break;
        }
        case BQUEEN:{
            int x = offsetX + (col*squaresize);
            int y = offsetY + (row*squaresize);

            DrawTexture(bqueen,x+3,y+5,WHITE);
            break;
        }
        case BKING:{
            int x = offsetX + (col*squaresize);
            int y = offsetY + (row*squaresize);

            DrawTexture(bking,x+3,y+5,WHITE);
            break;
        }
        }
        
}
}
}
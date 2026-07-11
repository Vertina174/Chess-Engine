#include"renderer.h"
#include"board.h"
#include"piece.h"
#include"src/include/raylib.h"
#include<iostream>
// For Refrerrence
// int y = board.offsetY + (row*board.squaresize);
// int x = board.offsetX + (col*board.squaresize);
Color highlight_color = {128,128,128,130};
Color legal_move = {0,0,0,125};


    Texture2D wpawn, wknight, wbishop, wrook, wqueen, wking;
    Texture2D bpawn, bknight, bbishop, brook, bqueen, bking;
    
void Load_Texture(){
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
void Unload_Texture(){
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

void draw_board(Board& board){
    
    
// Drawing Empty Board
    for(int row=0; row<8; ++row){
        for(int col=0; col<8; ++col){
            Color color;
            if((row+col)%2==0)
                color = {238,238,210,255};
            else
                color = {118,150,86,255};

        int x = board.offsetX + (col*board.squaresize);
        int y = board.offsetY + (row*board.squaresize);
        DrawRectangle(x,y,board.squaresize,board.squaresize,color);

        }
    }
}
// Drawing Pieces
void draw_pieces(Board& board){
for(int row=0; row<8; ++row){
    for(int col=0; col<8; ++col){

            int x = board.offsetX + (col*board.squaresize);
            int y = board.offsetY + (row*board.squaresize);

        switch(board.board[row][col]){
        case WPAWN:{
            DrawTexture(wpawn,x-5,y-7,WHITE);
            break;
        }
        case WROOK:{
            DrawTexture(wrook,x+3,y+5,WHITE);
            break;
        }
        case WKNIGHT:{
            DrawTexture(wknight,x+3,y+5,WHITE);
            break;
        }
        case WBISHOP:{
            DrawTexture(wbishop,x+3,y+5,WHITE);
            break;
        }
        case WQUEEN:{
            DrawTexture(wqueen,x+3,y+5,WHITE);
            break;
        }
        case WKING:{
            DrawTexture(wking,x+3,y+5,WHITE);
            break;
        }
        case BPAWN:{
            DrawTexture(bpawn,x-5,y-7,WHITE);
            break;
        }
        case BROOK:{
            DrawTexture(brook,x+3,y+5,WHITE);
            break;
        }
        case BKNIGHT:{
            DrawTexture(bknight,x+3,y+5,WHITE);
            break;
        }
        case BBISHOP:{
            DrawTexture(bbishop,x+3,y+5,WHITE);
            break;
        }
        case BQUEEN:{
            DrawTexture(bqueen,x+3,y+5,WHITE);
            break;
        }
        case BKING:{
            DrawTexture(bking,x+3,y+5,WHITE);
            break;
                }
            }
        
        }
    }
}
void highlighted_piece(Board& board){
    if(board.pieceinfo.selected_piece==0)
        return;

        int y = (board.pieceinfo.row *board.squaresize);
        int x = (board.pieceinfo.col *board.squaresize);
        DrawRectangle(x,y-50,board.squaresize,board.squaresize,highlight_color);
        DrawCircle(x+40,y-90,10,legal_move);
        DrawCircle(x+40,y-(85*2),10,legal_move);
}
void Draw(Board& board){
    draw_board(board);
    draw_pieces(board);
    if(board.pieceinfo.selected_piece!=0)
            highlighted_piece(board);
}
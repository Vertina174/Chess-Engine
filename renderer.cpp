/*Screen Coordinates using getmouse
int x = OFFSET_x + board.pieceinfo.col * SQUARE_SIZE;
int y = OFFSET_y + board.pieceinfo.row * SQUARE_SIZE;
*/
#include"src/include/raylib.h"
#include"board.h"
#include"renderer.h"
    Texture2D piecetexture[12];
    Color YELLOWISH ={255,215,0,100};
    
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

    ImageResize(&whitepawn,  75,75);
    ImageResize(&whiteknight,75,75);
    ImageResize(&whitebishop,75,75);
    ImageResize(&whiterook,  75,75);
    ImageResize(&whiteking,  75,75);
    ImageResize(&whitequeen, 75,75);

    ImageResize(&blackpawn,  75,75);
    ImageResize(&blackknight,75,75);
    ImageResize(&blackbishop,75,75);
    ImageResize(&blackrook,  75,75);
    ImageResize(&blackking,  75,75);
    ImageResize(&blackqueen, 75,75);

    piecetexture[WPAWN]   = LoadTextureFromImage(whitepawn);
    piecetexture[WKNIGHT] = LoadTextureFromImage(whiteknight);
    piecetexture[WBISHOP] = LoadTextureFromImage(whitebishop);
    piecetexture[WROOK]   = LoadTextureFromImage(whiterook);
    piecetexture[WQUEEN]  = LoadTextureFromImage(whitequeen);
    piecetexture[WKING]   = LoadTextureFromImage(whiteking);
    

    piecetexture[BPAWN]   = LoadTextureFromImage(blackpawn);
    piecetexture[BKNIGHT] = LoadTextureFromImage(blackknight);
    piecetexture[BBISHOP] = LoadTextureFromImage(blackbishop);
    piecetexture[BROOK]   = LoadTextureFromImage(blackrook);
    piecetexture[BQUEEN]  = LoadTextureFromImage(blackqueen);
    piecetexture[BKING]   = LoadTextureFromImage(blackking);

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
    

}

void Unload_Texture(){
for(int i=0; i<12; i++){
    UnloadTexture(piecetexture[i]);
}
    }
    
void drawboard(Board& board){
    Color color;
        
for(int row=0; row<8; row++){
    for(int col=0; col<8; col++){
        if((row+col)%2==0)
            color={238,238,210,255};
        else
            color={118,150,86,255};
        DrawRectangle(OFFSET_x+(col)*SQUARE_SIZE,OFFSET_y+(row)*SQUARE_SIZE,SQUARE_SIZE,SQUARE_SIZE,color);
    }
}
}

void drawpiece(Board& board){
for(int row=0; row<8; row++){
    for(int col=0; col<8; col++){
        Piece currentpiece = board.board[row][col];
        if(currentpiece==EMPTY) continue;

int left = OFFSET_x + (col*SQUARE_SIZE);
int top  = OFFSET_y + (row*SQUARE_SIZE);

DrawTexture(piecetexture[currentpiece],left,top,WHITE);
    }
}
}

void highlight_selected_piece(Board& board){

int x = OFFSET_x + board.pieceinfo.col * SQUARE_SIZE;
int y = OFFSET_y + board.pieceinfo.row * SQUARE_SIZE;
DrawRectangle(x,y,SQUARE_SIZE,SQUARE_SIZE,YELLOWISH);
}

void draw(Board& board){
drawboard(board);
highlight_selected_piece(board);
drawpiece(board);
    }
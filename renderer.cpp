/*Screen Coordinates using getmouse
int x = OFFSET_x + board.pieceinfo.col * SQUARE_SIZE;
int y = OFFSET_y + board.pieceinfo.row * SQUARE_SIZE;
*/
#include"src/include/raylib.h"
#include"board.h"
#include"renderer.h"
#include"piece.h"
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

    piecetexture[WPAWN  ]  = LoadTextureFromImage(whitepawn);
    piecetexture[WKNIGHT]  = LoadTextureFromImage(whiteknight);
    piecetexture[WBISHOP]  = LoadTextureFromImage(whitebishop);
    piecetexture[WROOK  ]  = LoadTextureFromImage(whiterook);
    piecetexture[WQUEEN ]  = LoadTextureFromImage(whitequeen);
    piecetexture[WKING  ]  = LoadTextureFromImage(whiteking);
    

    piecetexture[BPAWN  ] = LoadTextureFromImage(blackpawn);
    piecetexture[BKNIGHT] = LoadTextureFromImage(blackknight);
    piecetexture[BBISHOP] = LoadTextureFromImage(blackbishop);
    piecetexture[BROOK  ] = LoadTextureFromImage(blackrook);
    piecetexture[BQUEEN ] = LoadTextureFromImage(blackqueen);
    piecetexture[BKING  ] = LoadTextureFromImage(blackking);

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

void highlight_rook(Board& board){
    int startrow=board.pieceinfo.row;
    int startcol=board.pieceinfo.col;
  int Direction[4][2] = {   {-1,0}, {1,0}, {0,-1}, {0,1}   };
        for(int i=0; i<4; i++){
           int r=startrow;
           int c=startcol;
        while(true){
            r += Direction[i][0];
            c += Direction[i][1];
        if(r>=0 && r<8 && c>=0 && c<8){
        Piece p = board.board[r][c];
        if(p==EMPTY)
            DrawCircle(
                OFFSET_x+c*SQUARE_SIZE+SQUARE_SIZE/2,
                OFFSET_y+r*SQUARE_SIZE+SQUARE_SIZE/2,
                15,GRAY);
        
        else if(getPieceColor(p)!=getPieceColor(board.pieceinfo.selected_piece))
                DrawRectangleLines(
                    OFFSET_x+c*SQUARE_SIZE,
                    OFFSET_y+r*SQUARE_SIZE,
                    SQUARE_SIZE,
                    SQUARE_SIZE,
                    RED);
        }
        else
            break;
    }
}
}

void highlight_bishop(Board& board){
    int startrow=board.pieceinfo.row;
    int startcol=board.pieceinfo.col;
    int Direction[4][2]={   {-1,-1}, {-1,1}, {1,-1}, {1,1}  };
    for(int i=0; i<4; i++){
        int r=startrow;
        int c=startcol;
        while(true){
            r+=Direction[i][0];
            c+=Direction[i][1];
        if(r>=0 && r<8 && c>=0 && c<8){
        Piece p = board.board[r][c];
        if(p==EMPTY)
            DrawCircle(
                OFFSET_x+c*SQUARE_SIZE+SQUARE_SIZE/2,
                OFFSET_y+r*SQUARE_SIZE+SQUARE_SIZE/2,
                15,GRAY);
        
        else if(getPieceColor(p)!=getPieceColor(board.pieceinfo.selected_piece))
                DrawRectangleLines(
                    OFFSET_x+c*SQUARE_SIZE,
                    OFFSET_y+r*SQUARE_SIZE,
                    SQUARE_SIZE,
                    SQUARE_SIZE,
                    RED);
        }
        else
            break;
    }
    }
    
}

void highlight_selected_piece(Board& board){
int startrow = board.pieceinfo.row;
int startcol = board.pieceinfo.col;
int x = OFFSET_x + board.pieceinfo.col * SQUARE_SIZE;
int y = OFFSET_y + board.pieceinfo.row * SQUARE_SIZE;
DrawRectangle(x,y,SQUARE_SIZE,SQUARE_SIZE,YELLOWISH);
switch(board.pieceinfo.selected_piece){
    case WPAWN:
    case BPAWN:{
        int direction = (board.pieceinfo.selected_piece==WPAWN)?-1:1;
        
        break;
    }
    case BKNIGHT:
    case WKNIGHT:{
        int knightmoves[8][2]={
{-2,-1}, {-2,1}, {-1,-2}, {-1, 2},
{1,-2},  {1,2} , {2,-1} , {2 , 1}
};
for(int i=0; i<8; i++){
    int r = startrow + knightmoves[i][0];
    int c = startcol + knightmoves[i][1];
    if(r>=0 && r<8 && c>=0 && c<8){
        Piece p = board.board[r][c];
        if(p==EMPTY)
            DrawCircle(
                OFFSET_x+c*SQUARE_SIZE+SQUARE_SIZE/2,
                OFFSET_y+r*SQUARE_SIZE+SQUARE_SIZE/2,
                15,GRAY);
        
        else if(getPieceColor(p)!=getPieceColor(board.pieceinfo.selected_piece))
                DrawRectangleLines(
                    OFFSET_x+c*SQUARE_SIZE,
                    OFFSET_y+r*SQUARE_SIZE,
                    SQUARE_SIZE,
                    SQUARE_SIZE,
                    RED);
    }
}
        break;

    }
    case BBISHOP:
    case WBISHOP:{
        highlight_bishop(board);
        break;
    }
    case BROOK:
    case WROOK:{
      highlight_rook(board);
        break;
    }
    case BQUEEN:
    case WQUEEN:{
        highlight_bishop(board);
        highlight_rook(board);
        break;
    }
    case WKING:
    case BKING:{
        for(int drow=-1; drow<=1; drow++){
        for(int dcol=-1; dcol<=1; dcol++){
            if(drow==0 && dcol==0)
                continue;
                int r = startrow+drow;
                int c = startcol+dcol;
            if(r>=0 && r<8 && c>=0 && c<8){
        Piece p = board.board[r][c];
        if(p==EMPTY)
            DrawCircle(
                OFFSET_x+c*SQUARE_SIZE+SQUARE_SIZE/2,
                OFFSET_y+r*SQUARE_SIZE+SQUARE_SIZE/2,
                15,GRAY);
        
        else if(getPieceColor(p)!=getPieceColor(board.pieceinfo.selected_piece))
                DrawRectangleLines(
                    OFFSET_x+c*SQUARE_SIZE,
                    OFFSET_y+r*SQUARE_SIZE,
                    SQUARE_SIZE,
                    SQUARE_SIZE,
                    RED);
            }
        }
}
        break;
    }
}
}

void draw_promotion_window(Board& board){

    int x=OFFSET_x + 1*SQUARE_SIZE;
    int y=OFFSET_y + 3.5*SQUARE_SIZE;    
    DrawRectangle(x,y,6*SQUARE_SIZE, 2*SQUARE_SIZE,GRAY);
    DrawRectangleLines(x,y,6*SQUARE_SIZE,2*SQUARE_SIZE,GOLD);

    int startpiece = (board.pawnpromotion.PromotionColor==color_white)?WKNIGHT:BKNIGHT;

int itemy=y+SQUARE_SIZE/2;
for(int i=0; i<4; i++){
    int itemx=x+((i+1)*SQUARE_SIZE);
    DrawRectangle(itemx+3,itemy,75,75,YELLOWISH);
    DrawTexture(piecetexture[startpiece+i],itemx,itemy,WHITE);
    }
}

void draw(Board& board){
drawboard(board);
highlight_selected_piece(board);
drawpiece(board);
if(board.pawnpromotion.PromotionState)
    draw_promotion_window(board);
    }
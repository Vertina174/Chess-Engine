
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 700
#define SQUARE_SIZE   80
#define BOARD_SIZE    80*8
#define OFFSET_x      (SCREEN_WIDTH-BOARD_SIZE)/2
#define OFFSET_y      (SCREEN_HEIGHT -BOARD_SIZE)/2
#pragma once
enum Piece{
    EMPTY=0,

    WPAWN,
    WBISHOP,
    WKNIGHT,
    WROOK,
    WQUEEN,
    WKING,

    BPAWN,
    BBISHOP,
    BKNIGHT,
    BROOK,
    BQUEEN,
    BKING,
};
struct PieceInfo{
    int row=-1;
    int col=-1;
    Piece selected_piece=EMPTY;
};
class Board{
    public:
    PieceInfo pieceinfo;
    Piece board[8][8]{
        
        {BROOK,BKNIGHT,BBISHOP,BQUEEN,BKING,BBISHOP,BKNIGHT,BROOK},
        {BPAWN,BPAWN,BPAWN,BPAWN,BPAWN,BPAWN,BPAWN,BPAWN},
        {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
        {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
        {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
        {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
        {WPAWN,WPAWN,WPAWN,WPAWN,WPAWN,WPAWN,WPAWN,WPAWN},
        {WROOK,WKNIGHT,WBISHOP,WQUEEN,WKING,WBISHOP,WKNIGHT,WROOK}
    };
    
    
};
void select_a_piece(Board& board);
void show_selected_piece(Board& board);
void move_selected_piece(Board& board);
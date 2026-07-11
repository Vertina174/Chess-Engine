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
    const int squaresize    = 80;
    const int boardsize     = 80*8;
    const int screen_width  = 800;
    const int screen_height = 700;
    const int offsetX       =(screen_width-(boardsize))/2;
    const int offsetY       =(screen_height -(boardsize))/2;
    
};
void select_a_piece(Board& board);
void show_selected_piece(Board& board);
void move_selected_piece(Board& board);
#pragma once
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 700
#define SQUARE_SIZE   80
#define BOARD_SIZE    80*8
#define OFFSET_x      (SCREEN_WIDTH-BOARD_SIZE)/2
#define OFFSET_y      (SCREEN_HEIGHT -BOARD_SIZE)/2

enum Piece{
    EMPTY  =0,

    WPAWN  ,
    WBISHOP,
    WKNIGHT,
    WROOK  ,
    WQUEEN ,
    WKING  ,
    BPAWN  ,
    BBISHOP,
    BKNIGHT,
    BROOK  ,
    BQUEEN ,
    BKING  ,
};
enum PieceColor {color_none, color_white,color_black};
struct PieceInfo{
    int row=-1;
    int col=-1;
    Piece selected_piece=EMPTY;
    int en_passant_col=-1;

};
struct CASTLING{
    bool whiteKingSide = true;
    bool whiteQueenSide = true;
    bool blackKingSide = true;
    bool blackQueenSide = true;
};
class Board{
    public:
    PieceInfo pieceinfo;
    CASTLING castling;
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
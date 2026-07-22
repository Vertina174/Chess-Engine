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
    WKNIGHT,
    WBISHOP,
    WROOK  ,
    WQUEEN ,
    WKING  ,

    BPAWN  ,
    BKNIGHT,
    BBISHOP,
    BROOK  ,
    BQUEEN ,
    BKING  ,
};

enum PieceColor {color_none, color_white,color_black};

struct PieceInfo{
    int row=-1;
    int col=-1;
    PieceColor color=color_none;
    Piece selected_piece=EMPTY;
};

struct PawnPromotion{
    bool PromotionState=false;
    int  row=-1;
    int  col=-1;
    PieceColor PromotionColor=color_none;
};

struct Castling{
    bool whiteKingSide  = true;
    bool whiteQueenSide = true;
    bool blackKingSide  = true;
    bool blackQueenSide = true;
};

struct EnPassant{
    bool double_step_pawn=false;
    bool was_en_passant  = false;
    int row = -1;
    int col = -1;
};

struct SquareInAttack{
int row=-1;
int col=-1;
PieceColor opposite_color=color_none;
bool attacked=false;
};

class Board{
    public:
    PieceInfo pieceinfo;
    Castling  castling;
    EnPassant enpassant;
    PawnPromotion pawnpromotion;
    SquareInAttack square_attacked;
    Piece board[8][8]{
        
        {BROOK,BKNIGHT,BBISHOP,BQUEEN,BKING,BBISHOP,BKNIGHT,BROOK},
        // {BPAWN,BPAWN,BPAWN,BPAWN,BPAWN,BPAWN,BPAWN,BPAWN},
        {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
        {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
        {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
        {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
        {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
        {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
        // {WPAWN,WPAWN,WPAWN,WPAWN,WPAWN,WPAWN,WPAWN,WPAWN},
        {WROOK,WKNIGHT,WBISHOP,WQUEEN,WKING,WBISHOP,WKNIGHT,WROOK}
    };
    
};
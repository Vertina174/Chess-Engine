#include"move.h"
#include"piece.h"
int absolute(int n){
    if(n<0)
        return n*-1;
    return n;
}
bool isPawnLegal(Board& board, int row, int col){
    int startrow=board.pieceinfo.row;
    int startcol=board.pieceinfo.col;
    Piece selected_piece = board.pieceinfo.selected_piece;

    int direction =(selected_piece==WPAWN)?-1:1;
    int startingrow=(selected_piece==WPAWN)?6:1;

    int drow = row-startrow;
    int dcol = col-startcol;

// Forward one Square
    if(dcol==0 && drow==direction)
        return (board.board[row][col]==EMPTY);
// Forward two square

    if(dcol==0 && drow==2*direction){
        if(startrow==startingrow)
            return (board.board[startrow+direction][startcol]==EMPTY && board.board[row][col]==EMPTY);
        return false;
    }
// Caputer emeny Digonally
    if(drow==direction && absolute(dcol)==1  && board.board[row][col]!=EMPTY)
        return (isEnemy(board.board[startrow][startcol],board.board[row][col]));

int vaild_en_passant_row=(selected_piece==WPAWN)?2:5;
if (row == vaild_en_passant_row && col == board.pieceinfo.en_passant_col) {
    // Is the target column the same column as the pawn that just double-stepped?
    if (drow == direction && absolute(dcol)==1) {
        return true; // Yes! This diagonal move into an empty square is legal.
    }
}
    return false;
}

bool isKnightLegal(Board& board, int row, int col){
    int startrow=board.pieceinfo.row;
    int startcol=board.pieceinfo.col;
    Piece selected_piece = board.pieceinfo.selected_piece;
    int drow = row-startrow;
    int dcol = col-startcol;
// Up and Down
    if((drow==2 || drow==-2) &&  (dcol==1 || dcol==-1))
        return true;

// Left and Right
    if((dcol==2 || dcol==-2) &&  (drow==1 || drow==-1))
        return true;

return false;
}

bool isBishopLegal(Board& board, int row, int col){
    int startrow=board.pieceinfo.row;
    int startcol=board.pieceinfo.col;
    Piece selected_piece = board.pieceinfo.selected_piece;
    int drow = row-startrow;
    int dcol = col-startcol;  

    if(absolute(drow)!=absolute(dcol))
        return false;
    int steprow=(drow>0)?1:-1;
    int stepcol=(dcol>0)?1:-1;
    int r=startrow+steprow;
    int c=startcol+stepcol;
    while(r!=row && c!=col){
        if(board.board[r][c]!=EMPTY)
            return false;
        r+=steprow;
        c+=stepcol;
    }
return true;
}

bool isRookLegal  (Board& board, int row, int col){
    int startrow=board.pieceinfo.row;
    int startcol=board.pieceinfo.col;
    
    Piece selected_piece = board.pieceinfo.selected_piece;
    int drow = row-startrow;
    int dcol = col-startcol; 
     
    if(drow!=0 && dcol!=0)    
        return false;
    int steprow=0;
    int stepcol=0;
    if(drow!=0)
        steprow=(drow>0)?1:-1;
    else
        stepcol=(dcol>0)?1:-1;
    int r=startrow+steprow;
    int c=startcol+stepcol;
    while(r!=row && c!=col){
        if(board.board[r][c]!=EMPTY)
            return false;
        r+=steprow;
        c+=stepcol;
    }
return true; 
}
bool isKingLegal(Board& board, int row, int col){
    int startrow = board.pieceinfo.row;
    int startcol = board.pieceinfo.col;
    
    int drow = row - startrow;
    int dcol = col - startcol;

    // Use absolute differences (reusing your absolute function or std::abs)
    // The King can move at most 1 square in any direction
    if (absolute(drow) <= 1 && absolute(dcol) <= 1) {
        return true;
    }

    return false;
}
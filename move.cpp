#include"move.h"
#include"piece.h"
#include<iostream>
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
    if(dcol==0 && drow==direction){
        if(selected_piece==WPAWN && row==0 && board.board[row][col]==EMPTY){
            board.pawnpromotion.PromotionState=true;
            board.pawnpromotion.PromotionColor=color_white;
            board.pawnpromotion.row=row;
            board.pawnpromotion.col=col;
            board.board[startrow][startcol]=EMPTY;
            return false;
        }
        else if(selected_piece==BPAWN && row==7 && board.board[row][col]==EMPTY){
            board.pawnpromotion.PromotionState=true;
            board.pawnpromotion.PromotionColor=color_black;
            board.pawnpromotion.row=row;
            board.pawnpromotion.col=col;
            board.board[startrow][startcol]=EMPTY;
            return false;
        }
        return (board.board[row][col]==EMPTY);
}
// Forward two square
    if(dcol==0 && drow==2*direction){
        if(startrow==startingrow)
            return (board.board[startrow+direction][startcol]==EMPTY && board.board[row][col]==EMPTY);
        return false;
    }

// Caputer emeny Digonally
    if(drow==direction && absolute(dcol)==1  && board.board[row][col]!=EMPTY){
        if(selected_piece==WPAWN && row==0 && board.board[row][col]==EMPTY){
            board.pawnpromotion.PromotionState=true;
            board.pawnpromotion.PromotionColor=color_white;
            board.pawnpromotion.row=row;
            board.pawnpromotion.col=col;
            board.board[startrow][startcol]=EMPTY;
            return false;
        }
        else if(selected_piece==BPAWN && row==7 && board.board[row][col]==EMPTY){
            board.pawnpromotion.PromotionState=true;
            board.pawnpromotion.PromotionColor=color_black;
            board.pawnpromotion.row=row;
            board.pawnpromotion.col=col;
            board.board[startrow][startcol]=EMPTY;
            return false;
        }
        return (isEnemy(board.board[startrow][startcol],board.board[row][col]));}

// En Passant 
if (row == board.enpassant.row && col == board.enpassant.col) {
    // Is the target column the same column as the pawn that just double-stepped?
    if (drow == direction && absolute(dcol)==1) {
        clearEnPassant(board);
        return true; // Yes! This diagonal move into an empty square is legal.
    }
}
    clearEnPassant(board);
    return false;
}

bool isKnightLegal(Board& board, int row, int col){
    int startrow=board.pieceinfo.row;
    int startcol=board.pieceinfo.col;
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
    while(r!=row || c!=col){
        if(board.board[r][c]!=EMPTY)
            return false;
        r+=steprow;
        c+=stepcol;
    }
    if(startrow==0){
        if(startcol==0)
            board.castling.blackQueenSide=false;
        else if(startcol==7)
            board.castling.blackKingSide=false;
    }
    else if(startrow==7){
        if(startcol==0)
            board.castling.whiteQueenSide=false;
        else if(startcol==7)
            board.castling.whiteKingSide=false;
    }
return true;
}
bool isKingLegal(Board& board, int row, int col){
    int startrow = board.pieceinfo.row;
    int startcol = board.pieceinfo.col;
    
    int drow = row - startrow;
    int dcol = col - startcol;

    if (absolute(drow) <= 1 && absolute(dcol) <= 1)
        return true;
// Castling for White King
if(drow==0 && absolute(dcol)==2){
    if(board.pieceinfo.selected_piece==WKING){
//Kingside Castling (short castle)
        if(col==6 && board.castling.whiteKingSide){
            if(board.board[7][5]==EMPTY && board.board[7][6]==EMPTY && board.board[7][7]==WROOK){
                board.castling.whiteKingSide=false;
                board.castling.whiteQueenSide=false;
                board.board[row][5]=board.board[row][7];
                board.board[row][7]=EMPTY;
                return true;
            }
        }
//QueenSide Castling (long castle)
        if(col==2 && board.castling.whiteQueenSide){
            if(board.board[7][2]==EMPTY && board.board[7][3]==EMPTY && board.board[7][0]==WROOK){
            board.castling.whiteKingSide=false;
            board.castling.whiteQueenSide=false;
            board.board[row][3]=board.board[row][0];
            board.board[row][0]=EMPTY;
                return true;
            }
        }
    
}
// Castling For black king
else{
// KingSide Castling (Short Castle)
    if(col==6 && board.castling.blackKingSide){
        if(board.board[0][5]==EMPTY && board.board[0][6]==EMPTY && board.board[0][7]==BROOK){
            board.castling.blackKingSide=false;
            board.castling.blackQueenSide=false;
            board.board[row][5]=board.board[row][7];
            board.board[row][7]=EMPTY;
            return true;
        }
    }

// Queenside Castling (Long Castle)
    if(col==2 && board.castling.blackQueenSide){
        if(board.board[0][2]==EMPTY && board.board[0][3]==EMPTY && board.board[0][0]==BROOK){
            board.castling.blackKingSide=false;
            board.castling.blackQueenSide=false;
            board.board[row][3]=board.board[row][0];
            board.board[row][0]=EMPTY;
            return true;
            }
        }
    }
}
    return false;
}
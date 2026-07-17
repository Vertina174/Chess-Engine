/*
Board coordinates using getmouse
int col = (GetMouseX() - OFFSET_x) / SQUARE_SIZE;
int row = (GetMouseY() - OFFSET_y) / SQUARE_SIZE;

Screen Coordinates using getmouse
int x = OFFSET_x + board.pieceinfo.col * SQUARE_SIZE;
int y = OFFSET_y + board.pieceinfo.row * SQUARE_SIZE;
*/
#include"piece.h"
#include"src/include/raylib.h"
#include<iostream>
#include"move.h"
using namespace std;
bool double_step_pawn=false;
bool was_en_passant = false;

void clearPieceInfo(Board& board){
    board.pieceinfo.row = -1;
    board.pieceinfo.col = -1;
    board.pieceinfo.selected_piece = EMPTY;
}
void select_a_piece(Board& board){
    if(!IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            return;
    if( board.pieceinfo.selected_piece!=EMPTY)
        return;
int col = (GetMouseX() - OFFSET_x) / SQUARE_SIZE;
int row = (GetMouseY() - OFFSET_y) / SQUARE_SIZE;
if(board.board[row][col]!=EMPTY){
    board.pieceinfo.row=row;
    board.pieceinfo.col=col;
    board.pieceinfo.selected_piece=board.board[row][col];
    }

}
void show_selected_piece(Board& board){
//In Terminal
cout<<"\nSelected Piece: "<<board.pieceinfo.selected_piece;
cout<<" ["<<board.pieceinfo.row<<",";
cout<<board.pieceinfo.col<<"]\n";
cout<<"En passant col: "<<board.pieceinfo.en_passant_col<<std::endl;
}
PieceColor getPieceColor(Piece piece){
    if(piece == EMPTY)  return color_none;
    else if(piece>EMPTY && piece<=WKING) return color_white;

return color_black;
}
bool isEnemy(Piece p1, Piece p2){
    PieceColor c1 =getPieceColor(p1);
    PieceColor c2 = getPieceColor(p2);
    if(c1==color_none || c2 ==color_none)   return false;

    return c1!=c2;
}
bool legalmove(Board& board,int row, int col){
     if(board.pieceinfo.selected_piece==EMPTY){
        clearPieceInfo(board);
        return false;
    }
if(board.board[row][col]!=EMPTY && getPieceColor(board.board[row][col])==getPieceColor(board.pieceinfo.selected_piece)){
        clearPieceInfo(board);
        return false;
    }
    if(board.pieceinfo.row==row && board.pieceinfo.col==col){
        clearPieceInfo(board);
        return false;
    }
    bool move=false;
    switch(board.pieceinfo.selected_piece){
        case WPAWN:
        case BPAWN:{    
            if(absolute(row-board.pieceinfo.row)==2)
                    double_step_pawn=true;
                    
                if(col == board.pieceinfo.en_passant_col && board.board[row][col] == EMPTY)
                    was_en_passant = true;

            move=isPawnLegal(board, row, col);
            
            if (was_en_passant) 
                board.board[board.pieceinfo.row][col] = EMPTY;
    
            if(double_step_pawn)
                board.pieceinfo.en_passant_col=col;
            else
                board.pieceinfo.en_passant_col=-1;
            break;
        }
        case WKNIGHT:
        case BKNIGHT:{
            move=isKnightLegal(board, row, col);
            break;
        }
        case WBISHOP:
        case BBISHOP:{
            move=isBishopLegal(board,row,col);
            break;
        }
        case WROOK:
        case BROOK:{
            move=isRookLegal(board,row,col);
            break;
        }
        case WQUEEN:
        case BQUEEN:{
            move=(isBishopLegal(board,row,col)|| isRookLegal(board,row,col));
            break;
        }
        case WKING:
        case BKING:{
                move=isKingLegal(board, row, col);
                if(move){
                if(board.pieceinfo.selected_piece==WKING){
                    board.castling.whiteKingSide=false;
                    board.castling.whiteQueenSide=false;
                }
                else{
                    board.castling.blackKingSide=false;
                    board.castling.blackQueenSide=false;
                }
                }
                break;
        }
    }
    return move;
}

void move_selected_piece(Board& board){
     
    if(!IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        return;
  
    int col = (GetMouseX() - OFFSET_x) / SQUARE_SIZE;
    int row = (GetMouseY() - OFFSET_y) / SQUARE_SIZE;
    
    if(!legalmove(board, row, col)){
        clearPieceInfo(board);
        return;
    }
board.board[row][col]=board.pieceinfo.selected_piece;
board.board[board.pieceinfo.row][board.pieceinfo.col]=EMPTY;

clearPieceInfo(board);
}
void updatepositions(Board& board){
    
if(board.pieceinfo.selected_piece==EMPTY)
    select_a_piece(board);
    
else
    move_selected_piece(board);

show_selected_piece(board);// In Terminal
}
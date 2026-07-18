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

void clearPieceInfo(Board& board){
    board.pieceinfo.row = -1;
    board.pieceinfo.col = -1;
    board.pieceinfo.selected_piece = EMPTY;
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

void clearEnPassant(Board& board){
    board.enpassant.row=-1;
    board.enpassant.col=-1;
    board.enpassant.double_step_pawn=false;
    board.enpassant.was_en_passant=false;
}

void clearPromotioninfo(Board& board){
board.pawnpromotion.row=-1;
board.pawnpromotion.col=-1;
board.pawnpromotion.PromotionColor=color_none;
board.pawnpromotion.PromotionState=false;
}

void show_selected_piece(Board& board){
//In Terminal
cout<<"\nSelected Piece: "<<board.pieceinfo.selected_piece;
cout<<" ["<<board.pieceinfo.row<<",";
cout<<board.pieceinfo.col<<"]\n";
cout<<"\nEn passant col: "<<board.enpassant.col;
cout<<"\nEn passant Row: "<<board.enpassant.row;
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
                    board.enpassant.double_step_pawn=true;
                    
                if(col == board.enpassant.col && board.board[row][col] == EMPTY)
                    board.enpassant.was_en_passant = true;

            move=isPawnLegal(board, row, col);
            
            if(board.enpassant.double_step_pawn){
                board.enpassant.col=col; 
                board.enpassant.row=(board.pieceinfo.selected_piece==WPAWN)?2:5;
                board.enpassant.double_step_pawn=false;
            }

            if (board.enpassant.was_en_passant)
                board.board[board.pieceinfo.row][col] = EMPTY;

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

void handle_promotion(Board& board){
    if(!IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        return;
int col = (GetMouseX() - OFFSET_x) / SQUARE_SIZE;
int row = (GetMouseY() - OFFSET_y) / SQUARE_SIZE;

if(row==4){
    switch(col){
        case 2:{
            if(board.pawnpromotion.PromotionColor==color_white){
                board.board[board.pawnpromotion.row][board.pawnpromotion.col]=WKNIGHT;
                clearPromotioninfo(board);
            }
            else{
                board.board[board.pawnpromotion.row][board.pawnpromotion.col]=BKNIGHT;
                clearPromotioninfo(board);
            }
            break;
        }
        case 3:{
                        if(board.pawnpromotion.PromotionColor==color_white){
                board.board[board.pawnpromotion.row][board.pawnpromotion.col]=WBISHOP;
                clearPromotioninfo(board);
            }
            else{
                board.board[board.pawnpromotion.row][board.pawnpromotion.col]=BBISHOP;
                clearPromotioninfo(board);
            }
            break;
        }
        case 4:{
                        if(board.pawnpromotion.PromotionColor==color_white){
                board.board[board.pawnpromotion.row][board.pawnpromotion.col]=WROOK;
                clearPromotioninfo(board);
            }
            else{
                board.board[board.pawnpromotion.row][board.pawnpromotion.col]=BROOK;
                clearPromotioninfo(board);
            }
            break;
        }
        case 5:{
                        if(board.pawnpromotion.PromotionColor==color_white){
                board.board[board.pawnpromotion.row][board.pawnpromotion.col]=WQUEEN;
                clearPromotioninfo(board);
            }
            else{
                board.board[board.pawnpromotion.row][board.pawnpromotion.col]=BQUEEN;
                clearPromotioninfo(board);
            }
            break;
        }
    }
}
    
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
    if(board.pawnpromotion.PromotionState){
        handle_promotion(board);
        return;
    }
if(board.pieceinfo.selected_piece==EMPTY)
    select_a_piece(board);
    
else
    move_selected_piece(board);

show_selected_piece(board);// In Terminal
}
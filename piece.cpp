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
enum PieceColor {color_none, color_white,color_black};
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
std::cout<<"Select Piece";
board.pieceinfo.row=row;
board.pieceinfo.col=col;
board.pieceinfo.selected_piece=board.board[row][col];
}
void show_selected_piece(Board& board){
//In Terminal
std::cout<<"\nSelected Piece: "<<board.pieceinfo.selected_piece;
std::cout<<" ["<<board.pieceinfo.row<<",";
std::cout<<board.pieceinfo.col<<"]\n";
}
PieceColor getPieceColor(Piece piece){
    if(piece == EMPTY)  return color_none;
    else if(piece>EMPTY && piece<WKING) return color_white;

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
if(getPieceColor(board.board[row][col])==getPieceColor(board.pieceinfo.selected_piece)){
        clearPieceInfo(board);
        return false;
    }
    if(board.pieceinfo.row==row && board.pieceinfo.col==col){
        clearPieceInfo(board);
        return false;
    }
    return true;
}
void move_selected_piece(Board& board){
     
    if(!IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        return;
  
    int col = (GetMouseX() - OFFSET_x) / SQUARE_SIZE;
    int row = (GetMouseY() - OFFSET_y) / SQUARE_SIZE;
    
    if(!legalmove(board, row, col))
        return;
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
#include"board.h"
#include"src/include/raylib.h" 
#include<iostream>
using namespace std;

void select_a_piece(Board& board){
    if(board.pieceinfo.selected_piece!=0)   
        return;
if(!IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    return;
            int col = ((GetMouseX())/board.squaresize);
            int row = ((GetMouseY()+ board.offsetY)/board.squaresize);
board.pieceinfo.row            =row;
board.pieceinfo.col            =col;
board.pieceinfo.selected_piece =board.board[row-1][col-1];
}

void show_selected_piece(Board& board){
    cout<<"\nSelected Piece: "<<board.pieceinfo.selected_piece;
    cout<<" ["<<board.pieceinfo.row<<",";
    cout<<board.pieceinfo.col<<"]\n";
}

void move_selected_piece(Board& board){
    if(board.pieceinfo.selected_piece==0)   
        return;
 if(!IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    return;

 int col = GetMouseX() / board.squaresize;
 int row = (GetMouseY() + board.offsetY) / board.squaresize;

board.board[row-1][col-1] = board.pieceinfo.selected_piece;
board.board[board.pieceinfo.row-1][board.pieceinfo.col-1] = EMPTY;
board.pieceinfo.selected_piece = EMPTY;
board.pieceinfo.row = -1;
board.pieceinfo.col = -1;}
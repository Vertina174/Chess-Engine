#include"board.h"
int pawnlegalmove(Board& board){
if(board.pieceinfo.selected_piece!=1)
    return 0;


// if(board.board[board.pieceinfo.row-1][board.pieceinfo.col]==EMPTY){
// if(board.board[board.pieceinfo.row-2][board.pieceinfo.col]==EMPTY && board.pieceinfo.row==7){
//         return 2;
//     }
// return 1;
// }
return 0;
}
bool knightlegalmove(Board& board){

}

bool bishoplegalmove(Board& board){
    
}

bool rooklegalmove(Board& board){
    
}

bool queenlegalmove(Board& board){
    
}

bool kniglegalmove(Board& board){
    
}
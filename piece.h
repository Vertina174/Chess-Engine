#pragma once
#include"board.h"

void select_a_piece     (Board& board);
void show_selected_piece(Board& board);
void updatepositions    (Board& board);
void move_selected_piece(Board& board);
void clearPieceInfo     (Board& board);
bool isEnemy            (Piece p1, Piece p2);
bool legalmove          (Board& board);
PieceColor getPieceColor(Piece piece);
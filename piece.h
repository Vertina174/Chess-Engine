#pragma once
#include"board.h"

void select_a_piece     (Board& board);
void show_selected_piece(Board& board);
void updatepositions    (Board& board);
void move_selected_piece(Board& board);
void clearPieceInfo     (Board& board);
void clearPromotioninfo (Board& board);
void clearEnPassant     (Board& board);
bool legalmove          (Board& board);
void handle_promotion   (Board& board);
bool isEnemy            (Piece p1, Piece p2);
PieceColor getPieceColor(Piece piece);

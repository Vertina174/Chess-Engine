#pragma once
#include"board.h"

PieceColor getPieceColor(Piece piece);
void select_a_piece     (Board& board);
void show_selected_piece(Board& board);
void updatepositions    (Board& board);
void move_selected_piece(Board& board);
void clearPieceInfo     (Board& board);
void clearPromotioninfo (Board& board);
void clearEnPassant     (Board& board);
void handle_promotion   (Board& board);
bool KingInCheck        (Board& board, PieceColor color);
bool isEnemy            (Piece p1, Piece p2);
bool legalmove          (Board& board, int row, int col);
void FindKing           (Board& board, PieceColor color);



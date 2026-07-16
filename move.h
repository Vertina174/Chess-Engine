#pragma once
#include"board.h"
bool isPawnLegal  (Board& board,int row, int col);
bool isKnightLegal(Board& board,int row, int col);
bool isBishopLegal(Board& board,int row, int col);
bool isRookLegal  (Board& board,int row, int col);
bool isQueenLegal (Board& board,int row, int col);
bool isKingLegal  (Board& board,int row, int col);
int absolute(int n);
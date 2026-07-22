#pragma once
#include"board.h"
void Load_Texture();
void Unload_Texture();
void draw(Board& board);
void drawboard(Board& board);
void drawpiece(Board& board);
void highlight_rook(Board& board);
void highlight_bishop(Board& board);
void highlight_selected_piece(Board& board);
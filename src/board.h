//
// Created by ahmad on 5/7/22.
//

#ifndef UNICHESS_BOARD_H
#define UNICHESS_BOARD_H

#include <SDL.h>
#include <vector>
#include <array>
#include "piece.h"

class Board
{
public:
    explicit Board(SDL_Texture *pieceTexture);

    void Draw(SDL_Renderer *renderer);

    SDL_Rect *Boundary();

    void Click(int x, int y);

    void MouseMove(int x, int y);
private:
    std::array<std::array<Piece *, 8>, 8> pieces;
    std::array<std::array<int, 8>, 8> cells;

    int selectedRow = -1;
    int selectedCol = -1;

    int hoverRow = -1;
    int hoverCol = -1;

    SDL_Rect *boundryRect;

    const int width = 54;
    const int height = 52;
};


#endif //UNICHESS_BOARD_H

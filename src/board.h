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
    enum Cell {Normal, Selected, Hover, PathThrough};

    std::array<std::array<Cell, 8>, 8> cells;
    int selectedRow = -1;

    int selectedCol = -1;
    int hoverRow = -1;

    int hoverCol = -1;

    SDL_Rect *boundaryRect;
    const int width = 54;

    const int height = 52;
    enum State {Neutral, PIECE_SELECTED};

    State State;

    bool availableMoves[8][8];
};


class RGB
{
public:
    RGB(int r, int g, int b);
    int R;
    int G;
    int B;
};


#endif //UNICHESS_BOARD_H

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

private:
    std::array<std::array<Piece *, 8>, 8> pieces;
};


#endif //UNICHESS_BOARD_H

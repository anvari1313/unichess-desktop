//
// Created by ahmad on 5/6/22.
//

#ifndef UNICHESS_KNIGHT_H
#define UNICHESS_KNIGHT_H

#include <SDL.h>
#include "piece.h"

class Knight : public Piece
{
public:
    std::vector<SDL_Point> AvailableMoves() override;
    explicit Knight(SDL_Texture *img, bool white);

    bool IsKing() override;
};


#endif //UNICHESS_KNIGHT_H

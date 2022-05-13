//
// Created by ahmad on 5/6/22.
//

#ifndef UNICHESS_BISHOP_H
#define UNICHESS_BISHOP_H

#include <SDL.h>
#include "piece.h"

class Bishop : public Piece
{
public:
    explicit Bishop(SDL_Texture *img, bool white);

    std::vector<SDL_Point> AvailableMoves() override;

    bool IsKing() override;
};


#endif //UNICHESS_BISHOP_H

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
    explicit Knight(SDL_Surface *img);
};


#endif //UNICHESS_KNIGHT_H
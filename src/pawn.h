//
// Created by ahmad on 5/6/22.
//

#ifndef UNICHESS_PAWN_H
#define UNICHESS_PAWN_H

#include <SDL.h>
#include "piece.h"

class Pawn : public Piece
{
public:
    explicit Pawn(SDL_Surface *img, bool white);

};


#endif //UNICHESS_PAWN_H

//
// Created by ahmad on 5/6/22.
//

#ifndef UNICHESS_QUEEN_H
#define UNICHESS_QUEEN_H

#include <SDL.h>
#include "piece.h"

class Queen : public Piece{
public:
    explicit Queen(SDL_Surface *img);

};


#endif //UNICHESS_QUEEN_H

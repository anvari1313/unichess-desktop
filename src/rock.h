//
// Created by ahmad on 5/6/22.
//

#ifndef UNICHESS_ROCK_H
#define UNICHESS_ROCK_H

#include <SDL.h>
#include "piece.h"

class Rock : public Piece {
public:
    explicit Rock(SDL_Surface *img);

};


#endif //UNICHESS_ROCK_H

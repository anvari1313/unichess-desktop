//
// Created by ahmad on 5/6/22.
//

#ifndef UNICHESS_ROCK_H
#define UNICHESS_ROCK_H

#include <SDL.h>
#include "piece.h"

class Rock : public Piece {
public:
    explicit Rock(SDL_Texture *img, bool white);

    std::vector<SDL_Point> AvailableMoves(BoardOmniscient *omniscient) override;

    bool IsKing() override;
};


#endif //UNICHESS_ROCK_H

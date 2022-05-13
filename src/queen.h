//
// Created by ahmad on 5/6/22.
//

#ifndef UNICHESS_QUEEN_H
#define UNICHESS_QUEEN_H

#include <SDL.h>
#include "piece.h"

class Queen : public Piece{
public:
    explicit Queen(SDL_Texture *img, bool white);

    std::vector<SDL_Point> AvailableMoves() override;

    bool IsKing() override;
};


#endif //UNICHESS_QUEEN_H

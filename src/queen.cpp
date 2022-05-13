//
// Created by ahmad on 5/6/22.
//

#include "queen.h"

Queen::Queen(SDL_Texture *img, bool white) : Piece(img, 1, white)
{

}

std::vector<SDL_Point> Queen::AvailableMoves()
{
    return {};
}

bool Queen::IsKing()
{
    return false;
}

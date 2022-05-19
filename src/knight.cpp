//
// Created by ahmad on 5/6/22.
//

#include "knight.h"

Knight::Knight(SDL_Texture *img, bool white) : Piece(img, 3, white, true)
{

}

std::vector<SDL_Point> Knight::AvailableMoves(BoardOmniscient *omniscient)
{
    return {};
}

bool Knight::IsKing()
{
    return false;
}

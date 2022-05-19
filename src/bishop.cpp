//
// Created by ahmad on 5/6/22.
//

#include "bishop.h"

Bishop::Bishop(SDL_Texture *img, bool white) : Piece(img, 2, white, true)
{

}

std::vector<SDL_Point> Bishop::AvailableMoves(BoardOmniscient *omniscient)
{
    return {};
}

bool Bishop::IsKing()
{
    return false;
}

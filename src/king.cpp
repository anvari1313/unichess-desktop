//
// Created by ahmad on 5/6/22.
//

#include "king.h"

King::King(SDL_Texture *img, bool white) : Piece(img, 0, white, false)
{

}

std::vector<SDL_Point> King::AvailableMoves(BoardOmniscient *omniscient)
{
    return {};
}

bool King::IsKing()
{
    return true;
}

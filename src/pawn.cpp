//
// Created by ahmad on 5/6/22.
//

#include "pawn.h"

Pawn::Pawn(SDL_Texture *img, bool white) : Piece(img, 5, white, true)
{

}

std::vector<SDL_Point> Pawn::AvailableMoves(BoardOmniscient *omniscient)
{
    return {
            {2, 2},
            {3,3}
    };
}

bool Pawn::IsKing()
{
    return false;
}

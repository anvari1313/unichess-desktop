//
// Created by ahmad on 5/6/22.
//

#include "pawn.h"

Pawn::Pawn(SDL_Texture *img, bool white) : Piece(img, 5, white)
{

}

std::vector<SDL_Point> Pawn::AvailableMoves()
{
    return {};
}

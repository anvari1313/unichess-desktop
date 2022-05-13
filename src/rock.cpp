//
// Created by ahmad on 5/6/22.
//

#include "rock.h"

Rock::Rock(SDL_Texture *img, bool white) : Piece(img, 4, white) {

}

std::vector<SDL_Point> Rock::AvailableMoves()
{
    return {};
}

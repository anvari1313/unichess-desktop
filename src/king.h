//
// Created by ahmad on 5/6/22.
//

#ifndef UNICHESS_KING_H
#define UNICHESS_KING_H

#include "piece.h"

class King : public Piece {
public:
    explicit King(SDL_Texture *img, bool white);

    std::vector<SDL_Point> AvailableMoves(BoardOmniscient *omniscient) override;

    bool IsKing() override;
};


#endif //UNICHESS_KING_H

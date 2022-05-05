//
// Created by ahmad on 5/5/22.
//

#include "piece.h"

Piece::Piece(SDL_Surface *img, int startX, int startY): img(img), startIndexX(startX), startIndexY(startY)
{
    srcRect.x = this->startIndexX * this->SourceWidth;
    srcRect.y = this->startIndexY * this->SourceHeight;
    srcRect.w = this->SourceWidth;
    srcRect.h = this->SourceHeight;

    destRect.x = 0;
    destRect.y = 0;
    destRect.w = 54;
//        destRect.w = 161;
    destRect.h = 52;
//        destRect.h = 155;

}

void Piece::Draw(SDL_Surface *destSurface)
{
    SDL_BlitScaled(this->img, &srcRect, destSurface, &destRect);
}

void Piece::Move(int x, int y)
{
    destRect.x = x;
    destRect.y = y;
}

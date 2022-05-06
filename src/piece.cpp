//
// Created by ahmad on 5/5/22.
//

#include "piece.h"

Piece::Piece(SDL_Texture *img, int startX, bool white): img(img), startIndexX(startX), white(white)
{
    srcRect.x = this->startIndexX * this->SourceWidth;
    if (white)
        srcRect.y = 0;
    else
        srcRect.y = 1 * this->SourceHeight;
    srcRect.w = this->SourceWidth;
    srcRect.h = this->SourceHeight;

    destRect.x = 0;
    destRect.y = 0;
    destRect.w = 54;
//        destRect.w = 161;
    destRect.h = 52;
//        destRect.h = 155;

}

void Piece::Draw(SDL_Renderer *renderer)
{
    SDL_RenderCopy(renderer, this->img, &srcRect, &destRect);
}

void Piece::Move(int x, int y)
{
    destRect.x = x;
    destRect.y = y;
}

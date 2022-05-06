//
// Created by ahmad on 5/5/22.
//

#ifndef UNICHESS_PIECE_H
#define UNICHESS_PIECE_H

#include <SDL.h>

class Piece {
public:
    Piece(SDL_Surface *img, int startIndexX, bool white);

    int startIndexX;
    int startIndexY;

    bool white;

    void Draw(SDL_Surface *destSurface);

    void Move(int x, int y);

private:
    SDL_Surface *img;

    const int SourceWidth = 161;
    const int SourceHeight = 155;

    SDL_Rect srcRect;
    SDL_Rect destRect;
};


#endif //UNICHESS_PIECE_H

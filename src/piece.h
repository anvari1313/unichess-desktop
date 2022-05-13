//
// Created by ahmad on 5/5/22.
//

#ifndef UNICHESS_PIECE_H
#define UNICHESS_PIECE_H

#include <SDL.h>
#include <vector>

class Piece {
public:
    Piece(SDL_Texture *img, int startIndexX, bool white);

    int startIndexX;
    int startIndexY;

    bool white;

    void Draw(SDL_Renderer *renderer);

    void Move(int x, int y);

    virtual std::vector<SDL_Point> AvailableMoves() = 0;

    virtual bool IsKing() = 0;

private:
    SDL_Texture *img;

    const int SourceWidth = 161;
    const int SourceHeight = 155;

    SDL_Rect srcRect;
    SDL_Rect destRect;
};


#endif //UNICHESS_PIECE_H

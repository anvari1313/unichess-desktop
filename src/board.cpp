//
// Created by ahmad on 5/7/22.
//

#include "board.h"
#include "piece.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rock.h"
#include "pawn.h"
#include <array>

#define BLACK_ROCK new Rock(pieceTexture, false)
#define BLACK_KNIGHT new Knight(pieceTexture, false)
#define BLACK_BISHOP new Bishop(pieceTexture, false)
#define BLACK_QUEEN new Queen(pieceTexture, false)
#define BLACK_KING new King(pieceTexture, false)
#define BLACK_PAWN new Pawn(pieceTexture, false)
#define NO_PIECE nullptr
#define WHITE_ROCK new Rock(pieceTexture, true)
#define WHITE_KNIGHT new Knight(pieceTexture, true)
#define WHITE_BISHOP new Bishop(pieceTexture, true)
#define WHITE_QUEEN new Queen(pieceTexture, true)
#define WHITE_KING new King(pieceTexture, true)
#define WHITE_PAWN new Pawn(pieceTexture, true)

RGB::RGB(int r, int g, int b): R(r), G(g), B(b) {}

class ColorPallet1
{
public:
    RGB BlackNormal = RGB(84,45,30);
    RGB WhiteNormal = RGB(220, 181, 166);
    RGB BlackHover = RGB(241, 68, 0);
    RGB WhiteHover = RGB(150, 118, 148);
    RGB Other = RGB(255, 188, 19);
    RGB Other2 = RGB(250, 180, 10);

} COLOR_PALLET;

Board::Board(SDL_Texture *pieceTexture)
{
    this->cells = {Normal};
    this->pieces;
    pieces = {
            BLACK_ROCK, BLACK_KNIGHT, BLACK_BISHOP, BLACK_QUEEN, BLACK_KING, BLACK_BISHOP, BLACK_KNIGHT, BLACK_ROCK,
            BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN,
            NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE,
            NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE,
            NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE,
            NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE,
            WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN,
            WHITE_ROCK, WHITE_KNIGHT, WHITE_BISHOP, WHITE_QUEEN, WHITE_KING, WHITE_BISHOP, WHITE_KNIGHT, WHITE_ROCK,
    };

    this->boundaryRect = new SDL_Rect;
    this->boundaryRect->x = 0;
    this->boundaryRect->y = 0;
    this->boundaryRect->w = 8 * this->width;
    this->boundaryRect->h = 8 * this->height;

    for (int i = 0; i < this->pieces.size(); ++i)
    {
        for (int j = 0; j < this->pieces[0].size(); ++j)
        {
            if (pieces[j][i] != nullptr)
            {
                pieces[j][i]->Move(i * width, j * height);
            }
        }
    }

    this->State = Neutral;
}

void Board::Draw(SDL_Renderer *renderer)
{
    int startPos = 0;
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            SDL_Rect rect;
            rect.x = x * width;
            rect.y = y * height;
            rect.w = width;
            rect.h = height;
            if (startPos == 0) {
                if (selectedCol == x && selectedRow == y) {
                    auto p = COLOR_PALLET.BlackHover;
                    SDL_SetRenderDrawColor(renderer, p.R, p.G, p.B, 255);
                } else if (hoverCol == x && hoverRow == y) {
                    auto p = COLOR_PALLET.Other;
                    SDL_SetRenderDrawColor(renderer, p.R, p.G, p.B, 100);
                } else if (this->cells[y][x] == PathThrough) {
                    auto p = COLOR_PALLET.Other;
                    SDL_SetRenderDrawColor(renderer, p.R, p.G, p.B, 255);
                } else {
                    auto p = COLOR_PALLET.BlackNormal;
                    SDL_SetRenderDrawColor(renderer, p.R, p.G, p.B, 255);
                }

            } else {
                if (selectedCol == x && selectedRow == y) {
                    auto p = COLOR_PALLET.WhiteHover;
                    SDL_SetRenderDrawColor(renderer, p.R, p.G, p.B, 255);
                } else if (hoverCol == x && hoverRow == y) {
                    auto p = COLOR_PALLET.Other;
                    SDL_SetRenderDrawColor(renderer, p.R, p.G, p.B, 100);
                } else if (this->cells[y][x] == PathThrough) {
                    auto p = COLOR_PALLET.Other;
                    SDL_SetRenderDrawColor(renderer, p.R, p.G, p.B, 255);
                } else {
                    auto p = COLOR_PALLET.WhiteNormal;
                    SDL_SetRenderDrawColor(renderer, p.R, p.G, p.B, 255);
                }

            }
            SDL_RenderFillRect(renderer, &rect);
            startPos = 1 - startPos;
        }
        startPos = 1 - startPos;
    }

    for (int i = 0; i < this->pieces.size(); ++i)
    {
        for (int j = 0; j < this->pieces[0].size(); ++j)
        {
            if (pieces[j][i] != nullptr)
            {
                pieces[j][i]->Draw(renderer);
            }
        }
    }
}

SDL_Rect *Board::Boundary()
{
    return this->boundaryRect;
}

void Board::Click(int x, int y)
{
    auto col = (x - this->boundaryRect->x) / width;
    auto row = (y - this->boundaryRect->y) / height;

    if (this->State == Neutral)
    {
        if (this->pieces[row][col] != nullptr)
        {
            selectedCol = col;
            selectedRow = row;
            this->State = PIECE_SELECTED;
            auto p = this->pieces[row][col];
            auto moves = p->AvailableMoves(this);
            for (const auto &item: moves)
            {
                this->cells[item.y][item.x] = PathThrough;
            }
        }
        else
        {
            printf("This cell is empty and can not be selected\n");
        }
    }
    else if (this->State == PIECE_SELECTED)
    {
        this->pieces[selectedRow][selectedCol]->Move(col * this->width, row * this->height);
        std::swap(this->pieces[row][col], this->pieces[selectedRow][selectedCol]);
        printf("Move (%d, %d) -> (%d, %d)\n", selectedRow, selectedCol, row, col);
        this->State = Neutral;
    }
}

void Board::MouseMove(int x, int y)
{
    hoverCol = (x - this->boundaryRect->x) / width;
    hoverRow = (y - this->boundaryRect->y) / height;
}

void Board::WhatIsAt()
{

}

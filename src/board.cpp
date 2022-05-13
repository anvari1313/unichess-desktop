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

Board::Board(SDL_Texture *pieceTexture)
{
    this->cells = {0};
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

    this->boundryRect = new SDL_Rect;
    this->boundryRect->x = 0;
    this->boundryRect->y = 0;
    this->boundryRect->w = 8 * this->width;
    this->boundryRect->h = 8 * this->height;
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
                    SDL_SetRenderDrawColor(renderer, 59, 84, 8, 255);
                } else if (hoverCol == x && hoverRow == y) {
                    SDL_SetRenderDrawColor(renderer, 159, 150, 8, 255);
                } else {
                    SDL_SetRenderDrawColor(renderer, 159, 84, 8, 255);
                }

            } else {
                if (selectedCol == x && selectedRow == y) {
                    SDL_SetRenderDrawColor(renderer, 89, 0, 180, 255);
                } else if (hoverCol == x && hoverRow == y) {
                    SDL_SetRenderDrawColor(renderer, 159, 120, 180, 255);
                } else {
                    SDL_SetRenderDrawColor(renderer, 159, 0, 180, 255);
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
                pieces[j][i]->Move(i * width, j * height);
                pieces[j][i]->Draw(renderer);
            }
        }
    }

}

SDL_Rect *Board::Boundary()
{
    return this->boundryRect;
}

void Board::Click(int x, int y)
{
    selectedCol = (x - this->boundryRect->x) / width;
    selectedRow = (y - this->boundryRect->y) / height;
}

void Board::MouseMove(int x, int y)
{
    hoverCol = (x - this->boundryRect->x) / width;
    hoverRow = (y - this->boundryRect->y) / height;
}

//
// Created by ahmad on 5/5/22.
//

#include "game.h"
#include <SDL_image.h>
#include <vector>
#include "piece.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"

Game::Game() {
    this->gWindow = nullptr;
    this->gScreenSurface = nullptr;
    this->pieceSurface = nullptr;

    this->running = true;
}

void Game::Init() {
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return;
    } else {
        //Create window
        this->gWindow = SDL_CreateWindow("UniChess", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                         SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (this->gWindow == nullptr) {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            return;
        } else {
            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags)) {
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                return;
            } else {
                //Get window surface
                this->gScreenSurface = SDL_GetWindowSurface(this->gWindow);

                this->pieceSurface = this->loadSurface("../resource/piece.png");
            }
        }
    }

}

void Game::Run() {
    //Event handler
    SDL_Event e;

    std::vector<Piece> pieces;
    King k1(this->pieceSurface);
    King k2(this->pieceSurface);
    k2.Move(120, 10);

    Queen queen(this->pieceSurface);
    queen.Move(120, 50);


    Bishop bishop(this->pieceSurface);
    bishop.Move(120, 100);

    pieces.push_back(k1);
    pieces.push_back(k2);
    pieces.push_back(queen);
    pieces.push_back(bishop);

    //While application is running
    while (this->running)
    {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                this->running = false;
            }
                //User presses a key
            else if (e.type == SDL_KEYDOWN) {
                //Select surfaces based on key press
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
//                        gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
                        break;

                    case SDLK_DOWN:
//                        gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
                        break;

                    case SDLK_LEFT:
//                        gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
                        break;

                    case SDLK_RIGHT:
//                        gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
                        break;

                    default:
//                        gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
                        break;
                }
            } else if (e.type == SDL_KEYUP) {
//                gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
                break;
            }
        }

        for (auto & piece : pieces) {
            piece.Draw(gScreenSurface);
        }

        //Update the surface
        SDL_UpdateWindowSurface(gWindow);
    }

}

SDL_Surface *Game::loadSurface(const std::string &path)
{
    //The final optimized image
    SDL_Surface *optimizedSurface = nullptr;

    //Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    } else {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
        if (optimizedSurface == nullptr) {
            printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return optimizedSurface;
}

void Game::Close()
{
    SDL_FreeSurface( this->pieceSurface);
    this->pieceSurface = nullptr;

    //Destroy window
    SDL_DestroyWindow( this->gWindow );
    this->gWindow = nullptr;

    //Quit SDL subsystems
    SDL_Quit();
}


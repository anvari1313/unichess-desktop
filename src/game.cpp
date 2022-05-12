//
// Created by ahmad on 5/5/22.
//

#include "game.h"
#include <SDL_image.h>
#include <vector>
#include "board.h"

Game::Game() {
    this->gWindow = nullptr;
    this->renderer = nullptr;
    this->pieceTexture = nullptr;

    this->running = true;
}

void Game::Init() {
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return;
    } else {
        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            printf("Warning: Linear texture filtering not enabled!");
        }

        //Create window
        this->gWindow = SDL_CreateWindow("UniChess", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                         SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (this->gWindow == nullptr) {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            return;
        } else {
            //Create renderer for window
            this->renderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (this->renderer == NULL) {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                return;
            } else {
                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    return;
                } else {
                    //Get window surface
                    this->pieceTexture = this->loadTexture("../resource/piece.png");
                }
            }
        }
    }

}

void Game::Run() {
    //Event handler
    SDL_Event e;

    Board board(this->pieceTexture);

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
            }
            else if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
            {
                //Get mouse position
                int x, y;
                SDL_GetMouseState( &x, &y );

                auto b = board.Boundary();
                if (x >= b->x && y >= b->y && x <= b->x + b->w && y <= b->y + b->h)
                {
                    //Mouse is inside button
                    switch( e.type )
                    {
                        case SDL_MOUSEMOTION:
                            break;

                        case SDL_MOUSEBUTTONDOWN:
                            break;

                        case SDL_MOUSEBUTTONUP:
                            board.Click(x, y);
                            break;
                    }
                }
            }
        }

        board.Draw(this->renderer);

        //Update the surface
        SDL_RenderPresent(this->renderer);
    }

}

void Game::Close()
{
    SDL_DestroyTexture( this->pieceTexture);
    this->pieceTexture = nullptr;

    //Destroy window
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow( this->gWindow );
    this->renderer = nullptr;
    this->gWindow = nullptr;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture *Game::loadTexture(std::string path)
{
    //The final texture
    SDL_Texture *newTexture = NULL;

    //Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    } else {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(this->renderer, loadedSurface);
        if (newTexture == NULL) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}


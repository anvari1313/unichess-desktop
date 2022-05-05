//
// Created by ahmad on 5/5/22.
//

#ifndef UNICHESS_GAME_H
#define UNICHESS_GAME_H

#include <SDL.h>
#include <string>

class Game {
public:
    Game();

    void Init();

    void Run();

    void Close();

private:
    //Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    bool running;

    //The window we'll be rendering to
    SDL_Window *gWindow;

    //The surface contained by the window
    SDL_Surface *gScreenSurface;

    // Pieces surface
    SDL_Surface *pieceSurface;

    SDL_Surface *loadSurface(const std::string &path);
};


#endif //UNICHESS_GAME_H

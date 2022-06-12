#include "core.h"

bool InitWindow(int w, int h)
{
    bool success = true;

    /*SDL*/
    SDL_Init(SDL_INIT_VIDEO);

    /*SDL IMAGE*/
    int imgFlags = IMG_INIT_PNG;
    IMG_Init(imgFlags);

    /*TTF*/
    TTF_Init();

    /*create window*/
    gWindow = SDL_CreateWindow("window name", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    
    gFont = TTF_OpenFont("res/karma future.ttf", 15);

    dColor = { 255, 255, 255, 255 };

    return success;
}



void Close()
{
    /*free resources*/
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    gWindow = NULL;
    gRenderer = NULL;
    TTF_CloseFont(gFont);

    /*close subsytems*/
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
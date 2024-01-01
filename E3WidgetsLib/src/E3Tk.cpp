#include "E3Tk.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include <iostream>

using namespace E3Widgets;


bool E3Tk::InitializeE3()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return false;
    }
    if (TTF_Init() == -1)
    {
        std::cerr << "Failed to initialize TTF: " << TTF_GetError() << std::endl;
        SDL_Quit();
        return false;
    }
    return true;
}

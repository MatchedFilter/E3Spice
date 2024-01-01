#include "UI/MainScreen.h"

using namespace E3Spice;

MainScreen::MainScreen() : 
    Screen ( "E3Spice" )
{
}

MainScreen::~MainScreen()
{
    SDL_Quit();
}

bool MainScreen::Initialize()
{
    return Screen::Initialize();
}


void MainScreen::HandleEvent(SDL_Event &event)
{
    Screen::HandleEvent(event);
}

void MainScreen::Render()
{
    Screen::Render();
}
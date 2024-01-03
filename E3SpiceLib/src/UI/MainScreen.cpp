#include "UI/MainScreen.h"

using namespace E3Spice;

MainScreen::MainScreen() : 
    Screen ( "E3Spice" )
{
    m_IsMainScreen = true;
}

MainScreen::~MainScreen()
{
    SDL_Quit();
}

bool MainScreen::Initialize(E3Widgets::E3Tk *root)
{
    return Screen::Initialize(root);
}


void MainScreen::HandleEvent(SDL_Event &event)
{
    Screen::HandleEvent(event);
}

void MainScreen::Render()
{
    Screen::Render();
}
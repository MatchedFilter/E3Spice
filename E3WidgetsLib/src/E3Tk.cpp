#include "E3Tk.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "Font/FontManager.h"
#include "Widget/WidgetIdGenerator.h"
#include "Widget/Screen.h"
#include <iostream>

using namespace E3Widgets;


E3Tk::E3Tk() :
    m_ScreenSize { 0 }
{
    m_IsApplicationRunning = true;
}

E3Tk::~E3Tk() { }


bool E3Tk::Initialize()
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

    FontManager::Initialize();
    return true;
}

WidgetID E3Tk::RegisterScreen(Screen *screen)
{
    WidgetID widgetID = WidgetIdGenerator::GetNext();
    m_ScreenMap[widgetID] = screen;
    m_ScreenSize = m_ScreenMap.size();
    return widgetID;
}

bool E3Tk::RemoveScreen(WidgetID widgetID)
{
    if (m_ScreenMap.find(widgetID) != m_ScreenMap.end())
    {
        m_ScreenMap.erase(widgetID);
        m_ScreenSize = m_ScreenMap.size();
        return true;
    }
    return false;
}

void E3Tk::MainLoop()
{
    while (m_IsApplicationRunning)
    {
        SDL_Event event;
        SDL_WaitEventTimeout(&event, 50);
        bool bIsAtleastOneScreenAlive = false;
        for (auto &screenPair : m_ScreenMap)
        {
            Screen *screen = screenPair.second;
            if (screen->GetIsAlive())
            {
                screen->HandleEvent(event);
                screen->Render();
                bIsAtleastOneScreenAlive = true;
            }
            else
            {
                if (screen->IsMainScreen())
                {
                    m_IsApplicationRunning = false;
                }
            }
        }
        if (!bIsAtleastOneScreenAlive)
        {
            m_IsApplicationRunning = false;
        }
    }
}

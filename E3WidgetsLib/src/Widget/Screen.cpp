#include "Widget/Screen.h"
#include "E3Tk.h"
#include <iostream>
#include "SDL2/SDL.h"

using namespace E3Widgets;


Screen::Screen(std::string title) :
    m_Root { nullptr },
    m_IsAlive { false },
    m_Title { title },
    m_Size { DEFAULT_SCREEN_SIZE },
    m_Bg { DEFAULT_SCREEN_BG },
    m_Window { nullptr },
    m_Renderer { nullptr },
    m_ScreenID { 0 },
    m_IsMainScreen { false }
{
}

Screen::~Screen()
{
}

bool Screen::Initialize(E3Tk *root)
{
    m_Root = root;
    m_Window = SDL_CreateWindow(m_Title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Size.width, m_Size.height, SDL_WINDOW_RESIZABLE);
    if (m_Window == nullptr)
    {
        std::cerr << "Failed to create sdl window: " << SDL_GetError() << std::endl;
        return false;
    }
    m_ScreenID = SDL_GetWindowID(m_Window);

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);

    if (m_Renderer == nullptr)
    {
        std::cerr << "Failed to create sdl renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(m_Window);
        return false;
    }
    SDL_SetRenderDrawBlendMode(m_Renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(m_Renderer, m_Bg.r, m_Bg.g, m_Bg.b, m_Bg.a);

    m_IsAlive = true;
    m_WidgetID = root->RegisterScreen(this);
    return true;
}

void Screen::HandleEvent(SDL_Event &event)
{
    PlacableWidget::HandleEvent(event);
    if (event.type == SDL_QUIT)
    {
        m_IsAlive = false;
        return;
    }

    if (event.window.windowID == m_ScreenID)
    {
        switch (event.type)
        {
        case SDL_WINDOWEVENT:
            switch (event.window.event)
            {
            case SDL_WINDOWEVENT_CLOSE:
                m_IsAlive = false;
                SDL_HideWindow(m_Window);
                SDL_DestroyWindow(m_Window);
                break;

            default:
                break;
            }
        default:
            break;
        }
    }
}

void Screen::Render()
{
    SDL_SetRenderDrawColor(m_Renderer, m_Bg.r, m_Bg.g, m_Bg.b, m_Bg.a);
    SDL_RenderClear(m_Renderer);
    PlacableWidget::Render();
    SDL_RenderPresent(m_Renderer);
}

#include "Screen/Screen.h"
#include <iostream>
#include "SDL2/SDL.h"

using namespace E3Widgets;


Screen::Screen(std::string title) :
    m_IsAlive { false },
    m_Title { title },
    m_Size { DEFAULT_SCREEN_SIZE },
    m_Bg { DEFAULT_SCREEN_BG },
    m_Window { nullptr },
    m_Renderer { nullptr },
    m_ID { 0 }
{
}

Screen::~Screen()
{
}

bool Screen::Initialize()
{
    m_Window = SDL_CreateWindow(m_Title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Size.width, m_Size.height, SDL_WINDOW_RESIZABLE);
    if (m_Window == nullptr)
    {
        std::cerr << "Failed to create sdl window: " << SDL_GetError() << std::endl;
        return false;
    }
    m_ID = SDL_GetWindowID(m_Window);

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
    return true;
}


void Screen::HandleEvent(SDL_Event &event)
{
    if (event.type == SDL_QUIT)
    {
        m_IsAlive = false;
        return;
    }

    if (event.window.windowID == m_ID)
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
    // override
}

void Screen::Run()
{
    SDL_Event event;
    if (m_IsAlive)
    {
        SDL_WaitEventTimeout(&event, 50);
        HandleEvent(event);
        
        SDL_SetRenderDrawColor(m_Renderer, m_Bg.r, m_Bg.g, m_Bg.b, m_Bg.a);
        SDL_RenderClear(m_Renderer);
        Render();
        SDL_RenderPresent(m_Renderer);
    }
}

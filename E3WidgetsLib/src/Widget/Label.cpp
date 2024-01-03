#include "Widget/Label.h"
#include "Font/FontManager.h"
#include "SDL2/SDL_ttf.h"

using namespace E3Widgets;

Label::Label(const char *text)
    : m_Text { text },
    m_Font { "Fira Code"},
    m_FontPath { FontManager::GetFont(m_Font.c_str())},
    m_FontSize { 10 },
    m_Texture { nullptr }
{
    m_Size = Size(60, 15);
    m_Bg = Color(0x20, 0x20, 0x25, 255);
    m_Fg = Color(0xA0, 0xCA, 0xA0, 255);
}

Label::~Label()
{
}

bool Label::Initialize(IPlacable *root)
{
    bool bResult = Widget::Initialize(root);
    if (bResult)
    {
        TTF_Font* font = TTF_OpenFont(m_FontPath.c_str(), m_FontSize);
        SDL_Color fg {m_Fg.r, m_Fg.g, m_Fg.b, m_Fg.a};
        SDL_Color bg {m_Bg.r, m_Bg.g, m_Bg.b, m_Bg.a};
        SDL_Surface* textSurface = TTF_RenderUTF8_Shaded(font, m_Text.c_str(), fg, bg);
        m_Texture = SDL_CreateTextureFromSurface(m_Renderer, textSurface);
        SDL_Rect textRect { m_Position.x, m_Position.y, m_Size.width, m_Size.height};
        SDL_RenderCopy(m_Renderer, m_Texture, nullptr, &textRect);
        SDL_FreeSurface(textSurface);
        TTF_CloseFont(font);
    }
    return bResult;
}

void Label::SetFont(const char *font)
{
    m_Font = font;
    m_FontPath = FontManager::GetFont(font);
}


void Label::Render()
{
    SDL_Rect location = SDL_Rect{ m_Position.x, m_Position.y, m_Size.width, m_Size.height};
    SDL_RenderCopy(m_Renderer, m_Texture, nullptr, &location);

}

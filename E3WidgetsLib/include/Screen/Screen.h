#ifndef _E3WIDGETS_SCREEN_H_
#define _E3WIDGETS_SCREEN_H_
#include <string>
#include "E3Constants.h"
#include "SDL2/SDL.h"
namespace E3Widgets
{
    class Screen
    {
    public:
        Screen(std::string title = "E3");
        ~Screen();
        virtual bool Initialize();

    public:
        void SetTitle(const char *title) { m_Title = title; }
        const char * GetTitle() const { return m_Title.c_str();}
        
        void SetSize(Size size) { m_Size = size; }
        Size GetSize() const { return m_Size; }

        void SetBg(Color bg) { m_Bg = bg; }
        Color GetBg() const { return m_Bg; }

        bool GetIsAlive() const { return m_IsAlive; }
        void Destroy() { m_IsAlive = false; }
        
        void Run();

    protected:
        virtual void HandleEvent(SDL_Event &event);
        virtual void Render();

    protected:
        bool m_IsAlive;
        std::string m_Title;
        Size m_Size;
        Color m_Bg;
        SDL_Window *m_Window;
        SDL_Renderer *m_Renderer;
        uint32_t m_ID;
    };
} // namespace E3Widgets

#endif // _E3WIDGETS_SCREEN_H_
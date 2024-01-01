#ifndef _E3SPICE_MAINSCREEN_H_
#define _E3SPICE_MAINSCREEN_H_
#include "Screen/Screen.h"
namespace E3Spice
{
    class MainScreen : public E3Widgets::Screen
    {
    public:
        MainScreen();
        ~MainScreen();
        bool Initialize() override;

    protected:
        virtual void HandleEvent(SDL_Event &event);
        virtual void Render();

    friend class E3SpiceUI;
    
    };
} // namespace E3Spice

#endif // _E3SPICE_MAINSCREEN_H_
#ifndef _E3SPICE_MAINSCREEN_H_
#define _E3SPICE_MAINSCREEN_H_
#include "Widget/Screen.h"
#include "E3Tk.h"
namespace E3Spice
{
    class MainScreen : public E3Widgets::Screen
    {
    public:
        MainScreen();
        ~MainScreen();
        bool Initialize(E3Widgets::E3Tk *root) override;

    protected:
        virtual void HandleEvent(SDL_Event &event) override;
        virtual void Render() override;

    friend class E3SpiceUI;
    
    };
} // namespace E3Spice

#endif // _E3SPICE_MAINSCREEN_H_
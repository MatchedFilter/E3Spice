#ifndef _E3SPICE_E3SPICEUI_H_
#define _E3SPICE_E3SPICEUI_H_
#include "UI/MainScreen.h"
namespace E3Spice
{
    class E3SpiceUI
    {
    public:
        E3SpiceUI();
        ~E3SpiceUI();
        bool Initialize();
        void MainLoop();
    
    private:
        bool m_IsRunning;
        MainScreen m_MainScreen;
        E3Widgets::Screen m_TestScreen;
    };
} // namespace E3Spice

#endif // _E3SPICE_E3SPICEUI_H_
#ifndef _E3WIDGETS_E3TK_H_
#define _E3WIDGETS_E3TK_H_
#include <unordered_map>
#include "Widget/Screen.h"
#include <cinttypes>
namespace E3Widgets
{
    class E3Tk 
    {
    public:
        E3Tk();
        ~E3Tk();
        bool Initialize();
        void MainLoop();

        bool RemoveScreen(WidgetID widgetID);

    private:
        WidgetID RegisterScreen(Screen *screen);
        std::unordered_map<int32_t, Screen*> m_ScreenMap;
        bool m_IsApplicationRunning;
        int32_t m_ScreenSize;

    friend class Screen;
    
    };

} // namespace E3Widgets

#endif // _E3WIDGETS_E3TK_H_
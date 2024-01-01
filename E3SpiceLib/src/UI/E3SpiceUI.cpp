#include "UI/E3SpiceUI.h"
#include "E3Tk.h"

using namespace E3Spice;


E3SpiceUI::E3SpiceUI() :
    m_IsRunning { false },
    m_TestScreen { "Test"}
{
}

E3SpiceUI::~E3SpiceUI()
{
}

bool E3SpiceUI::Initialize()
{
    if (!E3Widgets::E3Tk::InitializeE3())
        return false;
    if (!m_MainScreen.Initialize())
        return false;
        
    m_TestScreen.SetSize(E3Widgets::Size(500, 300));
    if (!m_TestScreen.Initialize())
        return false;
    
    m_IsRunning = true;
    return true;
}

void E3SpiceUI::MainLoop()
{
    while (m_IsRunning)
    {
        if (!m_MainScreen.m_IsAlive)
        {
            m_IsRunning = false;
            m_TestScreen.Destroy();
        }
        else
        {
            m_MainScreen.Run();
            m_TestScreen.Run();
        }
    }
}

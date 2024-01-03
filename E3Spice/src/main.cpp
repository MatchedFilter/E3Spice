#include <iostream>
#include "UI/MainScreen.h"
#include "E3Tk.h"
#include "Widget/Label.h"

int main(int argc, char* argv[])
{
    std::cout << "E3Spice Application" << std::endl;
    E3Widgets::E3Tk win;
    win.Initialize();
    
    E3Spice::MainScreen mainScreen;
    E3Widgets::Screen firstScreen("Screen 1");
    
    mainScreen.Initialize(&win);
    firstScreen.Initialize(&win);

    E3Widgets::Label label("Test Label");
    label.Initialize(&mainScreen);
    
    label.Place(E3Widgets::Position(50, 50));

    win.MainLoop();
    return 0;
}
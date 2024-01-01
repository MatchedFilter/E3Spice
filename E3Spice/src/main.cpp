#include <iostream>
#include "UI/E3SpiceUI.h"

int main(int argc, char* argv[])
{
    std::cout << "E3Spice Application" << std::endl;
    E3Spice::E3SpiceUI spiceUI;
    if (spiceUI.Initialize())
    {
        spiceUI.MainLoop();
    }
    return 0;
}
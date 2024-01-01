#include <iostream>
#include "UI/MainScreen.h"

int main(int argc, char* argv[])
{
    std::cout << "E3Spice Application" << std::endl;
    E3Spice::MainScreen mainScreen;
    mainScreen.Initialize();
    return 0;
}
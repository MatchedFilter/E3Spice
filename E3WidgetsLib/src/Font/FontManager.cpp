#include "Font/FontManager.h"

using namespace E3Widgets;

std::unordered_map<std::string, std::string> FontManager::s_FontMap;

void FontManager::Initialize()
{
    s_FontMap["Fira Code"] = "resources/fonts/Fira_Code/FiraCode-VariableFont_wght.ttf";
}

const char *FontManager::GetFont(const char * fontName)
{
    if (s_FontMap.find(fontName) != s_FontMap.end())
    {
        return s_FontMap[fontName].c_str();
    }
    return fontName;
}

#ifndef _E3WIDGETS_FONTMANAGER_H_
#define _E3WIDGETS_FONTMANAGER_H_
#include <unordered_map>
#include <string>
namespace E3Widgets
{
    class FontManager
    {
    public:
        static void Initialize();
        static const char *GetFont(const char * fontName);

    private:
        static std::unordered_map<std::string, std::string> s_FontMap;

    };
} // namespace E3Widgets

#endif // _E3WIDGETS_FONTMANAGER_H_
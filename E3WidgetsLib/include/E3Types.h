#ifndef _E3WIDGETS_E3TYPES_H_
#define _E3WIDGETS_E3TYPES_H_
#include <cinttypes>
namespace E3Widgets
{
    struct Size
    {
        int32_t width;
        int32_t height;
        Size(int32_t width = 0, int32_t height = 0) : width { width }, height { height } { }
        Size (const Size& other) : width {other.width}, height { other.height } { }
        ~Size() { }
    };

    struct Color
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
        Color(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 0)
            : r { r }, g { g }, b { b }, a { a } { }
        Color (const Color& other) : r { other.r },
            g { other.g }, b { other.b }, a { other.a } { }
        ~Color() { }
    };


} // namespace E3Widgets

#endif // _E3WIDGETS_E3TYPES_H_
#ifndef _E3WIDGETS_E3WIDGETUTILS_H_
#define _E3WIDGETS_E3WIDGETUTILS_H_
#include "E3Types.h"
namespace E3Widgets
{
    class E3WidgetUtils
    {
    public:
        static bool IsOverlapped(const Area &area, const Position &position);
    };
} // namespace E3Widgets

#endif // _E3WIDGETS_E3WIDGETUTILS_H_
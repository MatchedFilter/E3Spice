#ifndef _E3WIDGETS_WIDGETIDGENERATOR_H_
#define _E3WIDGETS_WIDGETIDGENERATOR_H_
#include "IWidget.h"
namespace E3Widgets
{
    class WidgetIdGenerator
    {
    public:
        static WidgetID GetNext() { return ++s_CurrentCount; };

    private:
        static WidgetID s_CurrentCount;
        
    };
} // namespace E3Widgets

#endif // _E3WIDGETS_WIDGETIDGENERATOR_H_
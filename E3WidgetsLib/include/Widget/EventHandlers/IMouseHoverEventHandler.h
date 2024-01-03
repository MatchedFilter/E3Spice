#ifndef _E3WIDGETS_IMOUSEHOVEREVENTHANDLER_H_
#define _E3WIDGETS_IMOUSEHOVEREVENTHANDLER_H_
#include "Widget/IWidget.h"
#include "E3Types.h"
namespace E3Widgets
{
    class IMouseHoverEventHandler
    {
    public:
        virtual ~IMouseHoverEventHandler() { }
        virtual void OnMouseHover(IWidget *widget, const Position &mousePosition) = 0;
    };
} // namespace E3Widgets

#endif // _E3WIDGETS_IMOUSEHOVEREVENTHANDLER_H_
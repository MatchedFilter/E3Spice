#ifndef _E3WIDGETS_IPLACABLE_H_
#define _E3WIDGETS_IPLACABLE_H_
#include "E3Types.h"
#include "SDL2/SDL_render.h"
namespace E3Widgets
{
    class Widget;
    class IPlacable
    {
    public:
        virtual ~IPlacable() {}
        virtual Position GetPosition() const = 0;
        virtual SDL_Renderer *GetSDLRenderer() = 0;

    protected:
        virtual WidgetID RegisterWidget(Widget *widget) = 0;
        friend class Widget;
    };
} // namespace E3Widgets

#endif // _E3WIDGETS_IPLACABLE_H_
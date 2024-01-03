#ifndef _E3WIDGETS_IWIDGET_H_
#define _E3WIDGETS_IWIDGET_H_
#include "SDL2/SDL_events.h"
#include "IPlacable.h"
#include "E3Types.h"
#include <cinttypes>

namespace E3Widgets
{
    class IWidget
    {
    public:
        virtual ~IWidget() { }
        virtual bool Initialize(IPlacable *root) = 0;
        virtual WidgetID GetWidgetID() = 0;

    protected:
        virtual void Render() = 0;
        virtual void HandleEvent(SDL_Event &event) = 0;
    };
} // namespace E3Widgets

#endif // _E3WIDGETS_IWIDGET_H_
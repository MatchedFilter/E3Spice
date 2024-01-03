#ifndef _E3WIDGETS_WIDGET_H_
#define _E3WIDGETS_WIDGET_H_
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_render.h"
#include "E3Types.h"
#include "Widget/IWidget.h"
#include "Widget/EventHandlers/IMouseHoverEventHandler.h"
#include <vector>

namespace E3Widgets
{
    class E3Tk;
    class Widget : public IWidget
    {
    public:
        Widget();
        ~Widget();
        virtual bool Initialize(IPlacable *root) override;
        virtual WidgetID GetWidgetID() override { return m_WidgetID; };
        virtual void Place(Position position);
        void RegisterMouseHoverEventHandler(IMouseHoverEventHandler *mouseHoverEventHandler);

        
    protected:
        virtual void HandleEvent(SDL_Event &event);
    
    protected:
        SDL_Renderer* m_Renderer;
        WidgetID m_WidgetID;
        IPlacable *m_Root;
        Position m_Position;
        Size m_Size;
        Position m_RelativePosition;
        bool m_IsPositioned;
        std::vector<IMouseHoverEventHandler*> m_MouseHoverEventHandlers;

    private:
        Widget(const Widget &other);
        friend class PlacableWidget;
    };

} // namespace E3Widgets

#endif // _E3WIDGETS_WIDGET_H_
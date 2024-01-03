#ifndef _E3WIDGETS_IPLACABLEWIDGET_H_
#define _E3WIDGETS_IPLACABLEWIDGET_H_
#include "Widget/Widget.h"
#include <unordered_map>
namespace E3Widgets
{
    class PlacableWidget : public Widget, public IPlacable
    {
    public:
        PlacableWidget();
        virtual ~PlacableWidget();
        virtual Position GetPosition() const override { return m_Position; }
        virtual SDL_Renderer *GetSDLRenderer() override {return m_Root->GetSDLRenderer();}

    protected:
        virtual WidgetID RegisterWidget(Widget *widget) override;
        virtual void HandleEvent(SDL_Event &event) override;
        virtual void Render() override;

    protected:
        std::unordered_map<WidgetID, Widget*> m_WidgetMap;
    };
} // namespace E3Widgets

#endif // _E3WIDGETS_IPLACABLEWIDGET_H_
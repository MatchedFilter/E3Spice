#include "Widget/PlacableWidget.h"
#include "Widget/WidgetIdGenerator.h"

using namespace E3Widgets;

PlacableWidget::PlacableWidget() { }

PlacableWidget::~PlacableWidget() { }

WidgetID PlacableWidget::RegisterWidget(Widget *widget)
{
    WidgetID widgetID = WidgetIdGenerator::GetNext();
    m_WidgetMap[widgetID] = widget;
    return widgetID;
}

void PlacableWidget::HandleEvent(SDL_Event &event)
{
    for (auto &widgetPair : m_WidgetMap)
    {
        Widget *widget = widgetPair.second;
        if (widget->m_IsPositioned)
        {
            widget->HandleEvent(event);
        }
    }
}

void PlacableWidget::Render()
{
    for (auto &widgetPair : m_WidgetMap)
    {
        Widget *widget = widgetPair.second;
        if (widget->m_IsPositioned)
        {
            widget->Render();
        }
    }
}


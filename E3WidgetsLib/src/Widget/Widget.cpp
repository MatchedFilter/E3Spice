#include "Widget/Widget.h"
#include "Utils/E3WidgetUtils.h"
#include "SDL2/SDL_mouse.h"

using namespace E3Widgets;

Widget::Widget()
    : m_Renderer { nullptr }, 
    m_WidgetID { INVALID_WIDGET_ID },
    m_Root { nullptr },
    m_IsPositioned { false }
{
}

Widget::~Widget()
{
}

bool Widget::Initialize(IPlacable *root)
{
    m_WidgetID = root->RegisterWidget(this);
    m_Root = root;
    m_Renderer = m_Root->GetSDLRenderer();
    return true;
}

void Widget::HandleEvent(SDL_Event &event)
{
    Area widgetArea(m_Position, m_Size);
    Position mousePosition(event.motion.x, event.motion.y);
    if (E3WidgetUtils::IsOverlapped(widgetArea, mousePosition))
    {
        for (IMouseHoverEventHandler *mouseHoverEventHandler : m_MouseHoverEventHandlers)
        {
            mouseHoverEventHandler->OnMouseHover(this, mousePosition);
        }
    }
}

void Widget::Place(Position position)
{
    m_RelativePosition = position;
    m_Position = m_Root->GetPosition() + m_RelativePosition;
    m_IsPositioned = true;
}

void Widget::RegisterMouseHoverEventHandler(IMouseHoverEventHandler *mouseHoverEventHandler)
{
    m_MouseHoverEventHandlers.push_back(mouseHoverEventHandler);
}


Widget::Widget(const Widget &other) { }

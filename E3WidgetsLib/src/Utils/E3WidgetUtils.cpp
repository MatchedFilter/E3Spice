#include "Utils/E3WidgetUtils.h"

using namespace E3Widgets;

bool E3WidgetUtils::IsOverlapped(const Area &area, const Position &position)
{
    if (area.position.x < position.x &&
        area.position.y < position.y &&
        area.position.x + area.size.width > position.x &&
        area.position.y + area.size.height > position.y)
    {
        return true;
    }
    return false;
}

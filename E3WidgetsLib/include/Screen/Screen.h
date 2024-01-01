#ifndef _E3WIDGETS_SCREEN_H_
#define _E3WIDGETS_SCREEN_H_
namespace E3Widgets
{
    class Screen
    {
    public:
        Screen();
        ~Screen();
        virtual void Initialize();
        virtual void Run();
    };
} // namespace E3Widgets

#endif // _E3WIDGETS_SCREEN_H_
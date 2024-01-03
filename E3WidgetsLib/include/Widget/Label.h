#ifndef _E3WIDGETS_LABEL_H_
#define _E3WIDGETS_LABEL_H_
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_rect.h"
#include <string>
#include "Widget/Widget.h"
#include "E3Types.h"
namespace E3Widgets
{
    class Label : public Widget
    {
    public:
        Label(const char *text);
        ~Label();
        virtual bool Initialize(IPlacable *root) override;
        virtual void Render() override;

    public:
        void SetFont(const char *font);
        const char *GetFont() const {return m_Font.c_str(); }
        
        void SetFontSize(int32_t fontSize) { m_FontSize = fontSize; }
        int32_t GetFontSize() const { return m_FontSize; }

        void SetBg(Color bg) { m_Bg = bg;}
        Color GetBg() const { return m_Bg;}

        void SetFg(Color fg) { m_Fg = fg;}
        Color GetFg() const { return m_Fg; }

    protected:
        std::string m_Text;
        std::string m_Font;
        std::string m_FontPath;
        int32_t m_FontSize;
        Color m_Bg;
        Color m_Fg;
        SDL_Texture *m_Texture;

    };
} // namespace E3Widgets

#endif // _E3WIDGETS_LABEL_H_
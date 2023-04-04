#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#include <string>
#include <stdint.h>
#include <iostream>

namespace CG {

    template<class T>
    struct RGBA {
        T r;
        T g;
        T b;
        T a;

        RGBA() : r(0), g(0), b(0), a(0) {}
        RGBA(T r, T g, T b, T a) : r(r), g(g), b(b), a(a) {}
    };
    //  RGBA
    struct Color {
        uint32_t color;

        Color(uint32_t color = 0) : color(color) {}
        Color(uint8_t r, uint8_t g,  uint8_t b, uint8_t a = 0xFF);
        Color(RGBA<uint8_t> col);
        Color(RGBA<float> col);

        bool operator==(const Color& rhs) const noexcept; 
        bool operator!=(const Color& rhs) const noexcept;
        //  Alpha Blending
        Color operator+(const Color& rhs) const noexcept;

        const RGBA<uint8_t> rgba() const
        {
            return RGBA<uint8_t> {
                (uint8_t) ((color >> 8 * 0) & 0xFF), 
                (uint8_t) ((color >> 8 * 1) & 0xFF), 
                (uint8_t) ((color >> 8 * 2) & 0xFF), 
                (uint8_t) ((color >> 8 * 3) & 0xFF)
            }; 
        }
        const RGBA<float> normalized() const
        {
            return RGBA<float> {
                (((color >> 8 * 0) & 0xFF) / 255.0f), 
                (((color >> 8 * 1) & 0xFF) / 255.0f), 
                (((color >> 8 * 2) & 0xFF) / 255.0f), 
                (((color >> 8 * 3) & 0xFF) / 255.0f)
            };
        }
    };
    
    namespace Colors {
        inline const Color black{0xFF000000};
        inline const Color red {0xFF0000FF};
        inline const Color green {0xFF00FF00};
        inline const Color blue {0xFFFF0000};
        inline const Color yellow {0xFF00FFFF};
        inline const Color magenta {0xFF9000FF};
        inline const Color cyan {0xFFFFFF00};
        inline const Color white {0xFFFFFFFF};
        inline const Color darkgrey {0xFF474747};
        inline const Color lightred {0xFF6F6FFF};
        inline const Color lightgreen {0xFF90EE90};
        inline const Color lightyellow {0xFFE0FFFF};
        inline const Color lightblue {0xFFE6D8AD};
        inline const Color lightpurple {255, 85, 255, 255};
        inline const Color turquoise {0xFFC8D530};
        inline const Color lightwhite {0xFFD1D1D1};
    }

    inline const int colors_count = 16;
    inline Color colors[colors_count] = {
        Colors::black,
        Colors::red,
        Colors::green,
        Colors::blue,
        Colors::yellow,
        Colors::magenta,
        Colors::cyan,
        Colors::white,
        Colors::darkgrey,
        Colors::lightred,
        Colors::lightgreen,
        Colors::lightyellow,
        Colors::lightblue,
        Colors::lightpurple,
        Colors::turquoise,
        Colors::lightwhite
    };
}

struct ansi_code {
    static const std::string reset;
    static const std::string hide_cursor;

    static const std::string move_cursor(int up, int left);
    static const std::string background(CG::Color col);
    static const std::string foreground(CG::Color col);
};
#endif // __COLOR_HPP__
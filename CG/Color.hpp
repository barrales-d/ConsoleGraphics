#ifndef __COLOR_CODES_HPP__
#define __COLOR_CODES_HPP__

#include <string>
#include <stdint.h>

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

        static const Color black;
        static const Color red;
        static const Color green;
        static const Color yellow;
        static const Color blue;
        static const Color magenta;
        static const Color cyan;
        static const Color white;
        static const Color darkgrey;
        static const Color lightred;
        static const Color lightgreen;
        static const Color lightyellow;
        static const Color lightblue;
        static const Color lightpurple;
        static const Color turquoise;
        static const Color lightwhite;

        static const int colors_count;
        static Color colors[];
    };
}

struct ansi_code {
    static const std::string reset;
    static const std::string hide_cursor;

    static const std::string move_cursor(int up, int left);
    static const std::string background(CG::Color col);
    static const std::string foreground(CG::Color col);
};
#endif // __COLOR_CODES_HPP__
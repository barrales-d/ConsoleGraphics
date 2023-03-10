#ifndef __COLOR_CODES_HPP__
#define __COLOR_CODES_HPP__

#include <string>

namespace CG {
    //  RGB color Alpha channel ignored
    // 0xBBGGRR
    struct Color {
        uint32_t color;

        Color(uint32_t color = 0) : color((0xFF000000|color)) {}
        Color(uint8_t r, uint8_t g,  uint8_t b);

        const int r() const;
        const int g() const;
        const int b() const;

        bool operator==(const Color& rhs) const noexcept; 
        bool operator!=(const Color& rhs) const noexcept; 

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
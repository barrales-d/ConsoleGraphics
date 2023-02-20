#ifndef __COLOR_CODES_HPP__
#define __COLOR_CODES_HPP__

#include <string>

//  RGB color
struct CG_Color {
    uint32_t color;

    CG_Color(const uint32_t color = 0) : color(color) {}
    CG_Color(const uint8_t r, const uint8_t g, const  uint8_t b);

    const uint8_t r() const;
    const uint8_t g() const;
    const uint8_t b() const;
    const std::string to_ansi_bg() const;
    const std::string to_ansi_fg() const;
    
    bool operator==(const CG_Color& rhs) const noexcept; 
    bool operator!=(const CG_Color& rhs) const noexcept; 

    static const CG_Color black;
    static const CG_Color red;
    static const CG_Color green;
    static const CG_Color yellow;
    static const CG_Color blue;
    static const CG_Color magenta;
    static const CG_Color cyan;
    static const CG_Color white;
    static const CG_Color darkgrey;
    static const CG_Color lightred;
    static const CG_Color lightgreen;
    static const CG_Color lightyellow;
    static const CG_Color lightblue;
    static const CG_Color lightpurple;
    static const CG_Color turquoise;
    static const CG_Color lightwhite;
    
   static const int colors_count;
   static CG_Color colors[];
};

struct ANSICodes {
   static std::string Reset;
};
#endif // __COLOR_CODES_HPP__
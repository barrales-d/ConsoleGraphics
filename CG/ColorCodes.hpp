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
};

struct ColorCodes {
   static std::string Reset;

   static std::string fg_Black;
   static std::string fg_Red;
   static std::string fg_Green;
   static std::string fg_Yellow;
   static std::string fg_Blue;
   static std::string fg_Magenta;
   static std::string fg_Cyan;
   static std::string fg_White;

   static std::string bg_Black;
   static std::string bg_Red;
   static std::string bg_Green;
   static std::string bg_Yellow;
   static std::string bg_Blue;
   static std::string bg_Magenta;
   static std::string bg_Cyan;
   static std::string bg_White;

   static std::string fg_DarkGrey;
   static std::string fg_LightRed;
   static std::string fg_LightGreen;
   static std::string fg_LightYellow;
   static std::string fg_LightBlue;
   static std::string fg_LightPurple;
   static std::string fg_Turquoise;
   static std::string fg_LightWhite;

   static std::string bg_DarkGrey;
   static std::string bg_LightRed;
   static std::string bg_LightGreen;
   static std::string bg_LightYellow;
   static std::string bg_LightBlue;
   static std::string bg_LightPurple;
   static std::string bg_Turquoise;
   static std::string bg_LightWhite;
};

static std::string CG_background_colors[] = {
    ColorCodes::bg_Black,      ColorCodes::bg_White,
    ColorCodes::bg_Green,      ColorCodes::bg_Yellow,
    ColorCodes::bg_Blue,       ColorCodes::bg_Magenta,
    ColorCodes::bg_Cyan,       ColorCodes::bg_Red,
    ColorCodes::bg_DarkGrey,   ColorCodes::bg_LightRed,
    ColorCodes::bg_LightGreen, ColorCodes::bg_LightYellow,
    ColorCodes::bg_LightBlue,  ColorCodes::bg_LightPurple,
    ColorCodes::bg_Turquoise,  ColorCodes::bg_LightWhite
};

const int CG_bg_count = sizeof(CG_background_colors) / sizeof(CG_background_colors[0]);

static std::string CG_foreground_colors[] = {
    ColorCodes::fg_Black,      ColorCodes::fg_White,
    ColorCodes::fg_Green,      ColorCodes::fg_Yellow,
    ColorCodes::fg_Blue,       ColorCodes::fg_Magenta,
    ColorCodes::fg_Cyan,       ColorCodes::fg_Red,
    ColorCodes::fg_DarkGrey,   ColorCodes::fg_LightRed,
    ColorCodes::fg_LightGreen, ColorCodes::fg_LightYellow,
    ColorCodes::fg_LightBlue,  ColorCodes::fg_LightPurple,
    ColorCodes::fg_Turquoise,  ColorCodes::fg_LightWhite
};

const int CG_fg_count = sizeof(CG_foreground_colors) / sizeof(CG_foreground_colors[0]);

#endif // __COLOR_CODES_HPP__
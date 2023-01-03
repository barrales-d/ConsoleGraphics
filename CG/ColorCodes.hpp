#ifndef __COLOR_CODES_HPP__
#define __COLOR_CODES_HPP__

#include <string>

//  References: 
//  - https://www.2daygeek.com/understanding-the-color-code-of-linux-files/

static struct ColorCodes {
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

const std::string CG_BACK_COLORS[] = {
    ColorCodes::bg_Black,      ColorCodes::bg_White,
    ColorCodes::bg_Green,      ColorCodes::bg_Yellow,
    ColorCodes::bg_Blue,       ColorCodes::bg_Magenta,
    ColorCodes::bg_Cyan,       ColorCodes::bg_Red,
    ColorCodes::bg_DarkGrey,   ColorCodes::bg_LightRed,
    ColorCodes::bg_LightGreen, ColorCodes::bg_LightYellow,
    ColorCodes::bg_LightBlue,  ColorCodes::bg_LightPurple,
    ColorCodes::bg_Turquoise,  ColorCodes::bg_LightWhite
};

const int CG_BACK_COLORS_SIZE = sizeof(CG_BACK_COLORS) / sizeof(CG_BACK_COLORS[0]);

const std::string CG_FORE_COLORS[] = {
    ColorCodes::fg_Black,      ColorCodes::fg_White,
    ColorCodes::fg_Green,      ColorCodes::fg_Yellow,
    ColorCodes::fg_Blue,       ColorCodes::fg_Magenta,
    ColorCodes::fg_Cyan,       ColorCodes::fg_Red,
    ColorCodes::fg_DarkGrey,   ColorCodes::fg_LightRed,
    ColorCodes::fg_LightGreen, ColorCodes::fg_LightYellow,
    ColorCodes::fg_LightBlue,  ColorCodes::fg_LightPurple,
    ColorCodes::fg_Turquoise,  ColorCodes::fg_LightWhite
};

const int CG_FORE_COLORS_SIZE = sizeof(CG_FORE_COLORS) / sizeof(CG_FORE_COLORS[0]);

#endif // __COLOR_CODES_HPP__
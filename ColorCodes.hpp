#ifndef __COLOR_CODES_HPP__
#define __COLOR_CODES_HPP__

#include <string>

//  References: 
//  - https://www.2daygeek.com/understanding-the-color-code-of-linux-files/

static struct ColorCodes {
   static std::string Reset;

   static std::string fg_Black  ;
   static std::string fg_Red    ;
   static std::string fg_Green  ;
   static std::string fg_Yellow ;
   static std::string fg_Blue   ;
   static std::string fg_Magenta;
   static std::string fg_Cyan   ;
   static std::string fg_White  ;

   static std::string bg_Black  ;
   static std::string bg_Red    ;
   static std::string bg_Green  ;
   static std::string bg_Yellow ;
   static std::string bg_Blue   ;
   static std::string bg_Magenta;
   static std::string bg_Cyan   ;
   static std::string bg_White  ;

   static std::string fg_DarkGrey    ;
   static std::string fg_LightRed    ;
   static std::string fg_LightGreen  ;
   static std::string fg_LightYellow ;
   static std::string fg_LightBlue   ;
   static std::string fg_LightPurple ;
   static std::string fg_Turquoise   ;
   static std::string fg_LightWhite  ;

   static std::string bg_DarkGrey    ;
   static std::string bg_LightRed    ;
   static std::string bg_LightGreen  ;
   static std::string bg_LightYellow ;
   static std::string bg_LightBlue   ;
   static std::string bg_LightPurple ;
   static std::string bg_Turquoise   ;
   static std::string bg_LightWhite  ;
}; 
#endif // __COLOR_CODES_HPP__
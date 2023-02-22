#ifndef __COLOR_CODES_HPP__
#define __COLOR_CODES_HPP__

#include <string>

namespace CG {
   //  RGB color
   struct Color {
      uint32_t color;

      Color(const uint32_t color = 0) : color(color) {}
      Color(const uint8_t r, const uint8_t g, const  uint8_t b);

      const uint8_t r() const;
      const uint8_t g() const;
      const uint8_t b() const;

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
   static std::string reset;
   static std::string hide_cursor;

   static std::string move_cursor(int up, int left);
   static std::string background(const CG::Color& col);
   static std::string foreground(const CG::Color& col);
};
#endif // __COLOR_CODES_HPP__
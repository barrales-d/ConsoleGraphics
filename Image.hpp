#ifndef __IMAGE_HPP__
#define __IMAGE_HPP__

#include "Colors/ColorCodes.hpp"


#define DEFAULT_FILL ' '

class Pixel {
public: 
  std::string color;
  char fill;

  Pixel() = default;
  ~Pixel() = default;
};


class Image {
  int m_width;
  int m_max_width;
  int m_height;
  Pixel *m_pixels;

  void swap(int &a, int &b);
  void sort_by_x(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3);
public:
  Image(int width, int height);
  ~Image(); 

  void fill_background(const std::string &bgcolor = ColorCodes::bg_DarkGrey);

  void show();

  void fill_rect(int x, int y, int wd, int ht, const std::string &color);
  void fill_circle(int x, int y, int r, const std::string &color);
  void draw_line(int x1, int y1, int x2, int y2, std::string &color);

  void fill_triangle(int x1, int y1, int x2, int y2, int x3, int y3, const std::string&color);
};

#endif //  __IMAGE_HPP__
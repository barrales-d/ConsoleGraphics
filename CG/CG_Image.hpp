#ifndef __CG_Image_HPP__
#define __CG_Image_HPP__

#include "ColorCodes.hpp"


#define DEFAULT_FILL ' '
#define CIRCLE_SCALER 3
#define SQUARE_SCALER 2

class Pixel {
public: 
  std::string color;
  char fill;

  Pixel() = default;
  ~Pixel() = default;
};//  Pixel


class CG_Image {
  int m_width;
  int m_max_width;
  int m_height;
  Pixel *m_pixels;

  void swap(int &a, int &b);
  void sort_by_x(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3);
public:
  CG_Image(int width, int height);
  ~CG_Image(); 

  void fill_background(const std::string &bgcolor = ColorCodes::bg_DarkGrey);

  void show();

  void fill_rect(int x, int y, int wd, int ht, const std::string &color);
  void fill_circle(int x, int y, int r, const std::string &color);
  void draw_line(int x1, int y1, int x2, int y2, std::string &color);

  void fill_triangle(int x1, int y1, int x2, int y2, int x3, int y3, const std::string&color);
};//  CG_Image

#endif //  __CG_Image_HPP__
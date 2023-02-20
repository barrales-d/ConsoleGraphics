#ifndef __CG_Image_HPP__
#define __CG_Image_HPP__

#include "ColorCodes.hpp"


#define DEFAULT_FILL "  "
#define WIDTH_SCALER 2 

class CG_Pixel {
public: 
  CG_Color fg_color;
  CG_Color bg_color;
  std::string fill;

  CG_Pixel() = default;
  ~CG_Pixel() = default;
  bool operator==(const CG_Pixel& rhs) const noexcept; 
  bool operator!=(const CG_Pixel& rhs) const noexcept; 
};//  CG_Pixel


class CG_Image {
protected:
  int m_width;
  int m_height;
  CG_Pixel *m_pixels;

  void swap(int &a, int &b);
  void sort_by_x(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3);
public:
  CG_Image(const int width, const int height);
  ~CG_Image(); 

  void fill_background(const CG_Color &bg_color = CG_Color::darkgrey);

  void show();

  void fill_point(int x, int y, const CG_Color &bg_color);
  void fill_rect(int x, int y, int wd, int ht, const CG_Color &bg_color);
  void fill_circle(int x, int y, int r, const CG_Color &bg_color);
  void fill_triangle(int x1, int y1, int x2, int y2, int x3, int y3, const CG_Color &bg_color);

  void draw_line(int x1, int y1, int x2, int y2, const CG_Color &bg_color);
  void draw_text(int x, int y, const std::string &text, const CG_Color &fg_color);
  void draw_text(int x, int y, const std::string &text, const CG_Color &fg_color, const CG_Color &bg_color);
// 
  static CG_Image combine_image(const CG_Image& img1, const CG_Image& img2);
  friend class TestCase;
};//  CG_Image

#endif //  __CG_Image_HPP__
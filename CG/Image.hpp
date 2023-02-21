#ifndef __Image_HPP__
#define __Image_HPP__

#include "./Color.hpp"

#define DEFAULT_FILL "  "
#define WIDTH_SCALER 2 

namespace CG {

  class Pixel {
  public: 
    Color fg_color;
    Color bg_color;
    std::string fill;

    Pixel() = default;
    ~Pixel() = default;
    bool operator==(const Pixel& rhs) const noexcept; 
    bool operator!=(const Pixel& rhs) const noexcept; 
  };//  Pixel


  class Image {
  protected:
    int m_width;
    int m_height;
    Pixel *m_pixels;

    void swap(int &a, int &b);
    void sort_by_x(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3);
  public:
    Image(const int width, const int height);
    ~Image(); 

    void fill_background(const Color &bg_color = Color::darkgrey);

    void show();

    void fill_point(int x, int y, const Color &bg_color);
    void fill_rect(int x, int y, int wd, int ht, const Color &bg_color);
    void fill_circle(int x, int y, int r, const Color &bg_color);
    void fill_triangle(int x1, int y1, int x2, int y2, int x3, int y3, const Color &bg_color);

    void draw_line(int x1, int y1, int x2, int y2, const Color &bg_color);
    void draw_text(int x, int y, const std::string &text, const Color &fg_color);
    void draw_text(int x, int y, const std::string &text, const Color &fg_color, const Color &bg_color);
  // 
    static Image combine_image(const Image& img1, const Image& img2);
    friend class TestCase;
  };//  Image
}
#endif //  __Image_HPP__
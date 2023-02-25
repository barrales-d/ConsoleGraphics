#ifndef __Image_HPP__
#define __Image_HPP__

#include "./Color.hpp"

#define DEFAULT_FILL "  "
#define WIDTH_SCALER 2 

//  forward delaration to not have testcase in CG namespace
class TESTCASE;


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
    Image();
    Image(const int width, const int height);
    Image(const CG::Image& img);
    Image operator=(const CG::Image& img);
    ~Image(); 
    // | returns screen width = m_width * WIDTH_SCALER | pixel width = get_width() / WIDTH_SCALER |
    int get_width() const { return m_width * WIDTH_SCALER; }
    // | returns screen height = m_height + 1(because of '\n' in CG::Image::show()) | pixel height = get_height() - 1 |
    int get_height() const { return m_height + 1; }

    void fill_background(const Color &bg_color = Color::darkgrey);

    void show();

    void fill_point(int x, int y, const Color &bg_color);
    void fill_rect(int x, int y, int wd, int ht, const Color &bg_color);
    void fill_circle(int x, int y, int r, const Color &bg_color);
    void fill_triangle(int x1, int y1, int x2, int y2, int x3, int y3, const Color &bg_color);

    void draw_line(int x1, int y1, int x2, int y2, const Color &bg_color);
    void draw_text(int x, int y, const std::string &text, const Color &fg_color);
    void draw_text(int x, int y, const std::string &text, const Color &fg_color, const Color &bg_color);
  
    static Image combine_image(const Image& img1, const Image& img2, const Color &sep = Color::darkgrey);
    friend TESTCASE;
  };//  Image
}
#endif //  __Image_HPP__
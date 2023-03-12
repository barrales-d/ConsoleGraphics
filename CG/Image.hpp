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
        Image(int width, int height);
        Image(const Color *pixels, int width, int height);
        Image(const uint32_t *pixels, int width, int height);

        Image(const CG::Image& img);
        Image operator=(const CG::Image& img);

        ~Image();

        //  | returns screen width = m_width * WIDTH_SCALER | pixel width = get_width() / WIDTH_SCALER |
        int get_width() const { return m_width * WIDTH_SCALER; }
        //  | returns screen height = m_height + 1(because of '\n' in CG::Image::show()) | pixel height = get_height() - 1 |
        int get_height() const { return m_height + 1; }
        //  | you pass in the pointer where you want to store the pixels; you call new uint32_t[] outside this function
        //  | you deal with deleting the pixels when you want
        //  TODO: we know m_width and m_height return an array instead of passing a point into this 
        void get_uint32_pixels(uint32_t* pixels, int scale = 1) const; 

        void show();
        int save_image(const std::string& file_name, int scale = 1);

        void fill_background(Color bg_color = Color::darkgrey);
        void fill_point(int x, int y, Color bg_color);
        void fill_rect(int x, int y, int wd, int ht, Color bg_color);
        void fill_circle(int x, int y, int r, Color bg_color);
        void fill_triangle(int x1, int y1, int x2, int y2, int x3, int y3, Color bg_color);

        void draw_line(int x1, int y1, int x2, int y2, Color bg_color);
        void draw_text(int x, int y, const std::string &text, Color bg_color);

        void write_ascii(int x, int y, const std::string &text, Color fg_color, Color bg_color = CG::Color(1));

        static Image combine_image(const Image& img1, const Image& img2, Color sep = Color::darkgrey);
        friend TESTCASE;
    };//  Image
}
#endif //  __Image_HPP__
#include "./Image.hpp"

#include <iostream>
#include <unistd.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../Others/stb_image_write.h"

bool CG::Pixel::operator==(const CG::Pixel &rhs) const noexcept {
  if (this->bg_color == rhs.bg_color && this->fg_color == rhs.fg_color 
      && this->fill == rhs.fill) {
    return true;
  }
  return false;
}
bool CG::Pixel::operator!=(const CG::Pixel &rhs) const noexcept {
  return !(*this == rhs);
}

CG::Image::Image() {
  this->m_width = 0;
  this->m_height = 0;
  this->m_pixels = nullptr;
}
CG::Image::Image(const int width, const int height) {
  this->m_width = width;
  this->m_height = height;
  this->m_pixels = new CG::Pixel[m_width * m_height];

  this->fill_background();
}
CG::Image::Image(const CG::Image& img) {
  this->m_width  =  img.m_width;
  this->m_height =  img.m_height;
  this->m_pixels = new CG::Pixel[m_width * m_height];
  for (int y = 0; y < m_height; y++) {
    for (int x = 0; x < m_width; x++) {
      this->m_pixels[y * m_width + x] = img.m_pixels[y * m_width + x]; 
    }
  }
}
CG::Image::Image(CG::Color *pixels, const int width, const int height) {
  this->m_width  =  width;
  this->m_height =  height;
  this->m_pixels = new CG::Pixel[m_width * m_height];
  for (int y = 0; y < m_height; y++) {
    for (int x = 0; x < m_width; x++) {
      CG::Pixel p;
      p.fill = DEFAULT_FILL;
      p.bg_color = pixels[y * m_width + x];
      p.fg_color = CG::Color::white;
      this->m_pixels[y * m_width + x] = p; 
    }
  }
}
CG::Image::Image(const uint32_t *pixels, const int width, const int height) {
  this->m_width  =  width;
  this->m_height =  height;
  this->m_pixels = new CG::Pixel[m_width * m_height];
  for (int y = 0; y < m_height; y++) {
    for (int x = 0; x < m_width; x++) {
      CG::Pixel p;
      p.fill = DEFAULT_FILL;
      p.bg_color = CG::Color(pixels[y * m_width + x]);
      p.fg_color = CG::Color::white;
      this->m_pixels[y * m_width + x] = p; 
    }
  }
}

CG::Image CG::Image::operator=(const CG::Image& img) {
  this->m_width  =  img.m_width;
  this->m_height =  img.m_height;
  this->m_pixels = new CG::Pixel[m_width * m_height];
  for (int y = 0; y < m_height; y++) {
    for (int x = 0; x < m_width; x++) {
      this->m_pixels[y * m_width + x] = img.m_pixels[y * m_width + x]; 
    }
  }
  return *this;
}

CG::Image::~Image() { delete[] this->m_pixels; }

void CG::Image::swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void CG::Image::sort_by_x(int &x1, int &y1,
                         int &x2, int &y2, 
                         int &x3, int &y3) {
  if (x1 > x2) {
    swap(x1, x2);
    swap(y1, y2);
  }
  if (x2 > x3) {
    swap(x2, x3);
    swap(y2, y3);
  }
  if (x1 > x2) {
    swap(x1, x2);
    swap(y1, y2);
  }
}

void CG::Image::fill_background(const CG::Color &bg_color) {
  for (int y = 0; y < m_height; y++) {
    for (int x = 0; x < m_width; x++) {
      CG::Pixel *pixel = &this->m_pixels[y * m_width + x];
      pixel->fill = DEFAULT_FILL;
      pixel->bg_color = bg_color;
      pixel->fg_color = CG::Color::white;
    }
  }
}

void CG::Image::show() {
  for (int y = 0; y < m_height; y++) {
    for (int x = 0; x < m_width; x++) {
      CG::Pixel *pixel = &this->m_pixels[y * m_width + x];
      std::cout << ansi_code::foreground(pixel->fg_color);
      std::cout << ansi_code::background(pixel->bg_color);
      std::cout << pixel->fill;
    }
    std::cout << std::flush << ansi_code::reset;
    std::cout << "\r\n";
  }
  std::cout << ansi_code::reset << std::endl;
}

void CG::Image::fill_point(int x, int y, const CG::Color &bg_color) {
  if (y >= 0 && y < m_height) {
    if (x >= 0 && x < m_width) {
      this->m_pixels[y * m_width + x].bg_color = bg_color; 
    }
  }
}
int CG::Image::save_image(const std::string& file_name) {
  uint32_t *pixels = new uint32_t[m_width * m_height];
  this->get_uint32_pixels(pixels);

  int err = stbi_write_png(file_name.c_str(), m_width, m_height, 4, pixels, m_width*sizeof(uint32_t));
  if(err == 0) {
    std::cout << "\nstbi_write_png() failed\n";
  }
  return err;
}

void CG::Image::fill_rect(int x, int y, int wd, int ht,
                         const CG::Color &bg_color) {
  for (int cur_y = y; cur_y < (ht + y); cur_y++) {
    for (int cur_x = x; cur_x < (wd + x); cur_x++) {
      this->fill_point(cur_x, cur_y, bg_color);
    }
  }
}

void CG::Image::fill_circle(int x, int y, int r, const CG::Color &bg_color) {
  float max_x = x + r + 0.5f;
  float min_x = x - r + 0.5f;
  float max_y = y + r + 0.5f;
  float min_y = y - r + 0.5f;

  float r_sqr = (r + 0.5f) * (r + 0.5f);

  for (int y1 = min_y; y1 <= max_y; y1++) {
    for (int x1 = min_x; x1 <= max_x; x1++) {
      if ((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) <= r_sqr - 0.5f) {
        this->fill_point(y1, x1, bg_color);
      }
    }
  }
}

void CG::Image::draw_line(int x1, int y1,
                         int x2, int y2, const CG::Color &bg_color) {
  int dx = x2 - x1;
  if (dx != 0) {
    float slope = (float)(y2 - y1) / (float)(dx);
    float intercept = y1 - slope * x1;
    if (x1 > x2)
      swap(x1, x2);
    for (int x = x1; x < x2; x++) {
      int y = x * slope + intercept;
      //  check for case when line is to vertical to render one pixel
        if(abs(slope) > 1) {
          for (int yn = y; yn < y + 3; yn++) {
            this->fill_point(x, yn, bg_color);
          }
        } else {
          this->fill_point(x, y, bg_color);
        }

    }
  } else {
    int x = x1;
    if (y1 > y2)
      swap(y1, y2);
    for (int y = y1; y < y2; y++) {
        this->fill_point(x, y, bg_color);
    }
  }
}

void CG::Image::fill_triangle(int x1, int y1,
                              int x2, int y2,
                              int x3, int y3, const CG::Color &bg_color) {
  sort_by_x(x1, y1, x2, y2, x3, y3);

  //  slope and intercept for x1, y1 -> x2, y2
  float m_1 = (x2 - x1 != 0) ? (float)(y2 - y1) / (float)(x2 - x1) : 0;
  float b_1 = (float)y1 - m_1 * (float)x1;

  // slope and intercept for x1, y1 -> x3, y3
  float m_2 = (x3 - x1 != 0) ? (float)(y3 - y1) / (float)(x3 - x1) : 0;
  float b_2 = (float)y1 - m_2 * (float)x1;
  //  left half of the triangle
  for (int x = x1; x < x2; x++) {
    int y_start = x * m_1 + b_1;
    int y_end = x * m_2 + b_2;
    if (y_start > y_end) {
      swap(y_start, y_end);
    }
    for (int y = y_start; y <= y_end; y++) {
      this->fill_point(x, y, bg_color);
    }
  }
  //  right half of the triangle
  //  slope and intercept for x3, y3 -> x2, y2
  float m_3 = (x3 - x2 != 0) ? (float)(y3 - y2) / (float)(x3 - x2) : 0;
  float b_3 = (float)y2 - m_3 * (float)x2;
  for (int x = x2; x <= x3; x++) {
    int y_start = (float)x * m_3 + b_3;
    int y_end = (float)x * m_2 + b_2;

    if (y_start > y_end) {
      swap(y_start, y_end);
    }
    for (int y = y_start; y <= y_end; y++) {
      this->fill_point(x, y, bg_color);
    }
  }
}

void CG::Image::draw_text(int x, int y, const std::string &text,
                         const CG::Color &fg_color) {
  if (y < 0 || y > m_height) { return; }
  for (int ti = 0; ti < (int) text.size(); ti++) {
    int pos_x = ti + x;
    if (pos_x >= 0 && pos_x < m_width) {
      CG::Pixel *pixel = &this->m_pixels[y * m_width + pos_x];
      pixel->fg_color = fg_color;
      pixel->fill = text[ti];
      pixel->fill.append(" ");
    }
  }
}
void CG::Image::draw_text(int x, int y, const std::string &text,
                         const CG::Color &fg_color,
                         const CG::Color &bg_color) {
  if (y < 0 || y > m_height) { return; }
  for (int ti = 0; ti < (int) text.size(); ti++) {
    int pos_x = ti + x;
    if (pos_x >= 0 && pos_x < m_width) {
      CG::Pixel *pixel = &this->m_pixels[y * m_width + pos_x];
      pixel->fg_color = fg_color;
      pixel->bg_color = bg_color;
      pixel->fill = text[ti];
      pixel->fill.append(" ");
    }
  }
}
CG::Image CG::Image::combine_image(const CG::Image &img1, const CG::Image &img2, const CG::Color& sep) {
  int new_width = img1.m_width + img2.m_width + 1;
  CG::Image result(new_width, img1.m_height);
  for (int y = 0; y < result.m_height; y++) {
    for (int x = 0; x < result.m_width; x++) {
      if (x < img1.m_width) {
        result.m_pixels[y * result.m_width + x] =
            img1.m_pixels[y * img1.m_width + x];
      } else if (x == img1.m_width) {
        result.m_pixels[y * result.m_width + x].bg_color = sep;
      } else {
        result.m_pixels[y * result.m_width + x] =
            img2.m_pixels[y * img2.m_width + (x - (img1.m_width + 1))];
      }
    }
  }
  return result;
}

void CG::Image::get_uint32_pixels(uint32_t* pixels) const {
  for (int y = 0; y < m_height; y++) {
    for (int x = 0; x < m_width; x++) {
      pixels[y * m_width + x] = m_pixels[y * m_width + x].bg_color.color;
    }
  }
}

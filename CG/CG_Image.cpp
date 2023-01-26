#include "CG_Image.hpp"

#include <iostream>
#include <unistd.h>

bool CG_Pixel::operator==(const CG_Pixel &rhs) const noexcept {
  if (this->color == rhs.color && this->fg_color == rhs.fg_color &&
      this->fill == rhs.fill) {
    return true;
  }
  return false;
}
bool CG_Pixel::operator!=(const CG_Pixel &rhs) const noexcept {
  return !(*this == rhs);
}

CG_Image::CG_Image(const int width, const int height) {
  this->m_width = width * WIDTH_SCALER;
  this->m_height = height;
  this->m_pixels = new CG_Pixel[m_width * m_height];

  this->fill_background();
}

CG_Image::~CG_Image() { delete[] this->m_pixels; }

void CG_Image::swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void CG_Image::sort_by_x(int &x1, int &y1,
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

void CG_Image::fill_background(const std::string &bgcolor) {
  for (int y = 0; y < m_height; y++) {
    for (int x = 0; x < m_width; x++) {
      CG_Pixel *pixel = &this->m_pixels[y * m_width + x];
      pixel->fill = DEFAULT_FILL;
      pixel->color = bgcolor;
      pixel->fg_color = ColorCodes::fg_White;
    }
  }
}

void CG_Image::show() {
  for (int y = 0; y < m_height; y++) {
    for (int x = 0; x < m_width; x++) {
      CG_Pixel *pixel = &this->m_pixels[y * m_width + x];
      std::cout << pixel->fg_color;
      std::cout << pixel->color;
      std::cout << pixel->fill;
    }
    std::cout << std::flush << ColorCodes::Reset;
    std::cout << "\r\n";
  }
  std::cout << ColorCodes::Reset << std::endl;
  // move cursor to (0, 0) to animate: std::printf("\x1b[%dD\x1b[%dA", m_height,
  // m_width);
}

void CG_Image::fill_rect(int x, int y, int wd, int ht,
                         const std::string &color) {
  x *= WIDTH_SCALER;
  for (int cur_y = y; cur_y < (ht + y); cur_y++) {
    if (cur_y >= 0 && cur_y < m_height) {
      for (int curr_x = x; curr_x < (wd * WIDTH_SCALER + x); curr_x++) {
        if (curr_x >= 0 && curr_x < m_width) {
          this->m_pixels[cur_y * m_width + curr_x].color = color;
        }
      }
    }
  }
}

void CG_Image::fill_circle(int x, int y, int r, const std::string &color) {
  x *= WIDTH_SCALER;
  int max_x = x + r;
  int min_x = x - r;
  int max_y = y + r;
  int min_y = y - r;

  int r_sqr = r * r;

  for (int y1 = min_y; y1 <= max_y; y1++) {
    if (y1 >= 0 && y1 < m_height) {
      for (int x1 = min_x; x1 <= max_x; x1++) {
        if (x1 >= 0 && x1 < m_width) {
          if ((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) * CIRCLE_SCALER <= r_sqr) {
            this->m_pixels[y1 * m_width + x1].color = color;
          }
        }
      }
    }
  }
}
void CG_Image::draw_line(int x1, int y1,
                         int x2, int y2, std::string &color) {
  int dx = x2 - x1;
  if (dx != 0) {
    float slope = (float)(y2 - y1) / (float)(dx);
    float intercept = y1 - slope * x1;
    if (x1 > x2)
      swap(x1, x2);
    for (int x = x1; x <= x2; x++) {
      if (x >= 0 && x < m_width) {
        int y = x * slope + intercept;
        if (y >= 0 && y < m_height) {
          this->fill_point(x, y, color);
        }
      }
    }
  } else {
    int x = x1;
    if (x >= 0 && x < m_width) {
      if (y1 > y2)
        swap(y1, y2);
      for (int y = y1; y < y2; y++) {
        if (y >= 0 && y < m_height) {
          this->fill_point(x, y, color);
        }
      }
    }
  }
}

void CG_Image::fill_triangle(int x1, int y1,
                             int x2, int y2,
                             int x3, int y3, const std::string &color) {
  x1 *= WIDTH_SCALER;
  x2 *= WIDTH_SCALER;
  x3 *= WIDTH_SCALER;
  sort_by_x(x1, y1, x2, y2, x3, y3);

  //  slope and intercept for x1, y1 -> x2, y2
  float m_1 = (x2 - x1 != 0) ? (float)(y2 - y1) / (float)(x2 - x1) : 0;
  float b_1 = y1 - m_1 * x1;
  // slope and intercept for x1, y1 -> x3, y3
  float m_2 = (x3 - x1 != 0) ? (float)(y3 - y1) / (float)(x3 - x1) : 0;
  float b_2 = y1 - m_2 * x1;
  //  left half of the triangle
  for (int x = x1; x <= x2; x++) {
    if (x >= 0 && x < m_width) {
      int y_start = x * m_1 + b_1;
      int y_end = x * m_2 + b_2;
      if (y_start > y_end) {
        swap(y_start, y_end);
      }
      for (int y = y_start; y <= y_end; y++) {
        if (y >= 0 && y < m_height) {
          this->m_pixels[y * m_width + x].color = color;
        }
      }
    }
  }
  //  right half of the triangle
  //  slope and intercept for x3, y3 -> x2, y2
  m_1 = (x3 - x2 != 0) ? (float)(y3 - y2) / (float)(x3 - x2) : 0;
  b_1 = y2 - m_1 * x2;
  for (int x = x2; x <= x3; x++) {
    if (x >= 0 && x < m_width) {
      int y_start = x * m_1 + b_1;
      int y_end = x * m_2 + b_2;
      if (y_start > y_end) {
        swap(y_start, y_end);
      }
      for (int y = y_start; y <= y_end; y++) {
        if (y >= 0 && y < m_height) {
          this->m_pixels[y * m_width + x].color = color;
        }
      }
    }
  }
}

void CG_Image::fill_point(int x, int y, const std::string &color) {
  this->fill_rect(x, y, 1, 1, color);
}

void CG_Image::draw_text(int x, int y, const std::string &text,
                         const std::string &fg_color) {
  x *= WIDTH_SCALER;
  if (y >= 0 && y < m_height) {
    for (int ti = 0; ti < (int) text.size(); ti++) {
      int pos_x = ti + x;
      if (pos_x >= 0 && pos_x < m_width) {
        CG_Pixel *pixel = &this->m_pixels[y * m_width + pos_x];
        pixel->fg_color = fg_color;
        pixel->fill = text[ti];
      }
    }
  }
}
void CG_Image::draw_text(int x, int y, const std::string &text,
                         const std::string &fg_color,
                         const std::string &bg_color) {
  x *= WIDTH_SCALER;
  if (y >= 0 && y < m_height) {
    for (int ti = 0; ti < (int) text.size(); ti++) {
      int pos_x = ti + x;
      if (pos_x >= 0 && pos_x < m_width) {
        CG_Pixel *pixel = &this->m_pixels[y * m_width + pos_x];
        pixel->fg_color = fg_color;
        pixel->color = bg_color;
        pixel->fill = text[ti];
      }
    }
  }
}
CG_Image CG_Image::combine_image(const CG_Image &img1, const CG_Image &img2) {
  int new_width = (img1.m_width + img2.m_width) / 2 + 1;
  CG_Image result(new_width, img1.m_height);
  for (int y = 0; y < result.m_height; y++) {
    for (int x = 0; x < result.m_width; x++) {
      if (x < img1.m_width) {
        result.m_pixels[y * result.m_width + x] =
            img1.m_pixels[y * img1.m_width + x];
      } else if (x == img1.m_width || x == img1.m_width + 1) {
        result.m_pixels[y * result.m_width + x].color = ColorCodes::Reset;
      } else {
        result.m_pixels[y * result.m_width + x] =
            img2.m_pixels[y * img2.m_width + (x - (img1.m_width + 2))];
      }
    }
  }
  return result;
}

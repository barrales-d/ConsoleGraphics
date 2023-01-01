#include "CG_Image.hpp"

#include <iostream>
#include <unistd.h>

CG_Image::CG_Image(int width, int height) {
  this->m_width = width;
  this->m_max_width = m_width + 2;
  this->m_height = height;
  this->m_pixels = new CG_Pixel[m_max_width * m_height];

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
    for (int x = 0; x < m_max_width; x++) {
      if (x == m_width) {
        this->m_pixels[y * m_max_width + x].fill = '\r';
      } else if (x == (m_width + 1)) {
        this->m_pixels[y * m_max_width + x].fill = '\n';
      } else {
        this->m_pixels[y * m_max_width + x].fill = DEFAULT_FILL;
      }
      this->m_pixels[y * m_max_width + x].color = bgcolor;
    }
  }
}

void CG_Image::show() {
  for (int y = 0; y < m_height; y++) {
    for (int x = 0; x < m_max_width; x++) {
      std::cout << this->m_pixels[y * m_max_width + x].color;
      std::cout << this->m_pixels[y * m_max_width + x].fill;
    }
    std::cout << std::flush;
  }
  std::cout << ColorCodes::Reset << std::endl;
}

void CG_Image::fill_rect(int x, int y, 
                             int wd, int ht, const std::string &color) {

  for (int cur_y = y; cur_y < (ht + y); cur_y++) {
    if (cur_y >= 0 && cur_y < m_height) {
      for (int curr_x = x; curr_x < (wd * SQUARE_SCALER + x); curr_x++) {
        if (curr_x >= 0 && curr_x < m_width) {
          this->m_pixels[cur_y * m_max_width + curr_x].color = color;
        }
      }
    }
  }
}

void CG_Image::fill_circle(int x, int y, int r, const std::string &color) {
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
            this->m_pixels[y1 * m_max_width + x1].color = color;
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
          this->m_pixels[y * m_max_width + x].color = color;
        }
      }
    }
  } else {
    int x = x1;
    if (x >= 0 && x < m_width) {
      if (y1 > y2)
        swap(y1, y2);
      for (int y = y1; y <= y2; y++) {
        if (y >= 0 && y < m_height) {
          this->m_pixels[y * m_max_width + x].color = color;
        }
      }
    }
  }
}

void CG_Image::fill_triangle(int x1, int y1, 
                                 int x2, int y2, 
                                 int x3, int y3, const std::string &color) {
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
          this->m_pixels[y * m_max_width + x].color = color;
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
          this->m_pixels[y * m_max_width + x].color = color;
        }
      }
    }
  }
}

void CG_Image::draw_text(int x, int y, const std::string &text, const std::string&color){
  if(y >= 0 && y < m_height) {
    for(int ti = 0; ti < text.size(); ti++) {
      CG_Pixel pixel = {
        .color = color, 
        .fill = text[ti]
        };
      
      int pos_x = ti + x;
      if(pos_x >= 0 && pos_x < m_width){
        this->m_pixels[y * m_max_width + pos_x] = pixel;
      }
    }
  }
}
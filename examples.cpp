#include "./CG/Image.hpp"
#include "./CG/Color.hpp"
#include <iostream>

#define WIDTH 25
#define HEIGHT 25

using CG::Color;

void checker() {
  CG::Image image(WIDTH, HEIGHT);
  Color red(0xFF0000);
  image.fill_background(red);
  int width = 5;
  int height = 5;

  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      if ((x + y) % 2 == 0) {
        image.fill_rect(x * width, y * height, width, height, Color::black);
      }
    }
  }
  image.show();
}
void triangle() {
  CG::Image image(WIDTH, HEIGHT);
  int x1 = 0, y1 = HEIGHT;
  int x2 = WIDTH / 2, y2 = HEIGHT / 2;
  int x3 = WIDTH, y3 = 0;
  image.fill_triangle(x1, y1, x2, y3, x3, y1, Color::red);
  image.fill_triangle(x3, y3, x2, y3, x2, y2, Color::blue);
  image.fill_triangle(x2 - 7, y1, x2 + 7, y1 - 10, x2, y2, Color::green);
  image.show();
}

void all() {
  CG::Image image(WIDTH, HEIGHT);
  int x1 = 0, y1 = HEIGHT;
  int x2 = WIDTH / 2, y2 = 0;
  int x3 = WIDTH;
  int x4 = WIDTH / 2, y4 = HEIGHT / 2;
  image.fill_background(Color::black);
  image.fill_rect(x2, y2, 10, 10, Color::blue);
  image.fill_circle(x4, y4, 7, Color::lightred);
  image.draw_line(x1, y2, x3, y1, Color::magenta);
  image.fill_triangle(x1, y4, x2, y2, x4, y4, Color::green);
  image.show();
}
void circles() {
  CG::Image r_circle(WIDTH, HEIGHT);
  CG::Image g_circle(WIDTH, HEIGHT);
  CG::Image b_circle(WIDTH, HEIGHT);
  int cx = WIDTH / 2;
  int cy = HEIGHT / 2;

  uint8_t red = 0;
  uint8_t green = 0;
  uint8_t blue = 0;
  for (int r = WIDTH / 2; r >= 3; r -= 1) {
    r_circle.fill_circle(cx, cy, r, Color(red, green, blue));
    red += r * 3 / 2;
  }
  red = 0;
  green = 0;
  blue = 0;
  for (int r = WIDTH / 2; r >= 3; r -= 1) {
    g_circle.fill_circle(cx, cy, r, Color(red, green, blue));
    green += r * 3 / 2;
  }
  red = 0;
  green = 0;
  blue = 0;
  for (int r = WIDTH / 2; r >= 0; r -= 1) {
    b_circle.fill_circle(cx, cy, r, Color(red, green, blue));
    blue += r * 3 / 2;
  }
  CG::Image image = CG::Image::combine_image(r_circle, g_circle);
  CG::Image::combine_image(image, b_circle).show();
}

void insert_text(const std::string &text) {
  CG::Image image(WIDTH, HEIGHT);
  int x = WIDTH / 2 - text.size() / 2;
  int y = HEIGHT / 2;

  // //  change the background of text
  // image.fill_rect(x, y, text.size(), 1, Color::magenta);
  //  set text color
  image.draw_text(x, y, text, Color::blue);
  image.draw_text(x, y + 1, text, Color::blue, Color::black);
  image.show();
}

void color_palette() {
  const std::string text = "CONSOLE@GRAPHICS";
  CG::Image image(Color::colors_count, Color::colors_count);
  
  for (int x = 0; x < Color::colors_count; x++) {
    image.fill_rect(x, 0, 1, Color::colors_count,Color::colors[x]);
  }
  for (int y = 0; y < Color::colors_count; y++) {
    image.draw_text(0, y, text, Color::colors[y]);
  }
  image.show();
}
void point() {
  CG::Image image(WIDTH, HEIGHT);
  image.fill_point(0, 0, Color::red);
  image.fill_point(0, 3, Color::blue);
  image.fill_point(3, 0, Color::green);
  image.fill_point(WIDTH - 1, HEIGHT - 1, Color::black);
  image.show();
}

void gradiant() {
  int width = 150;
  int height = width / 2; 
  CG::Image image(width, height);
  for(uint8_t y = 0; y < width; y++) {
    for(uint8_t x = 0; x < width; x++) {
        int true_y = y * height / width;
        image.fill_point(x, y, Color(x, y, 0));
    }
  }
  image.show();
}

/* TODOs
  //  Update show() to act more like a batch renderer? (instead of pixel by pixel it prints row by row)
  //  Animations
  //  Implement stb_image_write to save images to png
  //    - think of a way to convert CG_Pixel[] to uint32_t[] (maybe a static function in CG::Image that returns a uint32_t[])
  //    - Use saved png test cases to compare against the draw functions in TestCase.cpp
  //  Implement actual text rendering (and then rename current draw_text -> draw_acsii)

*/

int main() {
  checker();
  circles();
  triangle();
  all();
  color_palette();
  point();
  gradiant();
  return 0;
}
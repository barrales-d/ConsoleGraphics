#include "./CG/CG_Image.hpp"
#include "./CG/ColorCodes.hpp"
#include <iostream>

#define WIDTH 25
#define HEIGHT 25

void checker() {
  CG_Image image(WIDTH, HEIGHT);
  ColorCodes palatte;
  image.fill_background(palatte.bg_Red);
  int width = 5;
  int height = 5;

  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      if ((x + y) % 2 == 0) {
        image.fill_rect(x * width, y * height, width, height, palatte.bg_Black);
      }
    }
  }
  image.show();
}
void triangle() {
  CG_Image image(WIDTH, HEIGHT);
  int x1 = 0, y1 = HEIGHT;
  int x2 = WIDTH / 2, y2 = HEIGHT / 2;
  int x3 = WIDTH, y3 = 0;
  image.fill_triangle(x1, y1, x2, y3, x3, y1, ColorCodes::bg_Red);
  image.fill_triangle(x3, y3, x2, y3, x2, y2, ColorCodes::bg_Blue);
  image.fill_triangle(x2 - 7, y1, x2 + 7, y1 - 10, x2, y2, ColorCodes::bg_Green);
  image.show();
}

void all() {
  CG_Image image(WIDTH, HEIGHT);
  int x1 = 0, y1 = HEIGHT;
  int x2 = WIDTH / 2, y2 = 0;
  int x3 = WIDTH;
  int x4 = WIDTH / 2, y4 = HEIGHT / 2;
  image.fill_background(ColorCodes::bg_Black);
  image.fill_rect(x2, y2, 10, 10, ColorCodes::bg_Blue);
  image.fill_circle(x4, y4, 7, ColorCodes::bg_LightRed);
  image.draw_line(x1, y2, x3, y1, ColorCodes::bg_Magenta);
  image.fill_triangle(x1, y4, x2, y2, x4, y4, ColorCodes::bg_Green);
  image.show();
}
void circles() {
  CG_Image image(WIDTH, HEIGHT);
  int cx = WIDTH / 2;
  int cy = HEIGHT / 2;

  for (int r = WIDTH / 2; r >= 3; r -= 1) {
    image.fill_circle(cx, cy, r, CG_background_colors[r % CG_bg_count]);
  }
  image.show();
}

void insert_text(const std::string &text) {
  CG_Image image(WIDTH, HEIGHT);
  int x = WIDTH / 2 - text.size() / 2;
  int y = HEIGHT / 2;

  // //  change the background of text
  // image.fill_rect(x, y, text.size(), 1, ColorCodes::bg_Magenta);
  //  set text color
  image.draw_text(x, y, text, ColorCodes::fg_Blue);
  image.draw_text(x, y + 1, text, ColorCodes::fg_Blue, ColorCodes::bg_Black);
  image.show();
}

void color_palette() {
  const std::string text = "CONSOLE@GRAPHICS";
  CG_Image image(CG_bg_count, CG_bg_count);

  for (int x = 0; x < CG_bg_count; x++) {
    image.fill_rect(x, 0, 1, CG_bg_count,
                    CG_background_colors[x % CG_bg_count]);
  }
  for (int y = 0; y < CG_fg_count; y++) {
    image.draw_text(0, y, text, CG_foreground_colors[y]);
  }
  image.show();
}
void point() {
  CG_Image image(WIDTH, HEIGHT);
  image.fill_point(0, 0, ColorCodes::bg_Red);
  image.fill_point(0, 3, ColorCodes::bg_Blue);
  image.fill_point(3, 0, ColorCodes::bg_Green);
  image.fill_point(WIDTH - 1, HEIGHT - 1, ColorCodes::bg_Black);
  image.show();
}
/* TODOs
  //  Update show() to act more like a batch renderer? (instead of pixel by pixel it prints row by row)
  //  Animations
  //  Implement stb_image_write to save images to png
  //    - think of a way to convert CG_Pixel[] to uint32_t[] (maybe a static function in CG_Image that returns a uint32_t[])
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
  return 0;
}
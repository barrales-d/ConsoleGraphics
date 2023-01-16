#include "./CG/CG_Image.hpp"
#include "./CG/ColorCodes.hpp"
#include <iostream>

#define WIDTH 45
#define HEIGHT 20

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
  int x2 = WIDTH / 2, y2 = 0;
  int x3 = WIDTH, y3 = HEIGHT;
  image.fill_triangle(x1, y1, x2, y2, x3, y3, ColorCodes::bg_Red);
  image.show();
}

void all() {
  CG_Image image(WIDTH, HEIGHT);
  int x1 = 0, y1 = HEIGHT;
  int x2 = WIDTH / 2, y2 = 0;
  int x3 = WIDTH;
  int x4 = WIDTH / 2, y4 = HEIGHT / 2;
  image.fill_background(ColorCodes::bg_Black);
  image.fill_rect(x2 + 10, y2, 10, 10, ColorCodes::bg_Blue);
  image.fill_circle(x4, y4, 10, ColorCodes::bg_LightRed);
  image.draw_line(x1, y2, x3, y1, ColorCodes::bg_Magenta);
  image.fill_triangle(x1, y4, x2, y2, x4, y4, ColorCodes::bg_Green);
  image.show();
}
void circles() {
  CG_Image image(WIDTH, HEIGHT);
  int cx = WIDTH / 2;
  int cy = HEIGHT / 2;

  for (int r = 20; r >= 0; r -= 2) {
    image.fill_circle(cx, cy, r, CG_BACK_COLORS[r % CG_BACK_COLORS_SIZE]);
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
  const std::string text = "C O N S O L E @ G R A P H I C S ";
  CG_Image image(CG_FORE_COLORS_SIZE, CG_BACK_COLORS_SIZE);

  for (int x = 0; x < CG_FORE_COLORS_SIZE; x++) {
    image.fill_rect(x, 0, 1, CG_BACK_COLORS_SIZE, CG_BACK_COLORS[x]);
  }
  for (int y = 0; y < CG_BACK_COLORS_SIZE; y++) {
    image.draw_text(0, y, text, CG_FORE_COLORS[y % CG_FORE_COLORS_SIZE]);
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
  //  Explore Testcases and unit tests by creating a class TestCase friend of CG_Image
  //  Update show() to act more like a batch renderer? (instead of pixel by pixel it prints row by row)
  //  Explore triangle scaler? 
  //  Animations?
  //  Create cooler examples like circles() which is a bulls-eye 

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
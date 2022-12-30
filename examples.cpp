
#include "./CG/ColorCodes.hpp"
#include "./CG/CG_Image.hpp"

#define WIDTH 150
#define HEIGHT 28

void checker() {
  CG_Image image(WIDTH, HEIGHT);
  ColorCodes palatte;
  image.fill_background(palatte.bg_Red);
  int width = WIDTH / 6;
  int height = HEIGHT / 4;

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
  int x3 = WIDTH, y3 = HEIGHT;
  int x4 = WIDTH / 2, y4 = HEIGHT / 2;
  image.fill_background(ColorCodes::bg_Black);
  image.fill_rect(x2 + 20, y2, 15, 15, ColorCodes::bg_Blue);
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
    image.fill_circle(cx, cy, r, CG_COLORS[r % CG_COLORS_SIZE]);
  }

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
  circles();
  return 0;
}
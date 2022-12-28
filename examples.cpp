
#include "./CI/ColorCodes.hpp"
#include "./CI/ConsoleImage.hpp"

#define WIDTH 150
#define HEIGHT 28

void checker() {
  ConsoleImage image(WIDTH, HEIGHT);
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
  ConsoleImage image(WIDTH, HEIGHT);
  int x1 = 0, y1 = HEIGHT;
  int x2 = WIDTH / 2, y2 = 0;
  int x3 = WIDTH, y3 = HEIGHT;
  image.fill_triangle(x1, y1, x2, y2, x3, y3, ColorCodes::bg_Red);
  image.show();
}

void all() {
  ConsoleImage image(WIDTH, HEIGHT);
  int x1 = 0, y1 = HEIGHT;
  int x2 = WIDTH / 2, y2 = 0;
  int x3 = WIDTH, y3 = HEIGHT;
  int x4 = WIDTH / 2, y4 = HEIGHT / 2;
  image.fill_background(ColorCodes::bg_Black);
  image.fill_rect(x2 + 20, y2, 30, 15, ColorCodes::bg_Blue);
  image.fill_circle(x4, y4, 10, ColorCodes::bg_LightRed);
  image.draw_line(x1, y2, x3, y1, ColorCodes::bg_Magenta);
  image.fill_triangle(x1, y4, x2, y2, x4, y4, ColorCodes::bg_Green);
  image.show();
}

void circles() {
  ConsoleImage image(WIDTH, HEIGHT);
  int cx = WIDTH / 2;
  int cy = HEIGHT / 2;
  for (int r = 20; r >= 0; r -= 2) {
    image.fill_circle(cx, cy, r, colors[r % color_size]);
  }

  image.show();
}

int main() {
  circles();
  return 0;
}
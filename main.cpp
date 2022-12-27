#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

#include "Colors/ColorCodes.hpp"
#include "Image.hpp"

#define WIDTH 10
#define HEIGHT 6

int main() {
  Image image(WIDTH, HEIGHT);
  image.fill_background(ColorCodes::bg_Black);
  int r = 1;
  int x1 = WIDTH / 3, y1 = HEIGHT / 3;
  image.fill_circle(x1, y1, r, ColorCodes::bg_Red);
  image.fill_circle(x1 * 2, y1, r, ColorCodes::bg_Red);
  image.fill_triangle(2, 3, WIDTH / 2, HEIGHT, 7, 3, ColorCodes::bg_Red);

  image.show();
  return 0;
}
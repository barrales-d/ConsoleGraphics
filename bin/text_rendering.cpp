#include <iostream>

#include "../CG/Image.hpp"

#define WIDTH 50
#define HEIGHT 30

using CG::Color;

int main() {
    CG::Image image(WIDTH, HEIGHT);
    int x = 0;
    int y = 0;

    // image.draw_text(x, y, "Con ole", Color::blue);
    // y += 7;
    // image.draw_text(x, y, "G aphic ", Color::blue);
    // y += 7;
    image.draw_text(x, y, "AaBbCcDd", Color::blue);
    y += 7;
    image.draw_text(x, y, "EeFfGgHh", Color::green);
    y += 7;
    image.draw_text(x, y, "IiJjKkLl", Color::red);
    y += 7;
    image.draw_text(x, y, "MmNnOoPp", Color::yellow);
    // image.write_ascii(x, y + 1, text, Color::blue, Color::black);
    image.show();
    return 0;
}
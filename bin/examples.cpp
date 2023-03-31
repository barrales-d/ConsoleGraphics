#include "../CG/Image.hpp"

#include <iostream>

#define WIDTH 32
#define HEIGHT 32

using CG::Color;
using namespace CG::Colors;

void checker()
{
    CG::Image image(WIDTH, HEIGHT);
    Color red(0x0000FF);
    image.fill_background(red);
    int width = 5;
    int height = 5;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if ((x + y) % 2 == 0) {
                image.fill_rect(x * width, y * height, width, height, CG::Colors::black);
            }
        }
    }
    image.show();
    // image.save_image("./ExampleImages/checkered.png");
}
void triangle()
{
    CG::Image image(WIDTH, HEIGHT);
    int x1 = 0, y1 = HEIGHT;
    int x2 = WIDTH / 2, y2 = HEIGHT / 2;
    int x3 = WIDTH, y3 = 0;

    image.fill_triangle(x1, y1, x2, y3, x3, y1, CG::Colors::red);
    image.fill_triangle(x3, y3, x2, y3, x2, y2, CG::Colors::blue);
    image.fill_triangle(x2 - 7, y1, x2 + 7, y1 - 10, x2, y2, CG::Colors::green);
    image.show();
    // image.save_image("./ExampleImages/triangle.png");
}

void all()
{
    CG::Image image(WIDTH, HEIGHT);
    int x1 = 0, y1 = HEIGHT;
    int x2 = WIDTH / 2, y2 = 0;
    int x3 = WIDTH;
    int x4 = WIDTH / 2, y4 = HEIGHT / 2;

    image.fill_background(Color(CG::RGBA<float>{0.5f, 0.5f, 0.2f, 1.0f}));
    // image.fill_background(CG::Colors::black);
    image.fill_rect(x2, y2, 10, 10, CG::Colors::blue);
    image.fill_circle(x4, y4, 7, Color(0XCC8080FF));
    image.draw_line(x1, y2, x3, y1, CG::Colors::magenta);
    image.fill_triangle(x1, y4, x2, y2, x4, y4, Color(0xA40FF40));
    image.show();
    // image.save_image("./ExampleImages/all.png");
}
void circles()
{
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
    CG::Image final = CG::Image::combine_image(image, b_circle);
    final.show();
    // final.save_image("./ExampleImages/circles.png");
}

void insert_text(const std::string &text)
{
    CG::Image image(WIDTH, HEIGHT);
    int x = 0;
    int y = HEIGHT / 2;

    image.draw_text(x, y, text, CG::Colors::blue);
    // image.write_ascii(x, y + 1, text, CG::Colors::blue, CG::Colors::black);
    image.show();
}

void color_palette()
{
    const std::string text = "CONSOLE@GRAPHICS";
    CG::Image image(CG::colors_count, CG::colors_count);

    for (int x = 0; x < CG::colors_count; x++)
        image.fill_rect(x, 0, 1, CG::colors_count,CG::colors[x]);

    for (int y = 0; y < CG::colors_count; y++)
        image.write_ascii(0, y, text, CG::colors[y]);

    image.show();
    // image.save_image("./ExampleImages/color_palatte.png");
}
void point()
{
    CG::Image image(WIDTH, HEIGHT);
    image.fill_point(0, 0, CG::Colors::red);
    image.fill_point(0, 3, CG::Colors::blue);
    image.fill_point(3, 0, CG::Colors::green);
    image.fill_point(WIDTH - 1, HEIGHT - 1, CG::Colors::black);
    image.show();
}

void gradient()
{
    int width = 128;
    int height = width / 2; 
    CG::Image image(width, height);
    for(uint8_t y = 0; y < width; y++) {
        for(uint8_t x = 0; x < width; x++) {
            image.fill_point(x, y, Color(x, y, 0));
        }
    }
    image.show();
    // image.save_image("./ExampleImages/gradient.png");
}

/* TODOs
//  Update show() to act more like a batch renderer? (instead of pixel by pixel it prints row by row)
*/

int main() {
    // insert_text("ab abba");
    checker();
    circles();
    triangle();
    all();
    color_palette();
    // point();
    // gradient();
    return 0;
}
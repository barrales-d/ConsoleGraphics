//	example program to create different images in the terminal

#include "CG.h"
using namespace CG;



int main()
{

	Image rainbow_tri(20, 20);
	rainbow_tri.fill_background(Colors::black);
	rainbow_tri.fill_triangle(0, 10, 10, 0, 20, 20, Colors::red, Colors::blue, Colors::green);
	rainbow_tri.save_txt("C:/Users/Diego Barrales/Documents/barrales-d/ConsoleGraphics/web/Images/rainbow_tri.txt");
	rainbow_tri.show();

	Image rainbow_square(20, 20);
	rainbow_square.fill_background();
	rainbow_square.fill_triangle(20, 0, 10, 10, 20, 20, Colors::magenta, Colors::yellow, Colors::cyan);
	rainbow_square.fill_triangle(0, 20, 10, 10, 20, 20, Colors::magenta, Colors::yellow, Colors::cyan);
	rainbow_square.fill_triangle(20, 0, 10, 10, 0, 0, Colors::magenta, Colors::yellow, Colors::cyan);
	rainbow_square.fill_triangle(0, 20, 10, 10, 0, 0, Colors::magenta, Colors::yellow, Colors::cyan);
	rainbow_square.save_txt("C:/Users/Diego Barrales/Documents/barrales-d/ConsoleGraphics/web/Images/rainbow_square.txt");
	rainbow_square.show();

	Image transparent_circle(20, 20);
	transparent_circle.fill_background();
	transparent_circle.fill_rect(3, 3, 13, 13, Colors::lightred);
	transparent_circle.fill_circle(5, 5, 5, Color(255, 0, 160, 128));
	transparent_circle.fill_circle(15, 15, 4, Color(255, 0, 160, 128));
	transparent_circle.save_txt("C:/Users/Diego Barrales/Documents/barrales-d/ConsoleGraphics/web/Images/transparent_circle.txt");
	transparent_circle.show();

	int size = 40;
	Image font_render(size, size);
	font_render.fill_background();
	const std::string msg = "Console\nGraphics";
	int center_y = (size / 2) - Font::height;
	font_render.fill_ellipse(int(size / 2), int(size / 2), Math::ceil(Font::width * size / 6), Font::height * 2, Color(255, 16, 31, 200));
	font_render.fill_text(5, center_y, msg, Color(253, 255, 252));
	font_render.save_txt("C:/Users/Diego Barrales/Documents/barrales-d/ConsoleGraphics/web/Images/font_render.txt");
	font_render.show();
	

	Image gradient_circle(size, size);
	gradient_circle.fill_background();
	uint8_t blue = 0;
	for (int r = size / 3; r >= 0; r -= 1) {
		gradient_circle.fill_circle((size / 2), (size / 2), r, Color(0, 0, blue));
		blue += r * 3 / 2;
	}
	gradient_circle.save_txt("C:/Users/Diego Barrales/Documents/barrales-d/ConsoleGraphics/web/Images/gradient_circle.txt");
	gradient_circle.show();
	
	Image line_bezier(40, 40);
	line_bezier.fill_background(Colors::black);
	line_bezier.fill_bezier_curve_line({ 0, 0 }, { 10, 20 }, { 40, 40 }, Colors::red);
	line_bezier.fill_bezier_curve_line({ 0, 10 }, { 20, 10 }, { 0, 40 }, { 40, 10 }, Colors::green);
	line_bezier.fill_bezier_curve_line({ 5, 15 }, { 20, 40 }, Colors::blue);
	line_bezier.save_txt("C:/Users/Diego Barrales/Documents/barrales-d/ConsoleGraphics/web/Images/line_bezier.txt");
	line_bezier.show();

	return 0;
}

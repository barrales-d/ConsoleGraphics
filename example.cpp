//	example program to create different images in the terminal

#include "CG.h"
using namespace CG;

#include <iomanip>
#include <ctime>


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
	font_render.fill_ellipse(int(size / 2), int(size / 2), Math::ceil(Font::width * size / 6), Font::height * 2, Color(201, 150, 20, 200));
	font_render.fill_text(5, center_y, msg, Colors::lightblue);
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
	
	Image line_bezier(30, 30);
	line_bezier.fill_background(Colors::black);
	line_bezier.fill_bezier_curve_line({ 0, 0 }, { 10, 20 }, { 30, 30 }, Colors::red);
	line_bezier.fill_bezier_curve_line({ 0, 10 }, { 20, 10 }, { 0, 30 }, { 30, 10 }, Colors::green);
	line_bezier.fill_bezier_curve_line({ 5, 15}, { 20, 30}, Colors::blue);
	line_bezier.save_txt("C:/Users/Diego Barrales/Documents/barrales-d/ConsoleGraphics/web/Images/line_bezier.txt");
	line_bezier.show();

#if 0
	srand(time(NULL));
	Image image(20, 20);
	image.fill_background(Colors::black);
	image.fill_rect(-9, -9, 15, 15, Color(0xFFFFFF00));
	image.fill_rect(1, 1, 11, 20, Color(255, 20, 20, 128));
	image.fill_circle(9, 9, 4, Colors::magenta);
	image.fill_ellipse(9, 9, 8, 4, Color(0, 50, 255, 128));
	image.fill_rect_line(3, 6, 5, 4, Colors::lightgreen);
	image.fill_triangle(20, 0, 10, 10, 20, 20, Colors::red, Colors::green, Colors::blue);
	image.show();
	
	ansi::move_cursor(20, 20 * 2);
	
	Image image2(20, 20);
	image2.fill_background();
	image2.fill_triangle(20, 0, 10, 10, 20, 20, Colors::magenta, Colors::yellow, Colors::cyan);
	image2.fill_triangle(0, 20, 10, 10, 20, 20, Colors::magenta, Colors::yellow, Colors::cyan);
	image2.fill_triangle(20, 0, 10, 10, 0, 0, Colors::magenta, Colors::yellow, Colors::cyan);
	image2.fill_triangle(0, 20, 10, 10, 0, 0, Colors::magenta, Colors::yellow, Colors::cyan);
	image2.show();

	image2.fill_background();
	image2.fill_triangle(20, 0, 10, 10, 20, 20, Colors::yellow, Colors::magenta, Colors::cyan);
	image2.fill_triangle(0, 20, 10, 10, 20, 20, Colors::yellow, Colors::magenta, Colors::cyan);
	image2.fill_triangle(20, 0, 10, 10, 0, 0, Colors::yellow, Colors::magenta, Colors::cyan);
	image2.fill_triangle(0, 20, 10, 10, 0, 0, Colors::yellow, Colors::magenta, Colors::cyan);
	image2.show();

	image2.fill_background();
	image2.fill_triangle(20, 0, 10, 10, 20, 20, Colors::cyan, Colors::yellow, Colors::magenta);
	image2.fill_triangle(0, 20, 10, 10, 20, 20, Colors::cyan, Colors::yellow, Colors::magenta);
	image2.fill_triangle(20, 0, 10, 10, 0, 0, Colors::cyan, Colors::yellow, Colors::magenta);
	image2.fill_triangle(0, 20, 10, 10, 0, 0, Colors::cyan, Colors::yellow, Colors::magenta);

	image2.fill_bezier_curve_line(Vec2(0, 0), Vec2(0, 20), Vec2(20, 20), Colors::black);
	image2.fill_bezier_curve_line(Vec2(0, 0), Vec2(20, 0), Vec2(20, 20), Colors::black);
	image2.show();

	//Image image3(50, 50);

	//image3.fill_background(Colors::black);

	//Vec2 p1(0, 0);
	//Vec2 p2(25, 50);
	//Vec2 p3(50, 0);
	//Vec2 p4(50, 50);
	////image3.fill_bezier_curve(p1, p2, p3, Colors::blue, 0.001f);
	////image3.fill_bezier_curve_line(p1, p2, p3, Color(255, 40, 40, 128), 0.001f);

	//image3.fill_bezier_curve(p1, p2, p3, p4, Color(0, 254, 0, 255), 0.001f);
	//image3.fill_bezier_curve_line(p1, p2, p3, p4, Color(255, 255, 40, 128), 0.001f);

	////image3.fill_bezier_curve_line(p1, p2, Colors::magenta, 0.001f);
	//image3.show();

	Image image4(20, 20);
	image4.fill_background(Colors::black);
	for (int i = 0; i < 20; i++) {
		image4.fill_rect(rand() % 20, rand() % 20, rand() % 3, rand() % 3, Color::random_alpha());
	}
	image4.show();
#endif

	return 0;
}

//	example program to create different images in the terminal

#include "CG.h"
using namespace CG;

#include <iomanip>
#include <ctime>

int main()
{
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

	Image image3(50, 50);

	image3.fill_background(Colors::black);

	Vec2 p1(0, 0);
	Vec2 p2(25, 50);
	Vec2 p3(50, 0);
	Vec2 p4(50, 50);
	//image3.fill_bezier_curve(p1, p2, p3, Colors::blue, 0.001f);
	//image3.fill_bezier_curve_line(p1, p2, p3, Color(255, 40, 40, 128), 0.001f);

	image3.fill_bezier_curve(p1, p2, p3, p4, Color(0, 254, 0, 255), 0.001f);
	image3.fill_bezier_curve_line(p1, p2, p3, p4, Color(255, 255, 40, 128), 0.001f);

	//image3.fill_bezier_curve_line(p1, p2, Colors::magenta, 0.001f);
	image3.show();
	return 0;
}

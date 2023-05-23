﻿//	example program to create different images in the terminal

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
	transparent_circle.fill_rect(3, 3, 13, 13, Colors::black);
	transparent_circle.fill_circle(10, 10, 8, Color(255, 255, 50, 128));
	transparent_circle.save_txt("C:/Users/Diego Barrales/Documents/barrales-d/ConsoleGraphics/web/Images/transparent_circle.txt");
	transparent_circle.show();

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

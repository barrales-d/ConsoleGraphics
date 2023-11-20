//	example program to create different images in the terminal

#include <CG.h>
using namespace CG;

#define SMALL_CANVAS 20
#define LARGE_CANVAS 40

int main()
{
	Image rainbow_tri(SMALL_CANVAS, SMALL_CANVAS);
	rainbow_tri.fill_background(Colors::black);
	rainbow_tri.fill_triangle(0, 10, 10, 0, SMALL_CANVAS, SMALL_CANVAS, Colors::red, Colors::blue, Colors::green);
	rainbow_tri.save_svg("C:/Users/Diego Barrales/Documents/barrales-d/ConsoleGraphics/web/Images/rainbow_tri.svg");
	rainbow_tri.show();

	Image rainbow_square(SMALL_CANVAS, SMALL_CANVAS);
	rainbow_square.fill_background();
	rainbow_square.fill_triangle(SMALL_CANVAS, 0, 10, 10, SMALL_CANVAS, SMALL_CANVAS, Colors::magenta, Colors::yellow, Colors::cyan);
	rainbow_square.fill_triangle(0, SMALL_CANVAS, 10, 10, SMALL_CANVAS, SMALL_CANVAS, Colors::magenta, Colors::yellow, Colors::cyan);
	rainbow_square.fill_triangle(SMALL_CANVAS, 0, 10, 10, 0, 0, Colors::magenta, Colors::yellow, Colors::cyan);
	rainbow_square.fill_triangle(0, SMALL_CANVAS, 10, 10, 0, 0, Colors::magenta, Colors::yellow, Colors::cyan);
	rainbow_square.save_svg("C:/Users/Diego Barrales/Documents/barrales-d/ConsoleGraphics/web/Images/rainbow_square.svg");
	rainbow_square.show();

	Image transparent_circle(SMALL_CANVAS, SMALL_CANVAS);
	transparent_circle.fill_background();
	transparent_circle.fill_rect(3, 3, 13, 13, Colors::lightred);
	transparent_circle.fill_circle(5, 5, 5, Color(255, 0, 160, 128));
	transparent_circle.fill_circle(15, 15, 4, Color(255, 0, 160, 128));
	transparent_circle.save_svg("C:/Users/Diego Barrales/Documents/barrales-d/ConsoleGraphics/web/Images/transparent_circle.svg");
	transparent_circle.show();

	Image font_render(LARGE_CANVAS, LARGE_CANVAS);
	font_render.fill_background();
	const std::string msg = "Hello!";
	const int msg_length = Font::width * msg.size();
	font_render.fill_ellipse(LARGE_CANVAS / 2, LARGE_CANVAS / 2, msg_length + 1, Font::height * 2 + 1, Colors::black);
	font_render.fill_ellipse(LARGE_CANVAS / 2, LARGE_CANVAS / 2, msg_length, Font::height * 2, Colors::lightpurple);
	font_render.fill_text(LARGE_CANVAS / 2 - msg_length / 2, LARGE_CANVAS / 2 - Font::height / 2, msg, Colors::turquoise);
	font_render.save_svg("C:/Users/Diego Barrales/Documents/barrales-d/ConsoleGraphics/web/Images/font_render.svg");
	font_render.show();


	Image gradient_circle(LARGE_CANVAS, LARGE_CANVAS);
	gradient_circle.fill_background();
	uint8_t blue = 0;
	for (int r = LARGE_CANVAS / 3; r >= 0; r -= 1) {
		gradient_circle.fill_circle((LARGE_CANVAS / 2), (LARGE_CANVAS / 2), r, Color(0, 0, blue));
		blue += r * 3 / 2;
	}
	gradient_circle.save_svg("C:/Users/Diego Barrales/Documents/barrales-d/ConsoleGraphics/web/Images/gradient_circle.svg");
	gradient_circle.show();

	Image line_bezier(LARGE_CANVAS, LARGE_CANVAS);
	line_bezier.fill_background(Colors::black);
	line_bezier.fill_bezier_curve_line({ 0, 0 }, { 10, 20 }, { LARGE_CANVAS, LARGE_CANVAS }, Colors::red);
	line_bezier.fill_bezier_curve_line({ 0, 10 }, { 20, 10 }, { 0, LARGE_CANVAS }, { LARGE_CANVAS, 10 }, Colors::green);
	line_bezier.fill_bezier_curve_line({ 5, 15 }, { 20, LARGE_CANVAS }, Colors::blue);
	line_bezier.save_svg("C:/Users/Diego Barrales/Documents/barrales-d/ConsoleGraphics/web/Images/line_bezier.svg");
	line_bezier.show();

	srand(2023);
	Image dots(SMALL_CANVAS, SMALL_CANVAS);
	dots.fill_background();

	int max = 4, min = 1;

		int radius = max;
	for (int i = 0; i < SMALL_CANVAS * SMALL_CANVAS; i++) {
		int pos_x = (rand() % SMALL_CANVAS * 2);
		int pos_y = (rand() % SMALL_CANVAS * 2);
		Color col;
		if(i % 2 == 0) {
			col = Color::random();
		}
		else {
			col = Color::random_alpha();
		}
		dots.fill_circle(pos_x, pos_y, radius, col);

	} 
	dots.save_svg("C:/Users/Diego Barrales/Documents/barrales-d/ConsoleGraphics/web/Images/dots.svg");
	dots.show();

	Image gradient_square(LARGE_CANVAS, LARGE_CANVAS);
	gradient_square.fill_background();
	gradient_square.fill_triangle(0, 0, LARGE_CANVAS, LARGE_CANVAS, LARGE_CANVAS, 0, Colors::blue, Colors::red);
	gradient_square.fill_triangle(0, 0, LARGE_CANVAS, LARGE_CANVAS, 0, LARGE_CANVAS, Colors::blue, Colors::red);
	gradient_square.save_svg("C:/Users/Diego Barrales/Documents/barrales-d/ConsoleGraphics/web/Images/gradient_square.svg");
	gradient_square.show();

	Image logo(SMALL_CANVAS, SMALL_CANVAS);
	logo.fill_background(Colors::black);
	logo.fill_rect_line(0, 0, SMALL_CANVAS - 1, SMALL_CANVAS - 1, Colors::cyan);
	logo.fill_text(SMALL_CANVAS / 2 - Font::width, SMALL_CANVAS / 2 - Font::height / 2, "CG", Colors::cyan);
	logo.save_svg("C:/Users/Diego Barrales/Documents/barrales-d/ConsoleGraphics/web/Images/logo.svg");
	logo.show();
	return 0;
}

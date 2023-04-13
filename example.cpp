//	example program to create different images in the terminal

#include "CG.h"
using namespace CG;

int main()
{
	srand(time(NULL));
	Image image(20, 20);
	image.fill_background(Colors::black);
	image.fill_rect(-9, -9, 15, 15, Color(0xFFFFFF00));
	image.fill_rect(1, 1, 11, 20, Color(255, 20, 20, 128));
	image.fill_circle(9, 9, 4, Colors::magenta);
	image.fill_ellipse(9, 9, 8, 4, Color(0, 50, 255, 128));
	image.fill_line_rect(3, 6, 5, 4, Colors::lightgreen);
	image.fill_triangle(20, 0, 10, 10, 20, 20, Colors::red, Colors::green, Colors::blue);
	image.show();

	Image image2(image);
	image2.fill_background();
	int x1 = rand() % 20;
	int y1 = rand() % 20;
	int x2 = rand() % 20;
	int y2 = rand() % 20;
	image2.fill_line(x1, y1, x2, y2, Colors::turquoise);
	image2.show();

	return 0;
}

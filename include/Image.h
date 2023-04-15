#ifndef __IMAGE_H__
#define __IMAGE_H__
#include "Color.h"
#include "Ansi_codes.h"
#include "Font.h"

#include <memory>
#include <iostream>

namespace CG {
	class Image
	{
	public:
		Image();
		Image(int width, int height);
		
		void show();

		void fill_background(Color bg_color = Colors::darkgrey);
		void fill_point(int x, int y, Color bg_color);
		void fill_rect(int x, int y, int width, int height, Color bg_color);
		void fill_line_rect(int x, int y, int width, int height, Color bg_color);
		void fill_line(int x1, int y1, int x2, int y2, Color bg_color);
		void fill_circle(int x, int y, int r, Color bg_color);
		void fill_ellipse(int x, int y, int rx, int ry, Color bg_color);
		void fill_text(int x, int y, const std::string& text, Color bg_color);
		void fill_triangle(int x1, int y1, int x2, int y2, int x3, int y3, Color c1,
							Color c2 = Colors::transparent, Color c3 = Colors::transparent);
		
		void resize(int width, int height);

	protected:
		int m_width;
		int m_height;
		std::shared_ptr<Color[]> m_pixels;

	private:
		//	X, Y = left and right of rectangle and Z, W = top and bottom
		//	iterate through for y = Vec4.z; y < Vec4.w
		//						for x = Vec4.x; x < Vec4.y
		Vec4 clamp_rect(int x, int y, int wd, int ht);
	};
}

#endif //	__IMAGE_H__
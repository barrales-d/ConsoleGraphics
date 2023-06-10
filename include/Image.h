#ifndef __IMAGE_H__
#define __IMAGE_H__
#include "Color.h"
#include "Ansi.h"
#include "Font.h"

#include <memory>
#include <iostream>
#include <string>
#include <fstream>

#define CG_ERROR(msg) do { ansi::foreground(Colors::red);		\
						   std::cerr << "ERROR: " << (msg);		\
						   ansi::reset(); } while(0);			\

namespace CG {
	class Testcase;
	class Image {
	public:
		Image();
		Image(int width, int height);
		
		void show();

		void fill_background(Color bg_color = Colors::darkgrey);
		void fill_point(int x, int y, Color bg_color);
		void fill_rect(int x, int y, int width, int height, Color bg_color);
		void fill_rect_line(int x, int y, int width, int height, Color bg_color);
		void fill_line(int x1, int y1, int x2, int y2, Color bg_color);
		void fill_circle(int x, int y, int r, Color bg_color);
		void fill_circle_line(int x, int y, int r, Color bg_color);
		void fill_ellipse(int x, int y, int rx, int ry, Color bg_color);
		void fill_text(int x, int y, const std::string& text, Color bg_color);
		void fill_triangle(int x1, int y1, int x2, int y2, int x3, int y3, Color c1,
							Color c2 = Colors::transparent, Color c3 = Colors::transparent);

		void fill_sprite(int x, int y, const std::vector<uint32_t>& sprite, int width, int height);

		void fill_bezier_curve(Vec2 p1, Vec2 p2, Vec2 p3, Color c1, 
							   Color c2 = Colors::transparent, float step = 0.01f);
		void fill_bezier_curve(Vec2 p1, Vec2 p2, Vec2 p3, Vec2 p4, Color c1,
							   Color c2 = Colors::transparent, float step = 0.01f);

		void fill_bezier_curve_line(Vec2 p1, Vec2 p2, Color c1, 
									Color c2 = Colors::transparent, float step = 0.01f);

		void fill_bezier_curve_line(Vec2 p1, Vec2 p2, Vec2 p3, Color c1, 
									Color c2 = Colors::transparent, float step = 0.01f);

		void fill_bezier_curve_line(Vec2 p1, Vec2 p2, Vec2 p3, Vec2 p4, Color c1,
									Color c2 = Colors::transparent, float step = 0.01f);
		
		void resize(int width, int height);

		void save_txt(const std::string& filename);
		bool load_txt(const std::string& filename);
		
		friend class Testcase;

	protected:
		int m_width;
		int m_height;
		std::unique_ptr<Color[]> m_pixels;

	private:
		//	X, Y = left and right of rectangle and Z, W = top and bottom
		//	iterate through for y = Vec4.z; y < Vec4.w
		//						for x = Vec4.x; x < Vec4.y
		Vec4 clamp_rect(int x, int y, int wd, int ht);
	};
}

#endif //	__IMAGE_H__
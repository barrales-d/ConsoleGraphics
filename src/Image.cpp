#include "../include/Image.h"

using namespace CG;

namespace {
	constexpr const char* deafult_fill = "  ";
}

Image::Image()
{
	m_width = 0;
	m_height = 0;
	m_pixels = nullptr;
}

//Image::~Image()
//{
//	free_pixels();
//}

Image::Image(int width, int height)
{
	m_width = width;
	m_height = height;
	m_pixels = std::shared_ptr<Color[]>(new Color[m_width * m_height]);
}

void Image::show()
{
	ansi_codes::hide_cursor();
	for (size_t y = 0; y < m_height; y++) {
		for (size_t x = 0; x < m_width; x++) {
			auto& pixel = m_pixels[y * m_width + x];
			ansi_codes::background(pixel);
			std::cout << deafult_fill;
		}
		ansi_codes::reset();
		std::cout << std::flush << "\r\n";
	}
}

void Image::fill_background(Color bg_color)
{
	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			this->fill_point(x, y, bg_color);
		}
	}
}

void Image::fill_point(int x, int y, Color bg_color)
{
	auto& pixel = this->m_pixels[(size_t)y * m_width + x];
	pixel = pixel + bg_color;
}

void Image::fill_rect(int x, int y, int width, int height, Color bg_color)
{
	Vec4 rect_bound = clamp_rect(x, y, width, height);
	if (rect_bound == Vec4::zero)
		return;
	for (int py = rect_bound.z; py < rect_bound.w; py++) {
		for (int px = rect_bound.x; px < rect_bound.y; px++) {
			this->fill_point(px, py, bg_color);
		}
	}
}

void Image::fill_line_rect(int x, int y, int width, int height, Color bg_color)
{
	Vec4 rect_bound = clamp_rect(x, y, width, height);
	if (rect_bound == Vec4::zero)
		return;
	for (int py = rect_bound.z; py <= rect_bound.w; py++) {
		this->fill_point(rect_bound.x, py, bg_color);
		this->fill_point(rect_bound.y, py, bg_color);
	}

	for (int px = rect_bound.x; px < rect_bound.y; px++) {
		this->fill_point(px, rect_bound.z, bg_color);
		this->fill_point(px, rect_bound.w, bg_color);
	}
}

void Image::fill_line(int x1, int y1, int x2, int y2, Color bg_color)
{
	Vec4 bound_box = clamp_rect(Math::min(x1, x2), Math::min(y1, y2), Math::abs(x2 - x1), Math::abs(y2 - y1));
	int dx = x2 - x1;
	if (dx == 0) { //	vertical line
		for (int y = bound_box.z; y <= bound_box.w; y++)
			this->fill_point(x1, y, bg_color);
		return;
	}
	
	//	y = mx + b
	float m = (float)(y2 - y1) / dx;
	float b = y1 - m * x1;
	for (int x = bound_box.x; x < bound_box.y; x++) {
		int y = static_cast<int>(x * m + b);
		if (Math::abs(m) > 1.0f) {
			//	use clamp instead of min to allow for negative values?
			int next_y = Math::clamp(y + (int)m, bound_box.z, bound_box.w - 1);
			this->fill_line(x, y, x, next_y, bg_color);
		}
		else {
			this->fill_point(x, y, bg_color);
		}
	}
}

void Image::fill_circle(int x, int y, int r, Color bg_color)
{
	Vec4 circle_bound = clamp_rect(x - r, y - r, x + r, y + r);
	if (circle_bound == Vec4::zero)
		return;
	float dr = (r + 0.5f) * (r + 0.5f);
	for (int py = circle_bound.z; py < circle_bound.w; py++) {
		for (int px = circle_bound.x; px < circle_bound.y; px++) {
			float dx = (float)(px - x);
			float dy = (float)(py - y);
			if (dx * dx + dy * dy < dr)
				this->fill_point(px, py, bg_color);
		}
	}
}

void Image::fill_ellipse(int x, int y, int rx, int ry, Color bg_color)
{
	Vec4 ellipse_bound = clamp_rect(x - rx, y - ry, 2 * rx, 2 * ry);
	if (ellipse_bound == Vec4::zero)
		return;

	float drx = 2.0f * rx;
	float dry = 2.0f * ry;
	for (int py = ellipse_bound.z; py < ellipse_bound.w; py++) {
		for (int px = ellipse_bound.x; px < ellipse_bound.y; px++) {
			float dx = (px - x) / drx;
			float dy = (py - y) / dry;
			if (dx * dx + dy * dy < 0.5f * 0.5f)
				this->fill_point(px, py, bg_color);
		}
	}
}

void Image::fill_text(int x, int y, const std::string& text, Color bg_color)
{
	int ogx = x;
	for (char ch : text) {
		if (ch == '\n') {
			x = ogx;
			y += Font::height + 1;
			continue;
		}
		auto& glyph = Font::get(ch);
		int max_col = 0;
		for (int row = 0; row < Font::height; row++) {
			for (int col = 0; col < Font::width; col++) {
				int pixel = glyph[(size_t)row * Font::width + col];
				int px = col + x;
				int py = row + y;
				if (pixel != 0 && px < m_width && py < m_height && px >= 0 && py >= 0) {
					this->fill_point(px, py, bg_color);
					max_col = Math::max(max_col, col);
				}
			}
		}
		x += max_col + 2;
	}
}

void Image::fill_triangle(int x1, int y1, int x2, int y2, int x3, int y3, Color c1, Color c2, Color c3)
{
	float determinate = (float) ((y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3));
	Vec2 point = Vec2(Math::min(x1, x2, x3), Math::min(y1, y2, y3));

	Vec4 tri_bound = clamp_rect(point.x, point.y, Math::max(x1, x2, x3) - point.x, Math::max(y1, y2, y3) - point.y);
	float epsilon = -0.000001f;
	for (int py = tri_bound.z; py < tri_bound.w; py++) {
		for (int px = tri_bound.x; px < tri_bound.y; px++) {
			float d1 = ((y2 - y3) * (px - x3) + (x3 - x2) * (py - y3)) / determinate;
			float d2 = ((y3 - y1) * (px - x3) + (x1 - x3) * (py - y3)) / determinate;
			float d3 = 1 - d1 - d2;

			if (d1 <= epsilon || d2 <= epsilon || d3 <= epsilon)
				continue;

			Color color = c1;
			if (c2 != Colors::transparent) {
				color = Color::lerp_colors(c1, c2, d2);
				if (c3 != Colors::transparent) {
					color = Color::lerp_colors(color, c3, d3);
				}
			}
			this->fill_point(px, py, color);
		}
	}
}

void Image::resize(int width, int height)
{
	std::shared_ptr<Color[]> resized_pixels = std::shared_ptr<Color[]>(new Color[width * height]);
	for (size_t y = 0; y < height; y++) {
		for (size_t x = 0; x < width; x++) {
			size_t nx = x * m_width / width;
			size_t ny = y * m_height / height;
			resized_pixels[y * width + x] = m_pixels[ny * m_width + nx];
		}
	}
	this->m_pixels.reset();
	this->m_pixels = resized_pixels;
	m_width = width;
	m_height = height;
}

Vec4 Image::clamp_rect(int x, int y, int wd, int ht)
{
	//	completely out of bounds
	if ((x > m_width || x + wd < 0) || (y > m_height || y + ht < 0))
		return Vec4::zero;
	//	partially out of bounds
	return Vec4(
		Math::max(x, 0),
		Math::min(x + wd, m_width),
		Math::max(y, 0),
		Math::min(y + ht, m_height)
	);
}

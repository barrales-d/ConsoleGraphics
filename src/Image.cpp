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
	: m_width(width), m_height(height)
{
	m_pixels = std::unique_ptr<Color[]>(new Color[m_width * m_height]);
}

void Image::show()
{
	ansi::hide_cursor();
	for (size_t y = 0; y < m_height; y++) {
		for (size_t x = 0; x < m_width; x++) {
			auto& pixel = m_pixels[y * m_width + x];
			ansi::background(pixel);
			std::cout << deafult_fill;
		}
		ansi::reset();
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
	for (int py = rect_bound.z; py <= rect_bound.w; py++) {
		for (int px = rect_bound.x; px <= rect_bound.y; px++) {
			this->fill_point(px, py, bg_color);
		}
	}
}

void Image::fill_rect_line(int x, int y, int width, int height, Color bg_color)
{
	Vec4 rect_bound = clamp_rect(x, y, width, height);
	if (rect_bound == Vec4::zero)
		return;
	for (int py = rect_bound.z; py <= rect_bound.w; py++) {
		this->fill_point(rect_bound.x, py, bg_color);
		this->fill_point(rect_bound.y, py, bg_color);
	}

	for (int px = rect_bound.x; px <= rect_bound.y; px++) {
		this->fill_point(px, rect_bound.z, bg_color);
		this->fill_point(px, rect_bound.w, bg_color);
	}
}

void Image::fill_line(int x1, int y1, int x2, int y2, Color bg_color)
{
	Vec4 bound_box = clamp_rect(Math::min(x1, x2), Math::min(y1, y2), Math::abs(x2 - x1), Math::abs(y2 - y1));
	if (bound_box == Vec4::zero)
		return;

	int dx = x2 - x1;
	if (dx == 0) { //	vertical line
		for (int y = bound_box.z; y <= bound_box.w; y++)
			this->fill_point(x1, y, bg_color);
		return;
	}
	
	//	y = mx + b
	float m = (float)(y2 - y1) / (float)dx;
	float b = y1 - m * x1;
	for (int x = bound_box.x; x <= bound_box.y; x++) {
		int y = Math::floor(x * m + b);
		if (Math::abs(m) > 1.0f) {
			//	use clamp instead of min to allow for negative values?
			int next_y = Math::clamp(y + (int)m, bound_box.z, bound_box.w);
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

	float dr = r * r + 0.5f;
	for (int py = circle_bound.z; py < circle_bound.w; py++) {
		for (int px = circle_bound.x; px < circle_bound.y; px++) {
			float dx = (float)(px - x) + 0.5f;
			float dy = (float)(py - y) + 0.5f;
			if (dx * dx + dy * dy < dr)
				this->fill_point(px, py, bg_color);
		}
	}
}

void Image::fill_circle_line(int x, int y, int r, Color bg_color)
{
	for (float angle = 1; angle < 360.0f; angle++) {
		int px = Math::floor(r * sinf(angle * Math::PI / 180.0f) + x);
		int py = Math::floor(r * cosf(angle * Math::PI / 180.0f) + y);
		if (px < m_width && py < m_height && px >= 0 && py >= 0)
			this->fill_point(px, py, bg_color);
	}
}

void Image::fill_ellipse(int x, int y, int rx, int ry, Color bg_color)
{
	Vec4 ellipse_bound = clamp_rect(x - rx, y - ry, 2 * rx, 2 * ry);
	if (ellipse_bound == Vec4::zero)
		return;

	float drx = 2.0f * rx;
	float dry = 2.0f * ry;
	for (int py = ellipse_bound.z; py <= ellipse_bound.w; py++) {
		for (int px = ellipse_bound.x; px <= ellipse_bound.y; px++) {
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
	if (tri_bound == Vec4::zero)
		return;

	float epsilon = -0.000001f;
	for (int py = tri_bound.z; py < tri_bound.w; py++) {
		for (int px = tri_bound.x; px < tri_bound.y; px++) {
			float d1 = ((y2 - y3) * (px - x3) + (x3 - x2) * (py - y3)) / determinate;
			float d2 = ((y3 - y1) * (px - x3) + (x1 - x3) * (py - y3)) / determinate;
			float d3 = 1 - d1 - d2;

			if (d1 <= epsilon || d2 <= epsilon || d3 <= epsilon)
				continue;

			Color color = c1;
			color = Color::lerp_colors(d3, Color::lerp_colors(d2, c1, c2), c3);
			this->fill_point(px, py, color);
		}
	}
}
void Image::fill_sprite(int x, int y, const std::vector<uint32_t>& sprite, int width, int height)
{
	Vec4 sprite_bound = clamp_rect(x, y, width, height);
	for (int py = sprite_bound.z; py < sprite_bound.w; py++) {
		for (int px = sprite_bound.x; px < sprite_bound.y; px++) {
			size_t sx = (size_t)px - sprite_bound.x;
			size_t sy = (size_t)py - sprite_bound.z;
			Color sprite_col = Color(sprite[sy * width + sx]);
			this->fill_point(px, py, sprite_col);
		}
	}
}
void Image::fill_bezier_curve(Vec2 p1, Vec2 p2, Vec2 p3, Color c1, Color c2, float step)
{
	float t = 0;
	float nt = 1 - t;
	int sx = Math::floor((Math::pow(nt, 2) * p1.x) + (2 * nt * t * p2.x) + (Math::pow(t, 2) * p3.x));
	int sy = Math::floor((Math::pow(nt, 2) * p1.y) + (2 * nt * t * p2.y) + (Math::pow(t, 2) * p3.y));
	Vec2 start(sx, sy);
	for (t = step; t < 1.0f; t += step) {
		nt = 1 - t;
		int px = Math::ceil((Math::pow(nt, 2) * p1.x) + (2 * nt * t * p2.x) + (Math::pow(t, 2) * p3.x));
		int py = Math::ceil((Math::pow(nt, 2) * p1.y) + (2 * nt * t * p2.y) + (Math::pow(t, 2) * p3.y));
		Vec2 point(px, py);
		this->fill_bezier_curve_line(start, point, c1, c2, step);
	}
}

void Image::fill_bezier_curve(Vec2 p1, Vec2 p2, Vec2 p3, Vec2 p4, Color c1, Color c2, float step)
{
	float t = 0;
	float nt = 1 - t;
	int sx = Math::floor((Math::pow(nt, 3) * p1.x) + (3 * Math::pow(nt, 2) * t * p2.x) +
		(3 * nt * Math::pow(t, 2) * p3.x) + (Math::pow(t, 3) * p4.x));
	int sy = Math::floor((Math::pow(nt, 3) * p1.y) + (3 * Math::pow(nt, 2) * t * p2.y) +
		(3 * nt * Math::pow(t, 2) * p3.y) + (Math::pow(t, 3) * p4.y));
	Vec2 start(sx, sy);

	for (t = step; t < 1.0f; t += step) {
		nt = 1 - t;
		int px = Math::ceil((Math::pow(nt, 3) * p1.x) + (3 * Math::pow(nt, 2) * t * p2.x) +
			(3 * nt * Math::pow(t, 2) * p3.x) + (Math::pow(t, 3) * p4.x));

		int py = Math::ceil((Math::pow(nt, 3) * p1.y) + (3 * Math::pow(nt, 2) * t * p2.y) +
			(3 * nt * Math::pow(t, 2) * p3.y) + (Math::pow(t, 3) * p4.y));
		Vec2 point(px, py);
		this->fill_bezier_curve_line(start, point, c1, c2, step);
	}
}
void Image::fill_bezier_curve_line(Vec2 p1, Vec2 p2, Color c1, Color c2, float step)
{
	for (float t = 0; t < 1.0f; t += step) {
		int px = Math::floor((1 - t) * p1.x + t * p2.x);
		int py = Math::floor((1 - t) * p1.y + t * p2.y);
		if (px < m_width && py < m_height && px >= 0 && py >= 0)
			this->fill_point(px, py, Color::lerp_colors(t, c1, c2));
	}
}

void Image::fill_bezier_curve_line(Vec2 p1, Vec2 p2, Vec2 p3, Color c1, Color c2, float step)
{
	for (float t = 0; t < 1.0f; t += step) {
		float nt = 1 - t;
		int px = Math::floor((Math::pow(nt, 2) * p1.x) + (2 * nt * t * p2.x) + (Math::pow(t, 2) * p3.x));
		int py = Math::floor((Math::pow(nt, 2) * p1.y) + (2 * nt * t * p2.y) + (Math::pow(t, 2) * p3.y));

		if (px < m_width && py < m_height && px >= 0 && py >= 0)
			this->fill_point(px, py, Color::lerp_colors(t, c1, c2));
	}
}

void Image::fill_bezier_curve_line(Vec2 p1, Vec2 p2, Vec2 p3, Vec2 p4, Color c1, Color c2, float step)
{
	for (float t = 0; t < 1.0f; t += step) {
		float nt = 1 - t;
		int px = Math::floor((Math::pow(nt, 3) * p1.x) + (3 * Math::pow(nt, 2) * t * p2.x) + 
				 (3 * nt * Math::pow(t, 2) * p3.x) + (Math::pow(t, 3) * p4.x));

		int py = Math::floor((Math::pow(nt, 3) * p1.y) + (3 * Math::pow(nt, 2) * t * p2.y) + 
				 (3 * nt * Math::pow(t, 2) * p3.y) + (Math::pow(t, 3) * p4.y));

		if (px < m_width && py < m_height && px >= 0 && py >= 0)
			this->fill_point(px, py, Color::lerp_colors(t, c1, c2));
	}
}

void Image::resize(int width, int height)
{
	std::unique_ptr<Color[]> resized_pixels = std::unique_ptr<Color[]>(new Color[width * height]);
	for (size_t y = 0; y < height; y++) {
		for (size_t x = 0; x < width; x++) {
			size_t nx = x * m_width / width;
			size_t ny = y * m_height / height;
			resized_pixels[y * width + x] = m_pixels[ny * m_width + nx];
		}
	}
	this->m_pixels.reset();
	this->m_pixels = std::move(resized_pixels);
	m_width = width;
	m_height = height;
}

Vec4 Image::clamp_rect(int x, int y, int wd, int ht)
{
	//	completely out of bounds
	if ((x >= m_width || x + wd < 0) || (y >= m_height || y + ht < 0))
		return Vec4::zero;
	//	partially out of bounds
	return Vec4(
		Math::max(x, 0),
		Math::min(x + wd, m_width - 1),
		Math::max(y, 0),
		Math::min(y + ht, m_height - 1)
	);
}

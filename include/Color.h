#ifndef __COLOR_H__
#define __COLOR_H__
#include <inttypes.h>
#include <iostream>
#include "Vector.h"
#include "Math.h"

namespace CG {
	struct Color
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;

		Color() : r(0), g(0), b(0), a(0) {}

		Color(uint32_t color)
			: r((color >> 8 * 0) & 0xFF),
			g((color >> 8 * 1) & 0xFF),
			b((color >> 8 * 2) & 0xFF),
			a((color >> 8 * 3) & 0xFF) {}

		Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
			: r(r), g(g), b(b), a(a) {}

		Color(Vec3 rgb)
			: r(rgb.x), g(rgb.y), b(rgb.z), a(255) {}
		
		Color(Vec3f rgb)
			: r((uint8_t)(rgb.x * 255)), g((uint8_t)(rgb.y * 255)), b((uint8_t)(rgb.z * 255)), a(255) {}

		Color(Vec4 rgba)
			: r(rgba.x), g(rgba.y), b(rgba.z), a(rgba.w) {}

		Color(Vec4f rgba)
			: r((uint8_t)(rgba.x * 255.0f)), g((uint8_t)(rgba.y * 255.0f)), b((uint8_t)(rgba.z * 255.0f)), a((uint8_t)(rgba.w * 255.0f)) {}
		
		Color& operator=(int color)
		{
			r = ((color >> 8 * 0) & 0xFF);
			g = ((color >> 8 * 1) & 0xFF);
			b = ((color >> 8 * 2) & 0xFF);
			a = ((color >> 8 * 3) & 0xFF);
			return *this;
		}

		bool operator==(Color rhs) const
		{
			return (r == rhs.r &&
				g == rhs.g &&
				b == rhs.b &&
				a == rhs.a);
		}
		Vec4f rgba() const 
		{
			return Vec4f(
				this->r / 255.0f,
				this->g / 255.0f,
				this->b / 255.0f,
				this->a / 255.0f
			);
		}
		// alpha blending
		Color operator+(Color rhs) const noexcept
		{
			Vec4f bg = this->rgba();
			Vec4f fg = rhs.rgba();

			float alpha = fg.w + bg.w * (1 - fg.w);
			float epsilon = 0.00000001f; // both bg and fg have 0 transparency 
			if (alpha < epsilon)
				return CG::Color();

			return Color(Vec4f{
				(fg.x * fg.w + bg.x * bg.w * (1 - fg.w)) / alpha,
				(fg.y * fg.w + bg.y * bg.w * (1 - fg.w)) / alpha,
				(fg.z * fg.w + bg.z * bg.w * (1 - fg.w)) / alpha,
				alpha
			});
		}

		const uint32_t color() const { 
			return (a << 8 * 3) | (b << 8 * 2) | (g << 8 * 1) | (r << 8 * 0);
		}

		static inline Color lerp_colors(Color c1, Color c2, float t)
		{
			return Color(
				Math::lerp(c1.r, c2.r, t),
				Math::lerp(c1.g, c2.g, t),
				Math::lerp(c1.b, c2.b, t),
				Math::lerp(c1.a, c2.a, t)
			);
		}
	};

	namespace Colors {
		inline const Color transparent	{ 0x00000000 };
		inline const Color black		{ 0xFF000000 };
		inline const Color red			{ 0xFF0000FF };
		inline const Color green		{ 0xFF00FF00 };
		inline const Color blue			{ 0xFFFF0000 };
		inline const Color yellow		{ 0xFF00FFFF };
		inline const Color magenta		{ 0xFF9000FF };
		inline const Color cyan			{ 0xFFFFFF00 };
		inline const Color white		{ 0xFFFFFFFF };
		inline const Color darkgrey		{ 0xFF474747 };
		inline const Color lightred		{ 0xFF6F6FFF };
		inline const Color lightgreen	{ 0xFF90EE90 };
		inline const Color lightyellow	{ 0xFFE0FFFF };
		inline const Color lightblue	{ 0xFFE6D8AD };
		inline const Color lightpurple	{ 255, 85, 255, 255 };
		inline const Color turquoise	{ 0xFFC8D530 };
		inline const Color lightwhite	{ 0xFFD1D1D1 };
	}
}

#endif // __COLOR_H__

#ifndef __MATH_H__
#define __MATH_H__

namespace CG {
	namespace Math {
		inline constexpr float PI = 3.14159265359f;
		template<class T>
		void swap(T& x, T& y) { T tmp = x; x = y; y = tmp; }

		template<class T>
		T abs(T x) { return x < 0 ? -x : x; }

		template<class T>
		T sign(T x) { return static_cast<T>(x == 0 ? 0 : (x < 0 ? -1 : 1)); }

		template<class T>
		T clamp(T x, T min, T max)
		{
			if (min > max) swap(min, max);
			return x < min ? min : (x > max ? max : x);
		}

		template<class T>
		T lerp(T a, T b, float t) { return static_cast<T>(a + t * (b - a)); }

		template<class T>
		T min(T a, T b) { return a < b ? a : b; }

		template<class T, class... Args>
		T min(T a, T b, Args... args) { return Math::min(a, Math::min(b, args...)); }

		template<class T>
		T max(T a, T b) { return a > b ? a : b; }
		
		template<class T, class... Args>
		T max(T a, T b, Args... args) { return Math::max(a, Math::max(b, args...)); }

		template<class T>
		T ceil(T a) { return static_cast<T>(a < 0 ? int(a) : int(a) + 1); }

		template<class T>
		T floor(T a) { return static_cast<T>(a < 0 ? int(a) - 1 : int(a)); }
		
		template<class T>
		T pow(T a, int b) { return static_cast<T>(b == 1 ? a : pow(a, b - 1) * a); }
	}
}

#endif //	__MATH_H__
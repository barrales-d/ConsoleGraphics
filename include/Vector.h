#ifndef __VECTOR_H__
#define __VECTOR_H__

namespace CG
{
	template<class>
	struct __BASE_VEC2__;
	template<class>
	struct __BASE_VEC3__;
	template<class>
	struct __BASE_VEC4__;

	template<class T>
	struct __BASE_VEC2__ { 
		T x = 0, y = 0;
		static const __BASE_VEC2__<T> zero;
		__BASE_VEC2__() = default;
		__BASE_VEC2__(T x, T y)
			: x(x), y(y) {}
		__BASE_VEC2__(__BASE_VEC3__<T> v)
			: x(v.x), y(v.y) {}
		__BASE_VEC2__(__BASE_VEC4__<T> v)
			: x(v.x), y(v.y) {}
		T magnitude();
	};
	template<class T>
	struct __BASE_VEC3__ {
		T x = 0, y = 0, z = 0;
		static const __BASE_VEC3__<T> zero;
		__BASE_VEC3__() = default;
		__BASE_VEC3__(T x, T y, T z)
			: x(x), y(y), z(z) {}
		__BASE_VEC3__(__BASE_VEC2__<T> v)
			: x(v.x), y(v.y), z(0) {}
		__BASE_VEC3__(__BASE_VEC4__<T> v)
			: x(v.x), y(v.y), z(v.z) {}
		T magnitude();
	};
	template<class T>
	struct __BASE_VEC4__ {
		T x = 0, y = 0, z = 0, w = 0;
		static const __BASE_VEC4__<T> zero;
		__BASE_VEC4__() = default;
		__BASE_VEC4__(T x, T y, T z, T w)
			: x(x), y(y), z(z), w(w) {}
		__BASE_VEC4__(__BASE_VEC2__<T> v)
			: x(v.x), y(v.y), z(0), w(0) {}
		__BASE_VEC4__(__BASE_VEC3__<T> v)
			: x(v.x), y(v.y), z(v.z), w(0) {}
		T magnitude();
	};
	//	VECTOR 2 OPERATIONS
	template<class T>
	__BASE_VEC2__<T> operator+(__BASE_VEC2__<T> a, __BASE_VEC2__<T> b);
	template<class T>
	__BASE_VEC2__<T> operator-(__BASE_VEC2__<T> a, __BASE_VEC2__<T> b);
	//	dot product
	template<class T>
	T operator*(__BASE_VEC2__<T> a, __BASE_VEC2__<T> b);
	//	scalar operations
	template<class T>
	__BASE_VEC2__<T> operator+(__BASE_VEC2__<T> a, T scalar);
	template<class T>
	__BASE_VEC2__<T> operator-(__BASE_VEC2__<T> a, T scalar);
	template<class T>
	__BASE_VEC2__<T> operator*(__BASE_VEC2__<T> a, T scalar);
	template<class T>
	__BASE_VEC2__<T> operator/(__BASE_VEC2__<T> a, T scalar);

	//	VECTOR 3 OPERATIONS
	template<class T>
	__BASE_VEC3__<T> operator+(__BASE_VEC3__<T> a, __BASE_VEC3__<T> b);
	template<class T>
	__BASE_VEC3__<T> operator-(__BASE_VEC3__<T> a, __BASE_VEC3__<T> b);
	template<class T>
	T operator*(__BASE_VEC3__<T> a, __BASE_VEC3__<T> b);
	template<class T>
	__BASE_VEC3__<T> operator+(__BASE_VEC3__<T> a, T scalar);
	template<class T>
	__BASE_VEC3__<T> operator-(__BASE_VEC3__<T> a, T scalar);
	template<class T>
	__BASE_VEC3__<T> operator*(__BASE_VEC3__<T> a, T scalar);
	template<class T>
	__BASE_VEC3__<T> operator/(__BASE_VEC3__<T> a, T scalar);
	//	VECTOR 4 OPERATIONS
	template<class T>
	__BASE_VEC4__<T> operator+(__BASE_VEC4__<T> a, __BASE_VEC4__<T> b);
	template<class T>
	__BASE_VEC4__<T> operator-(__BASE_VEC4__<T> a, __BASE_VEC4__<T> b);
	template<class T>
	T operator*(__BASE_VEC4__<T> a, __BASE_VEC4__<T> b);
	template<class T>
	__BASE_VEC4__<T> operator+(__BASE_VEC4__<T> a, T scalar);
	template<class T>
	__BASE_VEC4__<T> operator-(__BASE_VEC4__<T> a, T scalar);
	template<class T>
	__BASE_VEC4__<T> operator*(__BASE_VEC4__<T> a, T scalar);
	template<class T>
	__BASE_VEC4__<T> operator/(__BASE_VEC4__<T> a, T scalar);
	template<class T>
	bool operator==(__BASE_VEC4__<T> a, __BASE_VEC4__<T> b);

	typedef __BASE_VEC2__<int> Vec2;
	typedef __BASE_VEC2__<float> Vec2f;
	typedef __BASE_VEC3__<int> Vec3;
	typedef __BASE_VEC3__<float> Vec3f;
	typedef __BASE_VEC4__<int> Vec4;
	typedef __BASE_VEC4__<float> Vec4f;
}

namespace CG
{
	template<class T>
	__BASE_VEC2__<T> const __BASE_VEC2__<T>::zero = __BASE_VEC2__<T>(0, 0);
	template<class T>
	__BASE_VEC3__<T> const __BASE_VEC3__<T>::zero = __BASE_VEC3__<T>(0, 0, 0);
	template<class T>
	__BASE_VEC4__<T> const __BASE_VEC4__<T>::zero = __BASE_VEC4__<T>(0, 0, 0, 0);

	template<class T>
	__BASE_VEC2__<T> operator+(__BASE_VEC2__<T> a, __BASE_VEC2__<T> b)
	{
		return __BASE_VEC2__<T>(a.x + b.x, a.y + b.y);
	}
	template<class T>
	__BASE_VEC2__<T> operator-(__BASE_VEC2__<T> a, __BASE_VEC2__<T> b)
	{
		return __BASE_VEC2__<T>(a.x - b.x, a.y - b.y);
	}
	template<class T>
	T operator*(__BASE_VEC2__<T> a, __BASE_VEC2__<T> b)
	{
		return a.x * b.x + a.y * b.y;
	}
	template<class T>
	__BASE_VEC2__<T> operator+(__BASE_VEC2__<T> a, T scalar)
	{
		return __BASE_VEC2__<T>(a.x + scalar, a.y + scalar);
	}
	template<class T>
	__BASE_VEC2__<T> operator-(__BASE_VEC2__<T> a, T scalar)
	{
		return __BASE_VEC2__<T>(a.x - scalar, a.y - scalar);
	}
	template<class T>
	__BASE_VEC2__<T> operator*(__BASE_VEC2__<T> a, T scalar)
	{
		return __BASE_VEC2__<T>(a.x * scalar, a.y * scalar);
	}
	template<class T>
	__BASE_VEC2__<T> operator/(__BASE_VEC2__<T> a, T scalar)
	{
		return __BASE_VEC2__<T>(a.x / scalar, a.y / scalar);
	}
	template<class T>
	T __BASE_VEC2__<T>::magnitude()
	{
		return static_cast<T>(sqrt(x * x + y * y));
	}
	//	VEC 3
	template<class T>
	__BASE_VEC3__<T> operator+(__BASE_VEC3__<T> a, __BASE_VEC3__<T> b)
	{
		return __BASE_VEC3__<T>(a.x + b.x, a.y + b.y, a.z + b.z);
	}
	template<class T>
	__BASE_VEC3__<T> operator-(__BASE_VEC3__<T> a, __BASE_VEC3__<T> b)
	{
		return __BASE_VEC3__<T>(a.x - b.x, a.y - b.y, a.z - b.z);
	}
	template<class T>
	T operator*(__BASE_VEC3__<T> a, __BASE_VEC3__<T> b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}
	template<class T>
	__BASE_VEC3__<T> operator+(__BASE_VEC3__<T> a, T scalar)
	{
		return __BASE_VEC3__<T>(a.x + scalar, a.y + scalar, a.z + scalar);
	}
	template<class T>
	__BASE_VEC3__<T> operator-(__BASE_VEC3__<T> a, T scalar)
	{
		return __BASE_VEC3__<T>(a.x - scalar, a.y - scalar, a.z - scalar);
	}
	template<class T>
	__BASE_VEC3__<T> operator*(__BASE_VEC3__<T> a, T scalar)
	{
		return __BASE_VEC3__<T>(a.x * scalar, a.y * scalar, a.z * scalar);
	}
	template<class T>
	__BASE_VEC3__<T> operator/(__BASE_VEC3__<T> a, T scalar)
	{
		return __BASE_VEC3__<T>(a.x / scalar, a.y / scalar, a.z / scalar);
	}
	template<class T>
	T __BASE_VEC3__<T>::magnitude()
	{
		return static_cast<T>(sqrt(x * x + y * y + z * z));
	}
	//	VEC4
	template<class T>
	__BASE_VEC4__<T> operator+(__BASE_VEC4__<T> a, __BASE_VEC4__<T> b)
	{
		return __BASE_VEC4__<T>(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
	}
	template<class T>
	__BASE_VEC4__<T> operator-(__BASE_VEC4__<T> a, __BASE_VEC4__<T> b)
	{
		return __BASE_VEC4__<T>(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
	}
	template<class T>
	T operator*(__BASE_VEC4__<T> a, __BASE_VEC4__<T> b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	}
	template<class T>
	__BASE_VEC4__<T> operator+(__BASE_VEC4__<T> a, T scalar)
	{
		return __BASE_VEC4__<T>(a.x + scalar, a.y + scalar, a.z + scalar, a.w + scalar);
	}
	template<class T>
	__BASE_VEC4__<T> operator-(__BASE_VEC4__<T> a, T scalar)
	{
		return __BASE_VEC4__<T>(a.x - scalar, a.y - scalar, a.z - scalar, a.w - scalar);
	}
	template<class T>
	__BASE_VEC4__<T> operator*(__BASE_VEC4__<T> a, T scalar)
	{
		return __BASE_VEC4__<T>(a.x * scalar, a.y * scalar, a.z * scalar, a.w * scalar);
	}
	template<class T>
	__BASE_VEC4__<T> operator/(__BASE_VEC4__<T> a, T scalar)
	{
		return __BASE_VEC4__<T>(a.x / scalar, a.y / scalar, a.z / scalar, a.w / scalar);
	}
	template<class T>
	bool operator==(__BASE_VEC4__<T> a, __BASE_VEC4__<T> b) 
	{
		return (a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w);
	}
	template<class T>
	T __BASE_VEC4__<T>::magnitude()
	{
		return static_cast<T>(sqrt(x * x + y * y + z * z + w * w));
	}
}

#endif //	__VECTOR_H__
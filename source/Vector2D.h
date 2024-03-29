#pragma once
#include <string>
#include <sstream>


template <typename T> class Vector2D
{
public:
	T x;
	T y;
	
	//Description
	std::string description() const {
		std::stringstream s;
		s << "(" << x << ", " << y << ")";
		return s.str();
	}
	
	//Conversion to frequently used types
	inline operator Vector2D<int>() const { return Vector2D<int>(x, y); }
	inline operator Vector2D<float>() const { return Vector2D<float>(x, y); }
	inline operator Vector2D<double>() const { return Vector2D<double>(x, y); }
	
	//Constructors
	Vector2D()
	{
		x = 0;
		y = 0;
	}
	Vector2D(T x, T y)
	{
		this->x = x;
		this->y = y;
	}
	
	//Operators
	Vector2D<T>& operator= (Vector2D<T> v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}
	Vector2D<T> operator- () const	{ return Vector2D<T>(-x, -y); }
	
	//Boolean operators
	bool operator ==(Vector2D<T> v) const {
		return (x == v.x && y == v.y);
	}
	bool operator !=(Vector2D<T> v) const {
		return (x != v.x || y != v.y);
	}
	
	//Vector-Vector
	Vector2D<T> operator+ (Vector2D<T> v) const	{ return Vector2D<T>(x+v.x, y+v.y); }
	Vector2D<T> operator- (Vector2D<T> v) const	{ return Vector2D<T>(x-v.x, y-v.y); }
	Vector2D<T> operator* (Vector2D<T> v) const	{ return Vector2D<T>(x*v.x, y*v.y); }
	Vector2D<T> operator/ (Vector2D<T> v) const	{ return Vector2D<T>(x/v.x, y/v.y); }
	//Vector-Scalar
	Vector2D<T> operator+ (T v) const	{ return Vector2D<T>(x+v, y+v); }
	Vector2D<T> operator- (T v) const	{ return Vector2D<T>(x-v, y-v); }
	Vector2D<T> operator* (T v) const	{ return Vector2D<T>(x*v, y*v); }
	Vector2D<T> operator/ (T v) const	{ return Vector2D<T>(x/v, y/v); }
	
	//Vector-Vector
	Vector2D<T>& operator+= (Vector2D<T> v)	{ x += v.x; y += v.y; return *this; }
	Vector2D<T>& operator-= (Vector2D<T> v)	{ x -= v.x; y -= v.y; return *this;	}
	Vector2D<T>& operator*= (Vector2D<T> v)	{ x *= v.x; y *= v.y; return *this; }
	Vector2D<T>& operator/= (Vector2D<T> v)	{ x /= v.x; y /= v.y; return *this; }
	
	//Vector-Scalar
	Vector2D<T>& operator+= (T v)	{ x += v; y += v; return *this; }
	Vector2D<T>& operator-= (T v)	{ x -= v; y -= v; return *this; }
	Vector2D<T>& operator*= (T v)	{ x *= v; y *= v; return *this; }
	Vector2D<T>& operator/= (T v)	{ x /= v; y /= v; return *this; }
	
	//Operations
	inline T length() const
	{
		return sqrt(x*x + y*y);
	}
	
	double normalize()
	{
		T length = this->length();
		
		x /= length;
		y /= length;
		
		return length;
	}
	
	inline T dot(Vector2D<T> v) const
	{
		return (x*v.x + y*v.y);
	}
};

//Convenience typedefs
typedef Vector2D<int> int2;
typedef Vector2D<float> float2;
typedef Vector2D<double> double2;

#pragma once
template<typename T>
class Vec2
{

public:

	Vec2() = default;
	Vec2(T a, T b) :
		x(a),
		y(b)
	{

	}
	/*template<typename S>
	explicit Vec2(const Vec2<S>& src):
		x((S)src.x),
		y((S)src.y)
	{

	}*/
	Vec2 operator+(const Vec2& rhs) const
	{
		return Vec2(x + rhs.x, y + rhs.y);
	}
	Vec2& operator+=(const Vec2& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
	Vec2 operator-(const Vec2& rhs) const
	{
		return Vec2(x - rhs.x, y - rhs.y);
	}
	Vec2& operator-=(Vec2& rhs)
	{
		return *this = *this - rhs;
	}
	Vec2 operator*(T rhs) const
	{
		return Vec2(x*rhs, y*rhs);
	}
	Vec2& operator*=(T rhs)
	{
		return *this = *this *rhs;
	}
public:
	T x;
	T y;
};

typedef Vec2<float> Vec2f;
typedef Vec2<int> Vec2i;


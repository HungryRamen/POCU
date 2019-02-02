#include "Point.h"

namespace lab4
{
	Point::Point():
		mX(0.f),
		mY(0.f)
	{
	}

	Point::Point(float x, float y) :
		mX(x),
		mY(y)
	{
	}

	Point::~Point()
	{
	}

	Point Point::operator+(const Point& other) const
	{
		Point pointTemp(mX, mY);
		pointTemp.mX += other.GetX();
		pointTemp.mY += other.GetY();
		return pointTemp;
	}

	Point Point::operator-(const Point& other) const
	{
		Point pointTemp(mX, mY);
		pointTemp.mX -= other.GetX();
		pointTemp.mY -= other.GetY();
		return pointTemp;
	}

	float Point::Dot(const Point& other) const
	{
		float x = mX;
		float y = mY;
		x *= other.GetX();
		y *= other.GetY();
		return x + y;
	}

	Point Point::operator*(float operand) const
	{
		Point pointTemp(mX, mY);
		pointTemp.mX *= operand;
		pointTemp.mY *= operand;
		return pointTemp;
	}

	Point operator*(float operand, const Point& other)
	{
		Point pointTemp(other.GetX(), other.GetY());
		pointTemp.mX *= operand;
		pointTemp.mY *= operand;
		return pointTemp;
	}

	float Point::GetX() const
	{
		return mX;
	}

	float Point::GetY() const
	{
		return mY;
	}

	void Point::SetX(float x)
	{
		mX = x;
	}

	void Point::SetY(float y)
	{
		mY = y;
	}
}
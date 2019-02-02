#pragma once

namespace lab4
{
	class Point
	{
	public:
		Point();
		Point(float x, float y);
		~Point();

		Point operator+(const Point& other) const;
		Point operator-(const Point& other) const;
		float Dot(const Point& other) const;
		Point operator*(float operand) const;
		friend Point operator*(float multiplier, const Point& other);

		float GetX() const;
		float GetY() const;
		void SetX(float x);
		void SetY(float y);
	private:
		float mX;
		float mY;
	};
}
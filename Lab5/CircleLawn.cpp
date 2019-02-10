#include "CircleLawn.h"

namespace lab5
{
	CircleLawn::CircleLawn(unsigned int radius) :
		mRadius(radius)
	{
		mArea = static_cast<unsigned int>(floor(mRadius * mRadius * 3.14 + 0.5));
	}
	CircleLawn::~CircleLawn()
	{
	}
	unsigned int CircleLawn::GetArea() const
	{
		return mArea;
	}
}
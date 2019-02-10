#include "EquilateralTriangleLawn.h"

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int width) :
		mWidth(width)
	{
		mArea = static_cast<unsigned int>(sqrt(3) / 4 * (mWidth * mWidth));
	}
	EquilateralTriangleLawn::~EquilateralTriangleLawn()
	{
	}
	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		return mArea;
	}
	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		return mWidth * 3 * 4;
	}
	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		switch (fenceType)
		{
		case RED_CEDAR:
			return mWidth * 3 * 6;
		case SPRUCE:
			return mWidth * 3 * 7;
		}
		return 0;
	}
}
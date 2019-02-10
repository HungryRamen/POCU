#include "RectangleLawn.h"

namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned int width, unsigned int height) :
		mWidth(width),
		mHeight(height)
	{
		mArea = mWidth * mHeight;
	}
	RectangleLawn::~RectangleLawn()
	{
	}
	unsigned int RectangleLawn::GetArea() const
	{
		return mArea;
	}
	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		return ((mWidth * 2) + (mHeight * 2)) * 4;
	}
	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		switch (fenceType)
		{
		case RED_CEDAR:
			return ((mWidth * 2) + (mHeight * 2)) * 6;
		case SPRUCE:
			return ((mWidth * 2) + (mHeight * 2)) * 7;
		}
		return 0;
	}
}
#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine():
		mSize(0)
	{
	}

	PolyLine::PolyLine(const PolyLine& other):
		mSize(other.mSize)
	{
		for (unsigned int index = 0; index < other.mSize; index++)
		{
			mPoint[index] = other.mPoint[index];
		}
	}

	PolyLine::~PolyLine()
	{
		for (unsigned int index = 0; index < mSize; index++)
		{
			delete mPoint[index];
		}
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mSize >= 10)
		{
			return false;
		}
		mPoint[mSize++] = new Point(x, y);
		return true;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mSize >= 10)
		{
			return false;
		}
		mPoint[mSize++] = point;

		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mSize)
		{
			return false;
		}
		else
		{
			delete mPoint[i];
			for (unsigned int index = i; index < mSize - 1; index++)
			{
				mPoint[index] = mPoint[index + 1];
			}
		}
		mSize--;
		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mSize == 0)
			return false;
		outMin->SetX(mPoint[0]->GetX());
		outMin->SetY(mPoint[0]->GetY());
		outMax->SetX(mPoint[0]->GetX());
		outMax->SetY(mPoint[0]->GetY());
		for (unsigned int index = 1; index < mSize; index++)
		{
			if (outMin->GetX() > mPoint[index]->GetX())
			{
				outMin->SetX(mPoint[index]->GetX());
			}
			if(outMin->GetY() > mPoint[index]->GetY())
			{
				outMin->SetY(mPoint[index]->GetY());
			}
			if (outMax->GetX() < mPoint[index]->GetX())
			{
				outMax->SetX(mPoint[index]->GetX());
			}
			if (outMax->GetY() < mPoint[index]->GetY())
			{
				outMax->SetY(mPoint[index]->GetY());
			}
		}
		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i >= mSize)
		{
			return nullptr;
		}
		return mPoint[i];
	}
}
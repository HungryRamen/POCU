#include "Airplane.h"
#include "Boat.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount) :
		Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	unsigned int Boat::GetMaxSpeed()
	{
		return GetSailSpeed();
	}

	void Boat::Travel()
	{
		if (mMoveCount < 2)
		{
			mMoveCount++;
			mTotalMoveKm += GetMaxSpeed();
		}
		else if (mRestCount < 1)
		{
			mRestCount++;
			if (mRestCount >= 1)
			{
				mRestCount = 0;
				mMoveCount = 0;
			}
		}
	}

	unsigned int Boat::GetSailSpeed()
	{
		int temp = 800 - 10 * GetPassengersTotalWeight();
		return temp > 20 ? static_cast<unsigned int>(temp) : 20;
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		return Boatplane(plane, *this);
	}
}
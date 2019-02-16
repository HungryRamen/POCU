#include "Motorcycle.h"
#include "MyMath.h"
namespace assignment2
{
	Motorcycle::Motorcycle() :
		Vehicle(2)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetMaxSpeed()
	{
		return GetDriveSpeed();
	}

	void Motorcycle::Travel()
	{
		if (mMoveCount < 5)
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

	unsigned int Motorcycle::GetDriveSpeed()
	{
		int temp = MyMath::Round(MyMath::Power(-(GetPassengersTotalWeight() / 15.f), 3.f) + 2 * GetPassengersTotalWeight() + 400);
		return temp > 0 ? static_cast<unsigned int>(temp) : 0;
	}
}
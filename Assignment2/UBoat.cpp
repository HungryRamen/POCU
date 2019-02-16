#include "UBoat.h"
#include "MyMath.h"
namespace assignment2
{
	UBoat::UBoat() :
		Vehicle(50)
	{
	}

	UBoat::~UBoat()
	{
	}

	unsigned int UBoat::GetMaxSpeed()
	{
		return GetSailSpeed() > GetDiveSpeed() ? GetSailSpeed() : GetDiveSpeed();
	}

	void UBoat::Travel()
	{
		if (mMoveCount < 2)
		{
			mMoveCount++;
			mTotalMoveKm += GetMaxSpeed();
		}
		else if (mRestCount < 4)
		{
			mRestCount++;
			if (mRestCount >= 4)
			{
				mRestCount = 0;
				mMoveCount = 0;
			}
		}
	}

	unsigned int UBoat::GetSailSpeed()
	{
		int temp = mymath::Round(550 - GetPassengersTotalWeight() / 10.f);
		return temp > 200 ? static_cast<unsigned int>(temp) : 200;
	}

	unsigned int UBoat::GetDiveSpeed()
	{
		return static_cast<unsigned int>(mymath::Round(500 * mymath::Log((GetPassengersTotalWeight() + 150) / 150.f) + 30));
	}
}
#include "Airplane.h"
#include "Boat.h"
#include "MyMath.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount) :
		Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
	}

	unsigned int Airplane::GetMaxSpeed()
	{
		return GetDriveSpeed() > GetFlySpeed() ? GetDriveSpeed() : GetFlySpeed();
	}

	void Airplane::Travel()
	{
		if (mMoveCount < 1)
		{
			mMoveCount++;
			mTotalMoveKm += GetMaxSpeed();
		}
		else if (mRestCount < 3)
		{
			mRestCount++;
			if (mRestCount >= 3)
			{
				mRestCount = 0;
				mMoveCount = 0;
			}
		}
	}

	unsigned int Airplane::GetDriveSpeed()
	{
		unsigned int temp = static_cast<unsigned int>(MyMath::Round(4 * MyMath::Power(MyMath::EULER_NUM, ((-GetPassengersTotalWeight() + 400) / 70.f))));
		return temp;
	}

	unsigned int Airplane::GetFlySpeed()
	{
		unsigned int temp = static_cast<unsigned int>(MyMath::Round(200 * MyMath::Power(MyMath::EULER_NUM, ((-GetPassengersTotalWeight() + 800) / 500.f))));
		return temp;
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		return Boatplane(*this, boat);
	}
}
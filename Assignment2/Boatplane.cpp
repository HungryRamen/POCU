#include "Boatplane.h"
#include "Airplane.h"
#include "Boat.h"
#include "MyMath.h"
namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount) :
		Vehicle(maxPassengersCount)
	{
	}

	Boatplane::Boatplane(Airplane& plane, Boat& boat) :
		Vehicle(plane.GetMaxPassengersCount() + boat.GetMaxPassengersCount())
	{
		for (unsigned int index = 0; index < plane.GetPassengersCount(); index++)
		{
			AddPassenger(plane.GetPassenger(index));
		}
		for (unsigned int index = 0; index < boat.GetPassengersCount(); index++)
		{
			AddPassenger(boat.GetPassenger(index));
		}
		plane.PassengersExit();
		boat.PassengersExit();
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetMaxSpeed()
	{
		return GetFlySpeed() > GetSailSpeed() ? GetFlySpeed() : GetSailSpeed();
	}

	void Boatplane::Travel()
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

	unsigned int Boatplane::GetFlySpeed()
	{
		unsigned int temp = static_cast<unsigned int>(MyMath::Round(150 * MyMath::Power(MyMath::EULER_NUM, ((-GetPassengersTotalWeight() + 500) / 300.f))));
		return temp;
	}

	unsigned int Boatplane::GetSailSpeed()
	{
		int temp = MyMath::Round(800 - 1.7f * GetPassengersTotalWeight());
		return temp > 20 ? static_cast<unsigned int>(temp) : 20;
	}

}
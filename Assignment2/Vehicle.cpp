#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount) :
		mPassengersCount(0),
		mMaxPassengersCount(maxPassengersCount),
		mPassengersTotalWeight(0),
		mTotalMoveKm(0),
		mMoveCount(0),
		mRestCount(0)
	{
	}

	Vehicle::~Vehicle()
	{
		for (unsigned int index = 0; index < mPassengersCount; index++)
		{
			delete mPassengers[index];
		}
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mPassengersCount >= mMaxPassengersCount)
		{
			return false;
		}
		mPassengers[mPassengersCount++] = person;
		mPassengersTotalWeight += person->GetWeight();
		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i >= mPassengersCount)
		{
			return false;
		}
		mPassengersTotalWeight -= mPassengers[i]->GetWeight();
		delete mPassengers[i];
		for (unsigned int index = i; index < mPassengersCount - 1; index++)
		{
			mPassengers[index] = mPassengers[index + 1];
		}
		mPassengersCount--;
		return true;
	}

	void Vehicle::PassengersExit()
	{
		mPassengersCount = 0;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mPassengersCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}

	unsigned int Vehicle::GetTotalMoveKm() const
	{
		return mTotalMoveKm;
	}

	int Vehicle::GetPassengersTotalWeight() const
	{
		return static_cast<int>(mPassengersTotalWeight);
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i < mPassengersCount)
		{
			return mPassengers[i];
		}
		return nullptr;
	}
}
#pragma once

#include "Person.h"

namespace assignment2
{

	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		virtual ~Vehicle();

		virtual unsigned int GetMaxSpeed() = 0;
		virtual void Travel() = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		void PassengersExit();
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetTotalMoveKm() const;
		int GetPassengersTotalWeight() const;
	protected:
		unsigned int mTotalMoveKm;
		int mMoveCount;
		int mRestCount;
	private:
		const Person* mPassengers[100];
		unsigned int mPassengersCount;
		unsigned int mMaxPassengersCount;
		unsigned int mPassengersTotalWeight;
	};
}
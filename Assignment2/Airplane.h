#pragma once

#include "Boatplane.h"
#include "IDrivable.h"

namespace assignment2
{
	class Boat;

	class Airplane : public Vehicle, public IDrivable, public IFlyable
	{
	public:
		Airplane(unsigned int maxPassengersCount);
		~Airplane();

		virtual unsigned int GetMaxSpeed();
		virtual void Travel();

		virtual unsigned int GetDriveSpeed();
		virtual unsigned int GetFlySpeed();

		Boatplane operator+(Boat& boat);
	};
}
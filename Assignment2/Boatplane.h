#pragma once

#include "Vehicle.h"
#include "IFlyable.h"
#include "ISailable.h"

namespace assignment2
{
	class Airplane;
	class Boat;
	class Boatplane : public Vehicle, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		Boatplane(Airplane& plane, Boat& boat);
		~Boatplane();

		virtual unsigned int GetMaxSpeed();
		virtual void Travel();

		virtual unsigned int GetFlySpeed();
		virtual unsigned int GetSailSpeed();
	};
}
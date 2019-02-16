#pragma once

#include "Boatplane.h"


namespace assignment2
{
	class Airplane;

	class Boat :public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		~Boat();

		virtual unsigned int GetMaxSpeed();
		virtual void Travel();

		virtual unsigned int GetSailSpeed();

		Boatplane operator+(Airplane& plane);
	};
}
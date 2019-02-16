#pragma once

#include "Vehicle.h"
#include "ISailable.h"
#include "IDivable.h"

namespace assignment2
{
	class UBoat : public Vehicle, public ISailable, public IDivable
	{
	public:
		UBoat();
		~UBoat();

		virtual unsigned int GetMaxSpeed();
		virtual void Travel();

		virtual unsigned int GetSailSpeed();
		virtual unsigned int GetDiveSpeed();
	};
}
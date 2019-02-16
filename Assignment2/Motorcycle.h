#pragma once

#include "Vehicle.h"
#include "IDrivable.h"

namespace assignment2
{
	class Motorcycle : public Vehicle, public IDrivable
	{
	public:
		Motorcycle();
		~Motorcycle();

		virtual unsigned int GetMaxSpeed();
		virtual void Travel();

		virtual unsigned int GetDriveSpeed();
	};
}
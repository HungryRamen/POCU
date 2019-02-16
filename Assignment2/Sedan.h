#pragma once

#include "Vehicle.h"
#include "IDrivable.h"

namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable
	{
	public:
		Sedan();
		~Sedan();

		virtual unsigned int GetMaxSpeed();
		virtual void Travel();

		virtual unsigned int GetDriveSpeed();

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();
	private:
		const Trailer* mTrailer;
	};
}
#pragma once

#include "Vehicle.h"

namespace assignment2
{
	class DeusExMachina
	{
	public:
		DeusExMachina();
		~DeusExMachina();
		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;
	private:
		static DeusExMachina* mDeusExMachina;
		Vehicle* mVehicles[10];
		unsigned int mVehicleCount;
	};
}
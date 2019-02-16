#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::mDeusExMachina = nullptr;

	DeusExMachina::DeusExMachina() :
		mVehicleCount(0)
	{
	}

	DeusExMachina::~DeusExMachina()
	{
		for (unsigned int index = 0; index < mVehicleCount; index++)
		{
			delete mVehicles[index];
		}
		delete mDeusExMachina;
	}

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mDeusExMachina == nullptr)
		{
			mDeusExMachina = new DeusExMachina;
		}
		return mDeusExMachina;
	}

	void DeusExMachina::Travel() const
	{
		for (unsigned int index = 0; index < mVehicleCount; index++)
		{
			mVehicles[index]->Travel();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mVehicleCount >= 10)
		{
			return false;
		}
		mVehicles[mVehicleCount++] = vehicle;
		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i >= mVehicleCount)
		{
			return false;
		}
		delete mVehicles[i];
		for (unsigned int index = i; index < mVehicleCount - 1; index++)
		{
			mVehicles[index] = mVehicles[index + 1];
		}
		mVehicleCount--;
		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mVehicleCount == 0)
			return nullptr;
		Vehicle* vehicleTemp = mVehicles[0];
		for (unsigned int index = 1; index < mVehicleCount; index++)
		{
			if (vehicleTemp->GetTotalMoveKm() < mVehicles[index]->GetTotalMoveKm())
			{
				vehicleTemp = mVehicles[index];
			}
		}
		return vehicleTemp;
	}
}
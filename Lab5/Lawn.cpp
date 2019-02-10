#include "Lawn.h"

namespace lab5
{
	Lawn::Lawn()
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassTypePrice(eGrassType grassType) const
	{
		switch (grassType)
		{
		case BERMUDA:
			return 800;
		case BAHIA:
			return 500;
		case BENTGRASS:
			return 300;
		case PERENNIAL_RYEGRASS:
			return 250;
		case ST_AUGUSTINE:
			return 450;
		}
		return 0;
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		return static_cast<unsigned int>(floor(floor(GetMinimumSodRollsCount() * 0.3) * GetGrassTypePrice(grassType) / 100 + 0.5));
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		double temp1 = static_cast<double>(mArea) / 0.3;
		return static_cast<unsigned int>(ceil(temp1));
	}
}
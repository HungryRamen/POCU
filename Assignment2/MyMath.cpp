#include <math.h>
#include "MyMath.h"
namespace MyMath
{
	int Ceil(float value)
	{
		int intValue = static_cast<int>(value);
		if (value == static_cast<float>(intValue))
		{
			return intValue;
		}
		return intValue + 1;
	}

	int Floor(float value)
	{
		return static_cast<int>(value);
	}

	int Round(float value)
	{
		return static_cast<int>(value + 0.5f);
	}

	float Power(float value, float power)
	{
		return powf(value, power);
	}
	float Log(float value)
	{
		return logf(value);
	}
}

#pragma once
#include <math.h>

namespace mymath
{
	double Round(double value)
	{
		double value2;
		if (value < 0)
			value2 = (static_cast<double>(value) - 0.0005) * 1000;
		else
			value2 = (static_cast<double>(value) + 0.0005) * 1000;
		int value3 = static_cast<int>(value2);
		return static_cast<double>(value3) / 1000;
	}
}
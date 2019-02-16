#pragma once

#include <vector>

namespace lab6
{
	struct Number
	{
		int Num = 0;
		int NumCount = 0;
	};

	int Sum(const std::vector<int>& v);
	int Min(const std::vector<int>& v);
	int Max(const std::vector<int>& v);
	float Average(const std::vector<int>& v);
	int NumberWithMaxOccurrence(const std::vector<int>& v);
	void SortDescending(std::vector<int>& v);
}
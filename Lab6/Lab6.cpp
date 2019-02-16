#include "Lab6.h"

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		int value = 0;
		for (unsigned int index = 0; index < v.size(); index++)
		{
			value += v[index];
		}
		return value;
	}

	int Min(const std::vector<int>& v)
	{
		int min = 2147483647;
		for (unsigned int index = 0; index < v.size(); index++)
		{
			if (min > v[index])
			{
				min = v[index];
			}
		}
		return min;
	}

	int Max(const std::vector<int>& v)
	{
		int max = -2147483647;
		for (unsigned int index = 0; index < v.size(); index++)
		{
			if (max < v[index])
			{
				max = v[index];
			}
		}
		return max;
	}

	float Average(const std::vector<int>& v)
	{
		int sum = Sum(v);
		float size = static_cast<float>(v.size());
		return sum / size;
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		if (static_cast<int>(v.size()) == 0)
			return 0;
		Number* number = new Number[v.size()];
		int numberCount = 0;
		bool bCheck = false;
		for (unsigned int index1 = 0; index1 < v.size(); index1++)
		{
			bCheck = false;
			for (int index2 = 0; index2 < numberCount; index2++)
			{
				if (number[index2].Num == v[index1])
				{
					number[index2].NumCount++;
					bCheck = true;
					break;
				}
			}
			if (bCheck)
				continue;
			number[numberCount].Num = v[index1];
			number[numberCount++].NumCount++;
		}

		Number Maxnumber = number[0];
		for (int index = 1; index < numberCount; index++)
		{
			if (Maxnumber.NumCount < number[index].NumCount)
			{
				Maxnumber = number[index];
			}
		}
		delete[] number;
		return Maxnumber.Num;
	}

	void SortDescending(std::vector<int>& v)
	{
		for (unsigned int index1 = 0; index1 < v.size(); index1++)
		{
			for (unsigned int index2 = v.size() - 1; index2 > index1; index2--)
			{
				if (v[index2 - 1] < v[index2])
				{
					int temp = v[index2 - 1];
					v[index2 - 1] = v[index2];
					v[index2] = temp;
				}
			}
		}
	}

}
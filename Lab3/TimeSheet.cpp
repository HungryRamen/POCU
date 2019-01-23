#include "Timesheet.h"

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries) :mName(name), mMaxEntries(maxEntries), mCountEntries(0)
	{
		mTime = new unsigned int[maxEntries];
		memset(mTime, 0, mMaxEntries * sizeof(unsigned int));
	}

	TimeSheet::TimeSheet(const TimeSheet & copy) :mName(copy.mName), mMaxEntries(copy.mMaxEntries), mCountEntries(copy.mCountEntries)
	{
		mTime = new unsigned int[copy.mMaxEntries];
		memcpy(mTime, copy.mTime, copy.mCountEntries * sizeof(unsigned int));
	}

	TimeSheet::~TimeSheet()
	{
		delete mTime;
		mTime = nullptr;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours <= 0 || mMaxEntries <= mCountEntries)
		{
			return;
		}
		if (mTime[mCountEntries] + timeInHours > 10)
		{
			return;
		}
		mTime[mCountEntries++] += timeInHours;
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index > mCountEntries - 1)
		{
			return -1;
		}
		return mTime[index];
	}

	int TimeSheet::GetTotalTime() const
	{
		int tempTotalTime = 0;
		for (unsigned int index = 0; index < mCountEntries; index++)
		{
			tempTotalTime += mTime[index];
		}
		return tempTotalTime;
	}

	float TimeSheet::GetAverageTime() const
	{
		float countEntries = (float)mCountEntries;
		return GetTotalTime() / countEntries;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		float sum = 0.0f;
		float deviation = 0.0f;
		float averagetime = GetAverageTime();
		for (unsigned int index = 0; index < mCountEntries; index++)
		{
			deviation = mTime[index] - averagetime;
			sum += deviation * deviation;
		}

		return sqrtf(sum / mCountEntries - 1);
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}
}
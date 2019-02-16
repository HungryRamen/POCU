#include "Sedan.h"
#include "Trailer.h"
namespace assignment2
{
	Sedan::Sedan() :
		Vehicle(4),
		mTrailer(nullptr)
	{
	}

	Sedan::~Sedan()
	{
		delete mTrailer;
	}

	unsigned int Sedan::GetMaxSpeed()
	{
		return GetDriveSpeed();
	}

	void Sedan::Travel()
	{
		if (mTrailer == nullptr)
		{
			if (mMoveCount < 5)
			{
				mMoveCount++;
				mTotalMoveKm += GetMaxSpeed();
			}
			else if (mRestCount < 1)
			{
				mRestCount++;
				if (mRestCount >= 1)
				{
					mRestCount = 0;
					mMoveCount = 0;
				}
			}
		}
		else
		{
			if (mMoveCount < 5)
			{
				mMoveCount++;
				mTotalMoveKm += GetMaxSpeed();
			}
			else if (mRestCount < 2)
			{
				mRestCount++;
				if (mRestCount >= 2)
				{
					mRestCount = 0;
					mMoveCount = 0;
				}
			}
		}
	}

	unsigned int Sedan::GetDriveSpeed()
	{
		if (mTrailer == nullptr)
		{
			if (GetPassengersTotalWeight() > 350)
				return 300;
			else if (GetPassengersTotalWeight() > 260)
				return 380;
			else if (GetPassengersTotalWeight() > 160)
				return 400;
			else if (GetPassengersTotalWeight() > 80)
				return 458;
		}
		else
		{
			if (GetPassengersTotalWeight() + mTrailer->GetWeight() > 350)
				return 300;
			else if (GetPassengersTotalWeight() + mTrailer->GetWeight() > 260)
				return 380;
			else if (GetPassengersTotalWeight() + mTrailer->GetWeight() > 160)
				return 400;
			else if (GetPassengersTotalWeight() + mTrailer->GetWeight() > 80)
				return 458;
		}
		return 480;
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (mTrailer == nullptr)
		{
			mTrailer = trailer;
			return true;
		}
		return false;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mTrailer == nullptr)
		{
			return false;
		}
		delete mTrailer;
		mTrailer = nullptr;
		return true;
	}
}
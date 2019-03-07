#pragma once
#include <queue>
#include "MyMath.h"
namespace assignment3
{
	template<typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		~SmartQueue();
		void Enqueue(T value);
		T Peek();
		T Dequeue();
		T Max();
		T Min();
		double Average();
		T Sum();
		T RoundT(T value);
		double Variance();
		double StandardDeviation();
		unsigned int Count();
	private:
		std::queue<T> mQueue;
		T mQueueSum;
		T mQueueSigma;
	};
	template<typename T>
	inline SmartQueue<T>::SmartQueue() :
		mQueueSum(0),
		mQueueSigma(0)
	{
	}
	template<typename T>
	inline SmartQueue<T>::~SmartQueue()
	{
	}
	template<typename T>
	inline T SmartQueue<T>::RoundT(T value)
	{
		double value2;
		if (value < 0)
			value2 = (static_cast<double>(value) - 0.0005) * 1000;
		else
			value2 = (static_cast<double>(value) + 0.0005) * 1000;
		int value3 = static_cast<int>(value2);
		return static_cast<T>(value3) / 1000;
	}
	template<typename T>
	inline void SmartQueue<T>::Enqueue(T value)
	{
		mQueueSum += value;
		mQueueSigma += value * value;
		mQueue.push(value);
	}
	template<typename T>
	inline T SmartQueue<T>::Peek()
	{
		return mQueue.front();
	}
	template<typename T>
	inline T SmartQueue<T>::Dequeue()
	{
		T value = mQueue.front();
		mQueueSum -= value;
		mQueueSigma -= value * value;
		mQueue.pop();
		return value;
	}
	template<typename T>
	inline T SmartQueue<T>::Max()
	{
		T max = std::numeric_limits<T>::lowest();
		std::queue<T> queue = mQueue;
		while (!queue.empty())
		{
			if (max < queue.front())
			{
				max = queue.front();
			}
			queue.pop();
		}
		return max;
	}
	template<typename T>
	inline T SmartQueue<T>::Min()
	{
		T min = std::numeric_limits<T>::max();
		std::queue<T> queue = mQueue;
		while (!queue.empty())
		{
			if (min > queue.front())
			{
				min = queue.front();
			}
			queue.pop();
		}
		return min;
	}
	template<typename T>
	inline double SmartQueue<T>::Average()
	{
		return mymath::Round(static_cast<double>(mQueueSum) / mQueue.size());
	}
	template<typename T>
	inline T SmartQueue<T>::Sum()
	{
		return RoundT(mQueueSum);
	}
	template<typename T>
	inline double SmartQueue<T>::Variance()
	{
		return mymath::Round(mQueueSigma / mQueue.size() - pow(mQueueSum / mQueue.size(), 2));
	}
	template<typename T>
	inline double SmartQueue<T>::StandardDeviation()
	{
		return mymath::Round(sqrt(mQueueSigma / mQueue.size() - pow(mQueueSum / mQueue.size(), 2)));
	}
	template<typename T>
	inline unsigned int SmartQueue<T>::Count()
	{
		return static_cast<unsigned int>(mQueue.size());
	}
}
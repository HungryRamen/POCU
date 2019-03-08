#pragma once
#include <queue>
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
		double Round(double value);
		double Variance();
		double StandardDeviation();
		unsigned int Count();
	private:
		std::queue<T> mQueue;
		T mQueueSum;
		double mQueueSigma;
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
		return static_cast<T>(floor(value * pow(10.0, 3) + 0.5) / pow(10.0, 3));
	}
	template<typename T>
	inline double SmartQueue<T>::Round(double value)
	{
		return floor(value * pow(10.0, 3) + 0.5) / pow(10.0, 3);
	}
	template<typename T>
	inline void SmartQueue<T>::Enqueue(T value)
	{
		mQueueSum += value;
		mQueueSigma += static_cast<double>(value) * static_cast<double>(value);
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
		mQueueSigma -= static_cast<double>(value) * static_cast<double>(value);
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
		return floor(mQueueSum / static_cast<double>(mQueue.size()) * pow(10.0, 3) + 0.5) / pow(10.0, 3);
	}
	template<typename T>
	inline T SmartQueue<T>::Sum()
	{
		return mQueueSum;
	}
	template<typename T>
	inline double SmartQueue<T>::Variance()
	{
		return Round(mQueueSigma / mQueue.size() - pow(mQueueSum / static_cast<double>(mQueue.size()), 2));
	}
	template<typename T>
	inline double SmartQueue<T>::StandardDeviation()
	{
		return Round(sqrt(mQueueSigma / mQueue.size() - pow(mQueueSum / static_cast<double>(mQueue.size()), 2)));
	}
	template<typename T>
	inline unsigned int SmartQueue<T>::Count()
	{
		return static_cast<unsigned int>(mQueue.size());
	}
}
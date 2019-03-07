#pragma once
#include <stack>
#include "MyMath.h"
namespace assignment3
{
	template<typename T>
	class SmartStack
	{
	public:
		SmartStack();
		~SmartStack();

		void Push(T value);
		T Pop();
		T Peek();
		T Max();
		T Min();
		double Average();
		T Sum();
		T RoundT(T value);
		double Variance();
		double StandardDeviation();
		unsigned int Count();
	private:
		std::stack<T> mStack;
		std::stack<T> mStackMax;
		std::stack<T> mStackMin;
		T mStackSum;
		T mStackSigma;
	};
	template<typename T> inline SmartStack<T>::SmartStack() :
		mStackSum(0),
		mStackSigma(0)
	{
		mStackMin.push(std::numeric_limits<T>::max());
		mStackMax.push(std::numeric_limits<T>::lowest());
	}
	template<typename T> inline SmartStack<T>::~SmartStack()
	{
	}
	template<typename T>
	inline T SmartStack<T>::RoundT(T value)
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
	inline void SmartStack<T>::Push(T value)
	{
		mStackSum += value;
		mStackSigma += value * value;
		if (mStackMax.top() <= value)
			mStackMax.push(value);
		if (mStackMin.top() >= value)
			mStackMin.push(value);
		mStack.push(value);
	}

	template<typename T>
	inline T SmartStack<T>::Pop()
	{
		T value = mStack.top();
		mStackSum -= value;
		mStackSigma -= value * value;
		if (value == mStackMax.top())
			mStackMax.pop();
		if (value == mStackMin.top())
			mStackMin.pop();
		mStack.pop();
		return value;
	}

	template<typename T>
	inline T SmartStack<T>::Peek()
	{
		return mStack.top();
	}

	template<typename T>
	inline T SmartStack<T>::Max()
	{
		return mStackMax.top();
	}

	template<typename T>
	inline T SmartStack<T>::Min()
	{
		return mStackMin.top();
	}

	template<typename T>
	inline double SmartStack<T>::Average()
	{
		return mymath::Round(mStackSum / mStack.size());
	}

	template<typename T>
	inline T SmartStack<T>::Sum()
	{
		return RoundT(mStackSum);
	}

	template<typename T>
	inline double SmartStack<T>::Variance()
	{
		return mymath::Round(mStackSigma / mStack.size() - pow(mStackSum / mStack.size(), 2));
	}

	template<typename T>
	inline double SmartStack<T>::StandardDeviation()
	{
		return mymath::Round(sqrt(mStackSigma / mStack.size() - pow(mStackSum / mStack.size(), 2)));
	}

	template<typename T>
	inline unsigned int SmartStack<T>::Count()
	{
		return static_cast<unsigned int>(mStack.size());
	}
}
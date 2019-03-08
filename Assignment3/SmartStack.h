#pragma once
#include <stack>
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
		double Round(double value);
		double Variance();
		double StandardDeviation();
		unsigned int Count();
	private:
		std::stack<T> mStack;
		std::stack<T> mStackMax;
		std::stack<T> mStackMin;
		T mStackSum;
		double mStackSigma;
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
	inline double SmartStack<T>::Round(double value)
	{
		return floor(value * pow(10.0, 3) + 0.5) / pow(10.0, 3);
	}

	template<typename T>
	inline void SmartStack<T>::Push(T value)
	{
		mStackSum += value;
		mStackSigma += static_cast<double>(value) * static_cast<double>(value);
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
		mStackSigma -= static_cast<double>(value) * static_cast<double>(value);
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
		return floor(mStackSum / static_cast<double>(mStack.size()) * pow(10.0, 3) + 0.5) / pow(10.0, 3);
	}

	template<typename T>
	inline T SmartStack<T>::Sum()
	{
		return mStackSum;
	}

	template<typename T>
	inline double SmartStack<T>::Variance()
	{
		return Round(mStackSigma / mStack.size() - pow(mStackSum / static_cast<double>(mStack.size()), 2));
	}

	template<typename T>
	inline double SmartStack<T>::StandardDeviation()
	{
		return Round(sqrt(mStackSigma / mStack.size() - pow(mStackSum / static_cast<double>(mStack.size()), 2)));
	}

	template<typename T>
	inline unsigned int SmartStack<T>::Count()
	{
		return static_cast<unsigned int>(mStack.size());
	}
}
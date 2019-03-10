#pragma once
#include <queue>
#include <stack>

namespace assignment3
{
	template<typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int maxStackSize);
		~QueueStack();

		void Enqueue(T value);
		T Peek();
		T Dequeue();
		T Max();
		T Min();
		double Average();
		T Sum();
		unsigned int Count();
		unsigned int StackCount();

	private:
		std::queue<std::stack<T>> mQueueStack;
		T mQueueStackSum;
		unsigned int mCount;
		unsigned int mMaxStackSize;
	};
	template<typename T>
	inline QueueStack<T>::QueueStack(unsigned int maxStackSize) :
		mCount(0),
		mMaxStackSize(maxStackSize)
	{
	}
	template<typename T>
	inline QueueStack<T>::~QueueStack()
	{
	}
	template<typename T>
	inline void QueueStack<T>::Enqueue(T value)
	{
		mQueueStackSum += value;
		mCount++;
		if (mQueueStack.empty())
		{
			std::stack<T> stack;
			stack.push(value);
			mQueueStack.push(stack);
		}
		else
		{
			if (mQueueStack.back().size() >= mMaxStackSize)
			{
				std::stack<T> stack;
				stack.push(value);
				mQueueStack.push(stack);
			}
			else
			{
				mQueueStack.back().push(value);
			}
		}
	}
	template<typename T>
	inline T QueueStack<T>::Peek()
	{
		return mQueueStack.front().top();
	}
	template<typename T>
	inline T QueueStack<T>::Dequeue()
	{
		T value = mQueueStack.front().top();
		mQueueStackSum -= value;
		mCount--;
		mQueueStack.front().pop();
		if (mQueueStack.front().empty())
		{
			mQueueStack.pop();
		}
		return value;
	}
	template<typename T>
	inline T QueueStack<T>::Max()
	{
		T max = std::numeric_limits<T>::lowest();
		if (mQueueStack.empty())
			return max;
		std::queue<std::stack<T>> queuestack = mQueueStack;
		while (!queuestack.empty())
		{
			while (!queuestack.front().empty())
			{
				if (max < queuestack.front().top())
				{
					max = queuestack.front().top();
				}
				queuestack.front().pop();
			}
			queuestack.pop();
		}
		return max;
	}
	template<typename T>
	inline T QueueStack<T>::Min()
	{
		T min = std::numeric_limits<T>::max();
		if (mQueueStack.empty())
			return min;
		std::queue<std::stack<T>> queuestack = mQueueStack;
		while (!queuestack.empty())
		{
			while (!queuestack.front().empty())
			{
				if (min > queuestack.front().top())
				{
					min = queuestack.front().top();
				}
				queuestack.front().pop();
			}
			queuestack.pop();
		}
		return min;
	}
	template<typename T>
	inline double QueueStack<T>::Average()
	{
		unsigned int size = mCount;
		double value = static_cast<double>(mQueueStackSum) / size;
		return round(value * 1000) / 1000;
	}

	template<typename T>
	inline T QueueStack<T>::Sum()
	{
		if (mQueueStack.empty())
			mQueueStackSum = 0;
		return mQueueStackSum;
	}
	template<typename T>
	inline unsigned int QueueStack<T>::Count()
	{
		return mCount;
	}
	template<typename T>
	inline unsigned int QueueStack<T>::StackCount()
	{
		return mQueueStack.size();
	}
}
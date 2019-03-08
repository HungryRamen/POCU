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
		unsigned int mStackCount;
		unsigned int mMaxStackSize;
	};
	template<typename T>
	inline QueueStack<T>::QueueStack(unsigned int maxStackSize) :
		mCount(0),
		mStackCount(0),
		mMaxStackSize(maxStackSize)
	{
		std::stack<T> stack;
		mQueueStack.push(stack);
	}
	template<typename T>
	inline QueueStack<T>::~QueueStack()
	{
	}
	template<typename T>
	inline void QueueStack<T>::Enqueue(T value)
	{
		mQueueStackSum += value;
		if (mQueueStack.back().size() >= mMaxStackSize)
		{
			std::stack<T> stack;
			stack.push(value);
			mQueueStack.push(stack);
			mStackCount++;
		}
		else
		{
			if (mStackCount == 0)
				mStackCount++;
			mQueueStack.back().push(value);
		}
		mCount++;
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
		mQueueStack.front().pop();
		mCount--;
		if (mQueueStack.front().empty())
		{
			mStackCount--;
			mQueueStack.pop();
		}
		return value;
	}
	template<typename T>
	inline T QueueStack<T>::Max()
	{
		T max = std::numeric_limits<T>::lowest();
		if (mCount == 0)
			return max;
		std::queue<std::stack<T>> queuestack;
		std::stack<T> stack;
		while (!mQueueStack.empty())
		{
			while (!mQueueStack.front().empty())
			{
				if (max < mQueueStack.front().top())
				{
					max = mQueueStack.front().top();
				}
				stack.push(mQueueStack.front().top());
				mQueueStack.front().pop();
			}
			std::stack<T> stack2;
			while (!stack.empty())
			{
				stack2.push(stack.top());
				stack.pop();
			}
			mQueueStack.pop();
			queuestack.push(stack2);
		}
		queuestack.swap(mQueueStack);
		return max;
	}
	template<typename T>
	inline T QueueStack<T>::Min()
	{
		T min = std::numeric_limits<T>::max();
		if (mCount == 0)
			return min;
		std::queue<std::stack<T>> queuestack;
		std::stack<T> stack;
		while (!mQueueStack.empty())
		{
			while (!mQueueStack.front().empty())
			{
				if (min > mQueueStack.front().top())
				{
					min = mQueueStack.front().top();
				}
				stack.push(mQueueStack.front().top());
				mQueueStack.front().pop();
			}
			std::stack<T> stack2;
			while (!stack.empty())
			{
				stack2.push(stack.top());
				stack.pop();
			}
			mQueueStack.pop();
			queuestack.push(stack2);
		}
		queuestack.swap(mQueueStack);
		return min;
	}
	template<typename T>
	inline double QueueStack<T>::Average()
	{
		return floor(mQueueStackSum / static_cast<double>(mCount) * pow(10.0, 3) + 0.5) / pow(10.0, 3);
	}
	template<typename T>
	inline T QueueStack<T>::Sum()
	{
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
		return mStackCount;
	}
}
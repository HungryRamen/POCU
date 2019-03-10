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
		unsigned int mMaxStackSize;
	};
	template<typename T>
	inline QueueStack<T>::QueueStack(unsigned int maxStackSize) :
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
		if (mQueueStack.empty())
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
		unsigned int size = Count();
		double value = static_cast<double>(mQueueStackSum) / size;
		return round(value * 1000.0) / 1000.0;
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
		if (mQueueStack.empty())
			return 0;
		else if (mQueueStack.size() == 1)
		{
			return mQueueStack.front().size();
		}
		else if (mQueueStack.size() == 2)
		{
			return mQueueStack.front().size() + mQueueStack.back().size();
		}
		return mQueueStack.front().size() + mQueueStack.back().size() + (mQueueStack.size() - 2) * mMaxStackSize;
	}
	template<typename T>
	inline unsigned int QueueStack<T>::StackCount()
	{
		return mQueueStack.size();
	}
}
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
		T RoundT(T value);
		double Round(double value);
		unsigned int Count();
		unsigned int StackCount();

	private:
		std::queue<std::stack<T>*> mQueueStack;
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
		std::stack<T>* stack = new std::stack<T>();
		mQueueStack.push(stack);
	}
	template<typename T>
	inline QueueStack<T>::~QueueStack()
	{
		while (!mQueueStack.empty())
		{
			std::stack<T>* stack = mQueueStack.front();
			delete stack;
			mQueueStack.pop();
		}
	}
	template<typename T>
	inline void QueueStack<T>::Enqueue(T value)
	{
		mQueueStackSum += value;
		if (mQueueStack.back()->size() >= mMaxStackSize)
		{
			std::stack<T>* stack = new std::stack<T>();
			stack->push(value);
			mQueueStack.push(stack);
			mStackCount++;
		}
		else
		{
			if (mStackCount == 0)
				mStackCount++;
			mQueueStack.back()->push(value);
		}
		mCount++;
	}
	template<typename T>
	inline T QueueStack<T>::Peek()
	{
		return mQueueStack.front()->top();
	}
	template<typename T>
	inline T QueueStack<T>::Dequeue()
	{
		T value = mQueueStack.front()->top();
		mQueueStackSum -= value;
		mQueueStack.front()->pop();
		mCount--;
		if (mQueueStack.front()->empty())
		{
			mStackCount--;
			delete mQueueStack.front();
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
		std::queue<std::stack<T>*> queuestack;
		std::stack<T>* stack;
		std::stack<T> stack2;
		while (!mQueueStack.empty())
		{
			stack = mQueueStack.front();
			mQueueStack.pop();
			while (!stack->empty())
			{
				if (max < stack->top())
				{
					max = stack->top();
				}
				stack2.push(stack->top());
				stack->pop();
			}
			delete stack;
			stack = new std::stack<T>();
			while (!stack2.empty())
			{
				stack->push(stack2.top());
				stack2.pop();
			}
			queuestack.push(stack);
		}
		mQueueStack = queuestack;
		return max;
	}
	template<typename T>
	inline T QueueStack<T>::Min()
	{
		T min = std::numeric_limits<T>::max();
		if (mCount == 0)
			return min;
		std::queue<std::stack<T>*> queuestack;
		std::stack<T>* stack;
		std::stack<T> stack2;
		while (!mQueueStack.empty())
		{
			stack = mQueueStack.front();
			mQueueStack.pop();
			while (!stack->empty())
			{
				if (min > stack->top())
				{
					min = stack->top();
				}
				stack2.push(stack->top());
				stack->pop();
			}
			delete stack;
			stack = new std::stack<T>();
			while (!stack2.empty())
			{
				stack->push(stack2.top());
				stack2.pop();
			}
			queuestack.push(stack);
		}
		mQueueStack = queuestack;
		return min;
	}
	template<typename T>
	inline double QueueStack<T>::Average()
	{
		return Round(static_cast<double>(mQueueStackSum) / Count());
	}
	template<typename T>
	inline T QueueStack<T>::Sum()
	{
		return RoundT(mQueueStackSum);
	}
	template<typename T>
	inline T QueueStack<T>::RoundT(T value)
	{
		return static_cast<T>(floor(value * pow(10.0, 3) + 0.5) / pow(10.0, 3));
	}
	template<typename T>
	inline double QueueStack<T>::Round(double value)
	{
		return floor(value * pow(10.0, 3) + 0.5) / pow(10.0, 3);
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
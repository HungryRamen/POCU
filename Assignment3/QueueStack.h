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
		std::stack<T>* mStack;
		T mQueueStackSum;
		unsigned int mCount;
		unsigned int mStackCount;
		unsigned int mMaxStackSize;
	};
	template<typename T>
	inline QueueStack<T>::QueueStack(unsigned int maxStackSize) :
		mStackCount(0),
		mMaxStackSize(maxStackSize),
		mStack(nullptr)
	{
	}
	template<typename T>
	inline QueueStack<T>::~QueueStack()
	{
		while (!mQueueStack.empty())
		{
			mStack = mQueueStack.front();
			delete mStack;
			mQueueStack.pop();
		}
	}
	template<typename T>
	inline void QueueStack<T>::Enqueue(T value)
	{
		if (mStack == nullptr)
		{
			std::stack<T>* stack = new std::stack<T>();
			mStack = stack;
			mStackCount++;
		}
		mStack->push(value);
		mQueueStackSum += value;
		mCount++;
		if (mStack->size() >= mMaxStackSize)
		{
			mQueueStack.push(mStack);
			mStack = nullptr;
		}
	}
	template<typename T>
	inline T QueueStack<T>::Peek()
	{
		if (mQueueStack.empty())
		{
			if (!mStack->empty())
			{
				return mStack->top();
			}
		}
		std::stack<T>* stack = mQueueStack.front();
		return stack->top();
	}
	template<typename T>
	inline T QueueStack<T>::Dequeue()
	{
		if (mQueueStack.empty())
		{
			if (!mStack->empty())
			{
				T value = mStack->top();
				mStack->pop();
				mQueueStackSum -= value;
				mCount--;
				if (mStack->empty())
				{
					delete mStack;
					mStack = nullptr;
					mStackCount--;
				}
				return value;
			}
		}
		std::stack<T>* stack = mQueueStack.front();
		T value = stack->top();
		mQueueStackSum -= value;
		stack->pop();
		mCount--;
		if (stack->empty())
		{
			mStackCount--;
			mQueueStack.pop();
			delete stack;
		}
		return value;
	}
	template<typename T>
	inline T QueueStack<T>::Max()
	{
		T max = std::numeric_limits<T>::lowest();
		if (mQueueStack.empty() && mStack == nullptr)
			return max;
		std::queue<std::stack<T>*> queuestack;
		std::stack<T>* stack;
		std::stack<T> stack2;
		while (!mQueueStack.empty())
		{
			stack = mQueueStack.front();
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
			mQueueStack.pop();
		}
		mQueueStack = queuestack;
		while (!mStack->empty())
		{
			if (max < mStack->top())
			{
				max = mStack->top();
			}
			stack2.push(mStack->top());
			mStack->pop();
		}
		while (!stack2.empty())
		{
			mStack->push(stack2.top());
			stack2.pop();
		}
		return max;
	}
	template<typename T>
	inline T QueueStack<T>::Min()
	{
		T min = std::numeric_limits<T>::max();
		if (mQueueStack.empty() && mStack == nullptr)
			return min;
		std::queue<std::stack<T>*> queuestack;
		std::stack<T>* stack;
		std::stack<T> stack2;
		while (!mQueueStack.empty())
		{
			stack = mQueueStack.front();
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
			mQueueStack.pop();
		}
		mQueueStack = queuestack;
		while (!mStack->empty())
		{
			if (min > mStack->top())
			{
				min = mStack->top();
			}
			stack2.push(mStack->top());
			mStack->pop();
		}
		while (!stack2.empty())
		{
			mStack->push(stack2.top());
			stack2.pop();
		}
		return min;
	}
	template<typename T>
	inline double QueueStack<T>::Average()
	{
		double b = Round(static_cast<double>(mQueueStackSum) / Count());
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
		double value2;
		if (value < 0)
			value2 = (static_cast<double>(value) - 0.0005) * 1000;
		else
			value2 = (static_cast<double>(value) + 0.0005) * 1000;
		int value3 = static_cast<int>(value2);
		return static_cast<T>(value3) / 1000;
	}
	template<typename T>
	inline double QueueStack<T>::Round(double value)
	{
		double value2;
		if (value < 0)
			value2 = (static_cast<double>(value) - 0.0005) * 1000;
		else
			value2 = (static_cast<double>(value) + 0.0005) * 1000;
		int value3 = static_cast<int>(value2);
		return static_cast<double>(value3) / 1000;
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
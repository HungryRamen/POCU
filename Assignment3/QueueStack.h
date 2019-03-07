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
		if (mStack->size() >= mMaxStackSize)
		{
			mQueueStack.push(mStack);
			mStack = nullptr;
		}
	}
	template<typename T>
	inline T QueueStack<T>::Peek()
	{
		std::stack<T>* stack = mQueueStack.front();
		return stack->top();
	}
	template<typename T>
	inline T QueueStack<T>::Dequeue()
	{
		std::stack<T>* stack = mQueueStack.front();
		T value = stack->top();
		mQueueStackSum -= value;
		stack->pop();
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
		//std::queue<std::stack<T>*> queuestack;
		//std::stack<T>* stack;
		//std::stack<T>* stack2;
		//while (!mQueueStack.empty())
		//{
		//	stack = mQueueStack.front();
		//	while (!stack->empty())
		//	{
		//		if (max < stack->top())
		//		{
		//			max = stack->top();
		//		}
		//		stack->pop();
		//	}
		//	queuestack.pop();
		//}
		//while (!mStack->empty())
		//{
		//
		//}
		return max;
	}
	template<typename T>
	inline T QueueStack<T>::Min()
	{
		T min = std::numeric_limits<T>::max();
		//std::queue<std::stack<T>*> queuestack = mQueueStack;
		//std::stack<T>* stack;
		//while (!queuestack.empty())
		//{
		//	stack = queuestack.front();
		//	while (!stack->empty())
		//	{
		//		if (min > stack->top())
		//		{
		//			min = stack->top();
		//		}
		//		stack->pop();
		//	}
		//	queuestack.pop();
		//}
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
		if (mStack == nullptr)
			return mMaxStackSize * mStackCount;
		return mMaxStackSize * (mStackCount - 1) + mStack->size();
	}
	template<typename T>
	inline unsigned int QueueStack<T>::StackCount()
	{
		return mStackCount;
	}
}
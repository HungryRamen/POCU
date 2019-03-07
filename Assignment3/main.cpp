#include <cassert>
#include <iostream>
#include "SmartStack.h"
#include "SmartQueue.h"
#include "QueueStack.h"

void SmartStackTest()
{
	// {}
	assignment3::SmartStack<double> smartStack;
	assert(smartStack.Count() == 0);
	assert(smartStack.Max() == std::numeric_limits<double>::lowest());
	assert(smartStack.Min() == std::numeric_limits<double>::max());
	
	// {10.1}
	smartStack.Push(10.1);
	assert(smartStack.Count() == 1);
	assert(smartStack.Max() == 10.1);
	assert(smartStack.Min() == 10.1);
	assert(smartStack.Sum() == 10.1);
	assert(smartStack.Average() == 10.1);
	assert(smartStack.Variance() == 0.0);
	assert(smartStack.StandardDeviation() == 0.0);
	
	// {10.1, -5.5, 10.1, -5.5, 20.2, -11.0}
	smartStack.Push(-5.5);
	smartStack.Push(10.1);
	smartStack.Push(-5.5);
	smartStack.Push(20.2);
	smartStack.Push(-11.0);
	assert(smartStack.Count() == 6);
	assert(smartStack.Max() == 20.2);
	assert(smartStack.Min() == -11.0);
	assert(smartStack.Sum() == 18.4);
	assert(smartStack.Average() == 3.067);
	assert(smartStack.Variance() == 122.856);
	assert(smartStack.StandardDeviation() == 11.084);
	
	// {10.1, -5.5, 10.1, -5.5, 20.2}
	assert(smartStack.Peek() == -11.0);
	double popped = smartStack.Pop();
	assert(popped == -11.0);
	assert(smartStack.Count() == 5);
	assert(smartStack.Max() == 20.2);
	assert(smartStack.Min() == -5.5);
	assert(smartStack.Sum() == 29.4);
	assert(smartStack.Average() == 5.88);
	assert(smartStack.Variance() == 99.938);
	assert(smartStack.StandardDeviation() == 9.997);
	
	// {10.1, -5.5, 10.1, -5.5}
	popped = smartStack.Pop();
	assert(popped == 20.2);
	assert(smartStack.Count() == 4);
	assert(smartStack.Max() == 10.1);
	assert(smartStack.Min() == -5.5);
	assert(smartStack.Sum() == 9.2);
	assert(smartStack.Average() == 2.3);
	assert(smartStack.Variance() == 60.84);
	assert(smartStack.StandardDeviation() == 7.8);
	
	// {10.1, -5.5, 10.1}
	popped = smartStack.Pop();
	assert(popped == -5.5);
	assert(smartStack.Count() == 3);
	assert(smartStack.Max() == 10.1);
	assert(smartStack.Min() == -5.5);
	assert(smartStack.Sum() == 14.7);
	assert(smartStack.Average() == 4.9);
	assert(smartStack.Variance() == 54.08);
	assert(smartStack.StandardDeviation() == 7.354);
	
	// {10.1, -5.5}
	popped = smartStack.Pop();
	assert(popped == 10.1);
	assert(smartStack.Count() == 2);
	assert(smartStack.Max() == 10.1);
	assert(smartStack.Min() == -5.5);
	assert(smartStack.Sum() == 4.6);
	assert(smartStack.Average() == 2.3);
	assert(smartStack.Variance() == 60.84);
	assert(smartStack.StandardDeviation() == 7.8);
	
	// {10.1}
	popped = smartStack.Pop();
	assert(popped == -5.5);
	assert(smartStack.Count() == 1);
	assert(smartStack.Max() == 10.1);
	assert(smartStack.Min() == 10.1);
	assert(smartStack.Sum() == 10.1);
	assert(smartStack.Average() == 10.1);
	assert(smartStack.Variance() == 0.0);
	assert(smartStack.StandardDeviation() == 0.0);
	
	// {}
	popped = smartStack.Pop();
	assert(popped == 10.1);
	assert(smartStack.Count() == 0);
	assert(smartStack.Max() == std::numeric_limits<double>::lowest());
	assert(smartStack.Min() == std::numeric_limits<double>::max());
}

void SmartQueueTest()
{
	const double EPSILON = std::numeric_limits<double>::min();
	
	// {}
	assignment3::SmartQueue<double> smartQueue;
	assert(smartQueue.Count() == 0);
	assert(smartQueue.Max() == std::numeric_limits<double>::lowest());
	assert(smartQueue.Min() == std::numeric_limits<double>::max());
	
	// {20.2, -11.0, 10.1, -5.5, 10.1, -5.5}
	smartQueue.Enqueue(20.2);
	smartQueue.Enqueue(-11.0);
	smartQueue.Enqueue(10.1);
	smartQueue.Enqueue(-5.5);
	smartQueue.Enqueue(10.1);
	smartQueue.Enqueue(-5.5);
	assert(smartQueue.Peek() == 20.2);
	assert(smartQueue.Count() == 6);
	assert(smartQueue.Max() == 20.2);
	assert(smartQueue.Min() == -11.0);
	assert(smartQueue.Sum() == 18.4);
	assert(smartQueue.Average() == 3.067);
	assert(smartQueue.Variance() == 122.856);
	assert(smartQueue.StandardDeviation() == 11.084);
	
	// {-11.0, 10.1, -5.5, 10.1, -5.5} 
	double dequeued = smartQueue.Dequeue();
	assert(dequeued == 20.2);
	assert(smartQueue.Count() == 5);
	assert(smartQueue.Max() == 10.1);
	assert(smartQueue.Min() == -11.0);
	assert((smartQueue.Sum() - (-1.8)) < EPSILON);
	assert(smartQueue.Average() == -0.36);
	assert(smartQueue.Variance() == 76.974);
	assert(smartQueue.StandardDeviation() == 8.774);
	
	// {10.1, -5.5, 10.1, -5.5} 
	dequeued = smartQueue.Dequeue();
	assert(dequeued == -11.0);
	assert(smartQueue.Count() == 4);
	assert(smartQueue.Max() == 10.1);
	assert(smartQueue.Min() == -5.5);
	assert(smartQueue.Sum() == 9.2);
	assert(smartQueue.Average() == 2.3);
	assert(smartQueue.Variance() == 60.84);
	assert(smartQueue.StandardDeviation() == 7.8);
	
	// {-5.5, 10.1, -5.5} 
	dequeued = smartQueue.Dequeue();
	assert(dequeued == 10.1);
	assert(smartQueue.Count() == 3);
	assert(smartQueue.Max() == 10.1);
	assert(smartQueue.Min() == -5.5);
	assert((smartQueue.Sum() - (-0.9)) < EPSILON);
	assert(smartQueue.Average() == -0.3);
	assert(smartQueue.Variance() == 54.08);
	assert(smartQueue.StandardDeviation() == 7.354);
	
	// {10.1, -5.5} 
	dequeued = smartQueue.Dequeue();
	assert(dequeued == -5.5);
	assert(smartQueue.Count() == 2);
	assert(smartQueue.Max() == 10.1);
	assert(smartQueue.Min() == -5.5);
	assert(smartQueue.Sum() == 4.6);
	assert(smartQueue.Average() == 2.3);
	assert(smartQueue.Variance() == 60.84);
	assert(smartQueue.StandardDeviation() == 7.8);
	
	// {-5.5} 
	dequeued = smartQueue.Dequeue();
	assert(dequeued == 10.1);
	assert(smartQueue.Count() == 1);
	assert(smartQueue.Max() == -5.5);
	assert(smartQueue.Min() == -5.5);
	assert(smartQueue.Sum() == -5.5);
	assert(smartQueue.Average() == -5.5);
	assert(smartQueue.Variance() == 0.0);
	assert(smartQueue.StandardDeviation() == 0.0);
	
	// {} 
	dequeued = smartQueue.Dequeue();
	assert(dequeued == -5.5);
	assert(smartQueue.Count() == 0);
	assert(smartQueue.Max() == std::numeric_limits<double>::lowest());
	assert(smartQueue.Min() == std::numeric_limits<double>::max());
}

void QueueStackTest()
{
	// {}
	assignment3::QueueStack<int> queueStack(3);
	assert(queueStack.Count() == 0);
	assert(queueStack.StackCount() == 0);
	assert(queueStack.Max() == std::numeric_limits<int>::lowest());
	assert(queueStack.Min() == std::numeric_limits<int>::max());
	
	// { {20, -15, 10}, {-5, 20, -15}, {10, -5} }
	queueStack.Enqueue(20);
	queueStack.Enqueue(-15);
	queueStack.Enqueue(10);
	queueStack.Enqueue(-5);
	queueStack.Enqueue(20);
	queueStack.Enqueue(-15);
	queueStack.Enqueue(10);
	queueStack.Enqueue(-5);
	assert(queueStack.Peek() == 10);
	assert(queueStack.Count() == 8);
	assert(queueStack.StackCount() == 3);
	assert(queueStack.Max() == 20);
	assert(queueStack.Min() == -15);
	assert(queueStack.Sum() == 20);
	assert(queueStack.Average() == 2.5);
	
	// { {20, -15}, {-5, 20, -15}, {10, -5} }
	int dequeued = queueStack.Dequeue();
	assert(dequeued = 10);
	assert(queueStack.Peek() == -15);
	assert(queueStack.Count() == 7);
	assert(queueStack.StackCount() == 3);
	assert(queueStack.Max() == 20);
	assert(queueStack.Min() == -15);
	assert(queueStack.Sum() == 10);
	assert(queueStack.Average() == 1.429);
	
	// { {20}, {-5, 20, -15}, {10, -5} }
	dequeued = queueStack.Dequeue();
	assert(dequeued = -15);
	assert(queueStack.Peek() == 20);
	assert(queueStack.Count() == 6);
	assert(queueStack.StackCount() == 3);
	assert(queueStack.Max() == 20);
	assert(queueStack.Min() == -15);
	assert(queueStack.Sum() == 25);
	assert(queueStack.Average() == 4.167);
	
	// { {-5, 20, -15}, {10, -5} }
	dequeued = queueStack.Dequeue();
	assert(dequeued = 20);
	assert(queueStack.Peek() == -15);
	assert(queueStack.Count() == 5);
	assert(queueStack.StackCount() == 2);
	assert(queueStack.Max() == 20);
	assert(queueStack.Min() == -15);
	assert(queueStack.Sum() == 5);
	assert(queueStack.Average() == 1.0);
	
	// { {-5, 20}, {10, -5} }
	dequeued = queueStack.Dequeue();
	assert(dequeued = -15);
	assert(queueStack.Peek() == 20);
	assert(queueStack.Count() == 4);
	assert(queueStack.StackCount() == 2);
	assert(queueStack.Max() == 20);
	assert(queueStack.Min() == -5);
	assert(queueStack.Sum() == 20);
	assert(queueStack.Average() == 5.0);
	
	// { {-5}, {10, -5} }
	dequeued = queueStack.Dequeue();
	assert(dequeued = 20);
	assert(queueStack.Peek() == -5);
	assert(queueStack.Count() == 3);
	assert(queueStack.StackCount() == 2);
	assert(queueStack.Max() == 10);
	assert(queueStack.Min() == -5);
	assert(queueStack.Sum() == 0);
	assert(queueStack.Average() == 0.0);
	
	// { {10, -5} }
	dequeued = queueStack.Dequeue();
	assert(dequeued = -5);
	assert(queueStack.Peek() == -5);
	assert(queueStack.Count() == 2);
	assert(queueStack.StackCount() == 1);
	assert(queueStack.Max() == 10);
	assert(queueStack.Min() == -5);
	assert(queueStack.Sum() == 5);
	assert(queueStack.Average() == 2.5);
	
	// { {10} }
	dequeued = queueStack.Dequeue();
	assert(dequeued = -5);
	assert(queueStack.Peek() == 10);
	assert(queueStack.Count() == 1);
	assert(queueStack.StackCount() == 1);
	assert(queueStack.Max() == 10);
	assert(queueStack.Min() == 10);
	assert(queueStack.Sum() == 10);
	assert(queueStack.Average() == 10.0);
	
	// {}
	dequeued = queueStack.Dequeue();
	assert(dequeued = 10);
	assert(queueStack.Count() == 0);
	assert(queueStack.StackCount() == 0);
	assert(queueStack.Max() == std::numeric_limits<int>::lowest());
	assert(queueStack.Min() == std::numeric_limits<int>::max());
}

int main()
{
	SmartStackTest();
	SmartQueueTest();
	QueueStackTest();
	assignment3::SmartStack<float> ss;
 	ss.Push(3.4f);
	ss.Push(1.2f);
	ss.Push(4.6f);
	ss.Push(3.32f);
	ss.Push(10.2f);
	ss.Push(1.1f);
	ss.Push(-5.9f);
	ss.Push(1.1f);
	ss.Push(-12.4f);
	ss.Push(9.2f);
	
	assert(ss.Count() == 10U);
	assert(ss.Peek() == 9.2f);
	assert(ss.Max() == 10.2f);
	assert(ss.Min() == -12.4f);
	assert(ss.Sum() == 15.820f);
	assert(ss.Average() == 1.582);
	assert(ss.Variance() == 39.983);
	assert(ss.StandardDeviation() == 6.323);
	assert(ss.Peek() == 9.2f);
	
	float popped1 = ss.Pop();
	float popped2 = ss.Pop();
	
	assert(popped1 == 9.2f);
	assert(popped2 == -12.4f);
	
	return 0;
}
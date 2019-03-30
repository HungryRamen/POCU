#include <cassert>
#include <iostream>
#include "DoublyLinkedList.h"
#include "Node.h"
using namespace lab10;

void test2()
{
	enum class eMAX_SIZE
	{
		SIZE = 10
	};

	DoublyLinkedList<int> list1;

	{
		assert(list1.GetLength() == 0);
		assert(list1.Delete(1) == false);
		assert(list1.Search(1) == false);
		assert(list1[0] == nullptr);
	}

	for (size_t index = 0; index < static_cast<size_t>(eMAX_SIZE::SIZE); index++)
	{
		list1.Insert(std::make_unique<int>(index));
	}

	for (size_t index = 0; index < static_cast<size_t>(eMAX_SIZE::SIZE); index++)
	{
		assert(*list1[index]->Data == index);
	}

	for (size_t index = 0; index < list1.GetLength() - 1; index++)
	{
		assert(*list1[index]->Data == *list1[index + 1]->Previous.lock()->Data);
	}

	assert(list1.GetLength() == 10);

	{
		assert(list1.Search(0) == true);
		assert(list1.Search(15) == false);
		assert(list1.Search(7) == true);
		assert(list1.Search(9) == true);
	}

	{
		assert(list1.Delete(11) == false);
		assert(list1.Delete(0) == true);
		assert(*list1[0]->Data == 1);
		assert(list1.Delete(9) == true);
		assert(*list1[7]->Data == 8);
		assert(list1.Delete(5) == true);
		assert(*list1[4]->Data == 6);
		assert(list1.GetLength() == 7);
		assert(list1.Delete(5) == false);

		const size_t checkLength = list1.GetLength() - 1;
		for (size_t index = 0; index < checkLength; index++)
		{
			assert(*list1[index]->Data == *list1[index + 1]->Previous.lock()->Data);
		}
	}

	{
		list1.Print();
		list1.Insert(std::make_unique<int>(11), 0);
		list1.Print();
		assert(*list1[0]->Data == 11);
		assert(*list1[1]->Data == 1);
		list1.Insert(std::make_unique<int>(12), 1);
		list1.Print();
		assert(*list1[1]->Data == 12);
		assert(*list1[2]->Data == 1);
		assert(list1.GetLength() == 9);
		list1.Insert(std::make_unique<int>(13), 15);
		list1.Print();
		assert(*list1[9]->Data = 13);
		list1.Insert(std::make_unique<int>(14), 5);
 		assert(*list1[5]->Data == 14);

		const size_t checkLength = list1.GetLength() - 1;
		for (size_t index = 0; index < checkLength; index++)
		{
			assert(*list1[index]->Data == *list1[index + 1]->Previous.lock()->Data);
		}
	}
}

int main()
{
	test2();
	DoublyLinkedList<int> list;

	list.Insert(std::make_unique<int>(1));
	list.Insert(std::make_unique<int>(2));
	list.Insert(std::make_unique<int>(3));
	list.Insert(std::make_unique<int>(4));
	list.Insert(std::make_unique<int>(5));
	list.Insert(std::make_unique<int>(6));
	list.Insert(std::make_unique<int>(7));

	bool bSearched = list.Search(4);
	assert(bSearched);

	bSearched = list.Search(10);
	assert(!bSearched);

	unsigned int size = list.GetLength();
	assert(size == 7);

	bool bDeleted = list.Delete(3);
	assert(bDeleted);

	bDeleted = list.Delete(3);
	assert(!bDeleted);

	size = list.GetLength();
	assert(size == 6);

	std::shared_ptr<Node<int>> node = list[2];
	assert(*node->Data == 4);

	list.Insert(std::make_unique<int>(10), 2);

	node = list[2];
	assert(*node->Data == 10);

	list.Insert(std::make_unique<int>(0));

	bSearched = list.Search(0);
	assert(bSearched);

	return 0;
}
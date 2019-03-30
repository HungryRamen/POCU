#include <cassert>
#include <iostream>
#include "DoublyLinkedList.h"
#include "Node.h"
using namespace lab10;

void test2()
{
	DoublyLinkedList<int> list;

	list.Insert(std::make_unique<int>(1), 0);
	assert(list.GetLength() == 1);
	assert(*list[0]->Data == 1);
	std::cout << "Test Insert(data, index) - initial List: PASS" << std::endl;

	list.Insert(std::make_unique<int>(2));
	assert(*list[0]->Next->Data == 2);
	assert(list.GetLength() == 2);
	assert(*list[1]->Data == 2);
	std::cout << "Test Insert(data): PASS" << std::endl;

	list.Insert(std::make_unique<int>(3));
	list.Insert(std::make_unique<int>(4));
	list.Insert(std::make_unique<int>(6));
	list.Insert(std::make_unique<int>(7));

	assert(*list[0]->Data == 1);
	assert(*list[1]->Data == 2);
	assert(*list[2]->Data == 3);
	assert(*list[3]->Data == 4);
	assert(*list[4]->Data == 6);
	assert(*list[5]->Data == 7);

	list.Insert(std::make_unique<int>(5), 4);

	assert(*list[0]->Data == 1);
	assert(*list[1]->Data == 2);
	assert(*list[2]->Data == 3);
	assert(*list[3]->Data == 4);
	assert(*list[4]->Data == 5);
	assert(*list[5]->Data == 6);
	assert(*list[6]->Data == 7);
	
	list.Print();
	list.Delete(1);
	list.Delete(2);
	list.Delete(3);
	list.Delete(4);
	list.Delete(5);
	list.Delete(6);
	list.Delete(7);
	list.Print();

	list.Insert(std::make_unique<int>(1));
	list.Print();
	assert(*list[0]->Data == 1);
	std::cout << "Test Insert(data) - Insert() again after cleared list: PASS" << std::endl;

	list.Delete(1);
	list.Print();
	list.Insert(std::make_unique<int>(2), 1);
	list.Print();
	assert(*list[0]->Data == 2);
	std::cout << "Test Insert(data, index) - Insert() again after cleared list: PASS" << std::endl;
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

	return 0;
}
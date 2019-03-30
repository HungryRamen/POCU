#pragma once

#include <memory>
#include <iostream>

namespace lab10
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;

		void Print();
	private:
		std::shared_ptr<Node<T>> mHead;
		unsigned int mLength;
	};

	template<typename T> DoublyLinkedList<T>::DoublyLinkedList() :
		mLength(0)
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		if (mHead == nullptr)
		{
			std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data));
			mHead = newNode;
			mLength++;
			return;
		}
		std::shared_ptr<Node<T>> tempNode = mHead;
		for (unsigned int i = 0; i < mLength - 1; i++)
		{
			tempNode = tempNode->Next;
		}
		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data), tempNode);
		tempNode->Next = newNode;
		mLength++;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		if (mLength <= index)
		{
			Insert(std::move(data));
			return;
		}
		mLength++;
		std::shared_ptr<Node<T>> tempNode = mHead;
		for (unsigned int i = 0; i < index; i++)
		{
			tempNode = tempNode->Next;
		}
		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data), tempNode->Previous.lock());
		if (tempNode == mHead)
		{
			mHead = newNode;
		}
		newNode->Next = tempNode;
		if (tempNode->Previous.lock() != nullptr)
			tempNode->Previous.lock()->Next = newNode;
		tempNode->Previous = newNode;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		std::shared_ptr<Node<T>> tempNode = mHead;
		Node<T>* temp = tempNode.get();
		for (unsigned int i = 0; i < mLength; i++)
		{
			if (*temp->Data == data)
			{
				if (temp == mHead.get())
				{
					mHead = temp->Next;
				}
				if (temp->Next != nullptr)
					temp->Next->Previous = temp->Previous;
				if (temp->Previous.lock() != nullptr)
				{
					temp->Previous.lock()->Next = temp->Next;
				}
				mLength--;
				return true;
			}
			temp = temp->Next.get();
		}
		return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		std::shared_ptr<Node<T>> tempNode = mHead;
		Node<T>* temp = tempNode.get();
		for (unsigned int i = 0; i < mLength; i++)
		{
			if (*temp->Data == data)
			{
				return true;
			}
			temp = temp->Next.get();
		}
		return false;
	}

	template<typename T>
	inline void DoublyLinkedList<T>::Print()
	{
		std::shared_ptr<Node<T>> tempNode = mHead;
		Node<T>* temp = tempNode.get();
		for (unsigned int i = 0; i < mLength; i++)
		{
			std::cout << *temp->Data << "  ";
			temp = temp->Next.get();
		}
		std::cout << std::endl;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		if (mLength <= index)
			return nullptr;
		std::shared_ptr<Node<T>> tempNode = mHead;
		for (unsigned int i = 0; i < index; i++)
		{
			tempNode = tempNode->Next;
		}
		return tempNode;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mLength;
	}
}
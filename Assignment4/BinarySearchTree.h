#pragma once

#include <memory>
#include <vector>

namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);
	private:
		void RecursiveInsert(std::shared_ptr<TreeNode<T>>& node, std::unique_ptr<T> data, std::shared_ptr<TreeNode<T>>& parent);
		bool RecursiveSearch(std::shared_ptr<TreeNode<T>>& node, const T& data);
		bool recursiveDelete(std::shared_ptr<TreeNode<T>>& node, const T& data);
		static void RecursiveInOrder(const std::shared_ptr<TreeNode<T>>& node);
		std::shared_ptr<TreeNode<T>> mRoot;
		static std::vector<T> mTreeVector;
	};
	template<typename T>
	std::vector<T> BinarySearchTree<T>::mTreeVector;
	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		RecursiveInsert(mRoot, std::move(data), mRoot);
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		return mRoot;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		return RecursiveSearch(mRoot, data);
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		return recursiveDelete(mRoot, data);
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		if (!mTreeVector.empty())
			mTreeVector.clear();
		RecursiveInOrder(startNode);
		return mTreeVector;
	}
	template<typename T>
	inline void BinarySearchTree<T>::RecursiveInsert(std::shared_ptr<TreeNode<T>>& node, std::unique_ptr<T> data, std::shared_ptr<TreeNode<T>>& parent)
	{
		if (node == nullptr)
		{
			node = std::make_shared<TreeNode<T>>(parent, std::move(data));
			if (mRoot == nullptr)
			{
				mRoot = node;
			}
		}
		else if (*node->Data >= *data)
		{
			RecursiveInsert(node->Left, std::move(data), node);
		}
		else
		{
			RecursiveInsert(node->Right, std::move(data), node);
		}
	}
	template<typename T>
	inline bool BinarySearchTree<T>::RecursiveSearch(std::shared_ptr<TreeNode<T>>& node, const T& data)
	{
		if (node == nullptr)
			return false;
		else if (*node->Data == data)
			return true;
		else if (*node->Data > data)
			return RecursiveSearch(node->Left, data);
		return RecursiveSearch(node->Right, data);
	}
	template<typename T>
	inline bool BinarySearchTree<T>::recursiveDelete(std::shared_ptr<TreeNode<T>>& node, const T& data)
	{
		if (node == nullptr)
			return false;
		if (*node->Data > data)
			return recursiveDelete(node->Left, data);
		else if (*node->Data < data)
			return recursiveDelete(node->Right, data);
		else
		{
			if (node->Left == nullptr && node->Right == nullptr)
			{
				node = nullptr;
			}
			else if (node->Left == nullptr)
			{
				node = node->Right;
			}
			else if (node->Right == nullptr)
			{
				node = node->Left;
			}
			else
			{
				std::shared_ptr<TreeNode<T>> delNode = node->Right;
				while (delNode->Left != nullptr)
					delNode = delNode->Left;
				recursiveDelete(mRoot, *delNode->Data);
				delNode->Parent = node->Parent;
				delNode->Left = node->Left;
				delNode->Right = node->Right;
				node = delNode;
			}
		}
		return true;
	}
	template<typename T>
	inline void BinarySearchTree<T>::RecursiveInOrder(const std::shared_ptr<TreeNode<T>>& node)
	{
		if (node != nullptr)
		{
			RecursiveInOrder(node->Left);
			mTreeVector.push_back(*node->Data);
			RecursiveInOrder(node->Right);
		}
	}
}
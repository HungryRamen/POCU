#pragma once
#include <queue>
namespace lab9
{
	template <class T>
	class ObjectPool final
	{
	public:
		ObjectPool(size_t maxPoolSize);
		ObjectPool(const ObjectPool& copy) = delete;
		ObjectPool& operator=(const ObjectPool& copy) = delete;
		~ObjectPool();
		T* Get();
		void Return(T* t);
		size_t GetFreeObjectCount() const;
		size_t GetMaxFreeObjectCount() const;
	private:
		size_t mMaxPoolSize;
		std::queue<T*> mObjectPoolQueue;
	};
	template<typename T>
	inline ObjectPool<T>::ObjectPool(size_t maxPoolSize) :
		mMaxPoolSize(maxPoolSize)
	{
	}
	template<typename T>
	inline ObjectPool<T>::~ObjectPool()
	{
		while (!mObjectPoolQueue.empty())
		{
			delete mObjectPoolQueue.front();
			mObjectPoolQueue.pop();
		}
	}
	template<typename T>
	inline T* ObjectPool<T>::Get()
	{
		if (mObjectPoolQueue.empty())
		{
			return new T;
		}
		T* t = mObjectPoolQueue.front();
		mObjectPoolQueue.pop();
		return t;
	}

	template<typename T>
	inline void ObjectPool<T>::Return(T* t)
	{
		if (mMaxPoolSize <= mObjectPoolQueue.size())
		{
			delete t;
			return;
		}
		mObjectPoolQueue.push(t);
	}
	template<typename T>
	inline size_t ObjectPool<T>::GetFreeObjectCount() const
	{
		return mObjectPoolQueue.size();
	}
	template<typename T>
	inline size_t ObjectPool<T>::GetMaxFreeObjectCount() const
	{
		return mMaxPoolSize;
	}
}
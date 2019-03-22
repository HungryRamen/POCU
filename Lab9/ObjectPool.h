#pragma once
#include <queue>
namespace lab9
{
	template <typename T>
	class ObjectPool final
	{
	public:
		ObjectPool(size_t maxPoolSize);
		ObjectPool(const ObjectPool& copy) = delete;
		T* Get();
		void Return(T* t);
		size_t GetFreeObjectCount();
		size_t GetMaxFreeObjectCount();
	private:
		size_t mMaxPoolSize;
		std::queue<T*> mObjectPoolQueue;
	};
	template<typename T>
	inline ObjectPool<T>::ObjectPool(size_t maxPoolSize):
		mMaxPoolSize(maxPoolSize)
	{
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
	inline size_t ObjectPool<T>::GetFreeObjectCount()
	{
		return mObjectPoolQueue.size();
	}
	template<typename T>
	inline size_t ObjectPool<T>::GetMaxFreeObjectCount()
	{
		return mMaxPoolSize;
	}
}
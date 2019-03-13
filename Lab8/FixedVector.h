#pragma once

namespace lab8
{
	template<class T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		~FixedVector();
		bool Add(const T& value);
		bool Add(T&& value);
		bool Remove(T value);
		T Get(unsigned int index) const;
		T& operator[](unsigned int index);
		int GetIndex(T value);
		size_t GetSize();
		size_t GetCapacity();
	private:
		T mFixedVector[N];
		size_t mCount;
	};

	template<class T, size_t N>
	inline FixedVector<T, N>::FixedVector() :
		mCount(0)
	{
	}

	template<class T, size_t N>
	inline FixedVector<T, N>::~FixedVector()
	{
	}

	template<class T, size_t N>
	inline bool FixedVector<T, N>::Add(const T& value)
	{
		if (mCount >= N)
			return false;
		mFixedVector[mCount++] = value;
		return true;
	}

	template<class T, size_t N>
	inline bool FixedVector<T, N>::Add(T && value)
	{
		if (mCount >= N)
			return false;
		mFixedVector[mCount++] = value;
		return true;
	}

	template<class T, size_t N>
	inline bool FixedVector<T, N>::Remove(T value)
	{
		for (size_t index = 0; index < mCount; index++)
		{
			if (mFixedVector[index] == value)
			{
				mCount--;
				for (size_t index2 = index; index2 < mCount; index2++)
				{
					mFixedVector[index2] = mFixedVector[index2 + 1];
				}
				return true;
			}
		}
		return false;
	}

	template<class T, size_t N>
	inline T FixedVector<T, N>::Get(unsigned int index) const
	{
		return mFixedVector[index];
	}

	template<class T, size_t N>
	inline T& FixedVector<T, N>::operator[](unsigned int index)
	{
		return mFixedVector[index];
	}

	template<class T, size_t N>
	inline int FixedVector<T, N>::GetIndex(T value)
	{
		for (size_t index = 0; index < mCount; index++)
		{
			if (mFixedVector[index] == value)
			{
				return index;
			}
		}
		return -1;
	}

	template<class T, size_t N>
	inline size_t FixedVector<T, N>::GetSize()
	{
		return mCount;
	}

	template<class T, size_t N>
	inline size_t FixedVector<T, N>::GetCapacity()
	{
		return N;
	}

}
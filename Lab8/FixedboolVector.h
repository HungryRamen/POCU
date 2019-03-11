#pragma once
#include <iostream>
namespace lab8
{
	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		~FixedVector();
		bool Add(bool bData);
		bool Remove(bool bData);
		bool Get(unsigned int index);
		bool operator[](unsigned int index);
		int GetIndex(bool bData);
		size_t GetSize();
		size_t GetCapacity();
	private:
		int* mFixedBoolVector;
		size_t mCount;
	};
	template<size_t N>
	inline FixedVector<bool, N>::FixedVector() :
		mCount(0)
	{
		size_t size = N / (sizeof(int) * 8); //1비트 단위인 N 을 N/32비트로 나눠서 배열크기를 잡아준다.
		size += N % (sizeof(int) * 8) == 0 ? 0 : 1; //나머지몫이 0이아니면 추가 배열크기를 하나 더 늘린다.
		mFixedBoolVector = new int[size];      //할당
		std::memset(mFixedBoolVector, 0, sizeof(int) * size); //0으로 초기화
	}
	template<size_t N>
	inline FixedVector<bool, N>::~FixedVector()
	{
		delete[] mFixedBoolVector;   //동적해체
	}
	template<size_t N>
	inline bool FixedVector<bool, N>::Add(bool bData)
	{
		if (mCount >= N)
			return false;
		size_t size = mCount / (sizeof(int) * 8);  //N / 32 번째 첨자접근
		size_t count = mCount % (sizeof(int) * 8); //나머지 몫으로 비트플래그 번지수 접근
		if (bData)                                   // << 시프트 연산자로 1 << n 만큼 왼쪽으로 밀어준다.
		{
			mFixedBoolVector[size] |= (1 << count); // |= OR 연산자로 비트플래그를 1로 바꾼다.
		}
		else
		{
			mFixedBoolVector[size] &= ~(1 << count); // &= AND 연산자 ~ NOT연산자 ~연산자로 우선 역수를 만든뒤 AND로 비트플래그를 0으로 바꾼다.
		}
		mCount++;
		return true;
	}
	template<size_t N>
	inline bool FixedVector<bool, N>::Remove(bool bData)
	{
		size_t count = 0;
		for (size_t index = 0; index < mCount; index++)
		{
			count = index % (sizeof(int) * 8);
			if (static_cast<bool>(mFixedBoolVector[index / (sizeof(int) * 8)] & (1 << count)) == bData) // &를 이용하여 비트가 0인지 1인지 분별
			{
				mCount--;
				for (size_t index2 = index; index2 < mCount; index2++)
				{
					count = (index2 + 1) % (sizeof(int) * 8);
					if (static_cast<bool>(mFixedBoolVector[(index2 + 1) / (sizeof(int) * 8)] & (1 << count)) == true)
					{
						mFixedBoolVector[index2 / (sizeof(int) * 8)] |= (1 << (count - 1));
					}
					else
					{
						mFixedBoolVector[index2 / (sizeof(int) * 8)] &= ~(1 << (count - 1));
					}
				}
				mFixedBoolVector[(mCount + 1) / (sizeof(int) * 8)] &= ~(1 << (count));
				return true;
			}
		}
		return false;
	}
	template<size_t N>
	inline bool FixedVector<bool, N>::Get(unsigned int index)
	{
		return static_cast<bool>(mFixedBoolVector[index / (sizeof(int) * 8)] & (1 << (index % (sizeof(int) * 8))));
	}
	template<size_t N>
	inline bool FixedVector<bool, N>::operator[](unsigned int index)
	{
		return static_cast<bool>(mFixedBoolVector[index / (sizeof(int) * 8)] & (1 << (index % (sizeof(int) * 8))));
	}
	template<size_t N>
	inline int FixedVector<bool, N>::GetIndex(bool bData)
	{
		size_t count = 0;
		for (size_t index = 0; index < mCount; index++)
		{
			count = index % (sizeof(int) * 8);
			if (static_cast<bool>(mFixedBoolVector[index / (sizeof(int) * 8)] & (1 << count)) == bData)
			{
				return index;
			}
		}
		return -1;
	}
	template<size_t N>
	inline size_t FixedVector<bool, N>::GetSize()
	{
		return mCount;
	}
	template<size_t N>
	inline size_t FixedVector<bool, N>::GetCapacity()
	{
		return N;
	}
}
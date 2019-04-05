#pragma once
#include <iostream>
#include <memory>

namespace lab11
{
	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);
		Storage(Storage& copy);
		Storage(Storage&& copy);
		Storage<T>& operator=(const Storage& copy);
		Storage<T>& operator=(Storage&& copy);

		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;
	private:
		std::unique_ptr<T[]> mData;
		unsigned int mLength;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length) :
		mData(std::make_unique<T[]>(length)),
		mLength(length)
	{
		memset(mData.get(), 0, sizeof(T) * length);
	}

	template<typename T> Storage<T>::Storage(unsigned int length, const T& initialValue) :
		mData(std::make_unique<T[]>(length)),
		mLength(length)
	{
		for (unsigned int i = 0; i < length; i++)
		{
			mData[i] = initialValue;
		}
	}

	template<typename T> inline Storage<T>::Storage(Storage& copy) :
		mData(std::make_unique<T[]>(copy.mLength)),
		mLength(copy.mLength)
	{
		memcpy(mData.get(), copy.mData.get(), sizeof(T) * mLength);
	}

	template<typename T>
	inline Storage<T>::Storage(Storage&& copy) :
		mData(std::move(copy.mData)),
		mLength(copy.mLength)
	{
		copy.mData.reset();
		copy.mLength = 0;
	}

	template<typename T>
	inline Storage<T>& Storage<T>::operator=(const Storage& copy)
	{
		if (this != &copy)
		{
			mData.reset();
			mLength = copy.mLength;
			mData = std::make_unique<T[]>(mLength);
			memcpy(mData.get(), copy.mData.get(), sizeof(T) * mLength);
		}
		return *this;
	}

	template<typename T>
	inline Storage<T>& Storage<T>::operator=(Storage&& copy)
	{
		if (this != &copy)
		{
			mData.reset();
			mLength = copy.mLength;
			mData = std::make_unique<T[]>(mLength);
			mData = std::move(copy.mData);
			copy.mLength = 0;
		}
		return *this;
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (mLength <= index)
			return false;
		mData[index] = data;
		return true;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		return mData;
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mLength;
	}
}
#include "MyStream.h"
#include "MyString.h"

using namespace mystd;
namespace assignment1
{
	MyString::MyString(const char* s) :
		mStringLen(StrLen(s) + 1)
	{
		if (s == nullptr)
		{
			mStringLen = 1;
			mString = new char[mStringLen];
			MemCpy(mString, "\0", mStringLen);
		}
		else
		{
			mString = new char[mStringLen];
			MemCpy(mString, s, mStringLen);
		}
	}

	MyString::MyString(const MyString& other):
		mStringLen(other.mStringLen)
	{
		if (other.mString == nullptr)
		{
			mStringLen = 1;
			mString = new char[mStringLen];
			MemCpy(mString, "\0", mStringLen);
		}
		else
		{
			mString = new char[mStringLen];
			MemCpy(mString, other.mString, mStringLen);
		}
	}

	MyString::~MyString()
	{
		delete[] mString;
		mString = nullptr;
	}

	unsigned int MyString::GetLength() const
	{
		return mStringLen - 1;
	}

	const char* MyString::GetCString() const
	{
		return mString;
	}

	void MyString::Append(const char* s)
	{
		int stringLen = mStringLen + StrLen(s);
		if (stringLen == 0)
			return;
		char* stringSum = new char[stringLen];
		MemCpy(stringSum, mString, mStringLen - 1);
		MemCpy(stringSum + (mStringLen - 1), s, StrLen(s) + 1);
		delete[] mString;
		mString = stringSum;
		mStringLen = stringLen;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		MyString sum("");
		sum.Append(mString);
		sum.Append(other.mString);
		return sum;
	}

	int MyString::IndexOf(const char* s)
	{
		int index = 0;
		if (s == "")
			return index;
		int stringLen = StrLen(s);
		int count = 0;
		while (mString[index] != '\0')
		{
			for (count = 0; count < stringLen; count++)
			{
				if (mString[index + count] != s[count])
				{
					break;
				}
			}
			if (count == stringLen)
			{
				return index;
			}
			index++;
		}
		return -1;
	}

	int MyString::LastIndexOf(const char* s)
	{
		int index = mStringLen - 1;
		if (s == "")
			return index;
		int stringLen = StrLen(s);
		int count = 0;
		while (index >= 0)
		{
			for (count = 0; count < stringLen; count++)
			{
				if (mString[index - count] != s[stringLen - count - 1])
				{
					break;
				}
			}
			if (count >= stringLen)
			{
				return index - count + 1;
			}
			index--;
		}
		return -1;
	}

	void MyString::Interleave(const char* s)
	{
		int srcStringLen = StrLen(s);
		if (srcStringLen == 0)
			return;
		int stringLen = mStringLen + srcStringLen;
		char* stringSum = new char[stringLen];
		int index = 0;
		int indexSrc2 = 0;
		unsigned int indexSrc1 = 0;
		while (index < stringLen - 1)
		{
			if (indexSrc1 < mStringLen - 1)
			{
				stringSum[index] = mString[indexSrc1];
				indexSrc1++;
				index++;
			}
			if (indexSrc2 < srcStringLen)
			{
				stringSum[index] = s[indexSrc2];
				indexSrc2++;
				index++;
			}
		}
		stringSum[index] = '\0';
		delete[] mString;
		mString = stringSum;
		mStringLen = stringLen;
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		if (mStringLen - 1 <= index)
		{
			return false;
		}
		while (mString[index + 1] != '\0')
		{
			mString[index] = mString[index + 1];
			index++;
		}
		mString[index] = '\0';
		int stringLen = StrLen(mString) + 1;
		char* changeString = new char[stringLen];
		MemCpy(changeString, mString, stringLen);
		delete[] mString;
		mString = changeString;
		mStringLen = stringLen;
		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		if (totalLength < mStringLen - 1)
		{
			return;
		}
		char* stringPad = new char[totalLength + 1];
		unsigned int index = 0;
		for (index; index < totalLength - mStringLen + 1; index++)
		{
			stringPad[index] = ' ';
		}
		MemCpy(stringPad + index, mString, mStringLen);
		delete[] mString;
		mString = stringPad;
		mStringLen = totalLength + 1;
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		if (totalLength < mStringLen - 1)
		{
			return;
		}
		char* stringPad = new char[totalLength + 1];
		unsigned int index = 0;
		for (index; index < totalLength - mStringLen + 1; index++)
		{
			stringPad[index] = c;
		}
		MemCpy(stringPad + index, mString, mStringLen);
		delete[] mString;
		mString = stringPad;
		mStringLen = totalLength + 1;
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		if (totalLength < mStringLen - 1)
		{
			return;
		}
		char* stringPad = new char[totalLength + 1];
		MemCpy(stringPad, mString, mStringLen - 1);
		unsigned int index = mStringLen - 1;
		for (index; index < totalLength; index++)
		{
			stringPad[index] = ' ';
		}
		stringPad[index] = '\0';
		delete[] mString;
		mString = stringPad;
		mStringLen = totalLength + 1;
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		if (totalLength < mStringLen - 1)
		{
			return;
		}
		char* stringPad = new char[totalLength + 1];
		MemCpy(stringPad, mString, mStringLen - 1);
		unsigned int index = mStringLen - 1;
		for (index; index < totalLength; index++)
		{
			stringPad[index] = c;
		}
		stringPad[index] = '\0';
		delete[] mString;
		mString = stringPad;
		mStringLen = totalLength + 1;
	}

	void MyString::Reverse()
	{
		char* front = mString;
		char* back = mString + (mStringLen - 2);
		while (front < back)
		{
			char temp = *front;
			*front = *back;
			*back = temp;
			front++;
			back--;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		if (mStringLen != rhs.mStringLen)
		{
			return false;
		}
		for (unsigned int index = 0; index < mStringLen; index++)
		{
			if (mString[index] != rhs.mString[index])
				return false;
		}
		return true;
	}

	void MyString::ToLower()
	{
		for (unsigned int index = 0; index < mStringLen; index++)
		{
			if (mString[index] >= 'A' && mString[index] <= 'Z')
				mString[index] += 32;
		}
	}

	void MyString::ToUpper()
	{
		for (unsigned int index = 0; index < mStringLen; index++)
		{
			if (mString[index] >= 'a' && mString[index] <= 'z')
				mString[index] -= 32;
		}
	}
}
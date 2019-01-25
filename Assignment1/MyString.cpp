#include "MyStream.h"
#include "MyString.h"

using namespace mystd;
namespace assignment1
{
	MyString::MyString(const char* s) :
		mStringLen(StrLen(s) + 1)
	{
		mString = new char[mStringLen];
		MemCpy(mString, s, mStringLen);
	}

	MyString::MyString(const MyString& other):
		mStringLen(other.mStringLen)
	{
		mString = new char[mStringLen];
		MemCpy(mString, other.mString, mStringLen);
	}

	MyString::~MyString()
	{
		delete[] mString;
		mString = nullptr;
	}

	unsigned int MyString::GetLength() const
	{
		//return mStringLen - 1;
	}

	const char* MyString::GetCString() const
	{
		//return mString;
	}

	void MyString::Append(const char* s)
	{
		//int stringLen = mStringLen + StrLen(s);
		//char* stringSum = new char[stringLen];
		//MemCpy(stringSum, mString, mStringLen - 1);
		//MemCpy(stringSum + (mStringLen - 1), s, StrLen(s) + 1);
		//delete[] mString;
		//mString = stringSum;
		//mStringLen = stringLen;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		//MyString sum("");
		//sum.Append(mString);
		//sum.Append(other.mString);
		//return sum;
	}

	int MyString::IndexOf(const char* s)
	{
		//int index = 0;
		//if (s == "")
		//	return index;
		//bool bSearch = false;
		//int stringLen = StrLen(s);
		//while (mString[index] != '\0')
		//{
		//	for (int count = 0; count < stringLen; count++)
		//	{
		//		if (mString[index] == s[count])
		//		{
		//			bSearch = true;
		//			break;
		//		}
		//	}
		//	if (bSearch)
		//		break;
		//	index++;
		//}
		//if (!bSearch)
		//	index = -1;
		//return index;
	}

	int MyString::LastIndexOf(const char* s)
	{
		return 0;
	}

	void MyString::Interleave(const char* s)
	{
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		//if (mStringLen <= index)
		//	return false;
		//
		//while (mString[index + 1] != '\0')
		//{
		//	mString[index] = mString[index + 1];
		//	index++;
		//}
		//mString[index] = '\0';
		//int stringLen = StrLen(mString) + 1;
		//char* changeString = new char[stringLen];
		//MemCpy(changeString, mString, stringLen);
		//delete[] mString;
		//mString = changeString;
		//mStringLen = stringLen;
		//return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
	}

	void MyString::PadRight(unsigned int totalLength)
	{
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
	}

	void MyString::Reverse()
	{
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		return false;
	}

	void MyString::ToLower()
	{
	}

	void MyString::ToUpper()
	{
	}
}
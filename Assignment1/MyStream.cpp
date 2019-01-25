#include "MyStream.h"

namespace mystd
{
	int StrLen(const char* s)
	{
		if (s == nullptr)
			return -1;
		int index = 0;
		while (s[index] != '\0')
		{
			index++;
		}
		return index;
	}

	int StrLen(char* s)
	{
		if (s == nullptr)
			return -1;
		int index = 0;
		while (s[index] != '\0')
		{
			index++;
		}
		return index;
	}

	void* MemCpy(void* dst, const void* src, unsigned int count)
	{
		char* tempDst = (char*)dst;
		const char* tempSrc = (char*)src;
		while (count--)
		{
			*tempDst++ = *tempSrc++;
		}
		return dst;
	}

}

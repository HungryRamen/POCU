#pragma once

namespace Min
{
	int Min(long size1, long size2)
	{
		if (size1 > size2)
			return static_cast<int>(size2);
		return static_cast<int>(size1);
	}
}
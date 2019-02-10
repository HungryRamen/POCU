#pragma once

#include "Lawn.h"
#include "eFenceType.h"

namespace lab5
{
	class EquilateralTriangleLawn : public Lawn
	{
	public:
		EquilateralTriangleLawn(unsigned int width);
		virtual ~EquilateralTriangleLawn();

		virtual unsigned int GetArea() const;

		virtual unsigned int GetMinimumFencesCount() const;
		virtual unsigned int GetFencePrice(eFenceType fenceType) const;
	protected:
		unsigned int mWidth;
	};
}
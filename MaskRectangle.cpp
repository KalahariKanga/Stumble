#include "stdafx.h"
#include "MaskRectangle.h"


MaskRectangle::MaskRectangle(int x1, int y1, int x2, int y2)
{
	shape = MASK_SHAPE_RECTANGLE;
	this->x1 = std::min(x1,x2);
	this->y1 = std::min(y1,y2);
	this->x2 = std::max(x1,x2);
	this->y2 = std::max(y1,y2);
}


MaskRectangle::~MaskRectangle()
{
}

bool MaskRectangle::checkCollision(Mask* other)
{
	if (other->shape == MASK_SHAPE_RECTANGLE)
	{
		if (x1 < other->x2 && x2 > other->x1 &&	y1 < other->y2 && y2 > other->y1)
			return 1;
		return 0;
	}
	if (other->shape == MASK_SHAPE_CIRCLE)
	{

	}
	return 0;
}

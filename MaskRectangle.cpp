#include "stdafx.h"
#include "MaskRectangle.h"


MaskRectangle::MaskRectangle(int x, int y, int xr, int yr)
{
	shape = MASK_SHAPE_RECTANGLE;
	this->x = x;
	this->y = y;
	this->xr = xr;
	this->yr = yr;
}


MaskRectangle::~MaskRectangle()
{
}

bool MaskRectangle::checkCollision(Mask* other)
{
	if (other->shape == MASK_SHAPE_RECTANGLE)
	{
		MaskRectangle* o = (MaskRectangle*)other;
		if (x - xr < o->x + o->xr && x + xr > o->x - o->xr)
			if(	y-yr < o->y + o->yr && y + yr > o->y - o->yr)
				return 1;
		return 0;
	}
	if (other->shape == MASK_SHAPE_CIRCLE)
	{

	}
	return 0;
}


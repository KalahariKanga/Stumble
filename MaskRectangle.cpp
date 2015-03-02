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
		float nearestX = clamp(other->x,x-xr,x+xr);
		float nearestY = clamp(other->y,y-yr,y+yr);
		float dx = nearestX - other->x;
		float dy = nearestY - other->y;
		return dx*dx + dy*dy < other->r*other->r;
	}
	return 0;
}


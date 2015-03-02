#include "stdafx.h"
#include "MaskCircle.h"
#include "Vector2.h"

MaskCircle::MaskCircle(int x, int y, int r)
{
	this->x = x;
	this->y = y;
	this->r = r;
	shape = MASK_SHAPE_CIRCLE;
}


MaskCircle::~MaskCircle()
{
}

bool MaskCircle::checkCollision(Mask* other)
{
	if (other->shape == MASK_SHAPE_RECTANGLE)
	{
		float nearestX = clamp(x,other->x-other->xr,other->x+other->xr);
		float nearestY = clamp(y,other->y-other->yr,other->y+other->yr);
		float dx = nearestX - x;
		float dy = nearestY - y;
		return dx*dx + dy*dy < r*r;
	}
	if (other->shape == MASK_SHAPE_CIRCLE)
	{
		if ((Vector2(x, y) - Vector2(other->x, other->y)).getLength() < r + ((MaskCircle*)other)->r)
			return 1;
		return 0;
	}
}

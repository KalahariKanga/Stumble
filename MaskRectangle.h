#pragma once
#include "Mask.h"
class MaskRectangle :
	public Mask
{
public:
	MaskRectangle(int x1, int y1, int x2, int y2);
	~MaskRectangle();
	virtual bool checkCollision(Mask*);
	virtual void translate(float, float);
};


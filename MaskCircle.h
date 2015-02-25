#pragma once
#include "Mask.h"
class MaskCircle :
	public Mask
{
public:
	MaskCircle(int x, int y, int r);
	~MaskCircle();
	int r;
	virtual bool checkCollision(Mask*);
};


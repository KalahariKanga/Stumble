#pragma once
#include "Mask.h"
class DLL MaskRectangle :
	public Mask
{
public:
	MaskRectangle(int x, int y, int xr, int yr);
	~MaskRectangle();
	int xr, yr;
	virtual bool checkCollision(Mask*);
};


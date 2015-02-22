#pragma once
#include "core.h"
class Mask
{
public:
	Mask();
	~Mask();
	int shape;
	int x1, y1, x2, y2; 
	virtual bool checkCollision(Mask*) = 0;
};


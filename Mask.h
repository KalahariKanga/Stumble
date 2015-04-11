#pragma once
#include "core.h"
class DLL Mask
{
public:
	Mask();
	~Mask();
	int shape;
	float x, y;
	virtual bool checkCollision(Mask*) = 0;

};


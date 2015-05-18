#pragma once
#include "core.h"

class DLL Colour
{
public:
	Colour();
	Colour(int r, int g, int b, int a = 255);
	~Colour();
	int r, g, b, a;
	int h();
	int s();
	int v();
	void setRGB(int r, int g, int b, int a = 255);
	void setHSV(int h, int s, int v, int a = 255);
	void shiftRGB(int r, int g, int b, int a = 0);
	void shiftHSV(int h, int s, int v, int a = 0);
};


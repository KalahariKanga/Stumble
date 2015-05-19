#include "stdafx.h"
#include "core.h"
float clamp(float value, float min, float max)
{
	if (value < min)
		value = min;
	if (value > max)
		value = max;
	return value;
}

float randomRange(float a, float b)
{
	///TODO: this sucks
	float r = (float)rand() / (float)RAND_MAX;
	return a + r * (b - a);
}
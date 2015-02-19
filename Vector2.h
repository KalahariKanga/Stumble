#pragma once
#include <cmath>
class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();
	float x, y;
	float getDirection();
	float getLength();
	void setDirection(float d);
	void setLength(float d);

	Vector2 operator+(const Vector2& v);
	Vector2 operator-(const Vector2& v);
};



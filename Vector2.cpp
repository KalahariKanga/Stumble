#include "stdafx.h"
#include "Vector2.h"


Vector2::Vector2() : Vector2(0, 0)
{
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{
}

float Vector2::getDirection()
{
	return atan2(y, x);
}

float Vector2::getLength()
{
	return sqrt(x*x + y*y);
}

void Vector2::setDirection(float d)
{
	float l = getLength();
	x = l*cos(d);
	y = l*sin(d);
}

void Vector2::setLength(float l)
{
	float d = getDirection();
	x = l*cos(d);
	y = l*sin(d);
}

Vector2 Vector2::operator+(const Vector2& v)
{
	return Vector2(x + v.x, y + v.y);
}

Vector2 Vector2::operator-(const Vector2& v)
{
	return Vector2(x-v.x,y-v.y);
}

Vector2 Vector2::operator+=(const Vector2& v)
{
	this->x += v.x;
	this->y += v.y;
	return *this;
}
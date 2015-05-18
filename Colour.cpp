#include "stdafx.h"
#include "Colour.h"


Colour::Colour()
{
}

Colour::Colour(int r, int g, int b, int a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

Colour::~Colour()
{
}

int Colour::h()
{
	float min, max, delta, h;
	min = std::min(r, std::min(g, b));
	max = std::max(r, std::max(g, b));
	delta = max - min;

	if (r == max)
		h = (g - b) / delta;
	else if (g == max)
		h = 2 + (b - r) / delta;
	else
		h = 4 + (r - g) / delta;
	h *= ((float)256 / 6);
	if (h < 0)
		h += 256;
	return h;
}

int Colour::s()
{
	float min, max, delta;
	min = std::min(r, std::min(g, b));
	max = std::max(r, std::max(g, b));
	delta = max - min;
	if (max != 0)
		return 255 * (delta / max);
	else
		return 0;
}

int Colour::v()
{
	return std::max(r, std::max(g, b));
}

void Colour::setRGB(int r, int g, int b, int a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

void Colour::setHSV(int h, int s, int v, int a)
{
	float r, g, b;
	float H = (float)h / 255;
	float S = (float)s / 255;
	float V = (float)v / 255;

	int i = floor((float)H * 6);
	float f = H * 6 - i;
	float p = V * (1 - S);
	float q = V * (1 - f * S);
	float t = V * (1 - (1 - f) * S);

	switch (i % 6){
	case 0: r = V, g = t, b = p; break;
	case 1: r = q, g = V, b = p; break;
	case 2: r = p, g = V, b = t; break;
	case 3: r = p, g = q, b = V; break;
	case 4: r = t, g = p, b = V; break;
	case 5: r = V, g = p, b = q; break;
	}

	this->r = r * 255;
	this->g = g * 255;
	this->b = b * 255;
	this->a = a;
}

void Colour::shiftRGB(int r, int g, int b, int a)
{
	this->r += r;
	this->g += g;
	this->b += b;
	this->a += a;
}

void Colour::shiftHSV(int h, int s, int v, int a)
{
	setHSV(this->h() + h, this->s() + s, this->v() + v, this->a + a);
}
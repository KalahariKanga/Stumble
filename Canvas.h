#pragma once
#include "core.h"
class Canvas
{
	sf::Image* image;
	sf::Color drawColour;
	float alpha;
public:
	Canvas();
	Canvas(int, int);
	~Canvas();
	sf::Image* getImage();
	void setDrawColour(sf::Color);
	void setDrawAlpha(float);
	void drawPoint(int x, int y);
	void drawPoint(int x, int y, sf::Color col);
	void drawLine(int x1, int y1, int x2, int y2);
	void drawCircle(int x, int y, int r, bool outline);
	void drawRectangle(int x1, int y1, int x2, int y2, bool outline);
	void clear();
	
};


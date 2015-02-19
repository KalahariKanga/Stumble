#pragma once
#include "core.h"
class Canvas
{
	sf::Image* image;
	sf::Color drawColour;
public:
	Canvas();
	Canvas(int, int);
	~Canvas();
	sf::Image* getImage();
	void setDrawColour(sf::Color);
	void drawPoint(int x, int y, sf::Color col);
	void drawLine(int x1, int y1, int x2, int y2);
	void clear();
};


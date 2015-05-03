#pragma once
#include "core.h"
#include "Vector2.h"
class DLL Canvas
{
	//sf::Image* image;
	sf::Color drawColour;
	
public:
	Canvas();
	Canvas(int, int);
	~Canvas();
	sf::Uint8* data;
	void colorToData(int x, int y, sf::Color c);
	int width, height;

	void loadFromFile(std::string fname);

	sf::Color getPoint(int x, int y);
	void setDrawColour(sf::Color);
	void setDrawAlpha(float);
	void drawPoint(int x, int y);
	void drawPoint(int x, int y, sf::Color col);
	void drawLine(int x1, int y1, int x2, int y2);
	void drawCircle(int x, int y, int r, bool outline);
	void drawRectangle(int x1, int y1, int x2, int y2, bool outline);
	void drawCanvas(Canvas*, int x, int y);
	void drawCircleFunction(int x, int y, int r, std::function<float(float)> f);
	void drawLineFunction(int x0, int y0, int x1, int y1, std::function<float(float)> f, bool fixEndpoints = 1);
	void clear();
	void clear(sf::Color);

	void applyPixelModifier(std::function<sf::Color(Canvas*,int,int)> f);
};


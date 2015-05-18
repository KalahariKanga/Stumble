#pragma once
#include "core.h"
#include "Vector2.h"
#include "Colour.h"
class DLL Canvas
{
	//sf::Image* image;
	Colour drawColour;
	
public:
	Canvas();
	Canvas(int, int);
	~Canvas();
	sf::Uint8* data = nullptr;
	void colourToData(int x, int y, Colour c);
	int width, height;

	void loadFromFile(std::string fname);

	Colour getPoint(int x, int y);
	void setDrawColour(Colour);
	void setDrawAlpha(float);
	void drawPoint(int x, int y);
	void drawPoint(int x, int y, Colour col);
	void drawLine(int x1, int y1, int x2, int y2);
	void drawCircle(int x, int y, int r, bool outline);
	void drawRectangle(int x1, int y1, int x2, int y2, bool outline);
	void drawCanvas(Canvas*, int x, int y);
	void drawCircleFunction(int x, int y, int r, std::function<float(float)> f);
	void drawLineFunction(int x0, int y0, int x1, int y1, std::function<float(float)> f, bool fixEndpoints = 1);
	void clear();
	void clear(Colour);

	void applyPixelModifier(std::function<Colour(Canvas*, int, int)> f);
};


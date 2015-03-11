#include "stdafx.h"
#include "Canvas.h"


Canvas::Canvas()
{
	
}

Canvas::Canvas(int width, int height)
{
	drawColour = sf::Color::Red;
	image = new sf::Image();
	image->create(width, height);
	setDrawAlpha(255);
}

Canvas::~Canvas()
{
}

sf::Image* Canvas::getImage()
{
	return image;
}

sf::Color Canvas::getPoint(int x, int y)
{
	if (x < 0 || x >= image->getSize().x || y < 0 || y >= image->getSize().y)
		return sf::Color::Black; //TODO: wrap or extend or something
	return image->getPixel(x, y);
}

void Canvas::setDrawColour(sf::Color c)
{
	drawColour = c;
}

void Canvas::setDrawAlpha(float a)
{
	drawColour.a = clamp(a*255, 0, 255);
}

void Canvas::drawPoint(int x, int y)
{
	drawPoint(x, y, drawColour);
}

void Canvas::drawPoint(int x, int y, sf::Color col)
{
	if (x < 0 || x >= image->getSize().x || y < 0 || y >= image->getSize().y)
		return;
	if (col.a == 0)
		return;
	if (col.a < 255)
	{
		sf::Color dest = image->getPixel(x, y);
		sf::Color out;
		float ca = (float)col.a / 255;
		float da = (float)dest.a / 255;
		float oa = ca + da*(1 - ca);
		if (oa > 0)
		{
			
			out.r = (col.r*ca + dest.r*da*(1 - ca)) / oa;
			out.g = (col.g*ca + dest.g*da*(1 - ca)) / oa;
			out.b = (col.b*ca + dest.b*da*(1 - ca)) / oa;
			out.a = oa * 255;
		}
		else
		{
			out.r = 0;
			out.g = 0;
			out.b = 0;
		}

		image->setPixel(x, y, out);
	}
	else
	{
		image->setPixel(x, y, col);
	}
}

void Canvas::drawLine(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int dx1 = std::abs(dx);
	int dy1 = std::abs(dy);
	int px = 2 * dy1 - dx1;
	int py = 2 * dx1 - dy1;
	int x, y, xe, ye;
	if (dy1 <= dx1)
	{
		if (dx >= 0)
		{
			x = x1;
			y = y1;
			xe = x2;
		}
		else
		{
			x = x2;
			y = y2;
			xe = x1;
		}
		drawPoint(x, y, drawColour);
		for (int i = 0; x < xe; i++)
		{
			x = x + 1;
			if (px < 0)
			{
				px = px + 2 * dy1;
			}
			else
			{
				if ((dx < 0 && dy < 0) || (dx>0 && dy>0))
				{
					y = y + 1;
				}
				else
				{
					y = y - 1;
				}
				px = px + 2 * (dy1 - dx1);
			}
			drawPoint(x, y, drawColour);
		}
	}
	else
	{
		if (dy >= 0)
		{
			x = x1;
			y = y1;
			ye = y2;
		}
		else
		{
			x = x2;
			y = y2;
			ye = y1;
		}
		drawPoint(x, y, drawColour);
		for (int i = 0; y < ye; i++)
		{
			y = y + 1;
			if (py <= 0)
			{
				py = py + 2 * dx1;
			}
			else
			{
				if ((dx < 0 && dy < 0) || (dx>0 && dy>0))
				{
					x = x + 1;
				}
				else
				{
					x = x - 1;
				}
				py = py + 2 * (dx1 - dy1);
			}
			drawPoint(x, y, drawColour);
		}
	}
}

void Canvas::drawCircle(int x, int y, int r, bool outline)
{
	if (outline)
	{
		float jump = (2 * PI) / 32;
		for (int c = 0; c < 32; c++)
		{
			drawLine(x + r*cos(c*jump), y + r*sin(c*jump), x + r*cos((c + 1)*jump), y + r*sin((c + 1)*jump));
		}
	}
}

void Canvas::drawRectangle(int x1, int y1, int x2, int y2, bool outline)
{
	if (outline)
	{
		drawLine(x1, y1, x2, y1);
		drawLine(x2, y1, x2, y2);
		drawLine(x1, y2, x2, y2);
		drawLine(x1, y1, x1, y2);
	}
	else
	{
		for (int cx = x1; cx <= x2; cx++)
			for (int cy = y1; cy <= y2; cy++)
				drawPoint(cx, cy);
	}
}

void Canvas::drawCanvas(Canvas* source, int x, int y)
{
	for (int cx = 0; cx < source->getImage()->getSize().x; cx++)
		for (int cy = 0; cy < source->getImage()->getSize().y; cy++)
		{
			drawPoint(x + cx, y + cy, source->getPoint(cx, cy));
		}
}

void Canvas::clear(sf::Color c)
{
	for (int cx = 0; cx < image->getSize().x; cx++)
		for (int cy = 0; cy < image->getSize().y; cy++)
			image->setPixel(cx, cy, c);//guaranteed to be in range, so faster
}
void Canvas::clear()
{
	clear(drawColour);
}
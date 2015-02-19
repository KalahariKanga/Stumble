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
}

Canvas::~Canvas()
{
}

sf::Image* Canvas::getImage()
{
	return image;
}

void Canvas::setDrawColour(sf::Color c)
{
	drawColour = c;
}

void Canvas::drawPoint(int x, int y, sf::Color col)
{
	if (x < 0 || x > image->getSize().x || y < 0 || y > image->getSize().y)
		return;
	image->setPixel(x, y, col);
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

void Canvas::clear()
{
	for (int cx = 0; cx < image->getSize().x; cx++)
		for (int cy = 0; cy < image->getSize().y; cy++)
			image->setPixel(cx, cy, drawColour);//guaranteed to be in range, so faster
}
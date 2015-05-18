#include "stdafx.h"
#include "CanvasStore.h"

CanvasStore* CanvasStore::instance = nullptr;

CanvasStore::CanvasStore()
{
	clearColour = Colour(0, 0, 0, 255);
}


CanvasStore::~CanvasStore()
{
}

CanvasStore* CanvasStore::get()
{
	if (!instance)
		instance = new CanvasStore();
	return instance;
}

Canvas* CanvasStore::addCanvas(std::string name, int width, int height)
{
	Canvas* c = new Canvas(width, height);
	map.insert(std::pair<std::string, Canvas*>(name, c));
	return c;
}

Canvas* CanvasStore::addCanvas(std::string name, std::string fname)
{
	Canvas* c = new Canvas();
	c->loadFromFile(fname);
	map.insert(std::pair<std::string, Canvas*>(name, c));
	return c;
}

Canvas* CanvasStore::getCanvas(std::string name)
{
	if (map.count(name))
		return map.at(name);
	else
		return nullptr;
}

void CanvasStore::clearScreen()
{
	screen->setDrawColour(clearColour);
	screen->drawRectangle(0,0,WINDOW_WIDTH,WINDOW_HEIGHT,0);
}

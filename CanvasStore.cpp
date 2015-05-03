#include "stdafx.h"
#include "CanvasStore.h"


CanvasStore::CanvasStore()
{
}


CanvasStore::~CanvasStore()
{
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



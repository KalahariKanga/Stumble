#pragma once
#include "Canvas.h"
class CanvasStore
{
public:
	CanvasStore();
	~CanvasStore();

	std::map < std::string, Canvas* > map;
	Canvas* addCanvas(std::string name, int width, int height);
	Canvas* addCanvas(std::string name, std::string fname);
	
	Canvas* screen = 0;
};


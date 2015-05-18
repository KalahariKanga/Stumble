#pragma once
#include "Canvas.h"
class DLL CanvasStore
{
	CanvasStore();
	static CanvasStore* instance;
public:
	
	~CanvasStore();

	static CanvasStore* get();

	std::map < std::string, Canvas* > map;
	Canvas* addCanvas(std::string name, int width, int height);
	Canvas* addCanvas(std::string name, std::string fname);
	Canvas* getCanvas(std::string name);
	Canvas* screen = 0;
	Colour clearColour;
	void clearScreen();
};


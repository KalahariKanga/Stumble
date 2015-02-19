#pragma once
#include "GameObject.h"
class TestObject :
	public GameObject
{
public:
	TestObject();
	~TestObject();
	void step();
	void draw(sf::Image* i);
};


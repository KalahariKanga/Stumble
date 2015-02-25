#pragma once
#include "GameObject.h"
class TestObject :
	public GameObject
{
public:
	TestObject();
	~TestObject();
	void step();
	virtual void draw(Canvas* c);
	virtual void onCollision(GameObject*);
	virtual void onEvent(sf::Event*);
};


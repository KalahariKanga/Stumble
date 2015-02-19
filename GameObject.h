#pragma once
#include "core.h"
#include "Vector2.h"
#include "Canvas.h"

class GameObject
{
	
public:
	GameObject();
	~GameObject();
	std::string name;
	Vector2 position, velocity;
	std::vector<GameObject*>* store;

	void update();
	virtual void step() = 0;
	virtual void draw(Canvas*) = 0;
	
};


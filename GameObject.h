#pragma once
#include "core.h"
#include "Vector2.h"
#include "Canvas.h"
#include "MaskRectangle.h"

class GameObject
{
	
public:
	GameObject();
	~GameObject();
	std::string name;
	Vector2 position, velocity;
	std::vector<GameObject*>* store;
	Mask* mask;
	bool hasMask = 0;

	void update();
	virtual void step() = 0;
	virtual void draw(Canvas*) = 0;
	virtual void onCollision(GameObject*) = 0;
	
};


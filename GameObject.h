#pragma once
#include "core.h"
#include "Vector2.h"
#include "Canvas.h"
#include "MaskRectangle.h"
#include "Environment.h"
class GameObject
{
	
public:
	GameObject();
	~GameObject();
	std::string name;
	Vector2 position, velocity, previousPosition;
	static std::vector<GameObject*>* store;
	static std::vector<GameObject*>* tempstore;
	static Environment* environment;
	Mask* mask;
	bool hasMask = 0;

	template<class type> bool isType()
	{
		if (dynamic_cast<type>(this))
			return 1;
		return 0;
	};
	void update();

	virtual void step() = 0;
	virtual void draw(Canvas*) = 0;
	virtual void onCollision(GameObject*) = 0;
	virtual void onEvent(sf::Event*) = 0;
	
	void createInstance(GameObject*);
};


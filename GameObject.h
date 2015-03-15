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
	static std::vector<GameObject*>* toCreate;
	static std::vector<GameObject*>* toDestroy;
	static Environment* environment;
	Mask* mask = 0;
	bool hasMask = 0;
	int t = 0;
	template<class type> bool isType()
	{
		if (dynamic_cast<type>(this))
			return 1;
		return 0;
	};
	void update();

	virtual void step();
	virtual void draw(Canvas*);
	virtual void onCollision(GameObject*);
	virtual void onEvent(sf::Event*);
	virtual void onKeyDown(sf::Keyboard::Key);
	virtual void onKeyUp(sf::Keyboard::Key);
	virtual void onKey(sf::Keyboard::Key);
	
	void createInstance(GameObject*);
	void destroyInstance(GameObject*);
};


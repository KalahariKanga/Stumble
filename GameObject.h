#pragma once
#include "SFML/Graphics.hpp"
#include "Vector2.h"
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
	virtual void draw(sf::Image*) = 0; //draw(Canvas*);
	
};


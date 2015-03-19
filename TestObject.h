#pragma once
#include "GameObject.h"
class TestObject :
	public GameObject
{
	sf::Color col;
public:
	TestObject();
	~TestObject();
	void step();
	virtual void draw(Canvas* c);
	virtual void onCollision(GameObject*);
	virtual void onEvent(sf::Event*);
	virtual void onKey(sf::Keyboard::Key k);
	virtual void onKeyUp(sf::Keyboard::Key k);
	virtual void onKeyDown(sf::Keyboard::Key k);
	
	Synth* synth[2];

	float spd = 1;
};


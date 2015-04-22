#pragma once
#include "GameObject.h"
class oShot :
	public GameObject
{
public:
	oShot();
	~oShot();

	virtual void onStep();
	virtual void onDraw(Canvas*);
	/*virtual void onCollision(GameObject*);
	virtual void onEvent(sf::Event*);
	virtual void onKey(sf::Keyboard::Key);
	virtual void onKeyUp(sf::Keyboard::Key);*/
	virtual void onKeyDown(sf::Keyboard::Key);

};


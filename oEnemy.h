#pragma once
#include "GameObject.h"
#include "oShot.h"
class oEnemy :
	public GameObject
{
public:
	oEnemy();
	~oEnemy();

	void onStep();
	void onDraw(Canvas*);
	void onKeyDown(sf::Keyboard::Key);
	void pattern1();
	void pattern2();

	short p = 1;
};


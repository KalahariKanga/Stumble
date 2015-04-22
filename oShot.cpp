#include "stdafx.h"
#include "oShot.h"

oShot::oShot()
{
	position.x = 200;
	position.y = 200;
}


oShot::~oShot()
{
}

void oShot::onStep()
{
	if (position.x < 0 || position.x > WINDOW_WIDTH || position.y < 0 || position.y > WINDOW_HEIGHT)
		destroyInstance(this);
}

void oShot::onDraw(Canvas* c)
{
	int c1 = velocity.getDirection() * 42;
	c->setDrawColour(sf::Color(255 * sin((float)t / 300), 255 - c1, (int)position.x % WINDOW_WIDTH));
	c->drawCircle(position.x, position.y, 4 + 4 * sin((float)t / 20), 1);
	c->setDrawColour(sf::Color(c1, 255 - (int)position.y % WINDOW_HEIGHT, 255 * sin((float)t / 300)));
	c->drawCircle(position.x, position.y, 4 + 4 * cos((float)t / 20), 1);
}

void oShot::onKeyDown(sf::Keyboard::Key k)
{
	if (k == sf::Keyboard::Space)
		velocity.setDirection(velocity.getDirection() + PI);
}
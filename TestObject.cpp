#include "stdafx.h"
#include "TestObject.h"


TestObject::TestObject()
{
	position.x = 320;
	position.y = 240;
	velocity.x = 0.1;
	velocity.y = 0.1;
}


TestObject::~TestObject()
{
}

void TestObject::step()
{
	velocity.setDirection(velocity.getDirection() + 0.01);
}

void TestObject::draw(Canvas* c)
{
	c->setDrawColour(sf::Color::Red);
	c->setDrawAlpha(1);
	c->drawRectangle(position.x, position.y, position.x + 32, position.y + 32, 0);
	c->setDrawColour(sf::Color::Blue);
	c->setDrawAlpha(0.5);
	c->drawRectangle(position.x - 16, position.y - 16, position.x + 16, position.y + 16, 0);

}
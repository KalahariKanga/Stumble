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
	c->drawLine(position.x - 8, position.y, position.x + 8, position.y);
	c->drawLine(position.x, position.y - 8, position.x, position.y + 8);
	c->drawPoint(position.x, position.y, sf::Color::Red);
}
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

void TestObject::draw(sf::Image* i)
{
	for (int c = -8; c <= 8; c++)
	{
		i->setPixel(position.x, position.y + c, sf::Color::White);
		i->setPixel(position.x + c, position.y, sf::Color::White);
	}
}
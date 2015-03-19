#include "stdafx.h"
#include "TestObject.h"
#include "oShot.h"

TestObject::TestObject()
{
	position.x = rand() % WINDOW_WIDTH;
	position.y = rand() % WINDOW_HEIGHT;
	
	hasMask = 1;
	mask = new MaskRectangle(position.x, position.y, 16, 16);
	col.r = rand() % 256;
	col.g = rand() % 256;
	col.b = rand() % 256;

	synth[0] = environment->addSynth("bd.patch");
	synth[1] = environment->addSynth();


}


TestObject::~TestObject()
{
}

void TestObject::step()
{
	if (position.x < 0)
		position.x = WINDOW_WIDTH;
	if (position.x > WINDOW_WIDTH)
		position.x = 0;
	if (position.y < 0)
		position.y = WINDOW_HEIGHT;
	if (position.y > WINDOW_HEIGHT)
		position.y = 0;

	if (t % 30 == 0)
	{
		GameObject* o = new oShot();
		o->position = position + Vector2(16,16);
		o->velocity.x = 4;
		createInstance(o);
		synth[0]->playNoteDuration(Note(c3, 100), 0.2);
	}
}

void TestObject::draw(Canvas* c)
{
	c->setDrawColour(col);
	c->setDrawAlpha(1);
	c->drawRectangle(position.x, position.y, position.x + 32, position.y + 32, 0);
	c->setDrawColour(sf::Color::Blue);
	c->setDrawAlpha(1);
}

void TestObject::onCollision(GameObject* other)
{
	
}

void TestObject::onEvent(sf::Event* e)
{
		
}

void TestObject::onKey(sf::Keyboard::Key k)
{
	if (k == sf::Keyboard::Up)
		position.y -= spd;
	if (k == sf::Keyboard::Down)
		position.y += spd;
	if (k == sf::Keyboard::Left)
		position.x -= spd;
	if (k == sf::Keyboard::Right)
		position.x += spd;
}

void TestObject::onKeyDown(sf::Keyboard::Key k)
{

}

void TestObject::onKeyUp(sf::Keyboard::Key k)
{

}
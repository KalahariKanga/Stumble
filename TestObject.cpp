#include "stdafx.h"
#include "TestObject.h"


TestObject::TestObject()
{
	position.x = rand() % 640;
	position.y = rand() % 480;
	
	hasMask = 1;
	mask = new MaskRectangle(position.x, position.y, 16, 16);
	col.r = rand() % 256;
	col.g = rand() % 256;
	col.b = rand() % 256;
	synth = environment->addSynth();
	synth->addComponent("osc", "SimpleOscillator");
	synth->addComponent("env", "AmpEnvelope");
	synth->linkAudio("osc", "env");
	synth->linkAudio("env", "output");
	synth->setParameterRaw("osc", "waveform", 3);
	synth->noteDown(Note((Notes)c3, 100));
}


TestObject::~TestObject()
{
}

void TestObject::step()
{
	if (position.x < 0)
		position.x = 640;
	if (position.x > 640)
		position.x = 0;
	if (position.y < 0)
		position.y = 480;
	if (position.y > 480)
		position.y = 0;
}

void TestObject::draw(Canvas* c)
{
	c->setDrawColour(col);
	c->setDrawAlpha(0.5);
	c->drawRectangle(position.x, position.y, position.x + 32, position.y + 32, 0);
	c->setDrawColour(sf::Color::Blue);
	c->setDrawAlpha(1);
}

void TestObject::onCollision(GameObject* other)
{
	if (other->isType<TestObject*>())
	{
		velocity.setDirection(velocity.getDirection() + PI);
	}
}

void TestObject::onEvent(sf::Event* e)
{
	if (e->type == sf::Event::KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			position.y -= spd;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			position.y += spd;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			position.x -= spd;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			position.x += spd;
		
	}
	
}
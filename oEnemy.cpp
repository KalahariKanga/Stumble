#include "stdafx.h"
#include "oEnemy.h"


oEnemy::oEnemy()
{
	position.x = WINDOW_WIDTH / 2;
	position.y = WINDOW_HEIGHT / 2;
}


oEnemy::~oEnemy()
{
}

void oEnemy::onStep()
{
	if (p == 1)
		pattern1();
	if (p == 2)
		pattern2();
	if (p == 3)
	{
		pattern1();
		pattern2();
	}
}

void oEnemy::onDraw(Canvas* c)
{
	//c->setDrawColour(sf::Color(255, 255, 255));
	//c->drawCircle(position.x, position.y, 16, 1);
}

void oEnemy::pattern1()
{
	oShot* s = new oShot();
	s->position.x = position.x;
	s->position.y = position.y;
	s->velocity.setLength(5);
	s->velocity.setDirection(sin((float)t / 20) + (float)t / 30);
	createInstance(s);

	s = new oShot();
	s->position.x = position.x;
	s->position.y = position.y;
	s->velocity.setLength(5);
	s->velocity.setDirection(-sin((float)t / 20) - (float)t / 30);
	createInstance(s);

	s = new oShot();
	s->position.x = position.x;
	s->position.y = position.y;
	s->velocity.setLength(5);
	s->velocity.setDirection(sin((float)t / 20) + (float)t / 30 + PI);
	createInstance(s);

	s = new oShot();
	s->position.x = position.x;
	s->position.y = position.y;
	s->velocity.setLength(5);
	s->velocity.setDirection(-sin((float)t / 20) - (float)t / 30 + PI);
	createInstance(s);
}

void oEnemy::pattern2()
{
	oShot* s = new oShot();
	s->position.x = position.x;
	s->position.y = position.y;
	s->velocity.setLength(4 + sin((float)t / 50));
	s->velocity.setDirection(((float)t / 50)*sin((float)t / 100));
	createInstance(s);

	s = new oShot();
	s->position.x = position.x;
	s->position.y = position.y;
	s->velocity.setLength(4+sin((float)t / 50));
	s->velocity.setDirection(((float)t / 50)*sin((float)t / 100) + PI);
	createInstance(s);
}

void oEnemy::onKeyDown(sf::Keyboard::Key k)
{
	if (k == sf::Keyboard::Z)
	{
		p++;
		p = (p % 3) + 1;
	}
}
#include "stdafx.h"
#include "TestObject.h"
#include "oShot.h"

TestObject::TestObject()
{

	
	sprite.loadFromFile("p1_front.png");
	position.x = rand() % WINDOW_WIDTH;
	position.y = rand() % WINDOW_HEIGHT;
	
	hasMask = 1;
	mask = new MaskRectangle(position.x, position.y, 16, 16);
	col.r = rand() % 256;
	col.g = rand() % 256;
	col.b = rand() % 256;

	synth[0] = environment->addSynth("sine.patch");
	synth[1] = environment->addSynth("sine.patch");
	synth[2] = environment->addSynth("sine.patch");

	MidiPlayer* mp = environment->addPlayer("laura.mid");
	mp->assignTrack(1, synth[0]);
	mp->assignTrack(2, synth[1]);
	mp->assignTrack(3, synth[2]);
	mp->play();

	depth = -10;
}


TestObject::~TestObject()
{

}

void TestObject::onStep()
{
	if (position.x < 0)
		position.x = WINDOW_WIDTH;
	if (position.x > WINDOW_WIDTH)
		position.x = 0;
	if (position.y < 0)
		position.y = WINDOW_HEIGHT;
	if (position.y > WINDOW_HEIGHT)
		position.y = 0;

	
}

void TestObject::onDraw(CanvasStore* c)
{
	Canvas* canvas = c->screen;
	canvas->setDrawColour(col);
	canvas->setDrawAlpha(1);
	canvas->drawCircle(position.x, position.y, 32, 0);
	canvas->setDrawColour(Colour(0,0,255));
	canvas->setDrawAlpha(1);
	//canvas->drawCanvas(&sprite, position.x, position.y);
	
	for (int x = 0; x < WINDOW_WIDTH; x+=64)
		canvas->drawLineFunction(x, 0, x, WINDOW_HEIGHT, [&](float p){return 32 * sin((float)t / 30 + p*5 + x); },0);
	for (int y = 0; y < WINDOW_HEIGHT; y += 64)
		canvas->drawLineFunction(0, y, WINDOW_WIDTH, y, [&](float p){return 32 * sin((float)t / 30 + p * 5 + y); },0);

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
	if (k == sf::Keyboard::D)
		destroyInstance(this);
}

void TestObject::onKeyDown(sf::Keyboard::Key k)
{

}

void TestObject::onKeyUp(sf::Keyboard::Key k)
{

}

void TestObject::onMidiEvent(MidiEvent e)
{
	if (e.isNoteOn())
	{
		GameObject* s = new oShot();
		s->position.x = position.x+16;
		s->position.y = position.y+16;
		s->velocity.setLength(6);
		s->velocity.setDirection((float)e.getKeyNumber() / 5);
		createInstance(s);
	}
}

void TestObject::fire(std::string drum)
{
	GameObject* o = new oShot();
	o->position = position + Vector2(16, 16);
	createInstance(o);

	if (drum == "bd")
	{
		synth[0]->playNoteDuration(Note(c3, 100), 0.2);
		o->velocity.x = 4;
	}
	if (drum == "hh")
	{
		synth[1]->playNoteDuration(Note(c3, 100), 0.2);
		o->velocity.x = 6;
	}
	if (drum == "sd")
	{
		synth[2]->playNoteDuration(Note(c3, 100), 0.2);
		o->velocity.x = 5;
	}
}

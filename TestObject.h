#pragma once
#include "GameObject.h"
class TestObject :
	public GameObject
{
	sf::Color col;
	Canvas sprite;
public:
	TestObject();
	~TestObject();
	void onStep();
	virtual void onDraw(CanvasStore* c);
	virtual void onCollision(GameObject*);
	virtual void onEvent(sf::Event*);
	virtual void onKey(sf::Keyboard::Key k);
	virtual void onKeyUp(sf::Keyboard::Key k);
	virtual void onKeyDown(sf::Keyboard::Key k);
	virtual void onMidiEvent(MidiEvent e);
	Synth* synth[3];

	float spd = 4;

	void fire(std::string drum);
};


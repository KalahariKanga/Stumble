#include "stdafx.h"
#include "GameObject.h"

std::vector<GameObject*>* GameObject::store;
std::vector<GameObject*>* GameObject::toCreate;
std::vector<GameObject*>* GameObject::toDestroy;
Environment* GameObject::environment;

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::update()
{
	t++;
	previousPosition = position;
	position += velocity;
	if (mask != nullptr)
	{
		mask->x = position.x;
		mask->y = position.y;
	}
	step();
}

void GameObject::createInstance(GameObject* o)
{
	toCreate->push_back(o);
}

void GameObject::destroyInstance(GameObject* o)
{
	toDestroy->push_back(o);
}

void GameObject::step()
{

}
void GameObject::draw(Canvas*)
{

}
void GameObject::onCollision(GameObject*)
{

}
void GameObject::onEvent(sf::Event*)
{

}
void GameObject::onKeyDown(sf::Keyboard::Key)
{

}
void GameObject::onKeyUp(sf::Keyboard::Key)
{

}
void GameObject::onKey(sf::Keyboard::Key)
{

}
void GameObject::onMidiEvent(MidiEvent)
{

}
Environment* GameObject::getEnvironment()
{
	return environment;
}
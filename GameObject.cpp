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
	onStep();
}

void GameObject::createInstance(GameObject* o)
{
	toCreate->push_back(o);
}

void GameObject::destroyInstance(GameObject* o)
{
	toDestroy->push_back(o);
}

void GameObject::onStep()
{

}
void GameObject::onDraw(CanvasStore*)
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
void GameObject::onMidiEvent(MidiPlayerEvent)
{

}
Environment* GameObject::getEnvironment()
{
	return environment;
}
std::vector<GameObject*>* GameObject::getStore()
{
	return store;
}

void GameObject::addTag(std::string tag)
{
	if (tags.find(tag) != tags.end())
		return;
	tags.insert(tag);
}

bool GameObject::checkTag(std::string tag)
{
	return (tags.find(tag) != tags.end());
}

void GameObject::with(std::string tag, std::function<void(GameObject*)> f)
{
	for (auto i : *store)
		if (i->checkTag(tag))
			f(i);
}

void GameObject::with(std::function<bool(GameObject*)> condition, std::function<void(GameObject*)> f)
{
	for (auto i : *store)
		if (condition(i))
			f(i);
}

GameObject* GameObject::find(std::string tag)
{
	for (auto i : *store)
		if (i->checkTag(tag))
			return i;
}
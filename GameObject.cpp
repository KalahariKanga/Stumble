#include "stdafx.h"
#include "GameObject.h"

std::vector<GameObject*>* GameObject::store;
std::vector<GameObject*>* GameObject::tempstore;
Environment* GameObject::environment;

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::update()
{
	previousPosition = position;
	position += velocity;
	mask->x = position.x;
	mask->y = position.y;
	step();
}

void GameObject::createInstance(GameObject* o)
{
	tempstore->push_back(o);
}
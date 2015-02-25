#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::update()
{
	position += velocity;
	mask->x = position.x;
	mask->y = position.y;
	step();
}
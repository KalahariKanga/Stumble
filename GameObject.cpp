#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

//template<class type> bool GameObject::isType()
//{
//	if (dynamic_cast<type>(this))
//		return 1;
//	return 0;
//}

void GameObject::update()
{
	position += velocity;
	mask->translate(velocity.x, velocity.y);
	step();
}
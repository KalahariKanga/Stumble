#include "stdafx.h"
#include "Game.h"



Game::Game()
{
	window.create(sf::VideoMode(640, 480), "Window");
	canvas = new Canvas(640, 480);
	GameObject::store = &store;
	GameObject::tempstore = &tempstore;
}


Game::~Game()
{
}

void Game::addGameObject(GameObject* g)
{
	store.push_back(g);
	
}

void Game::update()
{
	time.Zero;
	//clear canvas
	canvas->setDrawColour(sf::Color::Black);
	canvas->clear();
	
	//handle events
	sf::Event event;
	while (window.pollEvent(event))
	{
		for (auto c : store)
			c->onEvent(&event);
	}

	//update/step
	for (auto c : store)
		c->update();

	//handle collisions
	for (int i = 0; i < store.size(); i++)
		for (int j = i+1; j < store.size(); j++)
		{
			if (store[i]->hasMask && store[j]->hasMask)
			{
				if (store[i]->mask->checkCollision(store[j]->mask))
				{
					store[i]->onCollision(store[j]);
					store[j]->onCollision(store[i]);
				}
			}
		}
	
	//draw objects
	for (auto c : store)
		c->draw(canvas);

	//merge objects
	store.insert(store.end(), tempstore.begin(), tempstore.end());
	tempstore.clear();

	//update screen
	tex.loadFromImage(*(canvas->getImage()));
	sprite.setTexture(tex);
	window.draw(sprite);
	window.display();
	std::this_thread::sleep_for(std::chrono::milliseconds((int)(1000*((float)(1/fps)-time.asSeconds()))));//no
}
#include "stdafx.h"
#include "Game.h"



Game::Game()
{
	window.create(sf::VideoMode(640, 480), "Window");
	canvas = new Canvas(640, 480);
}


Game::~Game()
{
}

void Game::addGameObject(GameObject* g)
{
	store.push_back(g);
	g->store = &store;
}

void Game::update()
{
	time.Zero;
	canvas->setDrawColour(sf::Color::Black);
	canvas->clear();
	
	for (auto c : store)
		c->update();
	for (auto c : store)
		c->draw(canvas);

	tex.loadFromImage(*(canvas->getImage()));
	sprite.setTexture(tex);
	window.draw(sprite);
	window.display();
	std::this_thread::sleep_for(std::chrono::milliseconds((int)(1000*((float)(1/fps)-time.asSeconds()))));//no
}
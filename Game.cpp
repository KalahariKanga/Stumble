#include "stdafx.h"
#include "Game.h"



Game::Game()
{
	window.create(sf::VideoMode(640, 480), "Window");
	image.create(640, 480);
	tex.loadFromImage(image);
	sprite.setTexture(tex);
	
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
	for (int cx = 0; cx < 640; cx++)
		for (int cy = 0; cy < 480; cy++)
			image.setPixel(cx, cy, sf::Color(0, 0, 0));
	
	for (auto c : store)
		c->update();
	for (auto c : store)
		c->draw(&image);

	tex.loadFromImage(image);
	sprite.setTexture(tex);
	window.draw(sprite);
	window.display();
}
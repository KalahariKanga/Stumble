#pragma once
#include "GameObject.h"
#include "Canvas.h"
class Game
{
	std::vector<GameObject*> store;
	sf::RenderWindow window;
	sf::Texture tex;
	sf::Sprite sprite;
	Canvas* canvas;

public:
	Game();
	~Game();
	void addGameObject(GameObject*);
	void update();
};


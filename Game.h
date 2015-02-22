#pragma once
#include "GameObject.h"
#include "Canvas.h"
#include "Scene.h"
class Game
{
	std::vector<GameObject*> store;
	sf::RenderWindow window;
	sf::Texture tex;
	sf::Sprite sprite;
	Canvas* canvas;
	const int fps = 60;
	sf::Time time;
public:
	Game();
	~Game();
	void addGameObject(GameObject*);
	void update();
};


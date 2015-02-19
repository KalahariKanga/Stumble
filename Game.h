#pragma once
#include "GameObject.h"
class Game
{
	std::vector<GameObject*> store;
	sf::RenderWindow window;
	sf::Texture tex;
	sf::Sprite sprite;
	sf::Image image;
public:
	Game();
	~Game();
	void addGameObject(GameObject*);
	void update();
};


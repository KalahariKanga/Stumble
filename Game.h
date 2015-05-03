#pragma once
#include "GameObject.h"
#include "CanvasStore.h"
//#include "Canvas.h"
#include "Scene.h"
#include "Environment.h"
#include "bass.h"
#include <thread>
#include <chrono>

class DLL Game
{
	
	std::vector<GameObject*> store;
	std::vector<GameObject*> toCreate;
	std::vector<GameObject*> toDestroy;
	Environment environment;
	HSTREAM stream;
	sf::RenderWindow window;
	sf::Texture tex;
	sf::Sprite sprite;
	sf::Image image;
	Canvas* screen;
	
	const int fps = 60;
	sf::Time time;
	void audioThreadFunction();
	std::thread* audioThread;
	std::chrono::time_point<std::chrono::system_clock> start, end;
	bool keyDown[100];
	void processMidiEvents();
public:
	Game();
	~Game();
	void addGameObject(GameObject*);
	void update();
	
	CanvasStore canvasStore;//not sure it needs to be public
};


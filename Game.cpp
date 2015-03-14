#include "stdafx.h"
#include "Game.h"



Game::Game()
{
	window.create(sf::VideoMode(640, 480), "Window");
	window.setKeyRepeatEnabled(0);
	canvas = new Canvas(640, 480);
	GameObject::store = &store;
	GameObject::tempstore = &tempstore;
	GameObject::environment = &environment;

	BASS_Init(-1, SAMPLE_RATE, 0, 0, NULL);
	BASS_SetConfig(BASS_CONFIG_BUFFER, 128);
	BASS_SetConfig(BASS_CONFIG_UPDATEPERIOD, 10);
	stream = BASS_StreamCreate(SAMPLE_RATE, 1, 0, STREAMPROC_PUSH, NULL);
	BASS_ChannelPlay(stream, 0);
	audioThread = new std::thread(&Game::audioThreadFunction,this);

	for (int c = 0; c < 100; c++)
		keyDown[100] = 0;
}


Game::~Game()
{
	audioThread->join();
	BASS_StreamFree(stream);
	BASS_Stop();
	BASS_Free();
}

void Game::addGameObject(GameObject* g)
{
	store.push_back(g);
	
}

void Game::update()
{
	start = std::chrono::system_clock::now();

	//clear canvas
	canvas->setDrawColour(sf::Color::Black);
	canvas->clear();
	
	//handle events
	sf::Event event;
	while (window.pollEvent(event))
	{
		for (auto c : store)
			c->onEvent(&event);
		if (event.type == sf::Event::KeyPressed)
		{
			keyDown[(int)event.key.code] = 1;
			for (auto c : store)
				c->onKeyDown(event.key.code);
		}
		if (event.type == sf::Event::KeyReleased)
		{
			keyDown[(int)event.key.code] = 0;
			for (auto c : store)
				c->onKeyUp(event.key.code);
		}
	}
	for (int c = 0; c < 100; c++)
		if (keyDown[c])
			for (auto d : store)
				d->onKey((sf::Keyboard::Key)c);

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

	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	int ms = (int)(1000 * ((float)(1 / fps) - elapsed_seconds.count()));
	//std::cout << ms << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void Game::audioThreadFunction()
{
	while (window.isOpen())
	{
		environment.update();
		while (BASS_StreamPutData(stream, NULL, 0) > 10){};
		BASS_StreamPutData(stream, (void*)environment.getBuffer(), BUFFER_LENGTH*sizeof(short));
		
	}
}
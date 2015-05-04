#include "stdafx.h"
#include "Game.h"



Game::Game()
{
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Window");
	window.setKeyRepeatEnabled(0);
	tex.setSmooth(0);
	screen = canvasStore.addCanvas("screen", WINDOW_WIDTH, WINDOW_HEIGHT);
	canvasStore.screen = screen;
	GameObject::store = &store;
	GameObject::toCreate = &toCreate;
	GameObject::toDestroy = &toDestroy;
	GameObject::environment = &environment;

	BASS_Init(-1, SAMPLE_RATE, 0, 0, NULL);
	BASS_SetConfig(BASS_CONFIG_BUFFER, 128);
	BASS_SetConfig(BASS_CONFIG_UPDATEPERIOD, 10);
	stream = BASS_StreamCreate(SAMPLE_RATE, 1, 0, STREAMPROC_PUSH, NULL);
	BASS_ChannelPlay(stream, 0);

#ifndef _DEBUG
	audioThread = new std::thread(&Game::audioThreadFunction,this);
#endif

	for (int c = 0; c < 100; c++)
		keyDown[c] = 0;


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
	canvasStore.clearScreen();
	
	
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

	processMidiEvents();

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

	//sort by depth (could be a flag for needsDepthUpdate)
	std::sort(store.begin(), store.end(), [](GameObject* a, GameObject* b)
	{
		return a->depth > b->depth;
	});
	
	//draw objects
	for (auto c : store)
		c->onDraw(&canvasStore);

	//update object vector
	store.insert(store.end(), toCreate.begin(), toCreate.end());
	toCreate.clear();
	for (auto c : toDestroy)
	{
		auto it = std::find(store.begin(), store.end(), c);
		if (it != store.end())
			store.erase(it);
	}
	

	//update screen
	image.create(WINDOW_WIDTH, WINDOW_HEIGHT, screen->data);
	tex.loadFromImage(image);
	sprite.setTexture(tex);
	window.draw(sprite);
	window.display();

	//timing
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	int ms = 1000 * (((1 / (float)fps)) - elapsed_seconds.count());
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void Game::audioThreadFunction()
{
	while (window.isOpen())
	{
		environment.update();
		while (BASS_StreamPutData(stream, NULL, 0) > 10)
			std::this_thread::sleep_for(std::chrono::milliseconds(5));
		
		BASS_StreamPutData(stream, (void*)environment.getBuffer(), BUFFER_LENGTH*sizeof(short));
		
	}
}

void Game::processMidiEvents()
{
	for (auto c : store)
		for (auto e : environment.events)
			c->onMidiEvent(e);
	environment.events.clear();
}
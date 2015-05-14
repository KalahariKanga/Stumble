#pragma once
#include <set>
#include "core.h"
#include "Vector2.h"
#include "CanvasStore.h"
#include "MaskRectangle.h"
#include "MaskCircle.h"
#include "Environment.h"
class DLL GameObject
{
	std::set<std::string> tags;
public:
	GameObject();
	virtual ~GameObject();

	Vector2 position, velocity, previousPosition;
	static std::vector<GameObject*>* store;
	static std::vector<GameObject*>* toCreate;
	static std::vector<GameObject*>* toDestroy;
	static Environment* environment;
	Mask* mask = 0;
	bool hasMask = 0;
	int t = 0;
	int depth = 0;
	
	void update();

	virtual void onStep();
	virtual void onDraw(CanvasStore*);
	virtual void onCollision(GameObject*);
	virtual void onEvent(sf::Event*);
	virtual void onKeyDown(sf::Keyboard::Key);
	virtual void onKeyUp(sf::Keyboard::Key);
	virtual void onKey(sf::Keyboard::Key);
	virtual void onMidiEvent(MidiPlayerEvent e);
	void createInstance(GameObject*);
	void destroyInstance(GameObject*);

	Environment* getEnvironment();
	std::vector<GameObject*>* getStore();

	void addTag(std::string tag);
	bool checkTag(std::string tag);
	void with(std::string tag, std::function<void(GameObject*)>);
	void with(std::function<bool(GameObject*)>, std::function<void(GameObject*)>);
	GameObject* find(std::string tag);
};


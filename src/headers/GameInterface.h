#pragma once
#ifndef __GAME_INTERFACE_H__
#define __GAME_INTERFACE_H__

#include <Model.h>
#include <glm\glm\glm.hpp>
#include <glm\glm\gtc\matrix_transform.hpp>
#include <glm\glm\gtc\type_ptr.hpp>
#include <cmath>

class GameController;

class Entity : public Model {
protected:
	GameController* gameController;

	/*Variables*/
	int power;
	int life;
public:
	Entity();
	Entity(GameController* gameController);
	~Entity();
	void Send(string message, void* data);
	void SetRenderController(GameController* renderController);
	virtual void Notify(string message, void* data) = 0;
};

class GameController {
public:
	virtual void Send(string message, void* data, Entity* renderColleague) = 0;
};

#endif
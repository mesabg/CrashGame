#pragma once
#ifndef __CONCRETE_GAME_CONTROLLER_H_
#define __CONCRETE_GAME_CONTROLLER_H_

#include <GameInterface.h>
#include <Enemy.h>
#include <Player.h>
#include <Object.h>

class ConcreteGameController : public GameController
{
private:
	/*All Instances of Colleagues*/
	Enemy** enemies;
	Player** players;
	Object* objects;

public:
	ConcreteGameController();
	ConcreteGameController(const float width, const float height);
	~ConcreteGameController();
	void Send(string message, void* data, Entity* entity);
	void initGLSLPrograms();

	/*Play and Pause*/
	int finish();
	int infinity();
};

#endif
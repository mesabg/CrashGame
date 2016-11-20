#pragma once
#ifndef __CONCRETE_GAME_CONTROLLER_H_
#define __CONCRETE_GAME_CONTROLLER_H_

#include <Enemy.h>
#include <Player.h>
#include <Object.h>

extern int amountOfEnemies, amountOfPlayers, amountOfObjects;

class ConcreteGameController : public GameController{
private:
	/*All Instances of Colleagues*/
	vector<Enemy*> enemies;
	vector<Player*> players;
	vector<Object*> objects;
public:
	ConcreteGameController();
	~ConcreteGameController();
	void Send(string message, void* data, Entity* entity);
};

#endif
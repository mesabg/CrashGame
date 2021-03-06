#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <GameInterface.h>

extern int amountOfPlayers;

class Player : public Entity {
private:
	/*Multiple Singleton*/
	static vector<Player*> uniquePlayers;

	/*Variables*/
	GameController* gameController;

	/*Functions*/
	Player(GameController *gameController, ModelRoutesData* routes, vector<int> *contextData);
	~Player();
public:
	/*Get Instance*/
	static Player* Instance(GameController* gameController, ModelRoutesData* routes, vector<int> *contextData, const int index);
	static void Destroy();

	/*Get message*/
	void Notify(string message, void* data);
};

#endif
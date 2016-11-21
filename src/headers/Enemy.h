#pragma once
#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <GameInterface.h>

extern int amountOfEnemies;

class Enemy : public Entity{
private:
	/*Multiple Singleton*/
	static vector<Enemy*> uniqueEnemies;

	/*Variables*/

	/*Functions*/
	Enemy(GameController *gameController, ModelRoutesData* route, vector<int> *contextData);
	~Enemy();
public:
	/*Get Instance*/
	static Enemy* Instance(GameController* gameController, ModelRoutesData* routes, vector<int> *contextData, const int index);
	static void Destroy();

	/*Get message*/
	void Notify(string message, void* data);
};


#endif
#pragma once
#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <GameInterface.h>

extern int amountOfEnemies;

class Enemy : public Entity{
private:
	/*Multiple Singleton*/
	static Enemy** uniqueEnemies;

	/*Variables*/

	/*Functions*/
	Enemy();
	~Enemy();
public:
	/*Get Instance*/
	static Enemy* Instance(GameController* gameController, const int index);
	static void Destroy();

	/*Get message*/
	void Notify(string message, void* data);
};


#endif
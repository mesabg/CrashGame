#pragma once
#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <GameInterface.h>

extern int amountOfObjects;

class Object : public Entity {
private:
	/*Multiple Singleton*/
	static vector<Object*> uniqueObjects;

	/*Variables*/

	/*Functions*/
	Object(GameController *gameController, ModelRoutesData* routes, vector<int> *contextData);
	~Object();
public:
	/*Get Instance*/
	static Object* Instance(GameController* gameController, ModelRoutesData* routes, vector<int> *contextData, const int index);
	static void Destroy();

	/*Get message*/
	void Notify(string message, void* data);
};


#endif

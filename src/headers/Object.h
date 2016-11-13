#pragma once
#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <GameInterface.h>

extern int amountOfObjects;

class Object : public Entity {
private:
	/*Multiple Singleton*/
	static Object** uniqueObjects;

	/*Variables*/

	/*Functions*/
	Object();
	~Object();
public:
	/*Get Instance*/
	static Object* Instance(GameController* gameController, const int index);
	static void Destroy();

	/*Get message*/
	void Notify(string message, void* data);
};


#endif

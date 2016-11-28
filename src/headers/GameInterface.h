#pragma once
#ifndef __GAME_INTERFACE_H__
#define __GAME_INTERFACE_H__

#include <CreatorOBJ.h>
#include <CreatorOFF.h>
#include <CreatorMD2.h>
#include <CreatorMD5.h>
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
	int lives;

	/*Model Creator*/
	ModelsCreator* localModelsCreator;
public:
	Entity(GameController* gameController, ModelRoutesData* routes, vector<int> *contextData);
	~Entity();
	void Send(string message, void* data);
	void SetRenderController(GameController* gameController);
	virtual void Notify(string message, void* data) = 0;
	/*Create Model*/
	Model* CreateModel(ModelRoutesData* routes);
};

class GameController {
public:
	virtual void Send(string message, void* data, Entity* renderColleague) = 0;
};

#endif
#pragma once
#ifndef __STAGE_H__
#define __STAGE_H__

#include <RenderInterface.h>
#include <Sound.h>
#include <SkyBox.h>
#include <Light.h>
#include <Camera.h>
#include <Projection.h>
#include <Player.h>
#include <Enemy.h>
#include <Object.h>

extern int amountOfEnemies, amountOfPlayers, amountOfObjects;

class Stage : public RenderColleague
{
private:
	/*Singleton*/
	static Stage* uniqueStage;

	/*Local Variables*/
	Sound* sound;
	SkyBox* skyBox;
	Light* light;
	Camera* camera;
	Projection* projection;
	vector<Entity*> entities;

	/*Shader ID*/
	GLuint shader_id;

	/*Uniforms IDs*/
	vector<GLint> *ID;

	/*Functions*/
	Stage(RenderController* renderController);
	~Stage();

public:
	
	/*Get Instance*/
	static Stage* Instance(RenderController* renderController);
	static void Destroy();

	/*Get message*/
	void Notify(string message, void* data);

	/*Functions*/
	void render();
};

#endif
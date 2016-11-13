#pragma once
#ifndef __STAGE_H__
#define __STAGE_H__

#include <RenderInterface.h>
#include <Sound.h>
#include <SkyBox.h>
#include <Light.h>
#include <Camera.h>
#include <Projection.h>
#include <GameInterface.h>

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
	Entity** entitys;

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
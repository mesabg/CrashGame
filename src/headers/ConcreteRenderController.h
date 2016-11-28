#pragma once
#ifndef __CONCRETE_RENDER_CONTROLLER_H_
#define __CONCRETE_RENDER_CONTROLLER_H_

#include <RenderInterface.h>
#include <Stage.h>
#include <GUI.h>
#include <CGLSLProgram.h>
#include <vector>
#include <time.h>

using std::vector;

class ConcreteRenderController : public RenderController
{
private:
	/*All Instances of Colleagues*/
	Stage* stage;
	GUI* gui;
	CGLSLProgram* illuminationProgram;

	/*Funcitons*/
	void render();

public:
	ConcreteRenderController();
	ConcreteRenderController(const float width, const float height);
	~ConcreteRenderController();
	void Send(string message, void* data, RenderColleague* colleague);
	void initGLSLPrograms();
	
	/*Play and Pause*/
	int finish();
	int infinity();
};

#endif
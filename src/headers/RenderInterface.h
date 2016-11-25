#pragma once
#ifndef __RENDER_INTERFACE_H__
#define __RENDER_INTERFACE_H__
#include <glew\glew.h>
#include <glfw3.h>
#include <glm\glm\glm.hpp>
#include <glm\glm\gtc\matrix_transform.hpp>
#include <glm\glm\gtc\type_ptr.hpp>
#include <cmath>
#include <string>
#include <vector>

using std::string;
using std::vector;

class RenderController;

class RenderColleague
{
protected:
	RenderController* renderController;
public:
	RenderColleague(RenderController* renderController);
	RenderColleague();
	~RenderColleague();
	void SetRenderController(RenderController* renderController);
	void Send(string message, void* data);
	virtual void Notify(string message, void* data) = 0;
};

class RenderController {
public:
	virtual void Send(string message, void* data, RenderColleague* renderColleague) = 0;
};

#endif
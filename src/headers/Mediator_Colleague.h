#pragma once
#ifndef __COLLEAGUE_H_
#define __COLLEAGUE_H_
#include <GLSLprogram.h>
#include <glm\glm\glm.hpp>
#include <glm\glm\gtc\matrix_transform.hpp>
#include <glm\glm\gtc\type_ptr.hpp>
#include <cmath>
#include <string>
#include <vector>
#include <RGB_.h>
#include <Vertex.h>
#include <BoundingBox.h>
using std::string;
using std::vector;

class Mediator;

class Colleague
{
protected:
	Mediator* mediator;
public:
	Colleague(Mediator* mediator);
	~Colleague();
	void Send(string message);
	void SetMediator(Mediator* mediator);
	virtual void Notify(string message) = 0;
};

class Mediator {
public:
	virtual void Send(std::string message, Colleague* colleague) = 0;
	virtual void SelectModel(int message, Colleague* colleague) = 0;
	virtual void AddAndSend(Colleague* setter, std::string message, Colleague* colleague) = 0;
	virtual void initGLSLPrograms() = 0;
	virtual int getSelectedIndex() = 0;
};

#endif
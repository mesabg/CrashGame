#pragma once
#ifndef __CONCRETE_MEDIATOR_H_
#define __CONCRETE_MEDIATOR_H_

#include <Mediator_Colleague.h>
#include <SideBar.h>
#include <UserInterface.h>
#include <FileLoader.h>
#include <Model.h>
#include <vector>

using std::vector;

class ConcreteMediator : public Mediator
{
private:
	SideBar* sideBar;
	UserInterface* userInterface;
	FileLoader* fileLoader;
	/*Array of models*/
	vector<Model*> models;
	/*Shaders Programs*/
	CGLSLProgram *glslProgramFlat;
	CGLSLProgram *glslProgramGouraud;
	CGLSLProgram *glslProgramPhong;
	CGLSLProgram *glslProgram;
	int selected;
	bool glDepth;
public:
	ConcreteMediator();
	~ConcreteMediator();
	void Send(std::string message, Colleague* colleague);
	void SelectModel(int message, Colleague* colleague);
	void AddAndSend(Colleague* setter, std::string message, Colleague* colleague);
	void SetSideBarColleague(SideBar* colleague);
	void SetUserInterfaceColleague(UserInterface* colleague);
	void SetFileLoaderColleague(FileLoader* colleague);
	void SetModelsColleague(Model* colleague, const int index);
	void AddModelColleague(Model* colleague);
	void LoadDefaultModels(vector<string> Models);
	int getSelectedIndex();
	void initGLSLPrograms();
};

#endif
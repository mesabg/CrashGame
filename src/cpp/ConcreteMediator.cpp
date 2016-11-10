#include <ConcreteMediator.h>
#include <iostream>

ConcreteMediator::ConcreteMediator() {
	this->selected = -1;
	this->glDepth = false;
	/*Main Program*/
	this->glslProgram = NULL;
}

ConcreteMediator::~ConcreteMediator() {}

void ConcreteMediator::Send(std::string message, Colleague* colleague) {
	if (message == "Load File" && colleague == this->sideBar)
		this->fileLoader->Notify(message);
	else if (message == "Render Models" && colleague == this->userInterface) {
		/*Iterate over each model*/
		this->models[0]->setCenterBB();
		this->models[0]->setDisplayBoundingBox(false);
		for (int i = 0; i < (int)this->models.size(); i++)
			if (this->glslProgram == this->glslProgramGouraud || this->glslProgram == this->glslProgramPhong)
				this->models[i]->display(this->glDepth, this->glslProgram, this->models[0]->getGLNormalsByVertex(), this->models[0]->getCenter2(), true);
			else
				this->models[i]->display(this->glDepth, this->glslProgram, this->models[0]->getGLNormals(), this->models[0]->getCenter2(), false);
	}
	else if ((message == "Perspective" || message == "OrtogonalX" || message == "OrtogonalY" || message == "OrtogonalZ") && colleague == this->sideBar)
		this->userInterface->Notify(message);
	else if (message == "Volver al principal" && colleague == this->userInterface) {
		this->sideBar->Notify("Desseleccionar");
		this->selected = -1;
	}
	else if (message == "ActiveGLDepth")
		this->glDepth = !this->glDepth;
	else if (message == "ActiveGLDepth_")
		this->glDepth = true;
	else if (message == "Activate Flat Shading" && colleague == this->sideBar)
		this->glslProgram = this->glslProgramFlat;
	else if (message == "Deactivate Flat Shading" && colleague == this->sideBar)
		this->glslProgram = NULL;
	else if (message == "Activate Gouraud Shading" && colleague == this->sideBar)
		this->glslProgram = this->glslProgramGouraud;
	else if (message == "Deactivate Gouraud Shading" && colleague == this->sideBar)
		this->glslProgram = NULL;
	else if (message == "Activate Phong Shading" && colleague == this->sideBar)
		this->glslProgram = this->glslProgramPhong;
	else if (message == "Deactivate Phong Shading" && colleague == this->sideBar)
		this->glslProgram = NULL;
	else if (message == "Reshaping" && colleague == this->userInterface)
		for (int i = 0; i < (int)this->models.size(); i++)
			this->models[i]->setProjMatrix(this->userInterface->getProjectMatrix(), this->userInterface->getModelViewMatrix());
	else if (message == "Set GL Color" && colleague == this->sideBar)
		this->userInterface->setGLColor(this->sideBar->getFillColor());
}

void ConcreteMediator::SelectModel(int message, Colleague* colleague) {
	if (colleague == this->sideBar) {
		this->selected = message;
		this->sideBar->setSelectedModel(this->models[this->selected]);
	}
}

void ConcreteMediator::AddAndSend(Colleague* setter, std::string message,Colleague * colleague){
	if (colleague == this->fileLoader) {
		this->models.push_back((Model*)setter);
		this->models.back()->loadModel(message);
		this->models.back()->escalar();
		this->models.back()->escalarBoundingBox();
		this->models.back()->normalCalculate();
		this->models.back()->initGLStructure();
		this->sideBar->addModel();
	}
}

void ConcreteMediator::SetSideBarColleague(SideBar * colleague){
	this->sideBar = colleague;
}

void ConcreteMediator::SetUserInterfaceColleague(UserInterface * colleague){
	this->userInterface = colleague;
}

void ConcreteMediator::SetFileLoaderColleague(FileLoader * colleague){
	this->fileLoader = colleague;
}

void ConcreteMediator::SetModelsColleague(Model* colleague, const int index){
	this->models[index] = colleague;
}

void ConcreteMediator::AddModelColleague(Model* colleague){
	this->models.push_back(colleague);
}

void ConcreteMediator::LoadDefaultModels( vector<string> Models ){
	for (int i = 0; i < (int)Models.size(); i++){
		OBJ *localOBJ = new OBJ(this);
		localOBJ->loadModel(Models[i]);
		localOBJ->setScale(0.4f);
		localOBJ->setTranslation(3.9f, 2.9f, 7.0f);
		localOBJ->setColorBorderColor(1.0f, 1.0f, 0.15f);
		localOBJ->setColorFillColor(1.0f, 1.0f, 0.15f);
		localOBJ->displayMode(2);
		this->models.push_back(localOBJ);
		this->models.back()->escalar();
		this->models.back()->escalarBoundingBox();
		this->models.back()->normalCalculate();
		this->models.back()->initGLStructure();
		this->models.back()->setShadingMode(true);
		this->sideBar->addModel();
	}
}

int ConcreteMediator::getSelectedIndex(){
	return this->selected;
}

void ConcreteMediator::initGLSLPrograms(){
	/*Initialize Shaders*/
	/*Flat Shader*/

	this->glslProgramFlat = new CGLSLProgram();
	this->glslProgramFlat->loadShader("../src/shaders/Flat.vert", CGLSLProgram::VERTEX);
	this->glslProgramFlat->loadShader("../src/shaders/Flat.frag", CGLSLProgram::FRAGMENT);
	this->glslProgramFlat->create_link();

	this->glslProgramGouraud = new CGLSLProgram();
	this->glslProgramGouraud->loadShader("../src/shaders/Gouraud.vert", CGLSLProgram::VERTEX);
	this->glslProgramGouraud->loadShader("../src/shaders/Gouraud.frag", CGLSLProgram::FRAGMENT);
	this->glslProgramGouraud->create_link();

	this->glslProgramPhong = new CGLSLProgram();
	this->glslProgramPhong->loadShader("../src/shaders/Phong.vert", CGLSLProgram::VERTEX);
	this->glslProgramPhong->loadShader("../src/shaders/Phong.frag", CGLSLProgram::FRAGMENT);
	this->glslProgramPhong->create_link();

}


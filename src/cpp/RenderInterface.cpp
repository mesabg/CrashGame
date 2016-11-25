#include <RenderInterface.h>

RenderColleague::RenderColleague() {
	this->renderController = NULL;
}

RenderColleague::RenderColleague(RenderController* renderController){
	this->renderController = renderController;
}

RenderColleague::~RenderColleague() {}

void RenderColleague::SetRenderController(RenderController* renderController) {
	this->renderController = renderController;
}

void RenderColleague::Send(string message, void * data){
	this->renderController->Send(message, data, this);
}

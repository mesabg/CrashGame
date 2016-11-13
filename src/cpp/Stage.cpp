#include <Stage.h>

Stage::Stage(RenderController* renderController):RenderColleague(renderController){

}

Stage::~Stage(){

}

Stage * Stage::Instance(RenderController * renderController){
	if (!uniqueStage)
		uniqueStage = new Stage(renderController);
	return uniqueStage;
}

void Stage::Destroy(){
	if (!uniqueStage) return;
	uniqueStage->~Stage();
}

void Stage::Notify(string message, void * data){

}

void Stage::render(){

}

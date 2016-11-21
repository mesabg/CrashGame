#include <Stage.h>

Stage* Stage::uniqueStage = NULL;

Stage::Stage(RenderController* renderController):RenderColleague(renderController){
	this->sound = new Sound({"", ""});
	this->skyBox = new SkyBox();
	this->light = new Light();
	this->camera = new Camera();
	this->projection = new Projection();
	for (int i = 0; i < amountOfPlayers; i++) this->entities.push_back(Player::Instance(NULL, NULL, NULL, i));
	for (int i = 0; i < amountOfEnemies; i++) this->entities.push_back(Enemy::Instance(NULL, NULL, NULL, i));
	for (int i = 0; i < amountOfObjects; i++) this->entities.push_back(Object::Instance(NULL, NULL, NULL, i));
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

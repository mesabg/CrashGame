#include <GameInterface.h>

Entity::Entity(GameController * gameController, ModelRoutesData* routes, vector<int> *contextData){
	this->gameController = gameController;
	Model::Inherit(CreateModel(routes));
}

Entity::~Entity(){

}

void Entity::Send(string message, void * data){
	this->gameController->Send(message, data, this);
}

void Entity::SetRenderController(GameController * gameController){
	this->gameController = gameController;
}

Model* Entity::CreateModel(ModelRoutesData* routes){
	printf("Hola\n");
	int length = routes->model.size();
	string type;
	type.push_back(routes->model.at(length - 3));
	type.push_back(routes->model.at(length - 2));
	type.push_back(routes->model.at(length - 1));

	if (type == "obj") return (localModelsCreator = new CreatorOBJ())->create(routes);
	if (type == "off") return (localModelsCreator = new CreatorOFF())->create(routes);
	if (type == "md2") return (localModelsCreator = new CreatorMD2())->create(routes);
	if (type == "md5") return (localModelsCreator = new CreatorMD5())->create(routes);
	return nullptr;
}

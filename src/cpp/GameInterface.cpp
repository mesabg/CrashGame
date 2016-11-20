#include <GameInterface.h>

Entity::Entity(GameController * gameController, string path){
	this->gameController = gameController;
	Model::Inherit(CreateModel(path));
}

Model* Entity::CreateModel(string path){
	int length = path.length();
	string type;
	type.push_back(path[length - 3]);
	type.push_back(path[length - 2]);
	type.push_back(path[length - 1]);

	if (type == "obj") return (localModelsCreator = new CreatorOBJ())->create(path);
	if (type == "off") return (localModelsCreator = new CreatorOFF())->create(path);
	if (type == "md2") return (localModelsCreator = new CreatorMD2())->create(path);
	if (type == "md5") return (localModelsCreator = new CreatorMD5())->create(path);
	return nullptr;
}

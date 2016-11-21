#include <ConcreteGameController.h>

ConcreteGameController::ConcreteGameController(){
	/*Create ModelRoutesData Array to load the models*/
	vector<ModelRoutesData*> playersRoutes(amountOfPlayers, NULL);
	vector<ModelRoutesData*> enemiesRoutes(amountOfEnemies, NULL);
	vector<ModelRoutesData*> objectsRoutes(amountOfObjects, NULL);

	/*Initializing Routes*/
	/*Players Routes*/
	playersRoutes.push_back(new ModelRoutesData(
		"../models/players/Crash/crash.obj",
		"../models/players/Crash/crash.png",
		{
			"../models/players/Crash/crash_step.mp3",
			"../models/players/Crash/crash_punch.mp3",
			"../models/players/Crash/crash_die.mp3"
		}
	));

	/*Enemies Routes*/
	enemiesRoutes.push_back(new ModelRoutesData(
		"../models/enemies/common/CarnivorousPlant/carnivorousPlant.obj",
		"../models/enemies/common/CarnivorousPlant/carnivorousPlant.png",
		{
			"../models/enemies/common/CarnivorousPlant/carnivorousPlant_step.mp3",
			"../models/enemies/common/CarnivorousPlant/carnivorousPlant_punch.mp3",
			"../models/enemies/common/CarnivorousPlant/carnivorousPlant_die.mp3"
		}
	));

	enemiesRoutes.push_back(new ModelRoutesData(
		"../models/enemies/common/LabAssistant/labAssistant.obj",
		"../models/enemies/common/LabAssistant/labAssistant.png",
		{
			"../models/enemies/common/LabAssistant/labAssistant_step.mp3",
			"../models/enemies/common/LabAssistant/labAssistant_punch.mp3",
			"../models/enemies/common/LabAssistant/labAssistant_die.mp3"
		}
	));

	enemiesRoutes.push_back(new ModelRoutesData(
		"../models/enemies/NGin/ngin.obj",
		"../models/enemies/NGin/ngin.png",
		{
			"../models/enemies/NGin/ngin_step.mp3",
			"../models/enemies/NGin/ngin_punch.mp3",
			"../models/enemies/NGin/ngin_die.mp3"
		}
	));

	/*Object Routes*/
	objectsRoutes.push_back(new ModelRoutesData(
		"../models/objects/Apple/apple.obj",
		"../models/objects/Apple/apple.png",
		{
			"../models/objects/Apple/apple.mp3"
		}
	));

	objectsRoutes.push_back(new ModelRoutesData(
		"../models/objects/Checkpoint/checkpoint.obj",
		"../models/objects/Checkpoint/checkpoint.png",
		{
			"../models/objects/Checkpoint/checkpoint.mp3"
		}
	));

	objectsRoutes.push_back(new ModelRoutesData(
		"../models/objects/Nitro/nitro.obj",
		"../models/objects/Nitro/nitro.png",
		{
			"../models/objects/Nitro/nitro.mp3"
		}
	));

	for (int i = 0; i < amountOfPlayers; i++) this->players.push_back(Player::Instance(this, playersRoutes[i], new vector<int>({ 100, 5 }), i));
	for (int i = 0; i < amountOfEnemies; i++) this->enemies.push_back(Enemy::Instance(this, enemiesRoutes[i], new vector<int>({ 100, 5 }), i));
	for (int i = 0; i < amountOfObjects; i++) this->objects.push_back(Object::Instance(this, objectsRoutes[i], new vector<int>({ 100, 5 }), i));
}

ConcreteGameController::~ConcreteGameController(){

}

void ConcreteGameController::Send(string message, void * data, Entity * entity){

}


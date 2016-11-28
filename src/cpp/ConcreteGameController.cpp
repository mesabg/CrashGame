#include <ConcreteGameController.h>

ConcreteGameController::ConcreteGameController(){
	/*Create ModelRoutesData Array to load the models*/
	vector<ModelRoutesData*> playersRoutes(amountOfPlayers, NULL);
	vector<ModelRoutesData*> enemiesRoutes(amountOfEnemies, NULL);
	vector<ModelRoutesData*> objectsRoutes(amountOfObjects, NULL);

	/*Initializing Routes*/
	/*Players Routes*/
	playersRoutes[0] = (new ModelRoutesData(
		"../models/players/Spaceship/spaceship.obj",
		"../models/players/Spaceship/spaceship.png",
		{
			"../models/Spaceship/Crash/spaceship_run.mp3",
			"../models/Spaceship/Crash/spaceship_shoot.mp3",
			"../models/Spaceship/Crash/spaceship_die.mp3"
		}
	));

	/*Enemies Routes*/
	enemiesRoutes[0] = new ModelRoutesData(
		"../models/enemies/common/Asteroid/Asteroid.obj",
		"../models/enemies/common/Asteroid/Asteroid.png",
		{
			"../models/enemies/common/Asteroid/asteroid_step.mp3",
			"../models/enemies/common/Asteroid/asteroid_punch.mp3",
			"../models/enemies/common/Asteroid/asteroid_die.mp3"
		}
	);


	/*Object Routes*/
	objectsRoutes[0] = new ModelRoutesData(
		"../models/objects/Bullet/bullet.obj",
		"../models/objects/Bullet/bullet.png",
		{
			"../models/objects/Bullet/bullet.mp3"
		}
	);

	/*Power/Lives*/
	for (int i = 0; i < amountOfPlayers; i++) this->players.push_back(Player::Instance(this, playersRoutes[i], new vector<int>({ 100, 5 }), i));
	for (int i = 0; i < amountOfEnemies; i++) this->enemies.push_back(Enemy::Instance(this, enemiesRoutes[i], new vector<int>({ 20, 1 }), i));
	for (int i = 0; i < amountOfObjects; i++) this->objects.push_back(Object::Instance(this, objectsRoutes[i], new vector<int>({ 0, 0 }), i));
}

ConcreteGameController::~ConcreteGameController(){
/**/
}

void ConcreteGameController::Send(string message, void * data, Entity * entity){
	if (message == "Arriba" || message == "Abajo" || message == "Izquierda" || message == "Derecha" || entity==this->players[0]){
		this->players[0]->setEstado(message);
	}
}


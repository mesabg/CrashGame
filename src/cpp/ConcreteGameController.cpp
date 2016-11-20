#include <ConcreteGameController.h>

ConcreteGameController::ConcreteGameController(){
	/*Hacer un vector de rutas e inicializar las entidades*/
	for (int i = 0; i < amountOfPlayers; i++) this->players.push_back(Player::Instance(this, "ruta", i));
	for (int i = 0; i < amountOfEnemies; i++) this->enemies.push_back(Enemy::Instance(this, i));
	for (int i = 0; i < amountOfObjects; i++) this->objects.push_back(Object::Instance(this, i));
}

ConcreteGameController::~ConcreteGameController(){
}

void ConcreteGameController::Send(string message, void * data, Entity * entity){

}


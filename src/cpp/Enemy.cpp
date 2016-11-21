#include <Enemy.h>

vector<Enemy*> Enemy::uniqueEnemies(amountOfEnemies, NULL);

Enemy::Enemy(GameController * gameController, ModelRoutesData* routes, vector<int> *contextData):Entity(gameController, routes, contextData) {

}

Enemy::~Enemy(){

}

Enemy * Enemy::Instance(GameController * gameController, ModelRoutesData * routes, vector<int> *contextData, const int index){
	if ( (int)uniqueEnemies.size() < (index + 1) || uniqueEnemies[index] == NULL)
		uniqueEnemies.push_back(new Enemy(gameController, routes, contextData));
	return uniqueEnemies[index];
}

void Enemy::Destroy(){
	/*Kill All the instances*/
	for (int i = 0; i < (int)uniqueEnemies.size(); i++) {
		uniqueEnemies[i]->~Enemy();
		uniqueEnemies[i] = NULL;
		delete uniqueEnemies[i];
	}
	uniqueEnemies.clear();
	uniqueEnemies.~vector();
}

void Enemy::Notify(string message, void * data){

}

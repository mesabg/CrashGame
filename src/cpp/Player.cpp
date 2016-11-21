#include <Player.h>

vector<Player*> Player::uniquePlayers(amountOfPlayers, NULL);

Player::Player(GameController * gameController, ModelRoutesData* routes, vector<int> *contextData):Entity(gameController, routes, contextData){

}

Player::~Player(){

}


Player * Player::Instance(GameController  *gameController, ModelRoutesData* routes, vector<int> *contextData, const int index){
	if ( (int)uniquePlayers.size() < (index+1) || uniquePlayers[index]==NULL )
		uniquePlayers.push_back( new Player(gameController, routes, contextData) );
	return uniquePlayers[index];
}

void Player::Destroy(){
	/*Kill All the instances*/
	for (int i = 0; i < (int)uniquePlayers.size(); i++) {
		uniquePlayers[i]->~Player();
		uniquePlayers[i] = NULL;
		delete uniquePlayers[i];
	}
	uniquePlayers.clear();
	uniquePlayers.~vector();
}

void Player::Notify(string message, void * data){

}

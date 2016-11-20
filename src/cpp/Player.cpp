#include <Player.h>

Player::Player(GameController * gameController, string path):Entity(gameController, path){

}


Player * Player::Instance(GameController * gameController, string path, const int index){
	if ( uniquePlayers.size() < (index+1) || uniquePlayers[index]==NULL )
		uniquePlayers.push_back( new Player(gameController, path) );
	return nullptr;
}

void Player::Notify(string message, void * data){

}

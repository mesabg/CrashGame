#include <Sound.h>

Sound::Sound(vector<string> routes){
	this->routes = routes;
}

Sound::~Sound(){
	for (int i = 0; i < (int)routes.size(); i++)
		this->routes[i].~basic_string();
	this->routes.clear();
	this->routes.~vector();
}

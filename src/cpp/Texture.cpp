#include <Texture.h>

Texture::Texture(string route){
	this->route = route;
}

Texture::~Texture(){
	this->route.~basic_string();
}

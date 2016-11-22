#pragma once
#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <string>
#include <glew\glew.h>
#include <stb-master\stb.h>
/*#include <sdl2\SDL.h>
#include <sdl2\SDL_image.h>*/

using std::string;

class Texture {
private:
	string route;
public:
	Texture(string route);
	~Texture();
};

#endif
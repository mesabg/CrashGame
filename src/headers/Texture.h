#pragma once
#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <string>
#include <glew\glew.h>
//#include <stb-master\stb.h>

/*#include <stb-master\stb.h>
#include <stb-master\stb_c_lexer.h>
#include <sdl2\SDL.h>
#include <sdl2\SDL_image.h>
#include <sdl2\SDL_main.h>*/
#include <soil\SOIL.h>
#include <iostream>

using namespace std;

using std::string;
class Texture {
private:
	string route;
	GLuint m_texture;
public:
	Texture(string route);
	~Texture();
	GLuint getID();
};

#endif


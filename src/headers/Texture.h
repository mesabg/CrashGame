#pragma once
#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <string>

using std::string;

class Texture {
private:
	string route;
public:
	Texture(string route);
	~Texture();
};

#endif
#pragma once
#ifndef __SOUND_H__
#define __SOUND_H__

#include <string>
#include <vector>

using std::string;
using std::vector;

class Sound {
private:
	vector<string> routes;
public:
	Sound(vector<string> routes);
	~Sound();
};

#endif
#pragma once
#ifndef __MODEL_ROUTES_DATA_H__
#define __MODEL_ROUTES_DATA_H__

#include <vector>
#include <string>

using std::string;
using std::vector;

class ModelRoutesData {
public:
	string model;
	string texture;
	vector<string> sounds;
	ModelRoutesData(string model, string texture, vector<string> sounds);
	ModelRoutesData();
	~ModelRoutesData();
};

#endif

#include <ModelRoutesData.h>

ModelRoutesData::ModelRoutesData(string model, string texture, vector<string> sounds){
	this->model = model;
	this->texture = texture;
	this->sounds = sounds;
}

ModelRoutesData::ModelRoutesData(){
}

ModelRoutesData::~ModelRoutesData(){
	this->model.~basic_string();
	this->texture.~basic_string();
	for (int i = 0; i < (int)this->sounds.size(); i++)
		this->sounds[i].~basic_string();
	this->sounds.clear();
	this->sounds.~vector();
	return;
}

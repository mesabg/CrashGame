#pragma once
#ifndef __OBJ_H_
#define __OBJ_H_

#include <ModelsCreator.h>

class OBJ : public Model
{
public:
	OBJ(string path);
	~OBJ();
	void loadModel(string ruta);
	void agregarFace(vector<int> Faces);
};

#endif
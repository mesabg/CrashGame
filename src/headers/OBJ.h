#pragma once
#ifndef __OBJ_H_
#define __OBJ_H_

#include <ModelsCreator.h>

class OBJ : public Model
{
public:
	OBJ(ModelRoutesData* routes);
	~OBJ();
	void agregarFace(vector<int> Faces);
};

#endif
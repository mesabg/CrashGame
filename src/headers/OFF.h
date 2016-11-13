#pragma once
#ifndef __OFF_H_
#define __OFF_H_

#include <ModelsCreator.h>

class OFF : public Model
{
public:
	OFF();
	~OFF();
	void loadModel(string ruta);
	void agregarFace(vector<int> Faces);
};

#endif

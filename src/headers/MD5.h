#pragma once
#ifndef __MD5_H_
#define __MD5_H_

#include <ModelsCreator.h>

class MD5 : public Model
{
public:
	MD5();
	~MD5();
	void loadModel(string ruta);
	void agregarFace(vector<int> Faces);
};

#endif
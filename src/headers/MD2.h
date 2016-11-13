#pragma once
#ifndef __MD2_H_
#define __MD2_H_

#include <ModelsCreator.h>

class MD2 : public Model
{
public:
	MD2();
	~MD2();
	void loadModel(string ruta);
	void agregarFace(vector<int> Faces);
};

#endif
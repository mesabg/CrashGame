#pragma once
#ifndef __OFF_H_
#define __OFF_H_

#include <ModelsCreator.h>

class OFF : public Model
{
public:
	OFF(ModelRoutesData* routes);
	~OFF();
	void agregarFace(vector<int> Faces);
};

#endif

#pragma once
#ifndef __MODELS_CREATOR_H_
#define __MODELS_CREATOR_H_

#include <Model.h>
#include <fstream>

using std::ifstream;

/*Interface Creator*/
class ModelsCreator
{
public:
	ModelsCreator();
	~ModelsCreator();
	virtual Model* factoryMethod(Mediator* mediator) = 0;
};

#endif

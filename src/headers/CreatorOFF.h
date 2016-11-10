#pragma once
#ifndef __CREATOR_OFF_H_
#define __CREATOR_OFF_H_

#include <OFF.h>

/*Concrete Creator*/
class CreatorOFF : public ModelsCreator
{
public:
	CreatorOFF();
	~CreatorOFF();
	Model* factoryMethod(Mediator* mediator);
};

#endif

#pragma once
#ifndef __CREATOR_MD2_H_
#define __CREATOR_MD2_H_

#include <MD2.h>

/*Concrete Creator*/
class CreatorMD2 : public ModelsCreator
{
public:
	CreatorMD2();
	~CreatorMD2();
	Model* factoryMethod();
};

#endif
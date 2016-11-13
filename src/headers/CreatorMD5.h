#pragma once
#ifndef __CREATOR_MD5_H_
#define __CREATOR_MD5_H_

#include <MD5.h>

/*Concrete Creator*/
class CreatorMD5 : public ModelsCreator
{
public:
	CreatorMD5();
	~CreatorMD5();
	Model* factoryMethod();
};

#endif
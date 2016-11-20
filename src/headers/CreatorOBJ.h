#pragma once
#ifndef __CREATOR_OBJ_H_
#define __CREATOR_OBJ_H_

#include <OBJ.h>

/*Concrete Creator*/
class CreatorOBJ : public ModelsCreator{
public:
	CreatorOBJ();
	~CreatorOBJ();
	Model* create(string path);
};

#endif
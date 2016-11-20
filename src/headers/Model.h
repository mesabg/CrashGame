#pragma once
#ifndef __MODEL_H_
#define __MODEL_H_

#include <Transformation.h>
#include <Sound.h>
#include <BoundingBox.h>
#include <Texture.h>
#include <string>

using std::string;

class Model{
protected:
	GLfloat* glVBO;
	Sound* sound;
	Transformation* transformation;
	BoundingBox* boundingBox;
	Texture* texture;

public:
	Model();
	~Model();
	void render();

	/*Getters*/
	GLfloat* getGLVBO();
	Sound* getSound();
	Transformation* getTransformation();
	BoundingBox* getBoundingBox();
	Texture* getTexture();

	/*Setters*/
	void setSound(Sound* sound);
	void setTransformation(Transformation* transformation);
	void setTexture(Texture* texture);

	/*Inherit*/
	void Inherit(Model* model);
};

#endif

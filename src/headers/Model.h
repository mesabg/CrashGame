#pragma once
#ifndef __MODEL_H_
#define __MODEL_H_

#include <glew\glew.h>
#include <Transformation.h>
#include <Sound.h>
#include <BoundingBox.h>
#include <Texture.h>
#include <ModelRoutesData.h>
#include <string>

using std::string;

class Model{
protected:
	GLfloat* glVBO; /*v1x v1y v1z vn1x vn1y vn1z vt1 vt2 vt3*/
	GLuint glVBO_dir;
	std::vector<GLfloat*> vertexes;
	std::vector<GLfloat*> normal;
	std::vector<GLfloat*> texture_;

	Sound* sound;
	Transformation* transformation;
	BoundingBox* boundingBox;
	Texture* texture;

	GLfloat max, min;

public:
	Model();
	Model(ModelRoutesData* routes);
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

	/*Functions*/
	void initGLDataBinding();
};

#endif

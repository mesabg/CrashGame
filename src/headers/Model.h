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

using glm::vec3;
using std::string;
using std::vector;

class Model{
protected:
	/*Array to VBO*/
	GLfloat* glVBO; /*v1x v1y v1z vn1x vn1y vn1z vt1 vt2 vt3*/
	GLuint glVBO_dir;

	/*Arrays to load a model*/
	vector<GLfloat*> vertexes;
	vector<GLfloat*> normal;
	vector<GLfloat*> texture_;
	GLfloat max, min;

	/*Structures*/
	Sound* sound;
	Transformation* transformation;
	BoundingBox* boundingBox;
	Texture* texture;

	/*Light values*/
	vec3 ambient;	/*Values of the refraction of the light*/
	vec3 diffuse;
	vec3 specular;
	float shininess;

	/*Uniforms IDs*/
	vector<GLint> *ID;
	
public:
	Model();
	Model(ModelRoutesData* routes);
	~Model();
	void render(GLuint shader_id);

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

#pragma once
#ifndef __MODEL_H_
#define __MODEL_H_

#include <glew\glew.h>
#include <Transformation.h>
#include <Sound.h>
#include <BoundingBox.h>
#include <Texture.h>
#include <ModelRoutesData.h>
#include <Light.h>
#include <string>
#include <sstream>

using glm::vec3;
using std::string;
using std::vector;

class Model{
protected:
	/*Array to VBO*/
	vector<GLfloat> glVBO; /*v1x v1y v1z vn1x vn1y vn1z vt1 vt2 vt3*/
	GLuint glVBO_dir;
	GLuint glVBO_indexes_dir;
	vector<GLuint> glVBO_indexes;
	GLuint glVBO_indexes_size;


	/*Arrays to load a model*/
	vector<GLfloat*> vertexes;
	vector<GLfloat*> normal;
	vector<GLfloat*> texture_;
	GLfloat max, min;
	int vertexesLenght;

	/*Structures*/
	Sound* sound;
	Transformation* transformation;
	BoundingBox* boundingBox;
	Texture* texture;

	/*Light values*/
	Light* material; /*Values of the refraction of the light*/
	float shininess;

	/*Uniforms IDs*/
	vector<GLint> *ID;
	
public:
	Model();
	Model(ModelRoutesData* routes);
	~Model();
	void render(GLuint shader_id);

	/*Getters*/
	vector<GLfloat> getGLVBO();
	Sound* getSound();
	Transformation* getTransformation();
	BoundingBox* getBoundingBox();
	Texture* getTexture();
	GLuint getGLVBO_dir();
	GLuint getGLVBO_indexes_dir();
	vector<GLuint> getGLVBO_indexes();
	GLuint getGLVBO_indexes_size();
	float getShininess();

	/*Setters*/
	void setSound(Sound* sound);
	void setTransformation(Transformation* transformation);
	void setTexture(Texture* texture);

	/*Inherit*/
	void Inherit(Model* model);

	/*Functions*/
	void initGLDataBinding();
};


/*Functions*/
void split(const std::string &s, char delim, std::vector<std::string> &elems);
#endif

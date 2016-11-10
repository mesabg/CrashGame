#pragma once
#ifndef __BOUNDING_BOX_H_
#define __BOUNDING_BOX_H_

#include <Vertex.h>
#include <RGB_.h>
#include <vector>
#include <glm\glm\glm.hpp>
#include <glm\glm\gtc\matrix_transform.hpp>
#include <glm\glm\gtc\type_ptr.hpp>
#include <glfw3.h>

using std::vector;

class BoundingBox
{
private:
	vector<Vertex*> vertexes;
	Vertex *min, *max;
	RGB_ color;
	glm::vec3 center, center2;
public:
	BoundingBox();
	~BoundingBox();
	void initVertexBox(Vertex* vertex);
	void setVertexBox(Vertex* vertex);
	void setColor(float r, float g, float b);
	RGB_ getColor();
	void display(glm::mat4x4 &TInverse, glm::mat4x4 &T, glm::mat4x4 &R, glm::mat4x4 &S);
	void setCenter(glm::mat4x4 &TInverse, glm::mat4x4 &T, glm::mat4x4 &R, glm::mat4x4 &S);
	void escalar(double max);
	glm::tvec4<GLdouble> transformVector(glm::mat4x4 &TInverse, glm::mat4x4 &T, glm::mat4x4 &R, glm::mat4x4 &S, Vertex * vector);
	glm::vec3 getCenter_(glm::mat4x4 &TInverse, glm::mat4x4 &T, glm::mat4x4 &R, glm::mat4x4 &S);
	glm::vec3 getCenter();
	glm::vec3 getCenter2();
};

#endif

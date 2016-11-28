#pragma once
#ifndef __BOUNDING_BOX_H_
#define __BOUNDING_BOX_H_

#include <vector>
#include <glm\glm\glm.hpp>
#include <glm\glm\gtc\matrix_transform.hpp>
#include <glm\glm\gtc\type_ptr.hpp>
#include <glfw3.h>

using std::vector;
using glm::vec3;

class BoundingBox
{
private:
	vec3 min, max, center;
public:
	BoundingBox();
	~BoundingBox();
	
	/*Functions*/
	void initVertexBox(vec3 vertex);
	void setVertexBox(vec3 vertex);
	
	/*Getters*/
	vec3 getCenter();
	vec3 getMin();
	vec3 getMax();
};

#endif

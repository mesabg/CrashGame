#pragma once
#ifndef __PROJECTION_H__
#define __PROJECTION_H__

#include <glm\glm\glm.hpp>
#include <glm\glm\gtx\transform.hpp>

using glm::mat4;
using glm::vec3;

class Projection {
private:
	mat4 projection;
	float fieldOfView;	/*Amount of zoom*/
	float aspectRatio;	/*Screen relation (width/height)*/
	float near;			/*Near plane*/
	float far;			/*Far plane*/

	/*Private Functions*/
	void refresh();
public:
	Projection();
	Projection(float fieldOfView, float aspectRatio, float near, float far);
	~Projection();

	/*Getters*/
	mat4 getMatrix();
	float getFieldOfView();
	float getAspectRatio();
	float getNear();
	float getFar();

	/*Setters*/
	void setFieldOfView(float fieldOfView);
	void setAspectRatio(float aspectRatio);
	void setNearAndFar(float near, float far);
	void setNear(float near);
	void setFar(float far);

	/*Adders*/
	void addFieldOfView(float fieldOfView);
	void addAspectRatio(float aspectRatio);
	void addNearAndFar(float near, float far);
	void addNear(float near);
	void addFar(float far);
};

#endif
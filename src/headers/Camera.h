#pragma once
#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <glm\glm\glm.hpp>
#include <glm\glm\gtx\transform.hpp>

using glm::mat4;
using glm::vec3;

class Camera {
private:
	mat4 view;
	vec3 position;	/*Position of the camera*/
	vec3 target;	/*What you want to look at (center of the principal player)*/
	vec3 up;		/*(0, 1, 0) to look upside*/
	
	/*Private Functions*/
	void refresh();
public:
	Camera();
	Camera(vec3 position, vec3 target, vec3 up);
	~Camera();

	/*Getters*/
	mat4 getMatrix();
	vec3 getPosition();
	vec3 getTarget();
	vec3 getUp();

	/*Setters*/
	void setPosition(vec3 position);
	void setPositionAndTarget(vec3 position, vec3 target);	/*Es la funcion que más va a ayudar*/
	void setTarget(vec3 target);
	void setUp(vec3 up);

	/*Adders*/
	void addPosition(vec3 position);
	void addPositionAndTarget(vec3 position, vec3 target);	/*Es la funcion que más va a ayudar*/
	void addTarget(vec3 target);
	void addUp(vec3 up);
};

#endif
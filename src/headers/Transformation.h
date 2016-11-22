#pragma once
#ifndef __TRANSFORMATION_H__
#define __TRANSFORMATION_H__

using glm::mat4;

class Transformation {
private:
	mat4 TInverse, T, S, R;

public:
	Transformation();
	Transformation(float tx, float ty, float tz, float scale, float rx, float ry, float rz);
	~Transformation();

	/*getters*/
	mat4 getTransformMatrix();
	mat4 getTraslationInverseMatrix();
	mat4 getTraslationMatrix();
	mat4 getScaleMatrix();
	mat4 getRotationMatrix();

	/*Setters*/
	void setTraslationMatrix(float tx, float ty, float tz);
	void setScaleMatrix(float scale);
	void setRotationMatrix(float rx, float ry, float rz);

	/*Adders*/
	void addTraslationMatrix(float tx, float ty, float tz);
	void addScaleMatrix(float scale);
	void addRotationMatrix(float rx, float ry, float rz);
};

#endif
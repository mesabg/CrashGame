#include <Transformation.h>

Transformation::Transformation(){
	this->TInverse = mat4(1.0f);
	this->T = mat4(1.0f);
	this->S = mat4(1.0f);
	this->R = mat4(1.0f);
	this->setTraslationMatrix(0.0f, 0.0f, 0.0f);
	this->setScaleMatrix(1.0f);
}

Transformation::Transformation(float tx, float ty, float tz, float scale, float angle, float rx, float ry, float rz){
	this->TInverse = mat4(1.0f);
	this->T = mat4(1.0f);
	this->S = mat4(1.0f);
	this->R = mat4(1.0f);
	this->setTraslationMatrix(tx, ty, tz);
	this->setScaleMatrix(scale);
	this->setRotationMatrix(angle, rx, ry, rz);
}

Transformation::~Transformation(){

}

mat4 Transformation::getTransformMatrix(){
	return this->T*this->R*this->S;
}

mat4 Transformation::getTraslationInverseMatrix(){
	return this->TInverse;
}

mat4 Transformation::getTraslationMatrix(){
	return this->T;
}

mat4 Transformation::getScaleMatrix(){
	return this->S;
}

mat4 Transformation::getRotationMatrix(){
	return this->R;
}

void Transformation::setTraslationMatrix(float tx, float ty, float tz){
	this->T = glm::translate( vec3(tx, ty, tz) );
	/*this->T[0][3] = tx; this->TInverse[0][3] = -tx;
	this->T[1][3] = ty; this->TInverse[1][3] = -ty;
	this->T[2][3] = tz; this->TInverse[2][3] = -tz;*/
}

void Transformation::setScaleMatrix(float scale){
	this->S = glm::scale( vec3(scale, scale, scale) );
	//for (int i = 0; i < 3; i++) this->S[i][i] = scale;
}

void Transformation::setRotationMatrix(float angle, float rx, float ry, float rz){
	this->R = glm::rotate(angle, glm::vec3(rx, ry, rz));
}

void Transformation::addTraslationMatrix(float tx, float ty, float tz){
	this->T[0][3] += tx; this->TInverse[0][3] += -tx;
	this->T[1][3] += ty; this->TInverse[1][3] += -ty;
	this->T[2][3] += tz; this->TInverse[2][3] += -tz;
}

void Transformation::addScaleMatrix(float scale){
	for (int i = 0; i < 3; i++) this->S[i][i] += scale;
}

void Transformation::addRotationMatrix(float angle, float rx, float ry, float rz){
	/*Falta por implementación*/
}

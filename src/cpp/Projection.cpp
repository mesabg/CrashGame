#include <Projection.h>

void Projection::refresh(){
	this->projection = glm::perspective(this->fieldOfView, this->aspectRatio, this->near, this->far);
}

Projection::Projection(){
	this->fieldOfView = 45.0f;
	this->aspectRatio = 1440.0f/900.0f;
	this->near = 1.0f;
	this->far = 1000.0f;
	this->refresh();
}

Projection::Projection(float fieldOfView, float aspectRatio, float near, float far){
	this->fieldOfView = fieldOfView;
	this->aspectRatio = aspectRatio;
	this->near = near;
	this->far = far;
	this->refresh();
}

Projection::~Projection(){

}

mat4 Projection::getMatrix(){
	return this->projection;
}

float Projection::getFieldOfView(){
	return this->fieldOfView;
}

float Projection::getAspectRatio(){
	return this->aspectRatio;
}

float Projection::getNear(){
	return this->near;
}

float Projection::getFar(){
	return this->far;
}

void Projection::setFieldOfView(float fieldOfView){
	this->fieldOfView = fieldOfView;
	this->refresh();
}

void Projection::setAspectRatio(float aspectRatio){
	this->aspectRatio = aspectRatio;
	this->refresh();
}

void Projection::setNearAndFar(float near, float far){
	this->near = near;
	this->far = far;
	this->refresh();
}

void Projection::setNear(float near){
	this->near = near;
	this->refresh();
}

void Projection::setFar(float far){
	this->far = far;
	this->refresh();
}

void Projection::addFieldOfView(float fieldOfView){
	this->fieldOfView += fieldOfView;
	this->refresh();
}

void Projection::addAspectRatio(float aspectRatio){
	this->aspectRatio += aspectRatio;
	this->refresh();
}

void Projection::addNearAndFar(float near, float far){
	this->near += near;
	this->far += far;
	this->refresh();
}

void Projection::addNear(float near){
	this->near = near;
	this->refresh();
}

void Projection::addFar(float far){
	this->far = far;
	this->refresh();
}

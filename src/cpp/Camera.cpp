#include <Camera.h>

void Camera::refresh(){
	this->view = glm::lookAt(this->position, this->target, this->up);
}

Camera::Camera(){
	this->position = vec3(3.0f, 3.0f, 10.0f);
	this->target = vec3(0.0f, 0.0f, 0.0f);
	this->up = vec3(0.0f, 1.0f, 0.0f);
	this->refresh();
}

Camera::Camera(vec3 position, vec3 target, vec3 up){
	this->position = position;
	this->target = target;
	this->up = up;
	this->refresh();
}

Camera::~Camera(){

}

mat4 Camera::getMatrix(){
	return this->view;
}

vec3 Camera::getPosition(){
	return this->position;
}

vec3 Camera::getTarget(){
	return this->target;
}

vec3 Camera::getUp(){
	return this->up;
}

void Camera::setPosition(vec3 position){
	this->position = position;
	this->refresh();
}

void Camera::setPositionAndTarget(vec3 position, vec3 target){
	this->position = position;
	this->target = target;
	this->refresh();
}

void Camera::setTarget(vec3 target){
	this->target = target;
	this->refresh();
}

void Camera::setUp(vec3 up){
	this->up = up;
	this->refresh();
}

void Camera::addPosition(vec3 position){
	this->position += position;
	this->refresh();
}

void Camera::addPositionAndTarget(vec3 position, vec3 target){
	this->position += position;
	this->target += target;
	this->refresh();
}

void Camera::addTarget(vec3 target){
	this->target += target;
	this->refresh();
}

void Camera::addUp(vec3 up){
	this->up += up;
	this->refresh();
}

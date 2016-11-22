#include <Light.h>

Light::Light(){
	this->position = vec3(0.0f, 0.0f, 0.0f);
	this->ambient = vec3(1.0f, 1.0f, 1.0f);
	this->diffuse = vec3(1.0f, 1.0f, 1.0f);
	this->specular = vec3(1.0f, 1.0f, 1.0f);
}

Light::Light(vec3 position, vec3 ambient, vec3 diffuse, vec3 specular){
	this->position = position;
	this->ambient = ambient;
	this->diffuse = diffuse;
	this->specular = specular;
}

Light::~Light(){

}

vec3 Light::getPosition(){
	return this->position;
}

vec3 Light::getAmbient(){
	return this->ambient;
}

vec3 Light::getDiffuse(){
	return this->diffuse;
}

vec3 Light::getSpecular(){
	return this->specular;
}

void Light::setPosition(vec3 position){
	this->position = position;
}

void Light::set(vec3 ambient, vec3 diffuse, vec3 specular){
	this->ambient = ambient;
	this->diffuse = diffuse;
	this->specular = specular;
}

void Light::setAmbient(vec3 ambient){
	this->ambient = ambient;
}

void Light::setDiffuse(vec3 diffuse){
	this->diffuse = diffuse;
}

void Light::setSpecular(vec3 specular){
	this->specular = specular;
}

void Light::addPosition(vec3 position){
	this->position += position;
}

#include <BoundingBox.h>
#include <iostream>

BoundingBox::BoundingBox() {}

BoundingBox::~BoundingBox() {}

void BoundingBox::initVertexBox(vec3 vertex){
	this->min = vertex;
	this->max = vertex;
	this->center = vertex;
}

void BoundingBox::setVertexBox(vec3 vertex){
	if (vertex.x < this->min.x) this->min.x = vertex.x;
	if (vertex.x > this->max.x) this->max.x = vertex.x;

	if (vertex.y < this->min.y) this->min.y = vertex.y;
	if (vertex.y > this->max.y) this->max.y = vertex.y;

	if (vertex.z < this->min.z) this->min.z = vertex.z;
	if (vertex.z > this->max.z) this->max.z = vertex.z;

	this->center.x = (this->min.x + this->max.x) / 2.0f;
	this->center.y = (this->min.y + this->max.y) / 2.0f;
	this->center.z = (this->min.z + this->max.z) / 2.0f;
}

vec3 BoundingBox::getCenter(){
	return this->center;
}

vec3 BoundingBox::getMin(){
	return this->min;
}

vec3 BoundingBox::getMin(){
	return this->max;
}
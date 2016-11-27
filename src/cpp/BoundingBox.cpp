#include <BoundingBox.h>
#include <iostream>

BoundingBox::BoundingBox() {

}

BoundingBox::~BoundingBox() {}

/*
void BoundingBox::setVertexBox(Vertex * vertex){
	if (vertex->x < this->min->x) this->min->x = vertex->x;
	if (vertex->x > this->max->x) this->max->x = vertex->x;

	if (vertex->y < this->min->y) this->min->y = vertex->y;
	if (vertex->y > this->max->y) this->max->y = vertex->y;

	if (vertex->z < this->min->z) this->min->z = vertex->z;
	if (vertex->z > this->max->z) this->max->z = vertex->z;

	this->center.x = (this->min->x + this->max->x) / 2.0f;
	this->center.y = (this->min->y + this->max->y) / 2.0f;
	this->center.z = (this->min->z + this->max->z) / 2.0f;
}

void BoundingBox::setColor(float r, float g, float b) {
	this->color.setColor(r, g, b);
}

RGB_ BoundingBox::getColor(){
	return this->color;
}



void BoundingBox::display(glm::mat4x4 &TInverse, glm::mat4x4 &T, glm::mat4x4 &R, glm::mat4x4 &S){
	glm::vec4 min, max;
	vector<glm::vec4> vertexes;
	
	vertexes.push_back(transformVector(TInverse, T, R, S, new Vertex(this->max->x, this->max->y, this->max->z)) );
	vertexes.push_back(transformVector(TInverse, T, R, S, new Vertex(this->max->x, this->min->y, this->max->z)));
	vertexes.push_back(transformVector(TInverse, T, R, S, new Vertex(this->min->x, this->max->y, this->max->z)));
	vertexes.push_back(transformVector(TInverse, T, R, S, new Vertex(this->min->x, this->min->y, this->max->z)));
	vertexes.push_back(transformVector(TInverse, T, R, S, new Vertex(this->min->x, this->max->y, this->min->z)));
	vertexes.push_back(transformVector(TInverse, T, R, S, new Vertex(this->min->x, this->min->y, this->min->z)));
	vertexes.push_back(transformVector(TInverse, T, R, S, new Vertex(this->max->x, this->max->y, this->min->z)));
	vertexes.push_back(transformVector(TInverse, T, R, S, new Vertex(this->max->x, this->min->y, this->min->z)));

	glColor3fv(this->color.rgb);
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < 10; i++)
		glVertex3d(vertexes[i % 8][0], vertexes[i % 8][1], vertexes[i % 8][2]);
	glEnd();
}

void BoundingBox::setCenter(glm::mat4x4 &TInverse, glm::mat4x4 &T, glm::mat4x4 &R, glm::mat4x4 &S){
	glm::vec4 min = transformVector(TInverse, T, R, S, new Vertex(this->min->x, this->min->y, this->min->z));
	glm::vec4 max = transformVector(TInverse, T, R, S, new Vertex(this->max->x, this->max->y, this->max->z));

	this->center2.x = (min.x + max.x) / 2.0f;
	this->center2.y = (min.y + max.y) / 2.0f;
	this->center2.z = (min.z + max.z) / 2.0f;
}



void BoundingBox::escalar(double max){
	this->min->x = this->min->x*1.0 / max;
	this->min->y = this->min->y*1.0 / max;
	this->min->z = this->min->z*1.0 / max;
	this->max->x = this->max->x*1.0 / max;
	this->max->y = this->max->y*1.0 / max;
	this->max->z = this->max->z*1.0 / max;

	this->center.x = (this->min->x + this->max->x) / 2.0f;
	this->center.y = (this->min->y + this->max->y) / 2.0f;
	this->center.z = (this->min->z + this->max->z) / 2.0f;
}

void BoundingBox::initVertexBox(Vertex* vertex){
	for (int i = 0; i < 4; i++)
		this->vertexes.push_back(new Vertex(vertex->x, vertex->y, vertex->z));
	this->min = new Vertex(vertex->x, vertex->y, vertex->z);
	this->max = new Vertex(vertex->x, vertex->y, vertex->z);
}


glm::tvec4<GLdouble> BoundingBox::transformVector(glm::mat4x4 &TInverse,glm::mat4x4 &T, glm::mat4x4 &R, glm::mat4x4 &S, Vertex * vector) {
	glm::tvec4<GLdouble> vertex, v;
	TInverse = glm::mat4(1.0f);
	
	TInverse[0][3] = -this->center.x;
	TInverse[1][3] = -this->center.y;
	TInverse[2][3] = -this->center.z;

	glm::mat4x4 transformInverse = TInverse*R*S;
	vertex.x = transformInverse[0][0] * (GLdouble)vector->x + transformInverse[0][1] * (GLdouble)vector->y + transformInverse[0][2] * (GLdouble)vector->z + transformInverse[0][3] * (GLdouble)1.0f;
	vertex.y = transformInverse[1][0] * (GLdouble)vector->x + transformInverse[1][1] * (GLdouble)vector->y + transformInverse[1][2] * (GLdouble)vector->z + transformInverse[1][3] * (GLdouble)1.0f;
	vertex.z = transformInverse[2][0] * (GLdouble)vector->x + transformInverse[2][1] * (GLdouble)vector->y + transformInverse[2][2] * (GLdouble)vector->z + transformInverse[2][3] * (GLdouble)1.0f;

	v.x = T[0][0] * vertex.x + T[0][1] * vertex.y + T[0][2] * vertex.z + T[0][3] * (GLdouble)1.0f;
	v.y = T[1][0] * vertex.x + T[1][1] * vertex.y + T[1][2] * vertex.z + T[1][3] * (GLdouble)1.0f;
	v.z = T[2][0] * vertex.x + T[2][1] * vertex.y + T[2][2] * vertex.z + T[2][3] * (GLdouble)1.0f;
	v.w = (GLdouble)1.0f;

	return v;
}

glm::vec3 BoundingBox::getCenter_(glm::mat4x4 &TInverse, glm::mat4x4 &T, glm::mat4x4 &R, glm::mat4x4 &S){
	glm::tvec4<GLdouble> out = transformVector( TInverse, T, R, S, new Vertex((GLfloat)(this->min->x + this->max->x) / 2.0f, (GLfloat)(this->min->y + this->max->y) / 2.0f, (GLfloat)(this->min->z + this->max->z) / 2.0f) );
	return glm::vec3( out.x, out.y, out.z );
}

glm::vec3 BoundingBox::getCenter(){
	return this->center;
}

glm::vec3 BoundingBox::getCenter2() {
	return this->center2;
}
*/
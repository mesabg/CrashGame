#include <Model.h>
#include <iostream>

Model::Model(){
	/*Do not do anything*/
}

Model::Model(ModelRoutesData* routes) {
	/*Init data structures*/
	this->texture = new Texture(routes->texture);
	this->sound = new Sound(routes->sounds);

	/*Init Uniforms ID*/
	this->ID = new vector<GLint>(10, 0);

	/*Init Tranformation*/
	this->transformation = new Transformation();

	/*Init Material Colors*/
	this->material = new Light( vec3(0.0f, 0.0f, 0.0f), vec3(0.5f, 0.3f, 0.2f), vec3(0.2f, 0.1f, 0.2f), vec3(0.25f, 0.0f, 0.2f) );
	this->shininess = 10.0f;
	
	/*Other Inits*/
	this->Estado = "Normal";
}

Model::~Model(){
	
}

void Model::render(GLuint shader_id){
	
		if(this->Estado == "Normal"){
			this->transformation->addTraslationMatrix(0.0f,0.0f,0.2f);
		}else if(this->Estado == "Arriba"){
			this->transformation->addTraslationMatrix(0.0f,0.2f,0.2f);
		}else if(this->Estado == "Abajo"){
			this->transformation->addTraslationMatrix(0.0f,-0.2f,0.2f);
		}else if(this->Estado == "Derecha"){
			this->transformation->addTraslationMatrix(0.2f,0.0f,0.2f);
		}else if(this->Estado == "Izquierda"){
			this->transformation->addTraslationMatrix(-0.2f,0.0f,0.2f);
		}
		
	/*Bind Uniforms*/
	this->ID->at(0) = glGetUniformLocation(shader_id, "u_matAmbientReflectances");
	glUniform3f(this->ID->at(0), this->material->getAmbient().r, this->material->getAmbient().g, this->material->getAmbient().b);

	this->ID->at(1) = glGetUniformLocation(shader_id, "u_matDiffuseReflectances");
	glUniform3f(this->ID->at(1), this->material->getDiffuse().r, this->material->getDiffuse().g, this->material->getDiffuse().b);

	this->ID->at(2) = glGetUniformLocation(shader_id, "u_matSpecularReflectances");
	glUniform3f(this->ID->at(2), this->material->getSpecular().r, this->material->getSpecular().g, this->material->getSpecular().b);

	this->ID->at(3) = glGetUniformLocation(shader_id, "u_matShininess");
	glUniform1f(this->ID->at(3), this->shininess);

	this->ID->at(4) = glGetUniformLocation(shader_id, "u_modelMat");
	glUniformMatrix4fv(this->ID->at(4), 1, GL_FALSE, &(this->transformation->getTransformMatrix())[0][0]);

	this->ID->at(5) = glGetUniformLocation(shader_id, "ourTexture");
	glUniform1i(this->ID->at(5), 0);
	
	glEnable(GL_TEXTURE_2D);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, this->glVBO_dir);
	  
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->glVBO_indexes_dir);

	/*Vertexes*/
	glEnableVertexAttribArrayARB(0);
	glVertexAttribPointerARB(0, 3, GL_FLOAT, GL_FALSE, 9*sizeof(GLfloat), 0 );

	/*Texture Coord*/
	glEnableVertexAttribArrayARB(2);
	glVertexAttribPointerARB(2, 3, GL_FLOAT, GL_FALSE, 9*sizeof(GLfloat), (void*)(3*sizeof(GLfloat)) );

	/*Normals*/
	glEnableVertexAttribArrayARB(1);
	glVertexAttribPointerARB(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));
	glBindTexture(GL_TEXTURE_2D, this->texture->getID());
	glUniform1i(glGetUniformLocation(shader_id, "ourTexture"), 0);
	
	glDrawElements(GL_TRIANGLES, this->glVBO_indexes_size, GL_UNSIGNED_INT, (void*)0);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);

}

vector<GLfloat> Model::getGLVBO(){
	return this->glVBO;
}

Sound * Model::getSound(){
	return this->sound;
}

Transformation * Model::getTransformation(){
	return this->transformation;
}

BoundingBox * Model::getBoundingBox(){
	return this->boundingBox;
}

Texture * Model::getTexture(){
	return this->texture;
}

GLuint Model::getGLVBO_dir(){
	return this->glVBO_dir;
}

GLuint Model::getGLVBO_indexes_dir(){
	return this->glVBO_indexes_dir;
}

vector<GLuint> Model::getGLVBO_indexes(){
	return this->glVBO_indexes;
}

GLuint Model::getGLVBO_indexes_size(){
	return this->glVBO_indexes_size;
}

float Model::getShininess(){
	return this->shininess;
}

void Model::setSound(Sound * sound){
	this->sound = sound;
}

void Model::setTransformation(Transformation * transformation){
	this->transformation = transformation;
}

void Model::setTexture(Texture * texture){
	this->texture = texture;
}

void Model::Inherit(Model * model) {
	/*Copy All the values*/
	this->glVBO = model->getGLVBO();
	this->sound = model->getSound();
	this->transformation = model->getTransformation();
	this->texture = model->getTexture();
	this->boundingBox = model->getBoundingBox();
	this->glVBO_dir = model->getGLVBO_dir();
	this->glVBO_indexes_dir = model->getGLVBO_indexes_dir();
	this->glVBO_indexes = model->getGLVBO_indexes();
	this->glVBO_indexes_size = model->getGLVBO_indexes_size();
	this->shininess = model->getShininess();
}

void Model::initGLDataBinding(){

	for (int i = 0; i < ((int)this->glVBO.size()/9); i++)
		this->glVBO_indexes.push_back( (GLuint) i);

	this->glVBO_indexes_size = this->glVBO_indexes.size();

	glGenBuffersARB(1, &(this->glVBO_dir));											// create a vbo
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, this->glVBO_dir);										// activate vbo id to use
	glBufferDataARB(GL_ARRAY_BUFFER_ARB, (this->glVBO.size())*sizeof(GLfloat), &(this->glVBO[0]), GL_STATIC_DRAW_ARB);	// upload data to video card
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);

	glGenBuffers(1, &(this->glVBO_indexes_dir));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->glVBO_indexes_dir);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->glVBO_indexes.size()*sizeof(GLuint), &(this->glVBO_indexes[0]), GL_STATIC_DRAW);
	glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER, 0);

	this->glVBO.~vector();
	this->glVBO_indexes.~vector();

	/*Enable Backface Culling and Z Buffer*/
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	/*glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE0);
	glActiveTexture(GL_TEXTURE0);*/
	System::GC::Collect();
}

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
}


void setEstado(string message){
	this->Estado = message;
}

string getEstado(){
	return this->Estado;
}


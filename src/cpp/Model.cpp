#include <Model.h>
#include <iostream>
/*
Model::Model(Mediator* mediator) :Colleague(mediator) {
	this->T = glm::mat4(1.0f);
	this->R = glm::mat4(1.0f);
	this->S = glm::mat4(1.0f);
	this->TInverse = glm::mat4(1.0f);

	this->T[0][3] = 0.0f;
	this->T[1][3] = 0.0f;
	this->T[2][3] = 0.0f;

	this->S[0][0] = 4.0f;
	this->S[1][1] = 4.0f;
	this->S[2][2] = 4.0f;
	this->Rotation[0] = 0.0f;
	this->Rotation[1] = 0.0f;
	this->Rotation[2] = 0.0f;
	this->Rotation[3] = 1.0f;

	this->boundingBoxColor = RGB_::make_rgb(0.1f);
	this->borderColor = RGB_::make_rgb(1.0f);
	this->fillColor = RGB_::make_rgb(0.5f);
	this->normalsColor = RGB_::make_rgb(0.8f, 0.0f, 0.0f);
	this->lightAmbientIntensity = RGB_::make_rgb(0.5f, 0.5f, 0.0f);
	this->lightDiffuseIntensity = RGB_::make_rgb(1.0f, 0.5f, 0.0f);
	this->lightSpecularIntensity = RGB_::make_rgb(0.0f, 1.0f, 0.0f);
	this->matAmbientReflectances = RGB_::make_rgb(0.2f, 0.5f, 0.0f);
	this->matDiffuseReflectances = RGB_::make_rgb(1.0f, 0.5f, 0.0f);
	this->matSpecularReflectances = RGB_::make_rgb(0.3f, 0.5f, 0.5f);
	this->matShininess = 50.0f;

	this->localBoundingBox = new BoundingBox();

	this->mode = 1;
	this->displayNormal = this->displayBackfaceCulling = false;
	this->displayBoundingBox = false;

	this->flatShading = false;
	this->gouraudShading = false;
	this->phongShading = false;

	this->shadingMode = false;

	this->speculateIntensity = 1.0f;
	this->diffuseIntensity = 1.0f;

	this->projection = glm::perspective(44.766655555f, 1440.0f / 900.0f, 1.0f, 1000.0f);// Hay que settearlos por el valor real !! reshape y todo el rollo NO CAMBIAR ESA CONSTANTE
	this->modelView = glm::lookAt(glm::vec3(3.0f, 3.0f, 10.0f) , glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	this->normalMatrix = glm::transpose(glm::inverse(this->TInverse*this->R*this->S));
}*/

Model::Model(){
	this->glVBO = (GLfloat*)malloc(sizeof(GLfloat));

	/*Init Uniforms ID*/
	this->ID = new vector<GLint>(8, 0);

	/*Init Tranformation*/
	this->transformation = new Transformation();

	/*Init Material Colors*/
	this->material = new Light();
	this->shininess = 4.0f;
}

Model::Model(ModelRoutesData* routes) {
	/*Init data structures*/
	this->glVBO = (GLfloat*)malloc(sizeof(GLfloat));
	this->texture = new Texture(routes->texture);
	this->sound = new Sound(routes->sounds);

	/*Init Uniforms ID*/
	this->ID = new vector<GLint>(8, 0);

	/*Init Tranformation*/
	this->transformation = new Transformation();

	/*Init Material Colors*/
	this->material = new Light();
	this->shininess = 4.0f;
}

Model::~Model(){
	
}

void Model::render(GLuint shader_id){
	/*delete this->glVBO;
	this->glVBO = NULL;
	this->glVBO = new GLfloat[36]{
		// Positions          // Colors           // Texture Coords
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, 0.0f,   // Top Right
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, 0.0f,   // Bottom Right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, 0.0f,   // Bottom Left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f, 0.0f,    // Top Left 
	};*/

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

	/*this->ID->at(4) = glGetUniformLocation(shader_id, "u_TInverse_Mat");
	glUniformMatrix4fv(this->ID->at(4), 1, GL_FALSE, glm::value_ptr(this->transformation->getTraslationInverseMatrix()));

	this->ID->at(5) = glGetUniformLocation(shader_id, "u_T_Mat");
	glUniformMatrix4fv(this->ID->at(5), 1, GL_FALSE, glm::value_ptr(this->transformation->getTraslationMatrix()));

	this->ID->at(6) = glGetUniformLocation(shader_id, "u_S_Mat");
	glUniformMatrix4fv(this->ID->at(6), 1, GL_FALSE, glm::value_ptr(this->transformation->getScaleMatrix()));

	this->ID->at(7) = glGetUniformLocation(shader_id, "u_R_Mat");
	glUniformMatrix4fv(this->ID->at(7), 1, GL_FALSE, glm::value_ptr(this->transformation->getRotationMatrix()));*/

	/*Rendering using VBO*/
	/*Revisar http://pastebin.com/1BZJMG0V*/
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, this->glVBO_dir);

	glEnableVertexAttribArrayARB(0);
	glVertexAttribPointerARB(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), 0);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);

	//glBindBufferARB(GL_ARRAY_BUFFER_ARB, this->glVBO_dir);


	//glEnableClientState(GL_VERTEX_ARRAY);
	//glEnableClientState(GL_NORMAL_ARRAY);
	//glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), 0);

	//glVertexPointer(3, GL_FLOAT, 9*sizeof(GLfloat), 0);
	//glNormalPointer(GL_FLOAT, 9*sizeof(GLfloat), (void*)(3*sizeof(GLfloat)) );
	//glTexCoordPointer( 3, GL_FLOAT, 9 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)) );

	
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	//glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));

	//glEnableVertexAttribArray(0);
	//glEnableVertexAttribArray(1);
	//glEnableVertexAttribArray(2);

	//glDisableVertexAttribArray(2);
	//glDisableVertexAttribArray(1);
	//glDisableVertexAttribArray(0);

	//glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	//glDisableClientState(GL_NORMAL_ARRAY);
	//glDisableClientState(GL_VERTEX_ARRAY);

	//glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
}

GLfloat * Model::getGLVBO(){
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

	/*delete this->glVBO;
	this->glVBO = NULL;
	this->glVBO = new GLfloat[36]{
		// Positions          // Colors           // Texture Coords
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, 0.0f,   // Top Right
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, 0.0f,   // Bottom Right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, 0.0f,   // Bottom Left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f, 0.0f,    // Top Left 
	};*/
}

void Model::initGLDataBinding(){
	delete this->glVBO;
	this->glVBO = NULL;
	this->glVBO = new GLfloat[36]{
		// Positions          // Colors           // Texture Coords
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, 0.0f,   // Top Right
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, 0.0f,   // Bottom Right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, 0.0f,   // Bottom Left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f, 0.0f,    // Top Left 
	};

	glGenBuffersARB(1, &(this->glVBO_dir));														// create a vbo
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, this->glVBO_dir);										// activate vbo id to use
	glBufferDataARB(GL_ARRAY_BUFFER_ARB, 36*sizeof(GLfloat), this->glVBO, GL_STATIC_DRAW_ARB);	// upload data to video card
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);

	delete this->glVBO;

	/*Enable Backface Culling and Z Buffer*/
	/*glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);*/
	/*glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE0);*/
}

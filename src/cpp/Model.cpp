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
}

Model::~Model(){
	
}

void Model::render(){
	glBindBuffer(GL_ARRAY_BUFFER, this->glVBO_dir);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_ARRAY);
	glVertexPointer(3, GL_FLOAT, 9*sizeof(GLfloat), 0);
	glVertexPointer(3, GL_FLOAT, 9*sizeof(GLfloat), (void*)(3*sizeof(GLfloat)) );
	glVertexPointer(3, GL_FLOAT, 9*sizeof(GLfloat), (void*)(6*sizeof(GLfloat)) );
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableClientState(GL_TEXTURE_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
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
}

void Model::initGLDataBinding(){
	glGenBuffers(1, &this->glVBO_dir);
	glBindBuffer(GL_ARRAY_BUFFER, this->glVBO_dir);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->glVBO), this->glVBO, GL_STATIC_DRAW);
}
/*
void Model::display(bool glDepth, CGLSLProgram* shadingProgram, GLfloat* lightSourceGLvector, glm::vec3 luzCentro, bool glNormalVertexTypeFlag){
	glm::tmat4x4<GLdouble> transform = this->getTransform();
	glm::tvec4<GLdouble> pivote;
	int type;

	if(glDepth) glEnable(GL_DEPTH_TEST);
	else glDisable(GL_DEPTH_TEST);


	if (this->displayBackfaceCulling) {	
	    glEnable(GL_NORMALIZE);
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
	} else {
		glDisable(GL_NORMALIZE);
		glDisable(GL_CULL_FACE);
	}
	//printf("%f \n", this->matShininess);

	if (this->mode == 0) { type = GL_POINTS; }
	else if (this->mode == 1 || this->mode == 2) { type = GL_TRIANGLES; }

	vector<GLuint> ID;
	if (shadingProgram!=NULL && !this->shadingMode) {
		//this->displayBoundingBox = false;

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		shadingProgram->enable();

		ID.push_back(glGetUniformLocation(shadingProgram->getProgramID(), "u_viewMat"));
		glUniformMatrix4fv(ID[0], 1, GL_FALSE, glm::value_ptr(this->modelView));

		ID.push_back(glGetUniformLocation(shadingProgram->getProgramID(), "u_normalMat"));
		glUniformMatrix4fv(ID[1], 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(this->modelView))));
		//glUniformMatrix4fv(ID[1], 1, GL_FALSE, glm::value_ptr(R));

		ID.push_back(glGetUniformLocation(shadingProgram->getProgramID(), "u_projMat"));
		glUniformMatrix4fv(ID[2], 1, GL_FALSE, glm::value_ptr(this->projection));

		ID.push_back(glGetUniformLocation(shadingProgram->getProgramID(), "u_lightPosition"));
		glUniform3f(ID[3], luzCentro.x, luzCentro.y, luzCentro.z);
//---------------------------------------------------------------------------------------///

		ID.push_back(glGetUniformLocation(shadingProgram->getProgramID(), "u_lightAmbientIntensitys"));
		glUniform3f(ID[4],this->lightAmbientIntensity.rgb[0], this->lightAmbientIntensity.rgb[1], this->lightAmbientIntensity.rgb[2]);

		ID.push_back(glGetUniformLocation(shadingProgram->getProgramID(), "u_lightDiffuseIntensitys"));
		glUniform3f(ID[5],this->lightDiffuseIntensity.rgb[0], this->lightDiffuseIntensity.rgb[1], this->lightDiffuseIntensity.rgb[2]);

		ID.push_back(glGetUniformLocation(shadingProgram->getProgramID(), "u_lightSpecularIntensitys"));
		glUniform3f(ID[6],this->lightSpecularIntensity.rgb[0], this->lightSpecularIntensity.rgb[1], this->lightSpecularIntensity.rgb[2]);

//------------------------------------------------------------------------------------------------//

		ID.push_back(glGetUniformLocation(shadingProgram->getProgramID(), "u_matAmbientReflectances"));
		glUniform3f(ID[7],this->matAmbientReflectances.rgb[0], this->matAmbientReflectances.rgb[1], this->matAmbientReflectances.rgb[2]);

		ID.push_back(glGetUniformLocation(shadingProgram->getProgramID(), "u_matDiffuseReflectances"));
		glUniform3f(ID[8],this->matDiffuseReflectances.rgb[0], this->matDiffuseReflectances.rgb[1], this->matDiffuseReflectances.rgb[2]);

		ID.push_back(glGetUniformLocation(shadingProgram->getProgramID(), "u_matSpecularReflectances"));
		glUniform3f(ID[9],this->matSpecularReflectances.rgb[0], this->matSpecularReflectances.rgb[1], this->matSpecularReflectances.rgb[2]);

		ID.push_back(glGetUniformLocation(shadingProgram->getProgramID(), "u_matShininess"));
		glUniform1f(ID[10], (GLfloat)this->matShininess);

		ID.push_back(glGetUniformLocation(shadingProgram->getProgramID(), "eye_position"));
		glUniform3f(ID[11], 3.0f, 3.0f, 10.0f);

		ID.push_back(glGetUniformLocation(shadingProgram->getProgramID(), "modelMat"));
		glUniformMatrix4fv(ID[12], 1, GL_FALSE, glm::value_ptr(this->TInverse*this->R*this->S));

		ID.push_back(glGetUniformLocation(shadingProgram->getProgramID(), "modelMatT"));
		glUniformMatrix4fv(ID[13], 1, GL_FALSE, glm::value_ptr(this->T));

	}
	else {
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
		if (this->displayBoundingBox)
			this->localBoundingBox->display(this->TInverse, this->T, this->R, this->S);
	}
	

	for (int i = 0; i < (int)this->faces.size(); i++) {
		if (this->mode == 2) {
			glPolygonMode(GL_FRONT, GL_FILL);
			glColor3fv(this->fillColor.rgb);

			glBegin(type);
			if (!glNormalVertexTypeFlag) 
				pivote = transformVector(transform, this->normalFaces[i]);
			else 
				pivote = transformVector(transform, this->normalVertexes[(int)this->faces[i]->x - 1]);
			
			glNormal3d(pivote[0], pivote[1], pivote[2]);
			pivote = transformVector(transform, this->vertexes[(int)this->faces[i]->x - 1]);
			glVertex3d(pivote[0], pivote[1], pivote[2]);
			

		
			if (!glNormalVertexTypeFlag)
				pivote = transformVector(transform, this->normalFaces[i]);
			else
				pivote = transformVector(transform, this->normalVertexes[(int)this->faces[i]->y - 1]);
			glNormal3d(pivote[0], pivote[1], pivote[2]);
			pivote = transformVector(transform, this->vertexes[(int)this->faces[i]->y - 1]);
			glVertex3d(pivote[0], pivote[1], pivote[2]);

		
			if (!glNormalVertexTypeFlag)
				pivote = transformVector(transform, this->normalFaces[i]);
			else
				pivote = transformVector(transform, this->normalVertexes[(int)this->faces[i]->z - 1]);
			glNormal3d(pivote[0], pivote[1], pivote[2]);
			pivote = transformVector(transform, this->vertexes[(int)this->faces[i]->z - 1]);
			glVertex3d(pivote[0], pivote[1], pivote[2]);

			glEnd();

			if (shadingProgram != NULL) continue;
		}

	
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			if (type == GL_POINTS)
				glPointSize((GLfloat) 4.0f);


			glColor3fv(this->borderColor.rgb);

			glBegin(type);
		
			glNormal3d(this->normalFaces[i]->x, this->normalFaces[i]->y, this->normalFaces[i]->z);
			pivote = transformVector(transform, this->vertexes[(int)this->faces[i]->x - 1]);
			glVertex3d(pivote[0], pivote[1], pivote[2]);

	

			pivote = transformVector(transform, this->vertexes[(int)this->faces[i]->y - 1]);
			glVertex3d(pivote[0], pivote[1], pivote[2]);


			pivote = transformVector(transform, this->vertexes[(int)this->faces[i]->z - 1]);
			glVertex3d(pivote[0], pivote[1], pivote[2]);
			glEnd();
		
	}


	if (shadingProgram != NULL && !this->shadingMode)
		shadingProgram->disable();


	if (this->displayBackfaceCulling) {
		glDisable(GL_NORMALIZE);
		glDisable(GL_CULL_FACE);
	}

	if (this->displayNormal) {
		glBegin(GL_LINES);
		Vertex* Aux = new Vertex();
		glColor3fv(this->normalsColor.rgb);
		for (int i = 0; i < (int)this->vertexes.size(); i++) {
			pivote = transformVector(transform, this->vertexes[i]);
			Aux->x = this->vertexes[i]->x + 1.1*(GLdouble)this->normalVertexes[i]->x;
			Aux->y = this->vertexes[i]->y + 1.1*(GLdouble)this->normalVertexes[i]->y;
			Aux->z = this->vertexes[i]->z + 1.1*(GLdouble)this->normalVertexes[i]->z;
			glVertex3d(pivote[0], pivote[1], pivote[2]); 
			pivote = transformVector(transform, Aux);
			glVertex3d(pivote[0], pivote[1], pivote[2]);
		}
		for (int i = 0; i < (int)this->facesMiddle.size(); i++){
			pivote = transformVector(transform, this->facesMiddle[i]);
			glVertex3d(pivote[0], pivote[1], pivote[2]);
			Aux->x = this->facesMiddle[i]->x + 1.1*(GLdouble)this->normalFaces[i]->x;
			Aux->y = this->facesMiddle[i]->y + 1.1*(GLdouble)this->normalFaces[i]->y;
			Aux->z = this->facesMiddle[i]->z + 1.1*(GLdouble)this->normalFaces[i]->z;
			pivote = transformVector(transform, Aux);
			glVertex3d(pivote[0], pivote[1], pivote[2]);
		}
		delete Aux;
		glEnd();
	}
}

void Model::Notify(string message) {
	if (message == "Activate Flat Shading") {
		this->flatShading = true;
		this->gouraudShading = false;
		this->phongShading = false;
	}else if (message == "Activate Gouraud Shading") {
		this->flatShading = false;
		this->gouraudShading = true;
		this->phongShading = false;
	}else if (message == "Activate Phong Shading") {
		this->flatShading = false;
		this->gouraudShading = false;
		this->phongShading = true;
	}
}

void Model::displayMode(int mode){
	this->mode = mode;
}

void Model::setTranslation(const float x, const float y, const float z){
	this->T[0][3] = x;
	this->T[1][3] = y;
	this->T[2][3] = z;
	this->TInverse[0][3] = -this->getCenter().x;
	this->TInverse[1][3] = -this->getCenter().y;
	this->TInverse[2][3] = -this->getCenter().z;
}

void Model::setRotation(float *quaternion){
	for (int i = 0; i < 4; i++)
		this->Rotation[i] = quaternion[i];

	//First Row
	this->R[0][0] = 1.0f - 2.0f * (quaternion[1] * quaternion[1] + quaternion[2] * quaternion[2]); 
	this->R[0][1] = 2.0f * (quaternion[0] * quaternion[1] - quaternion[3] * quaternion[2]); 
	this->R[0][2] = 2.0f * (quaternion[0] * quaternion[2] + quaternion[3] * quaternion[1]);
	this->R[0][3] = 0.0f;

	//Second Row
	this->R[1][0] = 2.0f * (quaternion[0] * quaternion[1] + quaternion[3] * quaternion[2]);
	this->R[1][1] = 1.0f - 2.0f * (quaternion[0] * quaternion[0] + quaternion[2] * quaternion[2]);
	this->R[1][2] = 2.0f * (quaternion[1] * quaternion[2] - quaternion[3] * quaternion[0]);
	this->R[1][3] = 0.0f;

	//Third Row
	this->R[2][0] = 2.0f * (quaternion[0] * quaternion[2] - quaternion[3] * quaternion[1]);
	this->R[2][1] = 2.0f * (quaternion[1] * quaternion[2] + quaternion[3] * quaternion[0]);
	this->R[2][2] = 1.0f - 2.0f * (quaternion[0] * quaternion[0] + quaternion[1] * quaternion[1]);
	this->R[2][3] = 0.0f;

	//Fourth Row 
	this->R[3][0] = 0.0f;
	this->R[3][1] = 0.0f;
	this->R[3][2] = 0.0f;
	this->R[3][3] = 1.0f;


}

void Model::setScale(float scale){
	this->S[0][0] = scale;
	this->S[1][1] = scale;
	this->S[2][2] = scale;
}

void Model::setScale(float scaleX, float scaleY, float scaleZ){
	this->S[0][0] = scaleX;
	this->S[1][1] = scaleY;
	this->S[2][2] = scaleZ;
}

void Model::setScaleUnique(const int index, const float value){
	this->S[index][index] = value;
}

void Model::setColorBorderColor(float r, float g, float b){
	this->borderColor.setColor(r, g, b);
}

void Model::setColorFillColor(float r, float g, float b){
	this->fillColor.setColor(r, g, b);
}

void Model::setColorBoundingBoxColor(float r, float g, float b){
	this->boundingBoxColor.setColor(r, g, b);
	this->localBoundingBox->setColor(r, g, b);
}

void Model::setNormalsColor(float r, float g, float b){
	this->normalsColor.setColor(r, g, b);
}

void Model::setDisplayBoundingBox(const bool displayBoundingBox){
	this->displayBoundingBox = displayBoundingBox;
}

void Model::setDisplayBackfaceCulling(const bool displayBackFaceCulling){
	this->displayBackfaceCulling = displayBackFaceCulling;
}

void Model::setDisplayNormal(const bool displayNormal){
	this->displayNormal = displayNormal;
}

void Model::setShadingMode(const bool shadingMode){
	this->shadingMode = shadingMode;
}

void Model::setShadingPrograms(CGLSLProgram * Flat, CGLSLProgram * Gouraud, CGLSLProgram * Phong){
	this->flatProgram = Flat;
	this->gouraudProgram = Gouraud;
	this->phongProgram = Phong;
}

void Model::setProjMatrix(glm::mat4x4 Matrix, glm::mat4x4 Model)
{
	this->mProjMatrix = Matrix;
	this->mModelViewMatrix = Model;

}

void Model::setSpeculateIntensity(const float speculateIntensity){
	this->speculateIntensity = speculateIntensity;
}

void Model::setDiffuseIntensity(const float diffuseIntensity){
	this->diffuseIntensity = diffuseIntensity;
}

void Model::setLightAmbientIntensity(const float r, const float g, const float b){
	this->lightAmbientIntensity.setColor(r, g, b);
}

void Model::setLightDiffuseIntensity(const float r, const float g, const float b){
	this->lightDiffuseIntensity.setColor(r, g, b);
}

void Model::setLightSpecularIntensity(const float r, const float g, const float b){
	this->lightSpecularIntensity.setColor(r, g, b);
}

void Model::setMatAmbientReflectances(const float r, const float g, const float b){
	this->matAmbientReflectances.setColor(r, g, b);
}

void Model::setMatDiffuseReflectances(const float r, const float g, const float b){
	this->matDiffuseReflectances.setColor(r, g, b);
}

void Model::setMatSpecularReflectances(const float r, const float g, const float b){
	this->matSpecularReflectances.setColor(r, g, b);
}

void Model::setMatShininess(const float shininess){
	this->matShininess = shininess;
}

void Model::initGLStructure(){
	delete this->glVertexes;
	this->glVertexes = NULL;
	this->glVertexes = new GLfloat[this->vertexes.size() * 3];
	delete this->glNormals;
	this->glNormals = NULL;
	this->glNormals = new GLfloat[this->faces.size() * 3 * 3];
	delete this->glNormalsByVertex;
	this->glNormalsByVertex = NULL;
	this->glNormalsByVertex = new GLfloat[this->vertexes.size() * 3 * 3];

	for (int i = 0, j = 0; j < (int)this->vertexes.size(); i+=3, j++){
		this->glVertexes[i] = (GLfloat)this->vertexes[j]->x;
		this->glVertexes[i+1] = (GLfloat)this->vertexes[j]->y;
		this->glVertexes[i+2] = (GLfloat)this->vertexes[j]->z;

		this->glNormalsByVertex[i] = (GLfloat)this->normalVertexes[j]->x;
		this->glNormalsByVertex[i+1] = (GLfloat)this->normalVertexes[j]->y;
		this->glNormalsByVertex[i+2] = (GLfloat)this->normalVertexes[j]->z;

	}
	
	for (int i = 0, j = 0; j < (int)this->faces.size(); i+=9, j++){
		this->glNormals[i] = (GLfloat)this->normalFaces[j]->x;
		this->glNormals[i + 1] = (GLfloat)this->normalFaces[j]->y;
		this->glNormals[i + 2] = (GLfloat)this->normalFaces[j]->z;
		this->glNormals[i + 3] = (GLfloat)this->normalFaces[j]->x;
		this->glNormals[i + 4] = (GLfloat)this->normalFaces[j]->y;
		this->glNormals[i + 5] = (GLfloat)this->normalFaces[j]->z;
		this->glNormals[i + 6] = (GLfloat)this->normalFaces[j]->x;
		this->glNormals[i + 7] = (GLfloat)this->normalFaces[j]->y;
		this->glNormals[i + 8] = (GLfloat)this->normalFaces[j]->z;
	}
	
}

void Model::sendDataToOpenGL(CGLSLProgram *Program, GLfloat* lightSourceGLvector, glm::vec3 lightPosition, bool glNormalVertexTypeFlag){
	

	
	
	
}

int Model::getMode(){
	return this->mode;
}

float Model::getTranslationX(){
	return (float)this->T[0][3];
}

float Model::getTranslationY() {
	return (float)this->T[1][3];
}

float Model::getTranslationZ() {
	return (float)this->T[2][3];
}

float* Model::getRotation(){
	return this->Rotation;
}

float Model::getScale(){
	return this->S[0][0];
}

int Model::getNumberOfVertexes(){
	return (int)this->vertexes.size();
}

GLfloat * Model::getGLVertexes(){
	return this->glVertexes;
}

GLfloat* Model::getGLNormals(){
	return this->glNormals;
}

GLfloat * Model::getGLNormalsByVertex(){
	return this->glNormalsByVertex;
}

RGB_ Model::getBorderColor(){
	return this->borderColor;
}

RGB_ Model::getBoundingBoxColor(){
	return this->localBoundingBox->getColor();
}

RGB_ Model::getFillColor(){
	return this->fillColor;
}

RGB_ Model::getNormalsColor(){
	return this->normalsColor;
}

RGB_ Model::getLightAmbientIntensity(){
	return this->lightAmbientIntensity;
}

RGB_ Model::getLightDiffuseIntensity(){
	return this->lightAmbientIntensity;
}

RGB_ Model::getLightSpecularIntensity(){
	return this->lightSpecularIntensity;
}

RGB_ Model::getMatAmbientReflectances(){
	return this->matAmbientReflectances;
}

RGB_ Model::getMatDiffuseReflectances(){
	return this->matDiffuseReflectances;
}

RGB_ Model::getMatSpecularReflectances(){
	return this->matSpecularReflectances;
}

glm::tmat4x4<GLfloat> Model::getTInverse(){
	return this->TInverse;
}

glm::tmat4x4<GLfloat> Model::getT(){
	return this->T;
}

glm::tmat4x4<GLfloat> Model::getR(){
	return this->R;
}

glm::tmat4x4<GLfloat> Model::getS(){
	return this->S;
}

float Model::getMatShininess(){
	return this->matShininess;
}

glm::vec3 Model::getCenter(){
	return this->localBoundingBox->getCenter();
}

glm::vec3 Model::getCenter2(){
	return this->localBoundingBox->getCenter2();
}

void Model::setCenterBB(){
	this->localBoundingBox->setCenter(this->TInverse, this->T, this->R, this->S);
}

glm::vec3 Model::getCenter_(){
	return this->localBoundingBox->getCenter_(this->TInverse, this->T, this->R, this->S);
}

glm::mat4x4 Model::getTransform(){
	return this->T*this->R*this->S;
}

void Model::normalCalculate(){
	glm::vec3 p1, p2, p3, pm, v_normal, vertex;

	Vertex *u = new Vertex();
	Vertex *v = new Vertex();
	Vertex *p = new Vertex();
	double norm;
	
	//Vectores normales para las caras
	this->normalFaces.clear();
	this->facesMiddle.clear();
	for (int i = 0; i < (int)this->faces.size(); i++){
		p1 = transformVector_(this->vertexes[(int)this->faces[i]->x - 1]);
		p2 = transformVector_(this->vertexes[(int)this->faces[i]->y - 1]);
		p3 = transformVector_(this->vertexes[(int)this->faces[i]->z - 1]);

		v_normal = glm::normalize(glm::cross(p2 - p1, p3 - p1));

		//Normalizamos - vector unitario
		this->normalFaces.push_back(new Vertex(v_normal.x, v_normal.y, v_normal.z));

		p1.x = this->vertexes[(int)this->faces[i]->x - 1]->x;
		p1.y = this->vertexes[(int)this->faces[i]->x - 1]->y;
		p1.z = this->vertexes[(int)this->faces[i]->x - 1]->z;

		p2.x = this->vertexes[(int)this->faces[i]->y - 1]->x;
		p2.y = this->vertexes[(int)this->faces[i]->y - 1]->y;
		p2.z = this->vertexes[(int)this->faces[i]->y - 1]->z;

		p3.x = this->vertexes[(int)this->faces[i]->z - 1]->x;
		p3.y = this->vertexes[(int)this->faces[i]->z - 1]->y;
		p3.z = this->vertexes[(int)this->faces[i]->z - 1]->z;

		//Calculamos el punto Medio para poder desplegar las normales por cara
		pm = (p1 + p2 + p3) / 3.0f;
		this->facesMiddle.push_back(new Vertex(pm[0], pm[1], pm[2]));
		
	}


	int n = 0;
	this->normalVertexes.clear();
	for (int i = 0; i < (int)this->vertexes.size(); i++){
		n = 0;
		p = new Vertex(0.0f, 0.0f, 0.0f);
		for (int j = 0; j < (int)this->faces.size(); j++)
			if ((int)(this->faces[j]->x - 1.0) == i || (int)(this->faces[j]->y - 1.0) == i || (int)(this->faces[j]->z - 1.0) == i) {
				p->x += this->normalFaces[j]->x;
				p->y += this->normalFaces[j]->y;
				p->z += this->normalFaces[j]->z;
				n++;
			}
		p->x /= (double)n;
		p->y /= (double)n;
		p->z /= (double)n;

		norm = pow(p->x*p->x + p->y*p->y + p->z*p->z, 0.5);
		p->x /= norm;
		p->y /= norm;
		p->z /= norm;
		this->normalVertexes.push_back(p);
	}
}

void Model::escalar(){
	glm::vec4 pivote;


	for (int i = 0; i < (int)this->vertexes.size(); i++){
		this->vertexes[i]->x = this->vertexes[i]->x*1.0 / this->max;
		this->vertexes[i]->y = this->vertexes[i]->y*1.0 / this->max;
		this->vertexes[i]->z = this->vertexes[i]->z*1.0 / this->max;

	}
}

void Model::escalarBoundingBox(){
	this->localBoundingBox->escalar(this->max);
}

void Model::normalizar(Vertex * vertex){
	double norm;
	norm = pow(vertex->x*vertex->x + vertex->y*vertex->y + vertex->z*vertex->z, 0.5);
	vertex->x /= norm;
	vertex->y /= norm;
	vertex->z /= norm;
	return;
}

glm::vec4 Model::product(glm::mat4x4 transform, glm::vec4 pivote){
	glm::vec4 vertex;
	vertex[0] = transform[0][0] * pivote[0] + transform[0][1] * pivote[1] + transform[0][2] * pivote[2] + transform[0][3] * pivote[3];
	vertex[1] = transform[1][0] * pivote[0] + transform[1][1] * pivote[1] + transform[1][2] * pivote[2] + transform[1][3] * pivote[3];
	vertex[2] = transform[2][0] * pivote[0] + transform[2][1] * pivote[1] + transform[2][2] * pivote[2] + transform[2][3] * pivote[3];
	return vertex;
}

glm::tvec4<GLdouble> Model::transformVector(glm::tmat4x4<GLdouble> transform_, Vertex * vector) {
	this->TInverse = glm::mat4(1.0f);
	glm::tvec4<GLdouble> vertex, v;
	this->TInverse[0][3] = -this->localBoundingBox->getCenter().x;
	this->TInverse[1][3] = -this->localBoundingBox->getCenter().y;
	this->TInverse[2][3] = -this->localBoundingBox->getCenter().z;

	glm::mat4x4 transformInverse = this->TInverse*this->R*this->S;
	vertex.x = transformInverse[0][0] * (GLdouble)vector->x + transformInverse[0][1] * (GLdouble)vector->y + transformInverse[0][2] * (GLdouble)vector->z + transformInverse[0][3] * (GLdouble)1.0f;
	vertex.y = transformInverse[1][0] * (GLdouble)vector->x + transformInverse[1][1] * (GLdouble)vector->y + transformInverse[1][2] * (GLdouble)vector->z + transformInverse[1][3] * (GLdouble)1.0f;
	vertex.z = transformInverse[2][0] * (GLdouble)vector->x + transformInverse[2][1] * (GLdouble)vector->y + transformInverse[2][2] * (GLdouble)vector->z + transformInverse[2][3] * (GLdouble)1.0f;

	glm::mat4x4 transform = this->T;
	v.x = transform[0][0] * vertex.x + transform[0][1] * vertex.y + transform[0][2] * vertex.z + transform[0][3] * (GLdouble)1.0f;
	v.y = transform[1][0] * vertex.x + transform[1][1] * vertex.y + transform[1][2] * vertex.z + transform[1][3] * (GLdouble)1.0f;
	v.z = transform[2][0] * vertex.x + transform[2][1] * vertex.y + transform[2][2] * vertex.z + transform[2][3] * (GLdouble)1.0f;
	v.w = (GLdouble)1.0f;

	return v;
}

glm::vec3 Model::transformVector_(Vertex * vector){
	glm::vec3 vertex;
	glm::mat4x4 transformInverse = this->TInverse*this->R*this->S;
	vertex.x = transformInverse[0][0] * (GLdouble)vector->x + transformInverse[0][1] * (GLdouble)vector->y + transformInverse[0][2] * (GLdouble)vector->z + transformInverse[0][3] * (GLdouble)1.0f;
	vertex.y = transformInverse[1][0] * (GLdouble)vector->x + transformInverse[1][1] * (GLdouble)vector->y + transformInverse[1][2] * (GLdouble)vector->z + transformInverse[1][3] * (GLdouble)1.0f;
	vertex.z = transformInverse[2][0] * (GLdouble)vector->x + transformInverse[2][1] * (GLdouble)vector->y + transformInverse[2][2] * (GLdouble)vector->z + transformInverse[2][3] * (GLdouble)1.0f;
	return vertex;
}

glm::vec3 Model::transformVector__(glm::vec3 vertex){
	glm::vec3 v;
	v.x = this->T[0][0] * vertex.x + this->T[0][1] * vertex.y + this->T[0][2] * vertex.z + this->T[0][3];
	v.y = this->T[1][0] * vertex.x + this->T[1][1] * vertex.y + this->T[1][2] * vertex.z + this->T[1][3];
	v.z = this->T[2][0] * vertex.x + this->T[2][1] * vertex.y + this->T[2][2] * vertex.z + this->T[2][3];
	return v;
}

glm::vec4 Model::__transformVector__(glm::mat4 & transformInverse, Vertex * vector){
	glm::vec4 vertex;
	vertex.x = transformInverse[0][0] * (GLdouble)vector->x + transformInverse[0][1] * (GLdouble)vector->y + transformInverse[0][2] * (GLdouble)vector->z + transformInverse[0][3] * (GLdouble)1.0f;
	vertex.y = transformInverse[1][0] * (GLdouble)vector->x + transformInverse[1][1] * (GLdouble)vector->y + transformInverse[1][2] * (GLdouble)vector->z + transformInverse[1][3] * (GLdouble)1.0f;
	vertex.z = transformInverse[2][0] * (GLdouble)vector->x + transformInverse[2][1] * (GLdouble)vector->y + transformInverse[2][2] * (GLdouble)vector->z + transformInverse[2][3] * (GLdouble)1.0f;
	return vertex;
}*/



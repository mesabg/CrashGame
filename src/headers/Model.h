#pragma once
#ifndef __MODEL_H_
#define __MODEL_H_

#include <Mediator_Colleague.h>

class Model : public Colleague{
protected:
	vector<Vertex*> vertexes;
	GLfloat *glVertexes;
	GLfloat *glNormals;
	GLfloat *glNormalsByVertex;
	vector<Vertex*> faces;
	vector<Vertex*> normalVertexes;
	vector<Vertex*> normalFaces;
	vector<Vertex*> facesMiddle;
	glm::tmat4x4<GLfloat> T, R, S;
	glm::tmat4x4<GLfloat> TInverse;
	float Rotation[4];
	float speculateIntensity, diffuseIntensity;
	bool shadingMode;
	int mode;
	BoundingBox* localBoundingBox;
	bool displayBoundingBox, displayBackfaceCulling, displayNormal;
	RGB_ borderColor, boundingBoxColor, fillColor, normalsColor;
	RGB_ lightAmbientIntensity, lightDiffuseIntensity, lightSpecularIntensity;
	RGB_ matAmbientReflectances, matDiffuseReflectances, matSpecularReflectances;
	float matShininess;
	double max;
	bool flatShading, gouraudShading, phongShading;
	CGLSLProgram *flatProgram;
	CGLSLProgram *gouraudProgram;
	CGLSLProgram *phongProgram;
	glm::mat4 mProjMatrix, mModelViewMatrix;
	glm::mat4 projection;
	glm::mat4 modelView;
	glm::mat4 normalMatrix;
public:
	Model(Mediator* mediator);
	~Model();
	virtual void loadModel(string message) = 0;
	void display(bool glDepth, CGLSLProgram* shadingProgram, GLfloat* lightSourceGLvector, glm::vec3 luzCentro, bool glNormalVertexTypeFlag);
	void Notify(string message);
	void displayMode(int mode);
	void setTranslation(const float x, const float y, const float z);
	void setRotation(float* quaternion);
	void setScale(float scale);
	void setScale(float scaleX, float scaleY, float scaleZ);
	void setScaleUnique(const int index, const float value);
	void setColorBorderColor(float r, float g, float b);
	void setColorFillColor(float r, float g, float b);
	void setColorBoundingBoxColor(float r, float g, float b);
	void setNormalsColor(float r, float g, float b);
	void setDisplayBoundingBox(const bool displayBoundingBox);
	void setDisplayBackfaceCulling(const bool displayBackFaceCulling);
	void setDisplayNormal(const bool displayNormal);
	void setShadingMode(const bool shadingMode);
	void setShadingPrograms(CGLSLProgram *Flat, CGLSLProgram *Gouraud, CGLSLProgram *Phong);
	void setProjMatrix(glm::mat4x4 Matrix, glm::mat4x4 Model);
	void setSpeculateIntensity(const float speculateIntensity);
	void setDiffuseIntensity(const float diffuseIntensity);
	void setLightAmbientIntensity(const float r, const float g, const float b);
	void setLightDiffuseIntensity(const float r, const float g, const float b);
	void setLightSpecularIntensity(const float r, const float g, const float b);
	void setMatAmbientReflectances(const float r, const float g, const float b);
	void setMatDiffuseReflectances(const float r, const float g, const float b);
	void setMatSpecularReflectances(const float r, const float g, const float b);
	void setMatShininess(const float shininess);
	void initGLStructure();
	void sendDataToOpenGL(CGLSLProgram *Program, GLfloat* lightSourceGLvector, glm::vec3 luzCentro, bool glNormalVertexTypeFlag);
	int getMode();
	float getTranslationX();
	float getTranslationY();
	float getTranslationZ();
	float* getRotation();
	float getScale();
	int getNumberOfVertexes();
	GLfloat* getGLVertexes();
	GLfloat* getGLNormals();
	GLfloat* getGLNormalsByVertex();
	RGB_ getBorderColor();
	RGB_ getBoundingBoxColor();
	RGB_ getFillColor();
	RGB_ getNormalsColor();
	RGB_ getLightAmbientIntensity();
	RGB_ getLightDiffuseIntensity();
	RGB_ getLightSpecularIntensity();
	RGB_ getMatAmbientReflectances();
	RGB_ getMatDiffuseReflectances();
	RGB_ getMatSpecularReflectances();
	glm::mat4x4 getTInverse();
	glm::mat4x4 getT();
	glm::mat4x4 getR();
	glm::mat4x4 getS();
	float getMatShininess();
	glm::vec3 getCenter();
	glm::vec3 getCenter2();
	void setCenterBB();
	glm::vec3 getCenter_();
	glm::mat4x4 getTransform();
	void normalCalculate();
	void escalar();
	void escalarBoundingBox();
	void normalizar(Vertex* vertex);
	glm::vec4 product(glm::mat4x4 transform, glm::vec4 pivote);
	glm::tvec4<GLdouble> transformVector(glm::tmat4x4<GLdouble> transform, Vertex* vector);
	glm::vec3 transformVector_(Vertex* vector);
	glm::vec3 transformVector__(glm::vec3 vector);
	glm::vec4 __transformVector__(glm::mat4 &matrix, Vertex* vector);
};

#endif

#pragma once
#ifndef __SIDE_BAR_H_
#define __SIDE_BAR_H_

#include <Mediator_Colleague.h>
#include <AntTweakBar.h>
#include <Model.h>

class SideBar : public Colleague {
private:
	static SideBar *uniqueSideBar;
	float TranslationSpeedX, TranslationSpeedY, TranslationSpeedZ;
	float Scale, ScaleX, ScaleY, ScaleZ, Rotation[4], aux[4];
	TwBar *principalBar;
	TwBar *modelPropertiesBar;
	Model* localModel;
	float borderColor[3], boundingBoxColor[3], fillColor[3], normalVectorsColor[3], selectedModel;
	float speculateIntensity, diffuseIntensity;
	float lightAmbientIntensity[3], lightDiffuseIntensity[3], lightSpecularIntensity[3];
	float matAmbientReflectances[3], matDiffuseReflectances[3], matSpecularReflectances[3], matShininess;
	int modelMode, nModels;
	bool displayBoundingBox, displayBackfaceCulling, displayNormal;
	bool flatShading, gouraudShading, phongShading;
	SideBar(Mediator* mediator);
	~SideBar();
	void show();
	void hide();
public:
	static SideBar* Instance(Mediator* mediator);
	void Notify(string message);
	void reshape(int gWidth, int gHeight);
	void setSelectedModel(Model* model);
	void addModel();
	void update();
	float* getFillColor();

	/*Callbacks*/
	void loadFileCall();
	void selectModelCall();
	void modelPointsCall();
	void modelMeshCall();
	void modelFilledPolygonsCall();
	void normalVectorsCall();
	void boundingBoxCall();
	void backFaceCullingCall();
	void ZBufferCall();
	void perspectiveCall();
	void orthogonalXCall();
	void orthogonalYCall();
	void orthogonalZCall();
	void flatShadingCall();
	void gouraudShadingCall();
	void phongShadingCall();
};



/*Callbacks*/
void TW_CALL loadCallback(void *clientData);
void TW_CALL selectModelCallback(void *clientData);
void TW_CALL modelPointsCallback(void *clientData);
void TW_CALL modelMeshCallback(void *clientData);
void TW_CALL modelFilledPolygonsCallback(void *clientData);
void TW_CALL normalVectorsCallback(void *clientData);
void TW_CALL boundingBoxCallback(void *clientData);
void TW_CALL backFaceCullingCallback(void *clientData);
void TW_CALL ZBufferCallback(void *clientData);
void TW_CALL perspectiveCallback(void *clientData);
void TW_CALL orthogonalXCallback(void *clientData);
void TW_CALL orthogonalYCallback(void *clientData);
void TW_CALL orthogonalZCallback(void *clientData);
void TW_CALL flatShadingCallback(void *clientData);
void TW_CALL gouraudShadingCallback(void *clientData);
void TW_CALL phongShadingCallback(void *clientData);

#endif

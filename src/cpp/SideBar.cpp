#include <SideBar.h>
#include <iostream>

SideBar* SideBar::uniqueSideBar = NULL;

SideBar::SideBar(Mediator* mediator):Colleague(mediator) {
	//Variables
	this->Scale = this->ScaleX = this->ScaleY = this->ScaleZ = aux[0] = aux[1] = aux[2] = aux[3]= 1.0f;
	for (int i = 0; i < 3; i++){
		this->boundingBoxColor[i] = 0.0f;
		this->borderColor[i] = 0.0f;
		this->fillColor[i] = 0.0f;
		this->normalVectorsColor[i] = 0.0f;
		this->lightAmbientIntensity[i] = RGB_::make_rgb(0.5f, 0.5f, 0.0f).rgb[i];
		this->lightDiffuseIntensity[i] = RGB_::make_rgb(1.0f, 0.5f, 0.0f).rgb[i];
		this->lightSpecularIntensity[i] = RGB_::make_rgb(0.0f, 1.0f, 0.0f).rgb[i];
		this->matAmbientReflectances[i] = 1.0f;
		this->matDiffuseReflectances[i] = 1.0f;
		this->matSpecularReflectances[i] = 1.0f;
	}
	this->TranslationSpeedX = this->TranslationSpeedY = this->TranslationSpeedZ = 0.0f;
	this->selectedModel = -1.0f;
	this->displayBoundingBox = true;
	this->displayBackfaceCulling = false;
	this->displayNormal = false;
	this->Rotation[0] = 0.0f;
	this->Rotation[1] = 0.0f;
	this->Rotation[2] = 0.0f;
	this->Rotation[3] = 1.0f;

	this->modelMode = 1;
	this->nModels = 0;

	this->flatShading = false;
	this->gouraudShading = false;
	this->phongShading = false;

	this->speculateIntensity = 0.5f;
	this->diffuseIntensity = 0.5;

	this->matShininess = 15.0f;

	// Adding the button options 
	this->principalBar = TwNewBar("Principal");
	TwDefine("Principal refresh = '0.0001f'");
	TwDefine("Principal resizable = false");
	TwDefine("Principal fontresizable = false");
	TwDefine("Principal movable = false");
	TwDefine("Principal visible = true");
	TwDefine("Principal position = '20 20'");
	TwDefine("Principal size = '280 130'");

	TwAddButton(this->principalBar, "Load", loadCallback, (void*)this, " label='Load model' ");
	TwAddSeparator(this->principalBar, "OptionsSeparator1", "");
	/*Combo Box*/
	TwAddVarRW(this->principalBar, "ModelSelect", TW_TYPE_FLOAT, &this->selectedModel, " min=-1 max=-1 step=1 group='Select a model' label='Model index' ");
	TwAddButton(this->principalBar, "Select", selectModelCallback, (void*)this, " group='Select a model' label='Select' ");

	// Addding the figure properties 
	this->modelPropertiesBar = TwNewBar("Model");
	TwDefine("Model visible = false");

	TwDefine("Model refresh = '0.0001f'");
	TwDefine("Model resizable = false");
	TwDefine("Model fontresizable = false");
	TwDefine("Model movable = false");
	TwDefine("Model visible = true");
	TwDefine("Model position = '20 20'");
	TwDefine("Model size = '280 850'");

	/*Display Mode*/
	TwAddButton(this->modelPropertiesBar, "ModelPoints", modelPointsCallback, (void*)this, " label='Points' group='Display mode' help='Display the model in points' ");
	TwAddButton(this->modelPropertiesBar, "ModelMesh", modelMeshCallback, (void*)this, " label='Mesh' group='Display mode' help='Display the model in mesh' ");
	TwAddButton(this->modelPropertiesBar, "ModelFilledPolygons", modelFilledPolygonsCallback, (void*)this, " label='Filled' group='Display mode' help='Display the model with filled polygons' ");

	/*Projection Mode*/
	TwAddButton(this->modelPropertiesBar, "Perspective", perspectiveCallback, (void*)this, " label='Perspective' group='Projection' help='Display the model in perspective projection.' ");
	TwAddButton(this->modelPropertiesBar, "Orthogonal", orthogonalXCallback, (void*)this, " label='Orthogonal' group='Projection' help='Display the model orthogonal' ");

	/*Transforms*/
	TwAddVarRW(this->modelPropertiesBar, "TranslationSpeedX", TW_TYPE_FLOAT, &this->TranslationSpeedX, " min=-10000 max=10000 step=0.01 group='Translation' label='Translation factor X' ");
	TwAddVarRW(this->modelPropertiesBar, "TranslationSpeedY", TW_TYPE_FLOAT, &this->TranslationSpeedY, " min=-10000 max=10000 step=0.01 group='Translation' label='Translation factor Y' ");
	TwAddVarRW(this->modelPropertiesBar, "TranslationSpeedZ", TW_TYPE_FLOAT, &this->TranslationSpeedZ, " min=-10000 max=10000 step=0.01 group='Translation' label='Translation factor Z' ");
	TwAddVarRW(this->modelPropertiesBar, "Rotation", TW_TYPE_QUAT4F, &this->Rotation, " label='Rotation' opened=true help='Change the model orientation.' ");
	TwAddVarRW(this->modelPropertiesBar, "ScaleAll", TW_TYPE_FLOAT, &this->Scale, " min=0.0 max=100000.0 step=0.01 group='Scale' label='Scale All'  ");
	TwAddVarRW(this->modelPropertiesBar, "ScaleX", TW_TYPE_FLOAT, &this->ScaleX, " min=0.0 max=100000.0 step=0.01 group='Scale' label='Scale X' ");
	TwAddVarRW(this->modelPropertiesBar, "ScaleY", TW_TYPE_FLOAT, &this->ScaleY, " min=0.0 max=100000.0 step=0.01 group='Scale' label='Scale Y' ");
	TwAddVarRW(this->modelPropertiesBar, "ScaleZ", TW_TYPE_FLOAT, &this->ScaleZ, " min=0.0 max=100000.0 step=0.01 group='Scale' label='Scale Z' ");
	TwDefine(" Model/Translation group=Transforms help='Change the model translations.'");
	TwDefine(" Model/Transforms help='Apply transforms to the selected model.' ");
	TwDefine(" Model/Rotation group=Transforms ");
	TwDefine(" Model/Scale group=Transforms help='Change the model scale.' ");

	/*Show Options*/
	TwAddButton(this->modelPropertiesBar, "NormalVectors",normalVectorsCallback, (void*)this, " label='Normal Vectors' group='Show' help='Show the model normal vectors'");
	TwAddButton(this->modelPropertiesBar, "BoundingBox", boundingBoxCallback, (void*)this, " label='Bounding Box' group='Show' help='Show the model bounding box' ");
	TwAddButton(this->modelPropertiesBar, "BackfaceCulling", backFaceCullingCallback, (void*)this, " label='Backface Culling' group='Show' help='Activate backface culling' ");
	TwAddButton(this->modelPropertiesBar, "ZBuffer", ZBufferCallback, (void*)this, " label='Z-Buffer' group='Show' help='Activate Z-Buffer' ");

	/*Shading Model*/
	TwAddButton(this->modelPropertiesBar, "FlatShading", flatShadingCallback, (void*)this, " label='Flat' group='Shading' help='Activate flat shading model.' ");
	TwAddButton(this->modelPropertiesBar, "GouraudShading", gouraudShadingCallback, (void*)this, " label='Gouraud' group='Shading' help='Activate gouraud shading model.' ");
	TwAddButton(this->modelPropertiesBar, "PhongShading", phongShadingCallback, (void*)this, " label='Phong' group='Shading' help='Activate phong model.' ");

	/*Colors*/
	TwAddVarRW(this->modelPropertiesBar, "BorderColor", TW_TYPE_COLOR3F, &this->borderColor, "group='Color' label='Border' opened=true help='Change the model border color.' ");
	TwAddVarRW(this->modelPropertiesBar, "FillColor", TW_TYPE_COLOR3F, &this->fillColor, "group='Color' label='Fill' opened=true help='Change the model fill color.' ");
	TwAddVarRW(this->modelPropertiesBar, "NormalVectorsColor", TW_TYPE_COLOR3F, &this->normalVectorsColor, "group='Color' label='Normal Vectors' opened=true help='Change the model normal vectors color.' ");
	TwAddVarRW(this->modelPropertiesBar, "BoundingBoxColor", TW_TYPE_COLOR3F, &this->boundingBoxColor, "group='Color' label='Bounding Box' opened=true help='Change the model bounding box color.' ");

	/*Lighting Factors*/
	/*Parameters of light*/
	TwAddVarRW(this->modelPropertiesBar, "LightAmbientIntensity", TW_TYPE_COLOR3F, &this->lightAmbientIntensity, "group='Light' label='Ambient Intensity' opened=true help='Change the light ambient intensity.' ");
	TwAddVarRW(this->modelPropertiesBar, "LightDiffuseIntensity", TW_TYPE_COLOR3F, &this->lightDiffuseIntensity, "group='Light' label='Diffuse Intensity' opened=true help='Change the light diffuse intensity.' ");
	TwAddVarRW(this->modelPropertiesBar, "LightSpecularIntensity", TW_TYPE_COLOR3F, &this->lightSpecularIntensity, "group='Light' label='Specular Intensity' opened=true help='Change the light specular intensity.' ");

	/*Material parameters*/
	TwAddVarRW(this->modelPropertiesBar, "MatAmbientReflectances", TW_TYPE_COLOR3F, &this->matAmbientReflectances, "group='Material' label='Ambient Reflectances' opened=true help='Change the material ambient reflectances.' ");
	TwAddVarRW(this->modelPropertiesBar, "MatDiffuseReflectances", TW_TYPE_COLOR3F, &this->matDiffuseReflectances, "group='Material' label='Diffuse Reflectances' opened=true help='Change the material diffuse reflectances.' ");
	TwAddVarRW(this->modelPropertiesBar, "MatSpecularReflectances", TW_TYPE_COLOR3F, &this->matSpecularReflectances, "group='Material' label='Specular Reflactances' opened=true help='Change the material specular reflectances.' ");
	TwAddVarRW(this->modelPropertiesBar, "MatShininess", TW_TYPE_FLOAT, &this->matShininess, " min=0.0 max=100.0 step=0.1 group='Material' label='Shininess factor' help='Change the shininess factor.'");

	/*
	ir a :: http://www.ite.educacion.es/formacion/materiales/181/cd/m6/difuso_y_especular.html
	*/
}

SideBar::~SideBar() {}

void SideBar::show(){
	TwDefine("Principal visible = true");
	TwDefine("Model visible = false");
}

void SideBar::hide(){
	TwDefine("Principal visible = false");
	TwDefine("Model visible = true");

	if (this->flatShading || this->gouraudShading || this->phongShading) {
		/*Show light and material parameters*/
		TwDefine("Model/Light visible = true");
		TwDefine("Model/Material visible = true");

		/*Setting Titles*/
		TwDefine("Model/FillColor label='Model color' visible = false");
		TwDefine("Model/BorderColor visible = false");
	} else {
		/*Hide light and material parameters*/
		TwDefine("Model/Light visible = false");
		TwDefine("Model/Material visible = false");

		/*Setting Titles*/
		TwDefine("Model/FillColor label='Border' visible = true");
		TwDefine("Model/BorderColor visible = true");
	}

	if (this->modelMode == 0) {
		TwDefine("Model/ModelPoints readonly=true");
		TwDefine("Model/ModelMesh readonly=false");
		TwDefine("Model/ModelFilledPolygons readonly=false");
	} else if (this->modelMode == 1) {
		TwDefine("Model/ModelPoints readonly=false");
		TwDefine("Model/ModelMesh readonly=true");
		TwDefine("Model/ModelFilledPolygons readonly=false");
	} else {
		TwDefine("Model/ModelPoints readonly=false");
		TwDefine("Model/ModelMesh readonly=false");
		TwDefine("Model/ModelFilledPolygons readonly=true");
	}

	/*
	float lightAmbientIntensity[3], lightDiffuseIntensity[3], lightSpecularIntensity[3];
	float matAmbientReflectances[3], matDiffuseReflectances[3], matSpecularReflectances[3], matShininess;
	*/

	this->localModel->setTranslation(this->TranslationSpeedX, this->TranslationSpeedY, this->TranslationSpeedZ);
	this->localModel->setRotation(this->Rotation);

	this->localModel->setColorBorderColor(this->borderColor[0], this->borderColor[1], this->borderColor[2]);
	this->localModel->setColorFillColor(this->fillColor[0], this->fillColor[1], this->fillColor[2]);
	this->localModel->setColorBoundingBoxColor(this->boundingBoxColor[0], this->boundingBoxColor[1], this->boundingBoxColor[2]);
	this->localModel->setNormalsColor(this->normalVectorsColor[0], this->normalVectorsColor[1], this->normalVectorsColor[2]);
	this->localModel->setLightAmbientIntensity(this->lightAmbientIntensity[0], this->lightAmbientIntensity[1], this->lightAmbientIntensity[2]);
	this->localModel->setLightDiffuseIntensity(this->lightDiffuseIntensity[0], this->lightDiffuseIntensity[1], this->lightDiffuseIntensity[2]);
	this->localModel->setLightSpecularIntensity(this->lightSpecularIntensity[0], this->lightSpecularIntensity[1], this->lightSpecularIntensity[2]);
	this->localModel->setMatAmbientReflectances(this->matAmbientReflectances[0], this->matAmbientReflectances[1], this->matAmbientReflectances[2]);
	this->localModel->setMatDiffuseReflectances(this->matDiffuseReflectances[0], this->matDiffuseReflectances[1], this->matDiffuseReflectances[2]);
	this->localModel->setMatSpecularReflectances(this->matSpecularReflectances[0], this->matSpecularReflectances[1], this->matSpecularReflectances[2]);
	this->localModel->setMatShininess(this->matShininess);
	

		if (aux[0] != this->Scale) {
			aux[0] = this->Scale;
			this->ScaleX = this->Scale;
			this->ScaleY = this->Scale;
			this->ScaleZ = this->Scale;
			aux[1] = this->Scale;
			aux[2] = this->Scale;
			aux[3] = this->Scale;
			this->localModel->setScale(this->Scale);
		}
		else if (aux[1]!= this->ScaleX) {
			aux[1] = this->ScaleX;
			this->localModel->setScaleUnique(0, this->ScaleX);		
		}
		else if (aux[2] != this->ScaleY) {
			aux[2] = this->ScaleY;
			this->localModel->setScaleUnique(1, this->ScaleY);
		}
		else if (aux[3] != this->ScaleZ) {
			aux[3] = this->ScaleZ;
			this->localModel->setScaleUnique(2, this->ScaleZ);
		}

	/*this->localModel->setScaleUnique(0, this->ScaleX);
	this->localModel->setScaleUnique(1, this->ScaleY);
	this->localModel->setScaleUnique(2, this->ScaleZ);*/
	//this->localModel->setScale(this->Scale);
	
	this->mediator->Send("Set GL Color", this);
}

SideBar* SideBar::Instance(Mediator* mediator){
	if (!uniqueSideBar)
		uniqueSideBar = new SideBar(mediator);
	return uniqueSideBar;
}

void SideBar::Notify(string message) {
	if (message == "Desseleccionar") {
		this->displayBoundingBox = false;
		this->localModel->setDisplayBoundingBox(false);
	}
}

void SideBar::reshape(int gWidth, int gHeight){
	TwWindowSize(gWidth, gHeight);
}

void SideBar::setSelectedModel(Model * model){
	this->localModel = model;
	this->TranslationSpeedX = this->localModel->getTranslationX();
	this->TranslationSpeedY = this->localModel->getTranslationY();
	this->TranslationSpeedZ = this->localModel->getTranslationZ();
	this->Scale = this->localModel->getScale();
	for (int i = 0; i < 4; i++)
		this->Rotation[i] = this->localModel->getRotation()[i];
	for (int i = 0; i < 3; i++){
		this->borderColor[i] = this->localModel->getBorderColor().rgb[i];
		this->boundingBoxColor[i] = this->localModel->getBoundingBoxColor().rgb[i];
		this->fillColor[i] = this->localModel->getFillColor().rgb[i];
		this->normalVectorsColor[i] = this->localModel->getNormalsColor().rgb[i];
		this->lightAmbientIntensity[i] = this->localModel->getLightAmbientIntensity().rgb[i]; 
		this->lightDiffuseIntensity[i] = this->localModel->getLightDiffuseIntensity().rgb[i];
		this->lightSpecularIntensity[i] = this->localModel->getLightSpecularIntensity().rgb[i];
		this->matAmbientReflectances[i] =  this->localModel->getMatAmbientReflectances().rgb[i]; 
		this->matDiffuseReflectances[i] = this->localModel->getMatDiffuseReflectances().rgb[i];
		this->matSpecularReflectances[i] = this->localModel->getMatSpecularReflectances().rgb[i]; 
	}
	this->matShininess = this->localModel->getMatShininess();
	this->modelMode = this->localModel->getMode();
}

void SideBar::addModel(){
	this->nModels++;
	this->selectedModel = (float)(this->nModels - 1);
	TwDefine(("Principal/ModelSelect min=0 max=" + std::to_string(this->nModels-1)).c_str());
}

void SideBar::update(){
	TwDraw();
	/*Condicional, decidir si hide o si show*/
	if (this->mediator->getSelectedIndex() == -1) show();
	else hide();
}

float * SideBar::getFillColor(){
	return this->fillColor;
}


/*Local Callbacks*/
void SideBar::loadFileCall() {
	this->mediator->Send("Load File", this);
}

void SideBar::selectModelCall() {
	if ((int)this->selectedModel == -1) return;
	this->mediator->SelectModel((int)this->selectedModel, this);
	this->displayBoundingBox = true;
	this->localModel->setDisplayBoundingBox(true);
}

void SideBar::modelPointsCall(){
	this->localModel->displayMode(0);
	this->modelMode = 0;
}

void SideBar::modelMeshCall(){
	this->localModel->displayMode(1);
	this->modelMode = 1;
}

void SideBar::modelFilledPolygonsCall(){
	this->localModel->displayMode(2);
	this->modelMode = 2;
}

void SideBar::normalVectorsCall(){
	this->displayNormal = !this->displayNormal;
	this->localModel->setDisplayNormal(this->displayNormal);
}

void SideBar::boundingBoxCall(){
	this->displayBoundingBox = !this->displayBoundingBox;
	this->localModel->setDisplayBoundingBox(this->displayBoundingBox);
}

void SideBar::backFaceCullingCall(){
	this->displayBackfaceCulling = !this->displayBackfaceCulling;
	this->localModel->setDisplayBackfaceCulling(this->displayBackfaceCulling);
}

void SideBar::ZBufferCall(){
	this->mediator->Send("ActiveGLDepth", this);
}

void SideBar::perspectiveCall(){
	this->mediator->Send("Perspective", this);
}

void SideBar::orthogonalXCall(){
	this->mediator->Send("OrtogonalX", this);
}

void SideBar::orthogonalYCall(){
	this->mediator->Send("OrtogonalY", this);
}

void SideBar::orthogonalZCall(){
	this->mediator->Send("OrtogonalZ", this);
}

void SideBar::flatShadingCall() {
	this->gouraudShading = false;
	this->phongShading = false;
	this->matShininess = this->localModel->getMatShininess();
	this->flatShading = !this->flatShading;
	if (this->flatShading) {
		this->mediator->Send("Activate Flat Shading", this);
		/*Activate Fill Mode*/
		this->localModel->displayMode(2);
		this->modelMode = 2;

		/*Activate Backface Culling*/
		this->displayBackfaceCulling = true;
		this->localModel->setDisplayBackfaceCulling(this->displayBackfaceCulling);

		/*Activate Z-Buffer*/
		this->mediator->Send("ActiveGLDepth_", this);

		/*Deavtivate Bounding box*/
		this->displayBoundingBox = false;
		this->localModel->setDisplayBoundingBox(this->displayBoundingBox);
	}
	else 
		this->mediator->Send("Deactivate Flat Shading", this);
}

void SideBar::gouraudShadingCall(){
	this->flatShading = false;
	this->phongShading = false;
	this->matShininess = this->localModel->getMatShininess();
	this->gouraudShading = !this->gouraudShading;
	if (this->gouraudShading) {
		this->mediator->Send("Activate Gouraud Shading", this);
		/*Activate Fill Mode*/
		this->localModel->displayMode(2);
		this->modelMode = 2;

		/*Activate Backface Culling*/
		this->displayBackfaceCulling = true;
		this->localModel->setDisplayBackfaceCulling(this->displayBackfaceCulling);

		/*Activate Z-Buffer*/
		this->mediator->Send("ActiveGLDepth_", this);

		/*Deavtivate Bounding box*/
		this->displayBoundingBox = false;
		this->localModel->setDisplayBoundingBox(this->displayBoundingBox);
	}
	else
		this->mediator->Send("Deactivate Gouraud Shading", this);
}

void SideBar::phongShadingCall(){
	this->phongShading = !this->phongShading;
	if (this->phongShading) {
		this->mediator->Send("Activate Phong Shading", this);
		/*Activate Fill Mode*/
		this->localModel->displayMode(2);
		this->modelMode = 2;

		/*Activate Backface Culling*/
		this->displayBackfaceCulling = true;
		this->localModel->setDisplayBackfaceCulling(this->displayBackfaceCulling);

		/*Activate Z-Buffer*/
		this->mediator->Send("ActiveGLDepth_", this);

		/*Deavtivate Bounding box*/
		this->displayBoundingBox = false;
		this->localModel->setDisplayBoundingBox(this->displayBoundingBox);
	}
	else
		this->mediator->Send("Deactivate Phong Shading", this);
	this->flatShading = false;
	this->gouraudShading = false;
	this->matShininess = this->localModel->getMatShininess();
}


/*Callbacks*/
void TW_CALL loadCallback(void *clientData) {
	SideBar* localSideBar = (SideBar*)clientData;
	localSideBar->loadFileCall();
}

void TW_CALL selectModelCallback(void * clientData){
	SideBar* localSideBar = (SideBar*)clientData;
	localSideBar->selectModelCall();
}

void TW_CALL modelPointsCallback(void * clientData){
	SideBar* localSideBar = (SideBar*)clientData;
	localSideBar->modelPointsCall();
}

void TW_CALL modelMeshCallback(void * clientData){
	SideBar* localSideBar = (SideBar*)clientData;
	localSideBar->modelMeshCall();
}

void TW_CALL modelFilledPolygonsCallback(void * clientData){
	SideBar* localSideBar = (SideBar*)clientData;
	localSideBar->modelFilledPolygonsCall();
}

void TW_CALL normalVectorsCallback(void * clientData){
	SideBar* localSideBar = (SideBar*)clientData;
	localSideBar->normalVectorsCall();
}

void TW_CALL boundingBoxCallback(void * clientData){
	SideBar* localSideBar = (SideBar*)clientData;
	localSideBar->boundingBoxCall();
}

void TW_CALL backFaceCullingCallback(void * clientData){
	SideBar* localSideBar = (SideBar*)clientData;
	localSideBar->backFaceCullingCall();
}

void TW_CALL ZBufferCallback(void * clientData){
	SideBar* localSideBar = (SideBar*)clientData;
	localSideBar->ZBufferCall();
}

void TW_CALL perspectiveCallback(void * clientData){
	SideBar* localSideBar = (SideBar*)clientData;
	localSideBar->perspectiveCall();
}

void TW_CALL orthogonalXCallback(void * clientData){
	SideBar* localSideBar = (SideBar*)clientData;
	localSideBar->orthogonalXCall();
}

void TW_CALL orthogonalYCallback(void * clientData){
	SideBar* localSideBar = (SideBar*)clientData;
	localSideBar->orthogonalYCall();
}

void TW_CALL orthogonalZCallback(void * clientData){
	SideBar* localSideBar = (SideBar*)clientData;
	localSideBar->orthogonalZCall();
}

void TW_CALL flatShadingCallback(void * clientData){
	SideBar* localSideBar = (SideBar*)clientData;
	localSideBar->flatShadingCall();
}

void TW_CALL gouraudShadingCallback(void * clientData){
	SideBar* localSideBar = (SideBar*)clientData;
	localSideBar->gouraudShadingCall();
}

void TW_CALL phongShadingCallback(void * clientData){
	SideBar* localSideBar = (SideBar*)clientData;
	localSideBar->phongShadingCall();
}


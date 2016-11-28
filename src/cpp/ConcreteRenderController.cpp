#include <ConcreteRenderController.h>

ConcreteRenderController::ConcreteRenderController() {
	this->gui = GUI::Instance(this);
	this->illuminationProgram = NULL;
	this->initGLSLPrograms();
	this->stage = Stage::Instance(this);
}

ConcreteRenderController::ConcreteRenderController(const float width, const float height){
	this->gui = GUI::Instance(this, (int)width, (int)height);
	this->illuminationProgram = NULL;
	this->initGLSLPrograms();
	this->stage = Stage::Instance(this);
	this->stage->Notify("width/height", (void*)(new float[2]{ width, height }));
	this->stage->Notify("init VBOs", NULL);
	this->stage->Notify("shader id", (void*)this->illuminationProgram->getProgramID());
	this->gui->reshape(this->gui->getWindow(), (int)width, (int)height);
}

ConcreteRenderController::~ConcreteRenderController() {}

void ConcreteRenderController::Send(string message, void* data, RenderColleague* renderColleague) {
	if (message == "Reshape" && renderColleague == this->gui)
		this->stage->getProjection()->setAspectRatio( ((float*)data)[0]/((float*)data)[1] );
	
	if(message == "Arriba")
		this->stage->Notify("Arriba",NULL);
	else if(message == "Abajo")
		this->stage->Notify("Abajo",NULL);
	else if(message == "Izquierda")
		this->stage->Notify("Izquierda",NULL);
	else if(message == "Derecha")
		this->stage->Notify("Derecha",NULL);
	else if(message == "Disparo")
		this->stage->Notify("Disparo",NULL);
	
	
}

void ConcreteRenderController::render(){
	/*Se sustituir� por el sky box*/
	glClearColor(0.8f, 0.8f, 0.8f, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*Render the stage*/
	this->stage->render();
}


void ConcreteRenderController::initGLSLPrograms(){
	/*Initialize Shaders*/
	/*Phong illumination Shader*/
	this->illuminationProgram = new CGLSLProgram(this);
	this->illuminationProgram->loadShader("../src/shaders/Phong.vert", CGLSLProgram::VERTEX);
	this->illuminationProgram->loadShader("../src/shaders/Phong.frag", CGLSLProgram::FRAGMENT);
	this->illuminationProgram->create_link();
}

int ConcreteRenderController::infinity() {
	int contador = 0;
	//clock_t tiempo = clock();
	while (!glfwWindowShouldClose(this->gui->getWindow())) {
		
	/*	if(count == 60){
			if( difftime (clock() - tiempo) < 1000){
				wait( 1000 - (difftime (clock() - tiempo)) );
				count = 0;
				tiempo = clock();
			}else{
				count = 0;
				tiempo = clock();
			}
		}*/
		this->illuminationProgram->enable();
		count++;
		this->render();
		//this->illuminationProgram->disable();
		glfwSwapBuffers(this->gui->getWindow());
		glfwPollEvents();
	}
	return EXIT_SUCCESS;
}

int ConcreteRenderController::finish() {
	this->gui->Destroy();
	return EXIT_SUCCESS;
}
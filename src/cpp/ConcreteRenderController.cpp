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
}

void ConcreteRenderController::render(){
	/*Se sustituirá por el sky box*/
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
	while (!glfwWindowShouldClose(this->gui->getWindow())) {
		this->illuminationProgram->enable();
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
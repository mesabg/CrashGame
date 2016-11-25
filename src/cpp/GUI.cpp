#include <GUI.h>

GUI* GUI::uniqueGUI = NULL;

GUI::GUI(RenderController* renderController):RenderColleague(renderController) {
	this->gWidth = 1440;
	this->gHeight = 900;

	if (!initGlfw() || glewInit() != GLEW_OK)
		exit(1);
}


GUI::GUI(RenderController* renderController, const int gWidth, const int gHeight) : RenderColleague(renderController) {
	this->gWidth = gWidth;
	this->gHeight = gHeight;

	if (!initGlfw() || glewInit() != GLEW_OK)
		exit(1);
}


GUI::~GUI() {
	glfwDestroyWindow(this->gWindow);
	glfwTerminate();
}


GUI* GUI::Instance(RenderController* renderController) {
	if (!uniqueGUI)
		uniqueGUI = new GUI(renderController);
	return uniqueGUI;
}

GUI* GUI::Instance(RenderController* renderController, const int width, const int height) {
	if (!uniqueGUI)
		uniqueGUI = new GUI(renderController, width, height);
	return uniqueGUI;
}

void GUI::Destroy(){
	if (!uniqueGUI) return;
	uniqueGUI->~GUI();
}


float GUI::getHeight() {
	return (float)this->gHeight;
}


float GUI::getWidth() {
	return (float)this->gWidth;
}


GLFWwindow * GUI::getWindow(){
	return this->gWindow;
}

void GUI::setSize(const float width, const float height){
	reshape(this->gWindow, (int)width, (int)height);
}

void GUI::Notify(string message, void* data) {

}


bool GUI::initGlfw() {
	if (!glfwInit())
		return false;

	this->gWindow = glfwCreateWindow(this->gWidth, this->gHeight, "Crash VO", NULL, NULL);

	if (!this->gWindow) {
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(this->gWindow);

	const GLFWvidmode * vidMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(this->gWindow, (vidMode->width - this->gWidth) >> 1, (vidMode->height - this->gHeight) >> 1);

	/*Callbacks GLFW*/
	glfwSetKeyCallback(this->gWindow, keyInput);
	glfwSetWindowSizeCallback(this->gWindow, reshape);
	glfwSetMouseButtonCallback(this->gWindow, mouseButton);
	glfwSetCursorPosCallback(this->gWindow, cursorPos);
	glfwSetScrollCallback(this->gWindow, scrollCallback);

	return true;
}


void GUI::reshape(GLFWwindow *window, int width, int height) {
	GUI* localGUI = GUI::Instance(NULL);
	localGUI->gWidth = width;
	localGUI->gHeight = height;

	glViewport(0, 0, localGUI->gWidth, localGUI->gHeight);

	/*Projection Matrix*/
	/*glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)localGUI->gWidth / (float)localGUI->gHeight, 1.0f, 1000.0f);*/
	//localGUI->mProjMatrix = glm::perspective(45.0f, (float)localGUI->gWidth / (float)localGUI->gHeight, 1.0f, 1000.0f);

	/*Model View Matrix*/
	/*glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(3.0f, 3.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);	*/
	//localGUI->mModelViewMatrix = glm::translate(glm::mat4(), glm::vec3(3.0f, 3.0f, 10.0f));

	localGUI->renderController->Send("Reshape", (void*)(new float[2]{ (float)localGUI->gWidth, (float)localGUI->gHeight }), localGUI);
}


/*Visual Callbacks*/
void GUI::cursorPos(GLFWwindow* window, double x, double y) {

}


void GUI::mouseButton(GLFWwindow* window, int button, int action, int mods) {

}


void GUI::keyInput(GLFWwindow * window, int key, int scancode, int action, int mods){
	//GUI *localUserInterface = GUI::Instance(NULL);
	/*if (key == GLFW_KEY_SPACE)
		localUserInterface->renderController->Send("Volver al principal", localUserInterface);*/
}

void GUI::scrollCallback(GLFWwindow * window, double x, double y){

}

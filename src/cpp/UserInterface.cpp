#include <UserInterface.h>
#include <GL\freeglut.h>

UserInterface* UserInterface::uniqueUserInterface = NULL;

UserInterface::UserInterface(Mediator* mediator):Colleague(mediator) {
}

UserInterface::~UserInterface() {
}

UserInterface::UserInterface(Mediator* mediator, int gWidth, int gHeight):Colleague(mediator){
	this->gWidth = gWidth;
	this->gHeight = gHeight;

	if (!initGlfw() || !initUserInterface() || glewInit() != GLEW_OK)
		exit(1);
	
	/*init Shaders*/
	printf("%s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	this->mediator->initGLSLPrograms();

	reshape(this->gWindow, this->gWidth, this->gHeight);

	/*glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	gluLookAt(3.0f, 3.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);*/
}


bool UserInterface::initShaders(){
	
	return true;
}

void UserInterface::sendDataToOpenGL(GLdouble *GLVertexes, GLdouble *GLNormals, const int nVertexes, float *color){

}

void UserInterface::setGLColor(float * color){
	
}

CGLSLProgram * UserInterface::getFlatProgram(){
	return this->glslProgramFlat;
}

CGLSLProgram * UserInterface::getGouraudProgram(){
	return this->glslProgramGouraud;
}

CGLSLProgram * UserInterface::getPhongProgram(){
	return this->glslProgramPhong;
}

glm::mat4x4 UserInterface::getProjectMatrix(){
	return this->mProjMatrix;
}

glm::mat4x4 UserInterface::getModelViewMatrix(){
	return this->mModelViewMatrix;
}

bool UserInterface::initGlfw() {
	if (!glfwInit())
		return false;

	this->gWindow = glfwCreateWindow(this->gWidth, this->gHeight, "3DMView", NULL, NULL);

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
	/*glfwSetScrollCallback(this->gWindow, scrollCallback);*/

	return true;
}


bool UserInterface::initUserInterface() {
	if (!TwInit(TW_OPENGL, NULL))
		return false;
	this->sideBar = SideBar::Instance(this->mediator);
	return true;
}


UserInterface* UserInterface::Instance(Mediator* mediator) {
	if (!uniqueUserInterface)
		uniqueUserInterface = new UserInterface(mediator);
	return uniqueUserInterface;
}

UserInterface* UserInterface::Instance(Mediator* mediator, int width, int height) {
	if (!uniqueUserInterface)
		uniqueUserInterface = new UserInterface(mediator, width, height);
	return uniqueUserInterface;
}

double* UserInterface::createOrthoProjectionMatrix(float left, float right, float top, float bottom, float near_, float far_)
{
	double *m = new double[16];
	
	m[0] = 2.0f / (right - left);
	m[1] = 0.0f;
	m[2] = 0.0f;
	m[3] = 0.0f;
			
	m[4] = 0.0f;
	m[5] = 2.0f / (top - bottom);
	m[6] = 0.0f;
	m[7] = 0.0f;
			
	m[8] = 0.0f;
	m[9] = 0.0f;
	m[10] = -2.0f / (far_ - near_);
	m[12] = 0.0f;
			
	m[13] = -(right + left  ) / (right - left  );
	m[14] = -(top   + bottom) / (top   - bottom);
	m[15] = -(far_   + near_  ) / (far_   - near_  );
	m[16] = 1.0f;
			
	return m;
}

float UserInterface::getHeight(){
	return (float)this->gHeight;
}

float UserInterface::getWidth(){
	return (float)this->gWidth;
}

void UserInterface::Notify(string message) {
	if (message == "Perspective") {
		/*Projection Matrix*/
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (float)this->gWidth / (float)this->gHeight, 1.0f, 1000.0f);
		
		/*Model View Matrix*/
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(3.0f, 3.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	}
	else if (message == "OrtogonalX") {
		/*Projection Matrix*/
	    glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//glOrtho(-2000, 2000, -2000, 2000, -1000.0f, 1000.0f);
		//glLoadMatrixd(createOrthoProjectionMatrix(0.0f, (float)gWidth, (float)gHeight, 0.0f, 1.0f, 1000.0f));
		//glLoadIdentity();
		//gluPerspective(45.0f, (float)this->gWidth / (float)this->gHeight, 1.0f, 1000.0f);
	
		//glOrtho(-2000, 2000, -2000, 2000, -1000.0f, 1000.0f);
		//glOrtho(0.0f,gWidth,0.0f,gHeight,1.0f,1000.0f);
		//gluOrtho2D(0, gWidth, 0, gHeight);
		/*Model View Matrix*/
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	}
	else if (message == "OrtogonalY") {
		/*Projection Matrix*/
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (float)this->gWidth / (float)this->gHeight, 1.0f, 1000.0f);

		/*Model View Matrix*/
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(3.0f, 3.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	}
	else if (message == "OrtogonalZ") {
		/*Projection Matrix*/
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//glOrtho(-0.5f, 0.5f, -0.5f, 0.5f, 0.01f, 20.0f);
		glOrtho(-gWidth/2, gWidth/2, -gHeight/2, gHeight/2, 1.0f, 1000.0f);
		//gluPerspective(45.0f, (float)this->gWidth / (float)this->gHeight, 1.0f, 1000.0f);
		/*Model View Matrix*/
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(3.0f, 3.0f, 10.0f, 0.0f, 0.0f, -50.0f, 0.0f, 1.0f, 0.0f);
	}
}


int UserInterface::finish() {
	TwTerminate();
	glfwDestroyWindow(this->gWindow);
	glfwTerminate();
	return EXIT_SUCCESS;
}


void UserInterface::reshape(GLFWwindow *window, int width, int height) {
	UserInterface *localUserInterface = UserInterface::Instance(NULL);
	localUserInterface->gWidth = width;
	localUserInterface->gHeight = height;

	glViewport(0, 0, localUserInterface->gWidth, localUserInterface->gHeight);
	localUserInterface->sideBar->reshape(localUserInterface->gWidth, localUserInterface->gHeight);

	/*Projection Matrix*/
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)localUserInterface->gWidth / (float)localUserInterface->gHeight, 1.0f, 1000.0f);
	localUserInterface->mProjMatrix = glm::perspective(45.0f, (float)localUserInterface->gWidth / (float)localUserInterface->gHeight, 1.0f, 1000.0f);

	/*Model View Matrix*/
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(3.0f, 3.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);	
	localUserInterface->mModelViewMatrix = glm::translate(glm::mat4(), glm::vec3(3.0f, 3.0f, 10.0f));

	//localUserInterface->mediator->Send("Reshaping", localUserInterface);
}


int UserInterface::infinity() {
	while (!glfwWindowShouldClose(this->gWindow)) {
		display();
		this->sideBar->update();
		glfwSwapBuffers(this->gWindow);
		glfwPollEvents();
	}
	return EXIT_SUCCESS;
}



void UserInterface::display() {
	glClearColor(0.8f, 0.8f, 0.8f, 1.0);
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	/*Renderizar*/
	mediator->Send("Render Models", this);
}


/*Visual Callbacks*/
void UserInterface::cursorPos(GLFWwindow* window, double x, double y) {
	if (TwEventMousePosGLFW(int(x), int(y)))
		return;
}

void UserInterface::mouseButton(GLFWwindow* window, int button, int action, int mods) {
	if (TwEventMouseButtonGLFW(button, action))
		return;
}

void UserInterface::keyInput(GLFWwindow * window, int key, int scancode, int action, int mods){
	UserInterface *localUserInterface = UserInterface::Instance(NULL);
	if (key == GLFW_KEY_SPACE)
		localUserInterface->mediator->Send("Volver al principal", localUserInterface);
}

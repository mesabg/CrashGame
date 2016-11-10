#pragma once
#ifndef __USER_INTERFACE_H_
#define __USER_INTERFACE_H_

#include <GLSLProgram.h>
#include <SideBar.h>

class UserInterface : public Colleague
{
private:
	/*Variables*/
	static UserInterface* uniqueUserInterface;
	SideBar* sideBar;
	GLFWwindow* gWindow;
	int gWidth;
	int gHeight;

	/*GLSL Programs*/
	CGLSLProgram *glslProgramFlat;
	CGLSLProgram *glslProgramGouraud;
	CGLSLProgram *glslProgramPhong;

	/*Model Matrix / Projection Matrix*/
	glm::mat4x4 mProjMatrix, mModelViewMatrix;

	/*Inicializadores*/
	UserInterface(Mediator* mediator);
	UserInterface(Mediator* mediator, int gWidth, int gHeight);
	~UserInterface();

	/*Funciones propias*/
	bool initUserInterface();
	bool initGlfw();
	void display();
	bool initShaders();

	/*GLFW Callbacks*/
	static void reshape(GLFWwindow *window, int width, int height);
	static void cursorPos(GLFWwindow* window, double x, double y);
	static void mouseButton(GLFWwindow* window, int button, int action, int mods);
	static void keyInput(GLFWwindow *window, int key, int scancode, int action, int mods);
public:
	/*Set GL data*/
	void sendDataToOpenGL(GLdouble *GLVertexes, GLdouble *GLNormals, const int nVertexes, float *color);
	void setGLColor(float *color);

	/*Get GLSL Programs*/
	CGLSLProgram* getFlatProgram();
	CGLSLProgram* getGouraudProgram();
	CGLSLProgram* getPhongProgram();

	/*Get Matrix*/
	glm::mat4x4 getProjectMatrix();
	glm::mat4x4 getModelViewMatrix();

	/*Get Instance*/
	static UserInterface* Instance(Mediator* mediator);
	static UserInterface* Instance(Mediator* mediator, int width, int height);

	/*Get message*/
	void Notify(string message);
	double * createOrthoProjectionMatrix(float left, float right, float top, float bottom, float near, float far);
	float getHeight();
	float getWidth();

	/*Play and Pause*/
	int finish();
	int infinity();
};

/*
void reshape(GLFWwindow *window, int width, int height);
void keyInput(GLFWwindow *window, int key, int scancode, int action, int mods);
void mouseButton(GLFWwindow* window, int button, int action, int mods);
void cursorPos(GLFWwindow* window, double x, double y);
void scrollCallback(GLFWwindow* window, double x, double y);
*/
#endif

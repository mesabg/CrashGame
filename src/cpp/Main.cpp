#include <Main.h>

/*void showFPS()
{
	static Timer timer;
	static int count = 0;
	static std::string fps = "0.0 FPS";
	double elapsedTime = 0.0;;

	// update fps every second
	++count;
	elapsedTime = timer.getElapsedTime();
	if (elapsedTime > 1.0)
	{
		std::stringstream ss;
		ss << std::fixed << std::setprecision(1);
		ss << (count / elapsedTime) << " FPS" << std::ends; // update fps string
		ss << std::resetiosflags(std::ios_base::fixed | std::ios_base::floatfield);
		fps = ss.str();
		count = 0;                      // reset counter
		timer.start();                  // restart timer
	}

	// backup current model-view matrix
	glPushMatrix();                     // save current modelview matrix
	glLoadIdentity();                   // reset modelview matrix

										// set to 2D orthogonal projection
	glMatrixMode(GL_PROJECTION);        // switch to projection matrix
	glPushMatrix();                     // save current projection matrix
	glLoadIdentity();                   // reset projection matrix
	gluOrtho2D(0, screenWidth, 0, screenHeight); // set to orthogonal projection

	float color[4] = { 1, 1, 0, 1 };
	int textWidth = (int)fps.size() * TEXT_WIDTH;
	drawString(fps.c_str(), screenWidth - textWidth, screenHeight - TEXT_HEIGHT, color, font);

	// restore projection matrix
	glPopMatrix();                      // restore to previous projection matrix

										// restore modelview matrix
	glMatrixMode(GL_MODELVIEW);         // switch to modelview matrix
	glPopMatrix();                      // restore to previous modelview matrix
}*/

int main() {
	ConcreteGameController* gameController = new ConcreteGameController();
	ConcreteRenderController* renderController = new ConcreteRenderController(1440.0f, 900.0f);
	renderController->infinity();
	renderController->finish();
}

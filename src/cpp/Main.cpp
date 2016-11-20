#include <Main.h>

//[System::STAThread]
int main() {
	ConcreteGameController* gameController = new ConcreteGameController();
	ConcreteRenderController* renderController = new ConcreteRenderController(1440.0f, 900.0f);
	renderController->infinity();
	renderController->finish();
}



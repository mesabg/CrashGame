#include <Main.h>

int main() {
	ConcreteGameController* gameController = new ConcreteGameController();
	ConcreteRenderController* renderController = new ConcreteRenderController(1440.0f, 900.0f);
	renderController->infinity();
	renderController->finish();
	return 0;
}



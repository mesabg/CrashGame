#include <CreatorOBJ.h>

CreatorOBJ::CreatorOBJ() {}

CreatorOBJ::~CreatorOBJ() {}

Model* CreatorOBJ::factoryMethod(Mediator* mediator) {
	return (Model*) new OBJ(mediator);
}

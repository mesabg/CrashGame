#include <CreatorOBJ.h>

CreatorOBJ::CreatorOBJ() {}

CreatorOBJ::~CreatorOBJ() {}

Model* CreatorOBJ::factoryMethod() {
	return new OBJ();
}

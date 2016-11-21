#include <CreatorOBJ.h>

CreatorOBJ::CreatorOBJ() {}

CreatorOBJ::~CreatorOBJ() {}

Model* CreatorOBJ::create(ModelRoutesData* routes) {
	return new OBJ(routes);
}

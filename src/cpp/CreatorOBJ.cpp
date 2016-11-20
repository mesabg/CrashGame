#include <CreatorOBJ.h>

CreatorOBJ::CreatorOBJ() {}

CreatorOBJ::~CreatorOBJ() {}

Model* CreatorOBJ::create(string path) {
	return new OBJ(path);
}

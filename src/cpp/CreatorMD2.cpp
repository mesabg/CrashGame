#include <CreatorMD2.h>

CreatorMD2::CreatorMD2() {}

CreatorMD2::~CreatorMD2() {}

Model* CreatorMD2::factoryMethod() {
	return new MD2();
}

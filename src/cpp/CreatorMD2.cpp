#include <CreatorMD2.h>

CreatorMD2::CreatorMD2() {}

CreatorMD2::~CreatorMD2() {}

Model* CreatorMD2::create(ModelRoutesData* routes) {
	return new MD2(routes);
}

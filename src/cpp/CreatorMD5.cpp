#include <CreatorMD5.h>

CreatorMD5::CreatorMD5() {}

CreatorMD5::~CreatorMD5() {}

Model* CreatorMD5::create(ModelRoutesData* routes) {
	return new MD5(routes);
}

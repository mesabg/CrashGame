#include <CreatorMD5.h>

CreatorMD5::CreatorMD5() {}

CreatorMD5::~CreatorMD5() {}

Model* CreatorMD5::factoryMethod() {
	return new MD5();
}

#include <CreatorOFF.h>

CreatorOFF::CreatorOFF() {}

CreatorOFF::~CreatorOFF() {}

Model* CreatorOFF::factoryMethod() {
	return new OFF();
}

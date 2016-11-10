#include <CreatorOFF.h>

CreatorOFF::CreatorOFF() {}

CreatorOFF::~CreatorOFF() {}

Model* CreatorOFF::factoryMethod(Mediator* mediator) {
	return new OFF(mediator);
}

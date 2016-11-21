#include <CreatorOFF.h>

CreatorOFF::CreatorOFF() {}

CreatorOFF::~CreatorOFF() {}

Model* CreatorOFF::create(ModelRoutesData* routes) {
	return new OFF(routes);
}

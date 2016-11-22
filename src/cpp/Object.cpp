#include <Object.h>

vector<Object*> Object::uniqueObjects(amountOfObjects, NULL);

Object::Object(GameController * gameController, ModelRoutesData* routes, vector<int> *contextData):Entity(gameController, routes, contextData) {

}

Object::~Object(){

}

Object * Object::Instance(GameController * gameController, ModelRoutesData * routes, vector<int>* contextData, const int index){
	if (index >= (int)uniqueObjects.size()) return NULL;
	if (uniqueObjects[index] == NULL)
		uniqueObjects[index] = (new Object(gameController, routes, contextData));
	return uniqueObjects[index];
}

void Object::Destroy(){
	/*Kill all the instances*/
	for (int i = 0; i < (int)uniqueObjects.size(); i++) {
		uniqueObjects[i]->~Object();
		uniqueObjects[i] = NULL;
		delete uniqueObjects[i];
	}
	uniqueObjects.clear();
	uniqueObjects.~vector();
}

void Object::Notify(string message, void * data){

}

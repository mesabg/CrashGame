#include <Mediator_Colleague.h>

Colleague::Colleague(Mediator* mediator){
	this->mediator = mediator;
}

Colleague::~Colleague() {}

void Colleague::Send(string message){
	this->mediator->Send(message,this);
}

void Colleague::SetMediator(Mediator* mediator) {
	this->mediator = mediator;
}

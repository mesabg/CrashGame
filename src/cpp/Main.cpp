#include <Main.h>

[System::STAThread]
int main() {
	vector<string> defaultModelsSrc;
	defaultModelsSrc.push_back("../models/sphere.obj");
	ConcreteMediator* mediator = new ConcreteMediator();
	UserInterface* localInterface = UserInterface::Instance(mediator, 1440, 900);
	mediator->SetUserInterfaceColleague(localInterface);
	mediator->SetSideBarColleague(SideBar::Instance(mediator));
	mediator->SetFileLoaderColleague(FileLoader::Instance(mediator));
	mediator->LoadDefaultModels(defaultModelsSrc);
	localInterface->infinity();
	localInterface->finish();
}



#pragma once
#ifndef __FILE_LOADER_H_
#define __FILE_LOADER_H_

#include <Mediator_Colleague.h>
#include <CreatorOBJ.h>
#include <CreatorOFF.h>

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

class FileLoader : public Colleague
{
private:
	static FileLoader* uniqueFileLoader;
	ModelsCreator* localModelsCreator;
	FileLoader(Mediator* mediator);
	~FileLoader();
public:
	static FileLoader* Instance(Mediator* mediator);
	void Notify(string message);
	Model* CreateModel(string type);
};


void MarshalString(String ^ s, string& os);

#endif

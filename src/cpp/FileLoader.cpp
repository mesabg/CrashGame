#include <FileLoader.h>

FileLoader* FileLoader::uniqueFileLoader = NULL;

FileLoader::FileLoader(Mediator* mediator) :Colleague(mediator) {
	
}

FileLoader::~FileLoader() {

}

FileLoader * FileLoader::Instance(Mediator* mediator){
	if (!uniqueFileLoader)
		uniqueFileLoader = new FileLoader(mediator);
	return uniqueFileLoader;
}

void FileLoader::Notify(string message) {
	/*Mediator solicita cargar un archivo*/
	String^ filePath;
	string fileNameString, type;
	OpenFileDialog^ openFile = gcnew OpenFileDialog;
	int length;

	openFile->InitialDirectory = "C:\\Users\\Equipo\\Desktop";
	openFile->Filter = "Model files (*.obj)|*.obj| Model files (*.off)|*.off";
	openFile->FilterIndex = 1;
	openFile->RestoreDirectory = true;
	
	if (openFile->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		filePath = openFile->FileName;
		MarshalString(filePath, fileNameString);
		length = fileNameString.length();
		type.push_back(fileNameString[length - 3]);
		type.push_back(fileNameString[length - 2]);
		type.push_back(fileNameString[length - 1]);
		this->mediator->AddAndSend(CreateModel(type), fileNameString, this);
	}
}

Model* FileLoader::CreateModel(string type){
	if (type == "obj") return (this->localModelsCreator = new CreatorOBJ())->factoryMethod(this->mediator);
	if (type == "off") return (this->localModelsCreator = new CreatorOFF())->factoryMethod(this->mediator);
	return nullptr;
}


void MarshalString(String ^ s, string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

#include <OFF.h>

OFF::OFF(Mediator* mediator) :Model(mediator) {}
OFF::~OFF() {}

#include <iostream>
using namespace std;


void OFF::loadModel(string ruta) {
	string archivo = ruta;
	if (archivo.empty()) return;
	ifstream fe(archivo);
	Vertex* vertex;
	int numVertices = 0;
	int numFaces = 0;
	string leer = "";
	double x, y, z;
	int numCaras;
	std::string::size_type sz;

	while (fe >> leer) {
		if (leer == "#" || leer[0] == '#') { //Saltar linea
			while (fe.get() != '\n') continue;
		}
		else if (leer != "OFF") {
			numVertices = atoi(leer.c_str());
			fe >> leer;
			numFaces = atoi(leer.c_str());
			fe >> leer;
			for (int i = 0; i < numVertices; i++)
			{
				fe >> leer;
				x = stod(leer, &sz);
				fe >> leer;
				y = stod(leer, &sz);
				fe >> leer;
				z = stod(leer, &sz);

				vertex = new Vertex(x, y, z);
				if ((int)this->vertexes.size() == 0) {
					this->localBoundingBox->initVertexBox(vertex);
					this->max = vertex->x;
				}
				this->vertexes.push_back(vertex);
				this->localBoundingBox->setVertexBox(vertex);

				if (vertex->x >= max) max = vertex->x;
				if (vertex->y >= max) max = vertex->y;
				if (vertex->z >= max) max = vertex->z;

			}

			for (int i = 0; i < numFaces; i++)
			{
				fe >> leer;
				numCaras = atoi(leer.c_str());
				vector<int> myarray;

				for (int j = 0; j < numCaras; j++)
				{
					fe >> leer;
					myarray.push_back(atoi(leer.c_str()) + 1);

				}
				agregarFace(myarray);
			}
		}
	}
}

void OFF::agregarFace(vector<int> myarray) {
	for (int i = 0; i < (int)myarray.size(); i++)
	{
		if (i == 0) {
			this->faces.push_back(new Vertex(myarray[i], myarray[i + 1], myarray[i + 2]));
			i = i + 2;
		}
		else {
			this->faces.push_back(new Vertex(myarray[0], myarray[i - 1], myarray[i]));
		}
	}
}
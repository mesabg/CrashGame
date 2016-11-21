#include <OBJ.h>
#include <iostream>

OBJ::OBJ(ModelRoutesData* routes) {
	//PONER NOMBRE DEL ARCHIVO | RUTA
	// string archivo=openfilename(); //PILA
	/*string archivo = routes->model;
	if (archivo.empty()) return;
	ifstream fe(archivo);
	Vertex* vertex;
	std::string::size_type sz;
	char aux;
	bool sigoLeyendo = false;
	string leer;
	double x, y, z;

	while (fe >> leer) {
		if (leer == "#" || leer[0] == '#') { //Saltar linea
			while (fe.get() != '\n') continue;
		}
		else if (leer == "v") {
		label3: fe >> leer;
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

			if (vertex->x >= this->max) this->max = vertex->x;
			if (vertex->y >= this->max) this->max = vertex->y;
			if (vertex->z >= this->max) this->max = vertex->z;
		}
		else if (leer == "f" && this->vertexes.size() != 0) {
		label: vector<int> myarray;
			bool aceptar = true;
			while (fe >> leer) {
				if (leer == "f") break;
				if (leer == "s" || leer == "#" || leer[0] == '#') {
				label2: while (fe.get() != '\n') continue;
					if (fe >> leer) {
						if (leer == "s" || leer == "#" || leer[0] == '#') {
							goto label2;
						}
						break;
					}
					else {
						return;
					}
				}
				aux = leer[0];
				string Auxiliar = "";

				for (int i = 1; i <= (int)leer.size() && aux != '/'; i++)
				{

					Auxiliar = Auxiliar + aux;
					if (i != leer.size())
						aux = leer[i];

				}

				for (int i = 0; i < (int)Auxiliar.size(); i++)
				{
					if (Auxiliar[i] != '0' && Auxiliar[i] != '1' && Auxiliar[i] != '2' && Auxiliar[i] != '3' && Auxiliar[i] != '3' && Auxiliar[i] != '4' && Auxiliar[i] != '5' && Auxiliar[i] != '6' && Auxiliar[i] != '7' && Auxiliar[i] != '8' && Auxiliar[i] != '9') {
						aceptar = false;
						break;
					}
				}
				if (aceptar)
					myarray.push_back(atoi(Auxiliar.c_str()));

			}
			agregarFace(myarray);
			if (leer == "f") {
				goto label;
			}
			else if (leer == "v") {
				goto label3;
			}
		}
	}*/
}

OBJ::~OBJ() {}

void OBJ::agregarFace(vector<int> myarray) {
	/*for (int i = 0; i < (int)myarray.size(); i++)
	{
		if (i == 0) {
			this->faces.push_back(new Vertex(myarray[i], myarray[i + 1], myarray[i + 2]));
			i = i + 2;
		}
		else {
			this->faces.push_back(new Vertex(myarray[0], myarray[i - 1], myarray[i]));
		}
	}*/
}
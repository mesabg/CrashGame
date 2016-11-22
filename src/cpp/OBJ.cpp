#include <OBJ.h>
#include <iostream>

OBJ::OBJ(ModelRoutesData* routes):Model(){
	//PONER NOMBRE DEL ARCHIVO | RUTA
	// string archivo=openfilename(); //PILA
	int index = 0;
	string archivo = routes->model;
	if (archivo.empty()) return;
	ifstream fe(archivo);
	GLfloat* vertex;
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
			vertex = new GLfloat[3];
			vertex[0] = x; vertex[1] = y; vertex[2] = z;
			if ((int)this->vertexes.size() == 0) {
				this->boundingBox->initVertexBox(vertex);
				this->max = vertex[0];
			}
			this->vertexes.push_back(vertex);
			this->boundingBox->setVertexBox(vertex);

			if (vertex[0] >= this->max) this->max = vertex[0];
			if (vertex[1] >= this->max) this->max = vertex[1];
			if (vertex[2] >= this->max) this->max = vertex[2];
		}else if(leer == "vn"){
			fe >> leer;
			x = stod(leer, &sz);
			fe >> leer;
			y = stod(leer, &sz);
			fe >> leer;
			z = stod(leer, &sz);
			vertex = new GLfloat[3];
			vertex[0] = x; vertex[1] = y; vertex[2] = z;
			this->normal.push_back(vertex);
		}else if(leer == "vt"){
			fe >> leer;
			x = stod(leer, &sz);
			fe >> leer;
			y = stod(leer, &sz);
			fe >> leer;
			z = stod(leer, &sz);
			vertex = new GLfloat[3];
			vertex[0] = x; vertex[1] = y; vertex[2] = z;
			this->texture.push_back(vertex);
		}
		else if (leer == "f") {
		label: vector<string> myarray;
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
				
				myarray.push_back(leer);
				
			/*	aux = leer[0];
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
					myarray.push_back(atoi(Auxiliar.c_str()));*/

			}
			
			
			agregarFace(myarray);
			if (leer == "f") {
				goto label;
			}
			else if (leer == "v") {
				goto label3;
			}
		}
	}
}

OBJ::~OBJ() {}
void OBJ::agregarFace(vector<string> myarray){
	vector<int> vertices;
	vector<int> normals;
	vector<int> textures;
	for(int i = 0; i < myarray.size(); i++){
		//Vertices
		char aux = myarray[i][0];
		string Auxiliar = "";
		for (int j = 1; j <= (int)myarray[i].size() && aux != '/'; j++){
			Auxiliar = Auxiliar + aux;
			if (j != (int)myarray[i].size())
				aux = (int)myarray[i][j];
		}
		vertices.push_back(atoi(Auxiliar.c_str())-1);
		//Normales
		char aux = myarray[i][j];
		Auxiliar = "";
		
		for (int k = j; k <= (int)myarray[i].size() && aux != '/'; k++){
			Auxiliar = Auxiliar + aux;
			if (k != (int)myarray[i].size())
				aux = (int)myarray[i][k];
		}
		normals.push_back(atoi(Auxiliar.c_str())-1);
		//Texture
		
		char aux = myarray[i][k];
		Auxiliar = "";
		
		for (int m = k; m <= (int)myarray[i].size() && aux != '/'; m++){
			Auxiliar = Auxiliar + aux;
			if (m != (int)myarray[i].size())
				aux = (int)myarray[i][m];
		}
		textures.push_back(atoi(Auxiliar.c_str())-1);
	}
	
	for (int i = 0; i < vertices.size(); i++) {
		
		if (i == 0) {
			this->glVBO = realloc(this->glVBO, (index+27) * sizeof(GLfloat));
			
			for(int j= 0; j < 3; j++){
				this->glVBO[index] = vertexes[vertices[j]][0]; index++;
				this->glVBO[index] = vertexes[vertices[j]][1]; index++;
				this->glVBO[index] = vertexes[vertices[j]][2]; index++;
				
				this->glVBO[index] = normal[normals[j]][0]; index++;
				this->glVBO[index] = normal[normals[j]][1]; index++;
				this->glVBO[index] = normal[normals[j]][2]; index++;
				
				this->glVBO[index] = texture[textures[j]][0]; index++;
				this->glVBO[index] = texture[textures[j]][1]; index++;
				this->glVBO[index] = texture[textures[j]][2]; index++;
			}
			i = i + 2;
		}
		else {
			// :)
			this->glVBO = realloc(this->glVBO, (index+27) * sizeof(GLfloat));
		
			this->glVBO[index] = vertexes[vertices[0]][0]; index++;
			this->glVBO[index] = vertexes[vertices[0]][1]; index++;
			this->glVBO[index] = vertexes[vertices[0]][2]; index++;
				
			this->glVBO[index] = normal[normals[0]][0]; index++;
			this->glVBO[index] = normal[normals[0]][1]; index++;
			this->glVBO[index] = normal[normals[0]][2]; index++;
				
			this->glVBO[index] = texture[textures[0]][0]; index++;
			this->glVBO[index] = texture[textures[0]][1]; index++;
			this->glVBO[index] = texture[textures[0]][2]; index++;
				
				
			this->glVBO[index] = vertexes[vertices[i-1]][0]; index++;
			this->glVBO[index] = vertexes[vertices[i-1]][1]; index++;
			this->glVBO[index] = vertexes[vertices[i-1]][2]; index++;
				
			this->glVBO[index] = normal[normals[i-1]][0]; index++;
			this->glVBO[index] = normal[normals[i-1]][1]; index++;
			this->glVBO[index] = normal[normals[i-1]][2]; index++;
				
			this->glVBO[index] = texture[textures[i-1]][0]; index++;
			this->glVBO[index] = texture[textures[i-1]][1]; index++;
			this->glVBO[index] = texture[textures[i-1]][2]; index++;
				
				
			this->glVBO[index] = vertexes[vertices[i]][0]; index++;
			this->glVBO[index] = vertexes[vertices[i]][1]; index++;
			this->glVBO[index] = vertexes[vertices[i]][2]; index++;
				
			this->glVBO[index] = normal[normals[i]][0]; index++;
			this->glVBO[index] = normal[normals[i]][1]; index++;
			this->glVBO[index] = normal[normals[i]][2]; index++;
				
			this->glVBO[index] = texture[textures[i]][0]; index++;
			this->glVBO[index] = texture[textures[i]][1]; index++;
			this->glVBO[index] = texture[textures[i]][2]; index++;
			
			
			//this->faces.push_back(new Vertex(myarray[0], myarray[i - 1], myarray[i]));   // Si ocurre el caso en el q hay mas de 3, hay que triangularizar y meter otras 9 cosas
		}
		
	}
	

	
	
	
}
//void OBJ::agregarFace(vector<int> myarray) {
	/*for (int i = 0; i < (int)myarray.size(); i++)
	{
		if (i == 0) {
			this->faces.push_back(new Vertex(myarray[i], myarray[i + 1], myarray[i + 2]));
			i = i + 2;
		}
		else {
			this->faces.push_back(new Vertex(myarray[0], myarray[i - 1], myarray[i]));
		}
	}
}*/

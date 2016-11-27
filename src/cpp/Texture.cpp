#include <Texture.h>

Texture::Texture(string route){
	this->route = route;
	
	int width, height;
	
	//if(image == NULL)
		//cout << "Texture loading failed: " << route << endl;
	
	glGenTextures(1, &m_texture);

	glBindTexture(GL_TEXTURE_2D , m_texture);
	//Puede que esto de problemas en el futuro
	
	/*glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);	
	glTextureParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTextureParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);*/
	
	unsigned char* image = SOIL_load_image(route.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	//glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture(){
	this->route.~basic_string();
}

GLuint Texture::getID(){
	return this->m_texture;
}
#include <Texture.h>

Texture::Texture(string route){
	this->route = route;
	
	unsigned int width, height, numComponents;
	unsigned char* imageData = stbi_load(route.c_str(),&width,&height,&numComponents,4);
	
	if(imageData == NULL)
		cout << "Texture loading failed: " << route << endl;
	
	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D , m_texture);
	//Puede que esto de problemas en el futuro
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	glTextureParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTextureParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glTexImage2D(GL_TEXTURE_2D, 0 , GL_RGBA, width, height, 0 , GL_RGBA, GL_UNSIGNED_BYTE, imageData);
	
	stbi_image_free(imageData);

}

Texture::~Texture(){
	this->route.~basic_string();
}

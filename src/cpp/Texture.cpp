#include <Texture.h>
#include <iostream>
Texture::Texture(string route){
	this->route = route;	
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D , m_texture);	
	
	/*unsigned char* image = SOIL_load_image(route.c_str(), &width, &height, NULL, 0);
	if (image == NULL)
		cout << "Texture error :(" << endl;*/
	SDL_Surface* temporal = loadImage(route.c_str(), true);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, temporal->w, temporal->h, 0, GL_RGB, GL_UNSIGNED_BYTE, temporal->pixels);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	
}

SDL_Surface* Texture::loadImage (const char *filename, bool alpha = true) {
	SDL_Surface* loadedImage = NULL;
	loadedImage = IMG_Load(filename);

	if (loadedImage != NULL) {
		cout << "ERROR CONVIVE" << endl;
	}
	return loadedImage;
}
/*int Texture::LoadTexture(const char *filename, int alpha)
{
	int i, j = 0; //Index variables
	FILE *l_file; //File pointer
	unsigned char *l_texture; //The pointer to the memory zone in which we will load the texture

							  // windows.h gives us these types to work with the Bitmap files
	BITMAPFILEHEADER fileheader;
	BITMAPINFOHEADER infoheader;
	RGBTRIPLE rgb;

	num_texture++; // The counter of the current texture is increased

	if ((l_file = fopen(filename, "rb")) == NULL) return (-1); // Open the file for reading

	fread(&fileheader, sizeof(fileheader), 1, l_file); // Read the fileheader

	fseek(l_file, sizeof(fileheader), SEEK_SET); // Jump the fileheader
	fread(&infoheader, sizeof(infoheader), 1, l_file); // and read the infoheader

													   // Now we need to allocate the memory for our image (width * height * color deep)
	l_texture = (byte *)malloc(infoheader.biWidth * infoheader.biHeight * 4);
	// And fill it with zeros
	memset(l_texture, 0, infoheader.biWidth * infoheader.biHeight * 4);

	// At this point we can read every pixel of the image
	for (i = 0; i < infoheader.biWidth*infoheader.biHeight; i++)
	{
		// We load an RGB value from the file
		fread(&rgb, sizeof(rgb), 1, l_file);

		// And store it
		l_texture[j + 0] = rgb.rgbtRed; // Red component
		l_texture[j + 1] = rgb.rgbtGreen; // Green component
		l_texture[j + 2] = rgb.rgbtBlue; // Blue component
		l_texture[j + 3] = alpha; // Alpha value
		j += 4; // Go to the next position
	}

	fclose(l_file); // Closes the file stream

	glBindTexture(GL_TEXTURE_2D, num_texture); // Bind the ID texture specified by the 2nd parameter

											   // The next commands sets the texture parameters
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // If the u,v coordinates overflow the range 0,1 the image is repeated
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // The magnification function ("linear" produces better results)
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //The minifying function

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECR);

	// Finally we define the 2d texture
	glTexImage2D(GL_TEXTURE_2D, 0, 4, infoheader.biWidth, infoheader.biHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);

	// And create 2d mipmaps for the minifying function
	gluBuild2DMipmaps(GL_TEXTURE_2D, 4, infoheader.biWidth, infoheader.biHeight, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);

	free(l_texture); // Free the memory we used to load the texture

	return (num_texture); // Returns the current texture OpenGL ID
}*/



Texture::~Texture(){
	this->route.~basic_string();
}

GLuint Texture::getID(){
	return this->m_texture;
}
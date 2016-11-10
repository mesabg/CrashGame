#include <RGB_.h>


RGB_::RGB_() {
	this->rgb = new float[3];
	this->rgb[0] = 1.0f;
	this->rgb[1] = 1.0f;
	this->rgb[2] = 1.0F;
}

RGB_::RGB_(float rgb) {
	this->rgb = new float[3];
	this->rgb[0] = rgb;
	this->rgb[1] = rgb;
	this->rgb[2] = rgb;
}

RGB_::RGB_(const float r, const float g, const float b) {
	this->rgb = new float[3];
	this->rgb[0] = r;
	this->rgb[1] = g;
	this->rgb[2] = b;
}

RGB_::~RGB_() {}

void RGB_::setColor(const float r, const float g, const float b) {
	this->rgb[0] = r;
	this->rgb[1] = g;
	this->rgb[2] = b;
}

void RGB_::setColor(float * rgb){
	this->rgb = rgb;
}

RGB_ RGB_::make_rgb(const float r, const float g, const float b) {
	return RGB_(r, g, b);
}

RGB_ RGB_::make_rgb(const float rgb) {
	return RGB_(rgb, rgb, rgb);
}
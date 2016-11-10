#pragma once
#ifndef __RGB_H_
#define __RGB_H_

class RGB_
{
public:
	/*Variables*/
	float *rgb;

	/*Inicializadores*/
	RGB_();
	RGB_(float rgb);
	RGB_(const float r, const float g, const float b);
	~RGB_();

	/*Funciones Propias*/
	void setColor(const float r, const float g, const float b);
	void setColor(float* rgb);
	static RGB_ make_rgb(const float r, const float g, const float b);
	static RGB_ make_rgb(const float rgb);
};

#endif
#pragma once

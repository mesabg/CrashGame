#version 330

in layout(location=0) vec3 a_position;

uniform mat4 u_viewMat;
uniform mat4 u_modelMat;
uniform mat4 u_projMat;

void main(void){
	gl_Position = u_projMat * u_viewMat * u_modelMat * vec4(a_position, 1.0);
} 
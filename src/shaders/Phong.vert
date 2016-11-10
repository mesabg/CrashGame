#version 330

in layout(location=0) vec3 position;
in layout(location=2) vec3 i_normal;

uniform vec3 position_vector;
uniform vec3 normal_vector;
uniform mat4 u_viewMat;
uniform mat4 u_normalMat;
uniform mat4 u_projMat;
uniform mat4 modelMat;
uniform mat4 modelMatT;
uniform vec3 u_lightPosition;
uniform vec3 eye_position;


// attributes
out vec3 o_normal;
out vec3 o_toLight;
out vec3 o_toCamera;


void main(void)
{

   vec4 worldPosition = vec4(position,1.0);
   //vec4 worldPosition = u_projMat * u_viewMat * vec4(position,1.0);
	//normal in world space
	o_normal = normalize( vec3(u_normalMat * vec4(i_normal, 0.0)) );

	//direction to light
	o_toLight = normalize( u_lightPosition - worldPosition.xyz ); 

   //direction to camera
   o_toCamera = normalize( eye_position - worldPosition.xyz );

   //screen space coordinates of the vertex
   gl_Position = u_projMat * u_viewMat * worldPosition;
   //gl_Position = worldPosition;
} 



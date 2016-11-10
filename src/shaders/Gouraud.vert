#version 330

in layout(location=0) vec3 position;
in layout(location=2) vec3 i_normal;

uniform mat4 u_viewMat;
uniform mat4 u_normalMat;
uniform mat4 u_projMat;
uniform mat4 modelMat;
uniform mat4 modelMatT;
uniform vec3 u_lightPosition;
uniform vec3 eye_position;

// parameters of the light and possible values
uniform vec3 u_lightAmbientIntensitys; 
uniform vec3 u_lightDiffuseIntensitys; 
uniform vec3 u_lightSpecularIntensitys;

// parameters of the material and possible values
uniform vec3 u_matAmbientReflectances; 
uniform vec3 u_matDiffuseReflectances; 
uniform vec3 u_matSpecularReflectances; 
uniform float u_matShininess; 

// attributes
out vec4 finalColor;

// returns intensity of reflected ambient lighting
vec3 ambientLighting()
{
   return u_matAmbientReflectances * u_lightAmbientIntensitys;
}

// returns intensity of diffuse reflection
vec3 diffuseLighting(in vec3 N, in vec3 L)
{
   // calculation as for Lambertian reflection
   return max(dot(N, L), 0.0) * u_matDiffuseReflectances * u_lightDiffuseIntensitys;
}

// returns intensity of specular reflection
vec3 specularLighting(in vec3 N, in vec3 L, in vec3 V)
{
   float specularTerm = 0;

   // calculate specular reflection only if
   // the surface is oriented to the light source


   if(dot(N, L) > 0)
   {
      // half vector
      vec3 H = normalize(L + V);
      specularTerm = max(pow(dot(N, H),u_matShininess),0.0);
   }

   return specularTerm * u_matSpecularReflectances * u_lightSpecularIntensitys;
}

void main(void)
{
	vec4 worldPosition = vec4(position, 1.0);
	//normal in world space
	vec3 o_normal = normalize( vec3(u_normalMat * vec4(i_normal, 0.0)) );

	//direction to light
	vec3 o_toLight = normalize( u_lightPosition - worldPosition.xyz ); 

   //direction to camera
   vec3 o_toCamera = normalize( eye_position - worldPosition.xyz );

   // normalize vectors after interpolation
   vec3 L = normalize(o_toLight);  // deberia ser normalize(u_toLightDirection); porque son todas los vectores que inciden sobre el vertice
   vec3 N = normalize(o_normal);
   vec3 V = normalize(o_toCamera);

   // get Blinn-Phong reflectance components
   vec3 Iamb =  ambientLighting();
   vec3 Idif = diffuseLighting(N, L);
   vec3 Ispe = specularLighting(N, L, V);

   // combination of all components and diffuse color of the object
   finalColor.xyz = Iamb + Idif + Ispe;
   finalColor.a = 1.0;

   //screen space coordinates of the vertex
   gl_Position = u_projMat * u_viewMat * worldPosition;
} 
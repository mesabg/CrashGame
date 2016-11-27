#version 330

// parameters of the light and possible values
uniform vec3 u_lightAmbientIntensitys; 
uniform vec3 u_lightDiffuseIntensitys; 
uniform vec3 u_lightSpecularIntensitys;

// parameters of the material and possible values
uniform vec3 u_matAmbientReflectances; 
uniform vec3 u_matDiffuseReflectances; 
uniform vec3 u_matSpecularReflectances; 
uniform float u_matShininess; 

in vec3 o_normal;
in vec3 o_toLight;
in vec3 o_toCamera;
//in vec3 texture;

//uniform sampler2D ourTexture;

out vec4 resultingColor;

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
   // normalize vectors after interpolation
   vec3 L = normalize(o_toLight);  // deberia ser normalize(u_toLightDirection); porque son todas los vectores que inciden sobre el vertice
   vec3 N = normalize(o_normal);
   vec3 V = normalize(o_toCamera);
   vec3 R = normalize(reflect(L, N));

   // get Blinn-Phong reflectance components
   vec3 Iamb =  ambientLighting();
   vec3 Idif = diffuseLighting(N, L);
   vec3 Ispe = specularLighting(N, L, V);

   // combination of all components and diffuse color of the object
   //resultingColor.xyz = texture2D(ourTexture ,vec2(texture.x,texture.y));
   resultingColor.xyz = Iamb + Idif + Ispe;
   resultingColor.a = 1.0;
} 
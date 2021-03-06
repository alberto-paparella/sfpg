#version 430 core

layout(location=0) in vec4 objCoords;
layout(location=1) in vec3 objNormals;
layout(location=2) in vec2 objTexCoords;

// Globals
uniform mat4 projMat;
uniform mat4 modelViewMat;
uniform mat3 normalMat;
uniform uint object;

out vec4 frontAmbDiffExport, frontSpecExport, backAmbDiffExport, backSpecExport;
out vec2 texCoordsExport;

struct Light {
   vec4 ambCols;
   vec4 difCols;
   vec4 specCols;
   vec4 coords;
};

uniform Light light0;
uniform vec4 globAmb;

struct Material {
   vec4 ambRefl;
   vec4 difRefl;
   vec4 specRefl;
   vec4 emitCols;
   float shininess;
};

uniform Material floorMatrl;

vec4 coords;
vec4 frontEmit, frontGlobAmb, frontAmb, frontDif, frontSpec, backEmit, backGlobAmb, backAmb, backDif, backSpec;
vec3 normal, lightDirection, eyeDirection, halfway;

void main(void)
{
   // The object we are plotting
   coords = objCoords;
   normal = objNormals;
   texCoordsExport = objTexCoords;

   normal = normalize(normalMat*normal);

   lightDirection = normalize(vec3(light0.coords));

   eyeDirection = -1.0f * normalize(vec3(modelViewMat*coords));

   halfway= (length(lightDirection+eyeDirection)==0.0f)?vec3(0.0):(lightDirection+eyeDirection)/length(lightDirection+eyeDirection);

   // Lighting calculation with Phong's model - FRONT FACE
   frontEmit = floorMatrl.emitCols;
   frontGlobAmb = globAmb * floorMatrl.ambRefl;
   frontAmb = light0.ambCols * floorMatrl.ambRefl;
   frontDif = max(dot(normal, lightDirection), 0.0f) * (light0.difCols*floorMatrl.difRefl);
   frontSpec = pow(max(dot(normal, halfway), 0.0f), floorMatrl.shininess) * (light0.specCols * floorMatrl.specRefl);
   frontAmbDiffExport = vec4(vec3(min(frontEmit + frontGlobAmb + frontAmb + frontDif, vec4(1.0))), 1.0);
   frontSpecExport = vec4(vec3(min(frontSpec, vec4(1.0))), 1.0);

   // Lighting calculation with Phong's model - BACK FACE
   normal = -1.0f * normal;
   backEmit = floorMatrl.emitCols;
   backGlobAmb = globAmb * floorMatrl.ambRefl;
   backAmb = light0.ambCols * floorMatrl.ambRefl;
   backDif = max(dot(normal, lightDirection), 0.0f) * (light0.difCols * floorMatrl.difRefl);
   backSpec = pow(max(dot(normal, halfway), 0.0f), floorMatrl.shininess) * (light0.specCols * floorMatrl.specRefl);
   backAmbDiffExport =  vec4(vec3(min(backEmit + backGlobAmb + backAmb + backDif, vec4(1.0))), 1.0);
   backSpecExport =  vec4(vec3(min(backSpec, vec4(1.0))), 1.0);

   gl_Position = projMat * modelViewMat * coords;
}

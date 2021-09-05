#version 430 core

#define FLOOR 0
#define WALLS 1

uniform vec4 wallsColor;

//material properties
in vec4 frontAmbDiffExport, frontSpecExport, backAmbDiffExport, backSpecExport;
//texture
in vec2 texCoordsExport;

// samplers for the textures
uniform sampler2D floorTex;

uniform uint object;
uniform vec4 sphColor;
vec4 texColor;

out vec4 colorsOut;

void main(void)
{
   if (object == FLOOR){
      texColor = texture(floorTex, texCoordsExport);
      colorsOut = frontAmbDiffExport * texColor + frontSpecExport;
   }else if (object == WALLS){
      colorsOut = frontAmbDiffExport * wallsColor + frontSpecExport;
   }

}
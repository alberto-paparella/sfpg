/**
 * File to generate basic shapes.
 *
 * IN DETAIL: the functions in this file fill the arrays given
 * with point coordinates.
 */

#include <GL/freeglut.h>
#include <cglm/cglm.h>
#include <cglm/types-struct.h>
#include <math.h>

#include "shapes.h"

/***
 * Floor.
 */

/**
 * Fills the arrays for coordinates, normals and texture-coordinates to generate a rectangle.
 * @param squVertices The vertices of the square.
 * @return Nothing.
 */
void fillSquVertexArray(Vertex squVertices[4]) {
    /* VERTEX 0 */
    /* Coordinates  */
    squVertices[0].coords.x = -70.0;
    squVertices[0].coords.y = -5.0;
    squVertices[0].coords.z = -70.0;
    squVertices[0].coords.w = 1.0;
    /* Normals      */
    squVertices[0].normal.x = 0.0;
    squVertices[0].normal.y = 1.0;
    squVertices[0].normal.z = 0.0;
    /* Texture      */
    squVertices[0].texCoords.x = 10.0;
    squVertices[0].texCoords.y = 0.0;

    /* VERTEX 1 */
    /* Coordinates  */
    squVertices[1].coords.x = -70.0;
    squVertices[1].coords.y = -5.0;
    squVertices[1].coords.z = 70.0;
    squVertices[1].coords.w = 1.0;
    /* Normals      */
    squVertices[1].normal.x = 0.0;
    squVertices[1].normal.y = 1.0;
    squVertices[1].normal.z = 0.0;
    /* Texture      */
    squVertices[1].texCoords.x = 0.0;
    squVertices[1].texCoords.y = 0.0;

    /* VERTEX 2 */
    /* Coordinates  */
    squVertices[2].coords.x = 70.0;
    squVertices[2].coords.y = -5.0;
    squVertices[2].coords.z = -70.0;
    squVertices[2].coords.w = 1.0;
    /* Normals      */
    squVertices[2].normal.x = 0.0;
    squVertices[2].normal.y = 1.0;
    squVertices[2].normal.z = 0.0;
    /* Texture      */
    squVertices[2].texCoords.x = 10.0;
    squVertices[2].texCoords.y = 10.0;

    /* VERTEX 3 */
    /* Coordinates  */
    squVertices[3].coords.x = 70.0;
    squVertices[3].coords.y = -5.0;
    squVertices[3].coords.z = 70.0;
    squVertices[3].coords.w = 1.0;
    /* Normals      */
    squVertices[3].normal.x = 0.0;
    squVertices[3].normal.y = 1.0;
    squVertices[3].normal.z = 0.0;
    /* Texture      */
    squVertices[3].texCoords.x = 0.0;
    squVertices[3].texCoords.y = 10.0;
}

/**
 * Fill the indices array for the quare.
 * @param squIndices[1][4] The indices array for the quare.
 * @return Nothing.
 */
void fillSquIndices(unsigned int squIndices[1][4]) {
    squIndices[0][0] = 0;
    squIndices[0][1] = 1;
    squIndices[0][2] = 2;
    squIndices[0][3] = 3;
}

/**
 * Fill the counts array for the quare.
 * @param squCounts[1] The counts array for the quare.
 * @return Nothing.
 */
void fillSquCounts(int squCounts[1]) {
    /* One triangle strip with 4 vertices. */
    squCounts[0] = 4;
}

/**
 * Fill the array of buffer offsets.
 * @param squOffsets[1] The offsets array for the quare.
 * @return Nothing.
 */
void fillSquOffsets(void* squOffsets[1]) {
    squOffsets[0] = 0;
}

/**
 * Fills the coordinates arrays and the pointers.
 * @param squVertices[4] The array that will contain the vertex coordinates data.
 * @param squCounts[1] The counts array for the square.
 * @param squOffsets[1] The offsets array for the square.
 * @return Nothing.
 */
void fillSqu(Vertex squVertices[4], unsigned int squIndices[1][4], int squCounts[1], void* squOffsets[1]) {
    fillSquVertexArray(squVertices);
    fillSquIndices(squIndices);
    fillSquOffsets(squOffsets);
    fillSquCounts(squCounts);
}

/***
 * Parallelepiped.
 */

/**
 * Fills the arrays for coordinates, normals and texture-coordinates to generate a parallelepiped.
 * @param center_position The center of the palallelepiped,.
 * @param X One half of the length on the X axys.
 * @param Y One half of the length on the Y axys.
 * @param Z One half of the length on the Z axys.
 * @param parVertices The vertex array to be filled.
 * @return Nothing.
 */
void fillParVertexArray(vec3 center_position, float X, float Y, float Z, Vertex parVertices[4*4]) {    
    /* FACE 0 */
    /* First rectangle */
    /* Coordinates  */
    parVertices[0].coords.x = center_position[0]+X;
    parVertices[0].coords.y = center_position[1]+Y;
    parVertices[0].coords.z = center_position[2]+Z;
    parVertices[0].coords.w = 1.0;
    /* Normals      */
    parVertices[0].normal.x = 0.0;
    parVertices[0].normal.y = 0.0;
    parVertices[0].normal.z = 1.0;
    /* Texture      */
    parVertices[0].texCoords.x = 3.0;
    parVertices[0].texCoords.y = 0.0;
    /* Second rectangle */
    /* Coordinates  */
    parVertices[1].coords.x = center_position[0]+X;
    parVertices[1].coords.y = center_position[1]-Y;
    parVertices[1].coords.z = center_position[2]+Z;
    parVertices[1].coords.w = 1.0;
    /* Normals      */
    parVertices[1].normal.x = 0.0;
    parVertices[1].normal.y = 0.0;
    parVertices[1].normal.z = 1.0;
    /* Texture      */
    parVertices[1].texCoords.x = 3.0;
    parVertices[1].texCoords.y = 1.0;
    /* Third rectangle  */
    /* Coordinates  */
    parVertices[2].coords.x = center_position[0]-X;
    parVertices[2].coords.y = center_position[1]+Y;
    parVertices[2].coords.z = center_position[2]+Z;
    parVertices[2].coords.w = 1.0;
    /* Normals      */
    parVertices[2].normal.x = 0.0;
    parVertices[2].normal.y = 0.0;
    parVertices[2].normal.z = 1.0;
    /* Texture      */
    parVertices[2].texCoords.x = 0.0;
    parVertices[2].texCoords.y = 0.0;
    /* Fourth rectangle */
    /* Coordinates  */
    parVertices[3].coords.x = center_position[0]-X;
    parVertices[3].coords.y = center_position[1]-Y;
    parVertices[3].coords.z = center_position[2]+Z;
    parVertices[3].coords.w = 1.0;
    /* Normals      */
    parVertices[3].normal.x = 0.0;
    parVertices[3].normal.y = 0.0;
    parVertices[3].normal.z = 1.0;
    /* Texture      */
    parVertices[3].texCoords.x = 0.0;
    parVertices[3].texCoords.y = 1.0;

    /* Face 1 */
    /* First rectangle  */
    /* Coordinates  */
    parVertices[4].coords.x = center_position[0]-X;
    parVertices[4].coords.y = center_position[1]+Y;
    parVertices[4].coords.z = center_position[2]+Z;
    parVertices[4].coords.w = 1.0;
    /* Normals      */
    parVertices[4].normal.x = -1.0;
    parVertices[4].normal.y = 0.0;
    parVertices[4].normal.z = 0.0;
    /* Texture      */
    parVertices[4].texCoords.x = 3.0;
    parVertices[4].texCoords.y = 0.0;
    /* Second rectangle */
    /* Coordinates  */
    parVertices[5].coords.x = center_position[0]-X;
    parVertices[5].coords.y = center_position[1]-Y;
    parVertices[5].coords.z = center_position[2]+Z;
    parVertices[5].coords.w = 1.0;
    /* Normals      */
    parVertices[5].normal.x = -1.0;
    parVertices[5].normal.y = 0.0;
    parVertices[5].normal.z = 0.0;
    /* Texture      */
    parVertices[5].texCoords.x = 3.0;
    parVertices[5].texCoords.y = 1.0;
    /* Third rectangle  */
    /* Coordinates  */
    parVertices[6].coords.x = center_position[0]-X;
    parVertices[6].coords.y = center_position[1]+Y;
    parVertices[6].coords.z = center_position[2]-Z;
    parVertices[6].coords.w = 1.0;
    /* Normals      */
    parVertices[6].normal.x = -1.0;
    parVertices[6].normal.y = 0.0;
    parVertices[6].normal.z = 0.0;
    /* Texture      */
    parVertices[6].texCoords.x = 0.0;
    parVertices[6].texCoords.y = 0.0;
    /* Fourth rectangle */
    /* Coordinates  */
    parVertices[7].coords.x = center_position[0]-X;
    parVertices[7].coords.y = center_position[1]-Y;
    parVertices[7].coords.z = center_position[2]-Z;
    parVertices[7].coords.w = 1.0;
    /* Normals      */
    parVertices[7].normal.x = -1.0;
    parVertices[7].normal.y = 0.0;
    parVertices[7].normal.z = 0.0;
    /* Texture      */
    parVertices[7].texCoords.x = 0.0;
    parVertices[7].texCoords.y = 1.0;

    /* Face 2 */
    /* First rectangle  */
    /* Coordinates  */
    parVertices[8].coords.x = center_position[0]-X;
    parVertices[8].coords.y = center_position[1]+Y;
    parVertices[8].coords.z = center_position[2]-Z;
    parVertices[8].coords.w = 1.0;
    /* Normals      */
    parVertices[8].normal.x = 0.0;
    parVertices[8].normal.y = 0.0;
    parVertices[8].normal.z = -1.0;
    /* Texture      */
    parVertices[8].texCoords.x = 3.0;
    parVertices[8].texCoords.y = 0.0;
    /* Second rectangle */
    /* Coordinates  */
    parVertices[9].coords.x = center_position[0]-X;
    parVertices[9].coords.y = center_position[1]-Y;
    parVertices[9].coords.z = center_position[2]-Z;
    parVertices[9].coords.w = 1.0;
    /* Normals      */
    parVertices[9].normal.x = 0.0;
    parVertices[9].normal.y = 0.0;
    parVertices[9].normal.z = -1.0;
    /* Texture      */
    parVertices[9].texCoords.x = 3.0;
    parVertices[9].texCoords.y = 1.0;
    /* Third rectangle  */
    /* Coordinates  */
    parVertices[10].coords.x = center_position[0]+X;
    parVertices[10].coords.y = center_position[1]+Y;
    parVertices[10].coords.z = center_position[2]-Z;
    parVertices[10].coords.w = 1.0;
    /* Normals      */
    parVertices[10].normal.x = 0.0;
    parVertices[10].normal.y = 0.0;
    parVertices[10].normal.z = -1.0;
    /* Texture      */
    parVertices[10].texCoords.x = 0.0;
    parVertices[10].texCoords.y = 0.0;
    /* Fourth rectangle */
    /* Coordinates  */
    parVertices[11].coords.x = center_position[0]+X;
    parVertices[11].coords.y = center_position[1]-Y;
    parVertices[11].coords.z = center_position[2]-Z;
    parVertices[11].coords.w = 1.0;
    /* Normals      */
    parVertices[11].normal.x = 0.0;
    parVertices[11].normal.y = 0.0;
    parVertices[11].normal.z = -1.0;
    /* Texture      */
    parVertices[11].texCoords.x = 0.0;
    parVertices[11].texCoords.y = 1.0;

    /* Face 3 */
    /* First rectangle  */
    /* Coordinates  */
    parVertices[12].coords.x = center_position[0]+X;
    parVertices[12].coords.y = center_position[1]+Y;
    parVertices[12].coords.z = center_position[2]-Z;
    parVertices[12].coords.w = 1.0;
    /* Normals      */
    parVertices[12].normal.x = 1.0;
    parVertices[12].normal.y = 0.0;
    parVertices[12].normal.z = 0.0;
    /* Texture      */
    parVertices[12].texCoords.x = 3.0;
    parVertices[12].texCoords.y = 0.0;
    /* Second rectangle */
    /* Coordinates  */
    parVertices[13].coords.x = center_position[0]+X;
    parVertices[13].coords.y = center_position[1]-Y;
    parVertices[13].coords.z = center_position[2]-Z;
    parVertices[13].coords.w = 1.0;
    /* Normals      */
    parVertices[13].normal.x = 1.0;
    parVertices[13].normal.y = 0.0;
    parVertices[13].normal.z = 0.0;
    /* Texture      */
    parVertices[13].texCoords.x = 3.0;
    parVertices[13].texCoords.y = 1.0;
    /* Third rectangle */
    /* Coordinates  */
    parVertices[14].coords.x = center_position[0]+X;
    parVertices[14].coords.y = center_position[1]+Y;
    parVertices[14].coords.z = center_position[2]+Z;
    parVertices[14].coords.w = 1.0;
    /* Normals      */
    parVertices[14].normal.x = 1.0;
    parVertices[14].normal.y = 0.0;
    parVertices[14].normal.z = 0.0;
    /* Texture      */
    parVertices[14].texCoords.x = 0.0;
    parVertices[14].texCoords.y = 0.0;
    /* Fourth rectangle */
    /* Coordinates  */
    parVertices[15].coords.x = center_position[0]+X;
    parVertices[15].coords.y = center_position[1]-Y;
    parVertices[15].coords.z = center_position[2]+Z;
    parVertices[15].coords.w = 1.0;
    /* Normals      */
    parVertices[15].normal.x = 1.0;
    parVertices[15].normal.y = 0.0;
    parVertices[15].normal.z = 0.0;
    /* Texture      */
    parVertices[15].texCoords.x = 0.0;
    parVertices[15].texCoords.y = 1.0;
}

/**
 * Fills the parallelepiped indixes array.
 * @param parIndices[4][4] The array to be filled.
 * @return Nothing.
 */
void fillParIndices(unsigned int parIndices[4][4]) {
    for(int v=0; v<4; v++) {
        for(int f=0; f<4; f++) {
            parIndices[v][f] = v*4+f;
            parIndices[v][f+1] = (v+1)*4+f;
        }
    }
}

/**
 * Fills the parallelepiped counts array.
 * @param parCounts[4] The array to be filled.
 * @return Nothing.
 */
void fillParCounts(int parCounts[4]) {
    /* Four triangle strips with 4 vertices each. */
    for(int f=0; f<4; f++){
        parCounts[f] = 4;
    }
}

/**
 * Fills the parallelepiped offets array.
 * @param parOffsets[4] The array to be filled.
 * @return Nothing.
 */
void fillParOffsets(void* parOffsets[4]) {
    for(int f = 0; f < 4; f++) 
      parOffsets[f] = (GLvoid*)(4*f*sizeof(unsigned int));
}

/**
 * Fills the coordinates arrays and the pointers
 * @param l1 The length of a side of the base rectangle.
 * @param l2 The length of a side of the base rectangle.
 * @param h The height of the parallelepiped.
 * @param parVertices[8] The array that will contain the vertex coordinates data.
 */
void fillPar(vec3 center_position, float X, float Y, float Z, Vertex parVertices[4*4],
             unsigned int parIndices[4][4], int parCounts[4], void* parOffsets[4]) {
    fillParVertexArray(center_position, X, Y, Z, parVertices);
    fillParIndices(parIndices);
    fillParCounts(parCounts);
    fillParOffsets(parOffsets);
}

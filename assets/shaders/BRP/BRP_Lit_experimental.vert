/* ********************************************************************************************* */
/* The mandatory part of the file begins here. */

#version 330 core
layout (location = 0) in vec3 iPos;
layout (location = 1) in vec3 iNormal;
layout (location = 2) in vec2 iTexCoord;

out Data {
    vec3 fragPos;
    vec3 normal;
    vec2 texCoord;
    vec4 fragPosLightSpace;
    //int drawDepthMap;
} data;

struct Matrix {
    mat4 transform;         // full transform matrix
    mat4 world;             // object's world matrix
    mat4 inversedWorld;     // object's inversed world matrix 
};



uniform Matrix matrix;




uniform mat4 lightSpaceMatrix;
uniform int DrawDepthMap;

/* The mandatory part of the file ends here. */
/* ********************************************************************************************* */


void main() {
    if (DrawDepthMap == 1) {
        gl_Position = lightSpaceMatrix * matrix.world * vec4(iPos, 1.0);
        //data.drawDepthMap = DrawDepthMap;
    }
    else {
        data.fragPos = vec3(matrix.world * vec4(iPos, 1.0));
        data.normal = mat3(transpose(matrix.inversedWorld)) * iNormal;
        data.texCoord = iTexCoord;
        data.fragPosLightSpace = lightSpaceMatrix * vec4(data.fragPos, 1.0);

        gl_Position = matrix.transform * vec4(iPos, 1.0);
    }
}
#version 330 core
layout (location = 0) in vec3 iPos;
layout (location = 1) in vec2 iTexCoord;

out vec2 vTexCoord;

uniform mat4 uTransformMatrix;
uniform mat4 uWorldMatrix;
uniform mat4 uInversedWorldMatrix;

void main() {
    gl_Position = uTransformMatrix * vec4(iPos, 1.0);
    vTexCoord = iTexCoord;
}
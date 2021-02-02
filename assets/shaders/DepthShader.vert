#version 330 core
layout (location = 0) in vec3 iPos;

uniform mat4 lightSpaceMatrix;

void main() {
    gl_Position = lightSpaceMatrix * vec4(iPos, 1.0);
}
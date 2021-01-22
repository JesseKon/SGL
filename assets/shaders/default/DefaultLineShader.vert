#version 330 core
layout (location = 0) in vec3 iPos;

uniform mat4 uTransform;

void main() {
    gl_Position = uTransform * vec4(iPos, 1.0);
}
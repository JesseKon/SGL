#version 330 core
layout (location = 0) in vec3 iPos;
layout (location = 1) in vec2 iTexCoord;

out vec2 vTexCoord;

uniform mat4 uTransform;

void main() {
    gl_Position = uTransform * vec4(iPos, 1.0);
    vTexCoord = iTexCoord;
}
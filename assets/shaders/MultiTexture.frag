#version 330 core
out vec4 FragColor;

in vec2 vTexCoord;

uniform sampler2D uTexture0;
uniform sampler2D uTexture1;

const float cfBlend = 0.5;

void main() {
    FragColor = mix(texture(uTexture0, vTexCoord), texture(uTexture1, vTexCoord), cfBlend);
}
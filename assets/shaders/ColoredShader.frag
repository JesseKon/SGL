#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform vec4 uFragColor;
uniform sampler2D uTexture;

void main() {
    FragColor = texture(uTexture, TexCoord);
}
/* ********************************************************************************************* */
/* The mandatory part of the file begins here. */

#version 330 core
out vec4 FragColor;

in vec3 vNormal;
in vec3 vFragPos;
in vec2 vTexCoord;

uniform sampler2D uTexture;

/* The mandatory part of the file ends here. */
/* ********************************************************************************************* */


// TODO: clean up

// https://learnopengl.com/Lighting/Materials
uniform vec4 uObjectColor;
uniform vec4 uAmbientColor;
uniform vec4 uLightPos;  // Should be vec3...
uniform vec4 uLightColor;
uniform vec4 uViewPos;

void main() {

    // Diffuse
    vec3 norm = normalize(vNormal);
    vec3 lightDir = normalize(uLightPos.xyz - vFragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * uLightColor.xyz;

    // Specular
    float specularStrength = 0.5;
    vec3 viewDir = normalize(uViewPos.xyz - vFragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * uLightColor.xyz;

    vec3 result = (uAmbientColor.xyz + diffuse + specular) * uObjectColor.xyz;
    FragColor = texture(uTexture, vTexCoord) * vec4(result, 1.0);
}
/* ********************************************************************************************* */
/* The mandatory part of the file begins here. */

#version 330 core
out vec4 FragColor;

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};

struct PointLight {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};

uniform Material material;
uniform PointLight light;

in vec3 vFragPos;
in vec3 vNormal;
in vec2 vTexCoord;


//uniform sampler2D uTexture;

uniform vec4 uObjectColor;
// uniform vec4 uAmbientColor;



/* The mandatory part of the file ends here. */
/* ********************************************************************************************* */

// TODO: clean up
//uniform vec4 uAmbientColor;
//uniform vec4 uLightColor;
uniform vec4 uLightPos;  // Should be vec3...
uniform vec4 uViewPos;



void main() {

    float distance = length(light.position - vFragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance +
        light.quadratic * (distance * distance));

    // ambient
    vec3 ambient = light.ambient * vec3(texture(material.diffuse, vTexCoord));

    // diffuse 
    vec3 norm = normalize(vNormal);
    vec3 lightDir = normalize(light.position - vFragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, vTexCoord));
    
    // specular
    vec3 viewDir = normalize(uViewPos.xyz - vFragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * vec3(texture(material.specular, vTexCoord));

    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    // result
    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
}
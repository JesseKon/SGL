/* ********************************************************************************************* */
/* The mandatory part of the file begins here. */

#version 330 core
out vec4 FragColor;

in Data {
    vec3 fragPos;
    vec3 normal;
    vec2 texCoord;
} data;

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    vec3 color;
    float shininess;
};

struct AmbientLight {
    vec3 color;
    float strength;
};

struct Light {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Material material;
uniform AmbientLight ambientLight;
uniform Light light;

/* The mandatory part of the file ends here. */
/* ********************************************************************************************* */

// TODO: clean up
uniform vec4 uLightPos;  // Should be vec3...
uniform vec4 uLightColor;
uniform vec4 uViewPos;



void main() {

    // ambient
    vec3 ambient = 
        ambientLight.color * ambientLight.strength *
        vec3(texture(material.diffuse, data.texCoord));

    // diffuse 
    vec3 norm = normalize(data.normal);
    vec3 lightDir = normalize(light.position - data.fragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, data.texCoord));
    
    // specular
    vec3 viewDir = normalize(uViewPos.xyz - data.fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * vec3(texture(material.specular, data.texCoord));

    // result
    vec3 result = (ambient + diffuse + specular) * material.color;
    FragColor = vec4(result, 1.0);
}
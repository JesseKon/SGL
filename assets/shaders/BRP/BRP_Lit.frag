/* ********************************************************************************************* */
/* The mandatory part of the file begins here. */

#version 330 core
out vec4 FragColor;

#define MAX_DIRECTIONAL_LIGHTS 4
#define MAX_POINT_LIGHTS 16
#define MAX_SPOT_LIGHTS 16

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

struct DirectionalLight {
    int active;
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct PointLight {
    int active;
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};

struct SpotLight {
    int active;
    vec3 position;
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float cutOff;
    float outerCutOff;
    float constant;
    float linear;
    float quadratic;
};

uniform vec3 viewPos;
uniform Material material;
uniform DirectionalLight directionalLight[MAX_DIRECTIONAL_LIGHTS];
uniform PointLight pointLight[MAX_POINT_LIGHTS];
uniform SpotLight spotLight[MAX_SPOT_LIGHTS];

/* The mandatory part of the file ends here. */
/* ********************************************************************************************* */

// function prototypes
vec3 calculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDir);
vec3 calculatePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 calculateSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);


void main() {
    vec3 norm = normalize(data.normal);
    vec3 viewDir = normalize(viewPos - data.fragPos);
    vec3 result = vec3(0.0);

    for (int i = 0; i < MAX_DIRECTIONAL_LIGHTS; ++i)
        if (directionalLight[i].active != 0)
            result += calculateDirectionalLight(directionalLight[i], norm, viewDir);

    for (int i = 0; i < MAX_POINT_LIGHTS; ++i)
        if (pointLight[i].active != 0)
            result += calculatePointLight(pointLight[i], norm, data.fragPos, viewDir);

    for (int i = 0; i < MAX_SPOT_LIGHTS; ++i) 
        if (spotLight[i].active != 0)
            result += calculateSpotLight(spotLight[i], norm, data.fragPos, viewDir);

    result *= material.color;
    FragColor = vec4(result, 1.0);
}

/* ********* */
vec3 calculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDir) {
    vec3 lightDir = normalize(-light.direction);
    vec3 halfwayDir = normalize(lightDir + viewDir);
    float diff = max(dot(normal, lightDir), 0.0);
    float spec = pow(max(dot(viewDir, halfwayDir), 0.0), material.shininess);

    vec3 ambient = light.ambient * vec3(texture(material.diffuse, data.texCoord));
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, data.texCoord));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, data.texCoord));
    return ambient + diffuse + specular;
}

/* ********* */
vec3 calculatePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir) {
    vec3 lightDir = normalize(light.position - fragPos);
    vec3 halfwayDir = normalize(lightDir + viewDir);
    float diff = max(dot(normal, lightDir), 0.0);
    float spec = pow(max(dot(viewDir, halfwayDir), 0.0), material.shininess);
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance +
        light.quadratic * (distance * distance));

    vec3 ambient = light.ambient * vec3(texture(material.diffuse, data.texCoord));
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, data.texCoord));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, data.texCoord));
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    return ambient + diffuse + specular;
}

/* ********* */
vec3 calculateSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir) {
    vec3 lightDir = normalize(light.position - fragPos);
    vec3 halfwayDir = normalize(lightDir + viewDir);
    float diff = max(dot(normal, lightDir), 0.0);
    float spec = pow(max(dot(viewDir, halfwayDir), 0.0), material.shininess);
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance +
        light.quadratic * (distance * distance));

    float theta = dot(lightDir, normalize(-light.direction));
    float epsilon = light.cutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);

    vec3 ambient = light.ambient * vec3(texture(material.diffuse, data.texCoord));
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, data.texCoord));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, data.texCoord));
    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;
    return ambient + diffuse + specular;
}
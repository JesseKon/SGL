/* ********************************************************************************************* */
/* The mandatory part of the file begins here. */

#version 330 core
out vec4 FragColor;

#define MAX_DIRECTIONAL_LIGHTS 1
#define MAX_POINT_LIGHTS 4
#define MAX_SPOT_LIGHTS 4

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

uniform float near_plane;
uniform float far_plane;

// required when using a perspective projection matrix
float LinearizeDepth(float depth)
{
    float z = depth * 2.0 - 1.0; // Back to NDC 
    return (2.0 * near_plane * far_plane) / (far_plane + near_plane - z * (far_plane - near_plane));	
}

void main()
{             
    float depthValue = texture(material.diffuse, data.texCoord).r;
    //FragColor = vec4(vec3(LinearizeDepth(depthValue) / far_plane), 1.0); // perspective
    //FragColor = vec4(vec3(depthValue), 1.0); // orthographic


    FragColor = vec4(texture(material.diffuse, data.texCoord));
}


#include "BRP_Shader.h"

namespace SGL {

    BRP_Shader::BRP_Shader(
    ) noexcept {

    }


    BRP_Shader::BRP_Shader(
        const std::string& vertexShaderFile,
        const std::string& fragmentShaderFile
    ) : ShaderGLSL(
        vertexShaderFile,
        fragmentShaderFile) 
    {

    }


    BRP_Shader::~BRP_Shader(
    ) noexcept {

    }


    auto BRP_Shader::setDirectionalLight(
        const glm::vec3& direction,
        const glm::vec3& ambient,
        const glm::vec3& diffuse,
        const glm::vec3& specular
    ) noexcept -> void {
        setActive();
    }

}


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


    auto BRP_Shader::setAmbientLight(
        const glm::vec3& color,
        const float strength
    ) noexcept -> void {
        setActive();
        setVector3("ambientLight.color", color);
        setFloat("ambientLight.strength", strength);
    }

}
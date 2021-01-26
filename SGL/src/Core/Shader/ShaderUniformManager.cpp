

#include "ShaderUniformManager.h"

namespace SGL {

    /* ***************************************************************************************** */
    ShaderUniformManager::ShaderUniformManager(
    ) {

    }


    /* ***************************************************************************************** */
    ShaderUniformManager::~ShaderUniformManager(
    ) noexcept {

    }


    /* ***************************************************************************************** */
    auto ShaderUniformManager::setInt(
        const std::string& uniformName,
        const std::int32_t value
    ) noexcept -> void {
        auto it = std::find_if(m_Uniforms.begin(), m_Uniforms.end(),
            [&](const Uniform& uniform) { return uniform.uniformName == uniformName; });

        if (it != m_Uniforms.end())
            m_Uniforms.at(std::distance(m_Uniforms.begin(), it)) = { UniformType::Int, uniformName, value };
        else
            m_Uniforms.push_back({ UniformType::Int, uniformName, value });
    }


    /* ***************************************************************************************** */
    auto ShaderUniformManager::setFloat(
        const std::string& uniformName,
        const float value
    ) noexcept -> void {
        auto it = std::find_if(m_Uniforms.begin(), m_Uniforms.end(),
            [&](const Uniform& uniform) { return uniform.uniformName == uniformName; });

        if (it != m_Uniforms.end())
            m_Uniforms.at(std::distance(m_Uniforms.begin(), it)) = { UniformType::Float, uniformName, value };
        else
            m_Uniforms.push_back({ UniformType::Float, uniformName, value });
    }


    /* ***************************************************************************************** */
    auto ShaderUniformManager::setVector4(
        const std::string& uniformName,
        const glm::vec4& value
    ) noexcept -> void {
        auto it = std::find_if(m_Uniforms.begin(), m_Uniforms.end(),
            [&](const Uniform& uniform) { return uniform.uniformName == uniformName; });

        if (it != m_Uniforms.end())
            m_Uniforms.at(std::distance(m_Uniforms.begin(), it)) = { UniformType::Vector4, uniformName, value };
        else
            m_Uniforms.push_back({ UniformType::Vector4, uniformName, value });
    }


    /* ***************************************************************************************** */
    auto ShaderUniformManager::setMatrix4(
        const std::string& uniformName,
        const Matrix4& value
    ) noexcept -> void {
        auto it = std::find_if(m_Uniforms.begin(), m_Uniforms.end(),
            [&](const Uniform& uniform) { return uniform.uniformName == uniformName; });

        if (it != m_Uniforms.end())
            m_Uniforms.at(std::distance(m_Uniforms.begin(), it)) = { UniformType::Matrix4, uniformName, value };
        else
            m_Uniforms.push_back({ UniformType::Matrix4, uniformName, value });
    }


    /* ***************************************************************************************** */
    auto ShaderUniformManager::activateAll(
        const ShaderGLSL* shader
    ) const noexcept -> void {
        for (auto it = m_Uniforms.begin(); it != m_Uniforms.end(); ++it) {
            switch (it->uniformType) {
            case UniformType::Int:
                shader->setInt(it->uniformName, std::get<0>(it->value));
                break;

            case UniformType::Float:
                shader->setFloat(it->uniformName, std::get<float>(it->value));
                break;

            case UniformType::Vector4:
                shader->setVector4(it->uniformName, std::get<glm::vec4>(it->value));
                break;

            case UniformType::Matrix4:
                shader->setMatrix4(it->uniformName, std::get<Matrix4>(it->value));
                break;
            }
        }
    }

}
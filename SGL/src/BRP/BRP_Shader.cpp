

#include "BRP_Shader.h"

namespace SGL {

    /* ***************************************************************************************** */
    BRP_Shader::BRP_Shader(
    ) noexcept {
        m_DirectionalLights = { nullptr };
        m_PointLights = { nullptr };
        m_SpotLights = { nullptr };
    }


    /* ***************************************************************************************** */
    BRP_Shader::BRP_Shader(
        const std::string& vertexShaderFile,
        const std::string& fragmentShaderFile
    ) : ShaderGLSL(
        vertexShaderFile,
        fragmentShaderFile) 
    {
        m_DirectionalLights = { nullptr };
        m_PointLights = { nullptr };
        m_SpotLights = { nullptr };
    }


    /* ***************************************************************************************** */
    BRP_Shader::~BRP_Shader(
    ) noexcept {
        m_DirectionalLights = { nullptr };
        m_PointLights = { nullptr };
        m_SpotLights = { nullptr };
    }


    /* ***************************************************************************************** */
    auto BRP_Shader::setDirectionalLight(
        const DirectionalLight* light
    ) -> void {
        m_DirectionalLights.at(light->id) = light;
    }


    /* ***************************************************************************************** */
    auto BRP_Shader::setPointLight(
        const PointLight* light
    ) -> void {
        m_PointLights.at(light->id) = light;
    }


    /* ***************************************************************************************** */
    auto BRP_Shader::setSpotLight(
        const SpotLight* light
    ) -> void {
        m_SpotLights.at(light->id) = light;
    }


    /* ***************************************************************************************** */
    auto BRP_Shader::updateLights(
    ) const noexcept -> void {
        setActive();

        // Update directional lights
        std::for_each(m_DirectionalLights.begin(), m_DirectionalLights.end(),
            [&](const DirectionalLight* light) {
                if (!light) return;

                std::string uniformName = "directionalLight[" + std::to_string(light->id) + std::string("]");
                setInt(uniformName + ".active", light->isActive);
                setVector3(uniformName + ".direction", light->direction);
                setVector3(uniformName + ".ambient", light->ambientColor);
                setVector3(uniformName + ".diffuse", light->diffuseColor);
                setVector3(uniformName + ".specular", light->specularColor);
            }
        );

        // Update point lights
        std::for_each(m_PointLights.begin(), m_PointLights.end(),
            [&](const PointLight* light) {
                if (!light) return;

                std::string uniformName = "pointLight[" + std::to_string(light->id) + std::string("]");
                setInt(uniformName + ".active", light->isActive);
                setVector3(uniformName + ".position", light->position);
                setVector3(uniformName + ".ambient", light->ambientColor);
                setVector3(uniformName + ".diffuse", light->diffuseColor);
                setVector3(uniformName + ".specular", light->specularColor);

                setFloat(uniformName + ".constant", 1.0f);
                setFloat(uniformName + ".linear", 4.5f / light->distance);
                setFloat(uniformName + ".quadtratic", 75.0f / (light->distance * light->distance));
            }
        );

        // Update spot lights
        std::for_each(m_SpotLights.begin(), m_SpotLights.end(),
            [&](const SpotLight* light) {
                if (!light) return;

                std::string uniformName = "spotLight[" + std::to_string(light->id) + std::string("]");
                setInt(uniformName + ".active", light->isActive);
                setVector3(uniformName + ".position", light->position);
                setVector3(uniformName + ".direction", light->direction);
                setVector3(uniformName + ".ambient", light->ambientColor);
                setVector3(uniformName + ".diffuse", light->diffuseColor);
                setVector3(uniformName + ".specular", light->specularColor);

                setFloat(uniformName + ".cutOff", glm::cos(glm::radians(light->innerCutOff)));
                setFloat(uniformName + ".outerCutOff", glm::cos(glm::radians(light->outerCutOff)));
                setFloat(uniformName + ".constant", 1.0f);
                setFloat(uniformName + ".linear", 4.5f / light->distance);
                setFloat(uniformName + ".quadtratic", 75.0f / (light->distance * light->distance));
            }
        );
    }

}


#ifndef _SGL_BRP_SHADER_H_
#define _SGL_BRP_SHADER_H_

#include "SGLCore.h"

#include "ShaderGLSL.h"
#include "Color.h"

namespace SGL {

    /// <summary>
    /// 
    /// </summary>
    struct DirectionalLight {
        DirectionalLight(
        ) :
            id(0),
            isActive(true),
            direction(glm::vec3(-0.2f, -0.5f, 1.0f)),
            ambientColor(glm::vec3(0.08f, 0.08f, 0.08f)),
            diffuseColor(glm::vec3(0.0f, 0.0f, 0.0f)),
            specularColor(glm::vec3(0.0f, 0.0f, 0.0f))
        {}

        DirectionalLight(
            const std::int32_t id_,
            const bool isActive_,
            const glm::vec3 direction_,
            const glm::vec3 ambientColor_,
            const glm::vec3 diffuseColor_,
            const glm::vec3 specularColor_
        ) :
            id(id_),
            isActive(isActive_),
            direction(direction_),
            ambientColor(ambientColor_),
            diffuseColor(diffuseColor_),
            specularColor(specularColor_)
        {}

        std::int32_t id;
        bool isActive;

        glm::vec3 direction;
        glm::vec3 ambientColor;
        glm::vec3 diffuseColor;
        glm::vec3 specularColor;
    };


    /// <summary>
    /// 
    /// </summary>
    struct PointLight {
        // TODO: constructor

        std::int32_t id;
        bool isActive;

        glm::vec3 position;
        glm::vec3 ambientColor;
        glm::vec3 diffuseColor;
        glm::vec3 specularColor;

        float distance;
    };


    struct SpotLight {
        // TODO: constructor

        std::int32_t id;
        bool isActive;

        glm::vec3 position;
        glm::vec3 direction;
        glm::vec3 ambientColor;
        glm::vec3 diffuseColor;
        glm::vec3 specularColor;

        float distance;
        float innerCutOff;
        float outerCutOff;
    };

    /// <summary>
    /// 
    /// </summary>
    class BRP_Shader : public ShaderGLSL
    {
    public:

        SGL_API BRP_Shader(
        ) noexcept;


        SGL_API BRP_Shader(
            const std::string& vertexShaderFile,
            const std::string& fragmentShaderFile
        );


        SGL_API ~BRP_Shader(
        ) noexcept;


        auto SGL_API setDirectionalLight(
            const DirectionalLight* light
        ) -> void;


        auto SGL_API setPointLight(
            const PointLight* light
        ) -> void;


        auto SGL_API setSpotLight(
            const SpotLight* light
        ) -> void;

        auto SGL_API updateLights(
        ) const noexcept -> void;


    private:
        std::array<const DirectionalLight*, 4> m_DirectionalLights;
        std::array<const PointLight*, 16> m_PointLights;
        std::array<const SpotLight*, 16> m_SpotLights;
    };
}

#endif
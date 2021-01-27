

#ifndef _SGL_BRP_SHADER_UNIFORM_MANAGER_H_
#define _SGL_BRP_SHADER_UNIFORM_MANAGER_H_

#include "SGLCore.h"
#include "ShaderGLSL.h"


namespace SGL {

    class BRP_ShaderUniformManager
    {
    public:

        SGL_API BRP_ShaderUniformManager(
        );


        SGL_API ~BRP_ShaderUniformManager(
        ) noexcept;


        auto SGL_API setInt(
            const std::string& uniformName,
            const std::int32_t value
        ) noexcept -> void;


        auto SGL_API setFloat(
            const std::string& uniformName,
            const float value
        ) noexcept -> void;


        auto SGL_API setVector3(
            const std::string& uniformName,
            const glm::vec3& value
        ) noexcept -> void;


        auto SGL_API setVector4(
            const std::string& uniformName,
            const glm::vec4& value
        ) noexcept -> void;


        auto SGL_API setMatrix4(
            const std::string& uniformName,
            const Matrix4& value
        ) noexcept -> void;


        auto SGL_API activateAll(
            const ShaderGLSL* shader
        ) const noexcept -> void;


    private:

        enum class UniformType {
            Int,
            Float,
            Vector3,
            Vector4,
            Matrix4
        };

        struct Uniform {
            UniformType uniformType;
            std::string uniformName;
            std::variant<std::int32_t, float, glm::vec3, glm::vec4, Matrix4> value;
        };
        std::vector<Uniform> m_Uniforms;

    };

}

#endif

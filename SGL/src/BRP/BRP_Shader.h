

#ifndef _SGL_BRP_SHADER_H_
#define _SGL_BRP_SHADER_H_

#include "SGLCore.h"

#include "ShaderGLSL.h"
#include "Color.h"

namespace SGL {

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


        auto SGL_API setAmbientLight(
            const glm::vec3& color,
            const float strength
        ) noexcept -> void;


    private:

    };
}

#endif
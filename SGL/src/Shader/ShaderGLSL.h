/**
 *
 *
 *
 */

#ifndef _SGL_SHADERGLSL_H_
#define _SGL_SHADERGLSL_H_

#include "SGLCore.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


namespace SGL {

    class ShaderGLSL
    {
    public:

        /**
         * 
         */
        SGL_API ShaderGLSL(
        ) noexcept;


        /**
         * 
         */
        SGL_API ShaderGLSL(
            const std::string& vertexShaderFile,
            const std::string& fragmentShaderFile
        );


        /**
         * 
         */
        SGL_API ~ShaderGLSL(
        ) noexcept;


        /**
         * 
         */
        auto SGL_API create(
            const std::string& vertexShaderFile,
            const std::string& fragmentShaderFile
        ) -> void;


        /**
         * 
         */
        auto SGL_API destroy(
        ) noexcept -> void;


        /**
         * 
         */
        auto SGL_API use(
        ) const noexcept -> void;


        /**
         * 
         */
        auto SGL_API setVector4(
            const std::string& uniformName,
            const glm::vec4& value
        ) noexcept -> void;


        /**
         *
         */
        auto SGL_API setMatrix4(
            const std::string& uniformName,
            const glm::mat4& value
        ) noexcept -> void;


    private:
        GLuint m_ProgramID;

    };

}  /* namespace SGL */

#endif  /* _SGL_SHADERGLSL_H_ */
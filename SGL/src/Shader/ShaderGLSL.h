/**
 *
 *
 *
 */

#ifndef _SGL_SHADERGLSL_H_
#define _SGL_SHADERGLSL_H_

#include "SGLCore.h"


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


    private:
        GLuint m_ProgramID;

    };

}  /* namespace SGL */

#endif  /* _SGL_SHADERGLSL_H_ */
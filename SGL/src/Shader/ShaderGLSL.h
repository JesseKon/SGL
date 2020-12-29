/**
 *
 *
 *
 */

#ifndef _SGL_SHADERGLSL_H_
#define _SGL_SHADERGLSL_H_

#include "SGLCore.h"
#include "Matrix4.h"
#include "TextureUnit.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


namespace SGL {

    class ShaderGLSL
    {
    public:

        /// <summary>
        /// Default constructor.
        /// </summary>
        /// 
        /// <returns></returns>
        SGL_API ShaderGLSL(
        ) noexcept;


        /// <summary>
        /// Create a new shader from given shader code files.
        /// </summary>
        /// 
        /// <param name="vertexShaderFile">
        /// The file that contains the vertex shader code.
        /// </param>
        /// 
        /// <param name="fragmentShaderFile">
        /// The file that contains the fragment shader code.
        /// </param>
        /// 
        /// <returns></returns>
        SGL_API ShaderGLSL(
            const std::string& vertexShaderFile,
            const std::string& fragmentShaderFile
        );


        /// <summary>
        /// Destructor.
        /// </summary>
        /// 
        /// <returns></returns>
        SGL_API ~ShaderGLSL(
        ) noexcept;


        /// <summary>
        /// Create a new shader from given shader code files.
        /// </summary>
        /// 
        /// <param name="vertexShaderFile">
        /// The file that contains the vertex shader code.
        /// </param>
        /// 
        /// <param name="fragmentShaderFile">
        /// The file that contains the fragment shader code.
        /// </param>
        /// 
        /// <returns></returns>
        auto SGL_API create(
            const std::string& vertexShaderFile,
            const std::string& fragmentShaderFile
        ) -> void;


        /// <summary>
        /// Destroy this shader.
        /// </summary>
        /// 
        /// <returns></returns>
        auto SGL_API destroy(
        ) noexcept -> void;


        /// <summary>
        /// Set this shader active for the following draw commands.
        /// </summary>
        /// 
        /// <returns></returns>
        auto SGL_API use(
        ) const noexcept -> void;


        /// <summary>
        /// 
        /// </summary>
        /// <param name="uniformName"></param>
        /// <param name="value"></param>
        /// <returns></returns>
        auto SGL_API setTextureUnit(
            const std::string& textureName,
            const TextureUnit::type textureUnit
        ) noexcept -> void;


        /// <summary>
        /// 
        /// </summary>
        /// <param name="uniformName"></param>
        /// <param name="value"></param>
        /// <returns></returns>
        auto SGL_API setInt(
            const std::string& uniformName,
            const std::int32_t& value
        ) noexcept -> void;


        /// <summary>
        /// 
        /// </summary>
        /// <param name="uniformName"></param>
        /// <param name="value"></param>
        /// <returns></returns>
        auto SGL_API setVector4(
            const std::string& uniformName,
            const glm::vec4& value
        ) noexcept -> void;


        /// <summary>
        /// 
        /// </summary>
        /// <param name="uniformName"></param>
        /// <param name="value"></param>
        /// <returns></returns>
        auto SGL_API setMatrix4(
            const std::string& uniformName,
            const glm::mat4& value
        ) noexcept -> void;


    private:
        GLuint m_ProgramID;

    };

}  /* namespace SGL */

#endif  /* _SGL_SHADERGLSL_H_ */
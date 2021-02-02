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

    /// <summary>
    /// Shader class. Use GLSL version 330 core.
    /// </summary>
    class ShaderGLSL
    {
    public:

        /// <summary>
        /// Default constructor.
        /// </summary>
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
        SGL_API ShaderGLSL(
            const std::string& vertexShaderFile,
            const std::string& fragmentShaderFile
        );


        /// <summary>
        /// Destructor.
        /// </summary>
        /// 
        /// <returns></returns>
        virtual SGL_API ~ShaderGLSL(
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
        /// Set texture unit for the corresponding sampler2D uniform.
        /// </summary>
        /// 
        /// <param name="uniformName">
        /// The sampler2D uniform name.
        /// </param>
        /// 
        /// <param name="textureUnit">
        /// The texture unit to be binded to this sampler2D uniform.
        /// </param>
        auto SGL_API setTextureUnit(
            const std::string& uniformName,
            const TextureUnit::type textureUnit
        ) const noexcept -> void;


        /// <summary>
        /// Set this shader active for subsequent commands. Shader has to be set active before
        /// its uniforms can be altered.
        /// </summary>
        auto SGL_API setActive(
        ) const noexcept -> void;


        /// <summary>
        /// Set uniform to given value.
        /// </summary>
        /// 
        /// <param name="uniformName">
        /// The uniform to be altered.
        /// </param>
        /// 
        /// <param name="value">
        /// New value for the uniform.
        /// </param>
        auto SGL_API setInt(
            const std::string& uniformName,
            const std::int32_t value
        ) const noexcept -> void;


        /// <summary>
        /// Set uniform to given value.
        /// </summary>
        /// 
        /// <param name="uniformName">
        /// The uniform to be altered.
        /// </param>
        /// 
        /// <param name="value">
        /// New value for the uniform.
        /// </param>
        auto SGL_API setFloat(
            const std::string& uniformName,
            const float value
        ) const noexcept -> void;


        /// <summary>
        /// 
        /// </summary>
        /// <param name="uniformName"></param>
        /// <param name="value"></param>
        /// <returns></returns>
        auto SGL_API setVector3(
            const std::string& uniformName,
            const glm::vec3& value
        ) const noexcept -> void;


        /// <summary>
        /// Set uniform to given value.
        /// </summary>
        /// 
        /// <param name="uniformName">
        /// The uniform to be altered.
        /// </param>
        /// 
        /// <param name="value">
        /// New value for the uniform.
        /// </param>
        auto SGL_API setVector4(
            const std::string& uniformName,
            const glm::vec4& value
        ) const noexcept -> void;


        /// <summary>
        /// Set uniform to given value.
        /// </summary>
        /// 
        /// <param name="uniformName">
        /// The uniform to be altered.
        /// </param>
        /// 
        /// <param name="value">
        /// New value for the uniform.
        /// </param>
        auto SGL_API setMatrix4(
            const std::string& uniformName,
            const Matrix4& value
        ) const noexcept -> void;


    protected:
        GLuint m_ProgramID;

    };

}  /* namespace SGL */

#endif  /* _SGL_SHADERGLSL_H_ */
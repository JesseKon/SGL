/**
 * 
 * 
 * 
 */

#ifndef _SGL_TRANSFORM_H_
#define _SGL_TRANSFORM_H_

#include "SGLCore.h"

#include "Vector2.h"
#include "Vector3.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


namespace SGL {

    class Matrix4
    {
    public:
    
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        SGL_API Matrix4(
        ) noexcept;


        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        SGL_API ~Matrix4(
        ) noexcept;


        /// <summary>
        /// 
        /// </summary>
        /// <param name="param"></param>
        /// <returns></returns>
        auto SGL_API operator* (
            const Matrix4& param
        ) noexcept -> Matrix4 {
            glm::mat4 temp = m_Matrix4 * param.toMat4();
            Matrix4 newMatrix4;
            newMatrix4.m_Matrix4 = temp;
            return newMatrix4;
        }


        /// <summary>
        /// 
        /// </summary>
        /// <param name="viewPort"></param>
        /// <param name="nearClipPlane"></param>
        /// <param name="farClipPlane"></param>
        /// <returns></returns>
        auto SGL_API createOrthoProjection(
            const Vector2<std::uint32_t>& viewPort,
            const float nearClipPlane = -1000.0f,
            const float farClipPlane = 1000.0f
        ) -> void;


        /// <summary>
        /// 
        /// </summary>
        /// <param name="viewPort"></param>
        /// <param name="fieldOfView"></param>
        /// <param name="nearClipPlane"></param>
        /// <param name="farClipPlane"></param>
        /// <returns></returns>
        auto SGL_API createPerspectiveProjection(
            const Vector2<std::uint32_t>& viewPort,
            const float fieldOfView,
            const float nearClipPlane = 0.1f,
            const float farClipPlane = 1000.0f
        ) -> void;


        /// <summary>
        /// 
        /// </summary>
        /// <param name="newPosition"></param>
        /// <returns></returns>
        auto SGL_API translate(
            const Vector3<float>& newPosition
        ) noexcept -> void;


        /// <summary>
        /// 
        /// </summary>
        /// <param name="newRotation"></param>
        /// <returns></returns>
        auto SGL_API rotate(
            const Vector3<float>& newRotation
        ) noexcept -> void;


        /// <summary>
        /// 
        /// </summary>
        /// <param name="newScale"></param>
        /// <returns></returns>
        auto SGL_API scale(
            const Vector3<float>& newScale
        ) noexcept -> void;


        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        auto SGL_API toMat4(
        ) const noexcept -> glm::mat4;

    
    private:
        glm::mat4 m_Matrix4;

    };

}  /* namespace SGL */

#endif  /* _SGL_TRANSFORM_H_ */
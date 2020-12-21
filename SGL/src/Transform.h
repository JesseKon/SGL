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

    class Transform 
    {
    public:
    
        /**
         * 
         */
        SGL_API Transform(
        ) noexcept;


        /**
         * 
         */
        SGL_API ~Transform(
        ) noexcept;


        /**
         * 
         */
        auto SGL_API createOrthoProjection(
            const Vector2<std::uint32_t>& viewPort,
            const float nearClipPlane = -1000.0f,
            const float farClipPlane = 1000.0f
        ) -> void;


        /**
         * 
         */
        auto SGL_API createPerspectiveProjection(
            const Vector2<std::uint32_t>& viewPort,
            const float fieldOfView,
            const float nearClipPlane = 0.1f,
            const float farClipPlane = 1000.0f
        ) -> void;


        auto SGL_API translate(
            const Vector3<float>& newPosition
        ) noexcept -> void;


        auto SGL_API rotate(
            const Vector3<float>& newRotation
        ) noexcept -> void;


        auto SGL_API scale(
            const Vector3<float>& newScale
        ) noexcept -> void;


        auto SGL_API toMatrix4(
        ) const noexcept -> glm::mat4;

    
    private:
        glm::mat4 m_Matrix4;

    };

}  /* namespace SGL */

#endif  /* _SGL_TRANSFORM_H_ */
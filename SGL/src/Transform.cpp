/**
 *
 *
 *
 */

#include "Transform.h"

namespace SGL {

    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors and destructor
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /* ***************************************************************************************** */
    Transform::Transform(
    ) noexcept {
        m_Matrix4 = glm::mat4(1.0f);
    }


    /* ***************************************************************************************** */
    Transform::~Transform(
    ) noexcept {
        m_Matrix4 = glm::mat4(1.0f);
    }


    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Public methods
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /* ***************************************************************************************** */
    auto Transform::createOrthoProjection(
        const Vector2<std::uint32_t>& viewPort,
        const float nearClipPlane,
        const float farClipPlane
    ) -> void {
        m_Matrix4 = glm::ortho(
            static_cast<float>(0), static_cast<float>(viewPort.x), 
            static_cast<float>(0), static_cast<float>(viewPort.y),
            nearClipPlane, farClipPlane
        );
    }


    /* ***************************************************************************************** */
    auto Transform::createPerspectiveProjection(
        const Vector2<std::uint32_t>& viewPort,
        const float fieldOfView,
        const float nearClipPlane,
        const float farClipPlane
    ) -> void {
        m_Matrix4 = glm::perspective(
            fieldOfView,
            static_cast<float>(viewPort.x) / static_cast<float>(viewPort.y),
            nearClipPlane, farClipPlane
        );
    }


    /* ***************************************************************************************** */
    auto Transform::translate(
        const Vector3<float>& newPosition
    ) noexcept -> void {
        m_Matrix4 = glm::translate(m_Matrix4, glm::vec3(newPosition.x, newPosition.y, newPosition.z));
    }


    /* ***************************************************************************************** */
    auto Transform::rotate(
        const Vector3<float>& newRotation
    ) noexcept -> void {
        m_Matrix4 = glm::rotate(m_Matrix4, glm::radians(newRotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
        m_Matrix4 = glm::rotate(m_Matrix4, glm::radians(newRotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        m_Matrix4 = glm::rotate(m_Matrix4, glm::radians(newRotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    }


    /* ***************************************************************************************** */
    auto Transform::scale(
        const Vector3<float>& newScale
    ) noexcept -> void {
        m_Matrix4 = glm::scale(m_Matrix4, glm::vec3(newScale.x, newScale.y, newScale.z));
    }


    /* ***************************************************************************************** */
    auto Transform::toMatrix4(
    ) const noexcept -> glm::mat4 {
        return m_Matrix4;
    }

}
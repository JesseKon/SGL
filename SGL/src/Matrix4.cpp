/**
 *
 *
 *
 */

#include "Matrix4.h"

namespace SGL {

    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors and destructor
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /* ***************************************************************************************** */
    Matrix4::Matrix4(
    ) noexcept {
        m_Matrix4 = glm::mat4(1.0f);
    }


    /* ***************************************************************************************** */
    Matrix4::~Matrix4(
    ) noexcept {
        m_Matrix4 = glm::mat4(1.0f);
    }


    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Public methods
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /* ***************************************************************************************** */
    auto Matrix4::identity(
    ) noexcept -> void {
        m_Matrix4 = glm::mat4(1.0f);
    }


    /* ***************************************************************************************** */
    auto Matrix4::createOrthoProjection(
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
    auto Matrix4::createPerspectiveProjection(
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
    auto Matrix4::translate(
        const Vector3<float>& newTranslation
    ) noexcept -> void {
        m_Matrix4 = glm::translate(m_Matrix4, glm::vec3(newTranslation.x, newTranslation.y, newTranslation.z));
    }


    /* ***************************************************************************************** */
    auto Matrix4::rotate(
        const Vector3<float>& newRotation
    ) noexcept -> void {
        m_Matrix4 = glm::rotate(m_Matrix4, glm::radians(newRotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
        m_Matrix4 = glm::rotate(m_Matrix4, glm::radians(newRotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        m_Matrix4 = glm::rotate(m_Matrix4, glm::radians(newRotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    }


    /* ***************************************************************************************** */
    auto Matrix4::scale(
        const Vector3<float>& newScale
    ) noexcept -> void {
        m_Matrix4 = glm::scale(m_Matrix4, glm::vec3(newScale.x, newScale.y, newScale.z));
    }


    /* ***************************************************************************************** */
    auto Matrix4::toMat4(
    ) const noexcept -> glm::mat4 {
        return m_Matrix4;
    }

}
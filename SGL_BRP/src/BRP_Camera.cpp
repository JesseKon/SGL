#include "BRP_Camera.h"

namespace SGL {

    /* ***************************************************************************************** */
    BRP_Camera::BRP_Camera(
    ) noexcept {

    }


    /* ***************************************************************************************** */
    BRP_Camera::BRP_Camera(
        const Window& window,
        const BRP_Shader& shader,
        const BRP_CameraType cameraType
    ) {

        // TODO: nearclip and farclip

        switch (cameraType) {
        case BRP_CameraType::Orthographic:
            m_ViewMatrix4.createOrthoProjection(
                window.getRenderer()->getWindowSize()
            );
            break;

        case BRP_CameraType::Perspective:
            m_ViewMatrix4.createPerspectiveProjection(
                window.getRenderer()->getWindowSize(),
                45.0f
            );
            break;
        }

        m_pBRP_Shader = &shader;

    }


    /* ***************************************************************************************** */
    BRP_Camera::~BRP_Camera(
    ) noexcept {

    }


    /* ***************************************************************************************** */
    auto BRP_Camera::getMatrix4(
    ) const noexcept -> Matrix4 {
        return m_ViewMatrix4 * Matrix4::inverse(m_WorldMatrix4);
    }

}
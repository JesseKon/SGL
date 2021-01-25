#include "Camera.h"

namespace SGL {

    /* ***************************************************************************************** */
    Camera::Camera(
    ) noexcept {

    }


    /* ***************************************************************************************** */
    Camera::Camera(
        const Window& window,
        const CameraType cameraType
    ) {

        // TODO: nearclip and farclip

        switch (cameraType) {
        case CameraType::Orthographic:
            m_ViewMatrix4.createOrthoProjection(
                window.getRenderer()->getWindowSize()
            );
            break;

        case CameraType::Perspective:
            m_ViewMatrix4.createPerspectiveProjection(
                window.getRenderer()->getWindowSize(),
                45.0f
            );
            break;
        }

    }


    /* ***************************************************************************************** */
    Camera::~Camera(
    ) noexcept {

    }


    /* ***************************************************************************************** */
    auto Camera::getMatrix4(
    ) const noexcept -> Matrix4 {
        return m_ViewMatrix4 * Matrix4::inverse(m_WorldMatrix4);
    }

}


#ifndef _SGL_CAMERA_H_
#define _SGL_CAMERA_H_

#include "SGLCore.h"
#include "Window.h"
#include "Matrix4.h"
#include "Transform.h"

namespace SGL {

    enum class CameraType {
        Orthographic,
        Perspective
    };


    class Camera : public Transform
    {
    public:

        SGL_API Camera(
        ) noexcept;


        SGL_API Camera(
            const Window& window,
            const CameraType cameraType
        );


        SGL_API ~Camera(
        ) noexcept;


        SGL_API auto getMatrix4(
        ) const noexcept -> Matrix4;


    private:
        Matrix4 m_ViewMatrix4;

    };

}

#endif
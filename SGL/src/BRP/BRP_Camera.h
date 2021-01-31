

#ifndef _SGL_BRP_CAMERA_H_
#define _SGL_BRP_CAMERA_H_

#include "SGLCore.h"
#include "Window.h"
#include "Matrix4.h"
#include "Transform.h"

#include "BRP_Shader.h"

namespace SGL {

    enum class BRP_CameraType {
        Orthographic,
        Perspective
    };


    class BRP_Camera : public Transform
    {
    public:

        SGL_API BRP_Camera(
        ) noexcept;


        SGL_API BRP_Camera(
            const Window& window,
            const BRP_Shader& shader,
            const BRP_CameraType cameraType
        );


        SGL_API ~BRP_Camera(
        ) noexcept;


        SGL_API auto getMatrix4(
        ) const noexcept -> Matrix4;


    private:
        const BRP_Shader* m_pBRP_Shader;

        Matrix4 m_ViewMatrix4;

    };

}

#endif
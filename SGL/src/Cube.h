

#ifndef _SGL_CUBE_H_
#define _SGL_CUBE_H_

#include "SGLCore.h"

#include "Camera.h"
#include "Drawable.h"
#include "ShaderGLSL.h"
#include "ShaderUniformManager.h"
#include "Color.h"
#include "Vector3.h"
#include "Transform.h"

namespace SGL {

    class Cube : public Transform
    {
    public:

        SGL_API Cube(
            const Camera& camera,
            const ShaderGLSL& shader,
            const Vector3<float>& size,
            const bool setStatic = false
        );


        SGL_API ~Cube(
        ) noexcept;


        auto SGL_API getShaderUniformManager(
        ) const noexcept -> ShaderUniformManager*;


        auto SGL_API draw(
        ) const noexcept -> void;


    private:
        const Camera* m_pCamera;
        const ShaderGLSL* m_pShaderGLSL;
        ShaderUniformManager* m_pShaderUniformManager;
        Drawable m_Drawable;
        bool m_IsStatic;
    };
}

#endif

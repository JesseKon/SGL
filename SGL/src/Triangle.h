

#ifndef _SGL_TRIANGLE_H_
#define _SGL_TRIANGLE_H_

#include "SGLCore.h"

#include "Camera.h"
#include "Drawable.h"
#include "ShaderGLSL.h"
#include "ShaderUniformManager.h"
#include "Color.h"
#include "Vector3.h"
#include "Transform.h"

namespace SGL {

    class Triangle
    {
    public:

        SGL_API Triangle(
            const Camera& camera,
            const ShaderGLSL& shader,
            const Vector3<float>& p1,
            const Vector3<float>& p2,
            const Vector3<float>& p3,
            const Color& color,
            const bool setStatic = false
        );


        SGL_API ~Triangle(
        ) noexcept;


        auto SGL_API setPoints(
            const Vector3<float>& p1,
            const Vector3<float>& p2,
            const Vector3<float>& p3
        ) -> void;


        auto SGL_API getShaderUniformManager(
        ) const noexcept -> ShaderUniformManager*;


        auto SGL_API draw(
        ) const noexcept -> void;


    private:
        const Camera* m_pCamera;
        const ShaderGLSL* m_pShaderGLSL;
        ShaderUniformManager* m_pShaderUniformManager;
        Drawable m_Drawable;
        Color m_Color;
        bool m_IsStatic;
    };

}

#endif
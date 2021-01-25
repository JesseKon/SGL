

#ifndef _SGL_QUAD_H_
#define _SGL_QUAD_H_

#include "SGLCore.h"

#include "Camera.h"
#include "Drawable.h"
#include "ShaderGLSL.h"
#include "Color.h"
#include "Vector3.h"
#include "Transform.h"

namespace SGL {

    class Quad
    {
    public:

        SGL_API Quad(
            const Camera& camera,
            const ShaderGLSL& shader,
            const Vector3<float>& p1,
            const Vector3<float>& p2,
            const Vector3<float>& p3,
            const Vector3<float>& p4,
            const Color& color,
            const bool setStatic = false
        );


        SGL_API ~Quad(
        ) noexcept;


        auto SGL_API setPoints(
            const Vector3<float>& p1,
            const Vector3<float>& p2,
            const Vector3<float>& p3,
            const Vector3<float>& p4
        ) -> void;


        auto SGL_API draw(
        ) const noexcept -> void;


    private:
        const Camera* m_pCamera;
        const ShaderGLSL* m_pShaderGLSL;
        Drawable m_Drawable;
        Color m_Color;
        bool m_IsStatic;
    };

}

#endif


#ifndef _SGL_LINE_H_
#define _SGL_LINE_H_

#include "SGLCore.h"
#include "Camera.h"
#include "Drawable.h"
#include "ShaderGLSL.h"
#include "Color.h"
#include "Vector3.h"
#include "Transform.h"


namespace SGL {

    class Line : public Transform
    {
    public:

        SGL_API Line(
            const Camera& camera,
            const ShaderGLSL& shader,
            const Vector3<float>& p1,
            const Vector3<float>& p2,
            const Color& color
        );


        auto SGL_API setPoints(
            const Vector3<float>& p1,
            const Vector3<float>& p2
        ) -> void;


        auto SGL_API draw(
        ) const noexcept -> void;


    private:
        const Camera* m_pCamera;
        const ShaderGLSL* m_pShaderGLSL;
        Drawable m_Drawable;
        Color m_Color;
    };

}

#endif
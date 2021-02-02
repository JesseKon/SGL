

#ifndef _SGL_BRP_QUAD_H_
#define _SGL_BRP_QUAD_H_

#include "SGLCore.h"

#include "Drawable.h"
#include "ShaderGLSL.h"
#include "Color.h"
#include "Vector3.h"
#include "Transform.h"

#include "BRP_Camera.h"
#include "BRP_Shader.h"
#include "BRP_ShaderUniformManager.h"

namespace SGL {

    class BRP_Quad
    {
    public:

        SGL_API BRP_Quad(
            const BRP_Camera& camera,
            const BRP_Shader& shader,
            const Vector3<float>& p1,
            const Vector3<float>& p2,
            const Vector3<float>& p3,
            const Vector3<float>& p4,
            const bool setStatic = false
        );


        SGL_API ~BRP_Quad(
        ) noexcept;


        auto SGL_API setPoints(
            const Vector3<float>& p1,
            const Vector3<float>& p2,
            const Vector3<float>& p3,
            const Vector3<float>& p4
        ) -> void;


        /// <summary>
        /// Draw this object to the currently active renderer.
        /// </summary>
        auto SGL_API draw(
        ) const noexcept -> void;


    private:
        const BRP_Camera* m_pCamera;
        const BRP_Shader* m_pShaderGLSL;
        BRP_ShaderUniformManager* m_pBRP_ShaderUniformManager;
        Drawable m_Drawable;
        bool m_IsStatic;
    };

}

#endif
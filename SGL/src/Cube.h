

#ifndef _SGL_CUBE_H_
#define _SGL_CUBE_H_

#include "SGLCore.h"

#include "Camera.h"
#include "Drawable.h"
#include "ShaderGLSL.h"
#include "ShaderUniformManager.h"
#include "Texture.h"
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
            const Texture* diffuseMap = nullptr,
            const Texture* specularMap = nullptr,
            const bool setStatic = false
        );


        SGL_API ~Cube(
        ) noexcept;


        auto SGL_API setColor(
            const Color& newColor
        ) noexcept -> void;


        auto SGL_API getColor(
        ) const noexcept -> Color;


        auto SGL_API getShaderUniformManager(
        ) const noexcept -> ShaderUniformManager*;


        /// <summary>
        /// Draw this object to the currently active renderer.
        /// </summary>
        auto SGL_API draw(
        ) const noexcept -> void;


    private:
        const Camera* m_pCamera;
        const ShaderGLSL* m_pShaderGLSL;
        ShaderUniformManager* m_pShaderUniformManager;
        Drawable m_Drawable;
        bool m_IsStatic;
        Color m_ObjectColor;

        const Texture* m_pDiffuseMap;
        const Texture* m_pSpecularMap;
    };
}

#endif

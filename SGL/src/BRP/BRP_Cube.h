

#ifndef _SGL_BRP_CUBE_H_
#define _SGL_BRP_CUBE_H_

#include "SGLCore.h"

#include "Drawable.h"
#include "ShaderGLSL.h"
#include "Texture.h"
#include "Color.h"
#include "Vector3.h"
#include "Transform.h"

#include "BRP_Camera.h"
#include "BRP_Shader.h"
#include "BRP_ShaderUniformManager.h"

namespace SGL {

    class BRP_Cube : public Transform
    {
    public:

        SGL_API BRP_Cube(
            const BRP_Camera& camera,
            const BRP_Shader& shader,
            const Vector3<float>& size,
            const Texture* diffuseMap = nullptr,
            const Texture* specularMap = nullptr,
            const bool setStatic = false
        );


        SGL_API ~BRP_Cube(
        ) noexcept;


        auto SGL_API setColor(
            const Color& color
        ) noexcept -> void;


        auto SGL_API getColor(
        ) const noexcept -> Color;


        auto SGL_API setShininess(
            const float shininess
        ) noexcept -> void;


        auto SGL_API getShininess(
        ) const noexcept -> float;


        auto SGL_API getBRP_ShaderUniformManager(
        ) const noexcept -> BRP_ShaderUniformManager*;


        /// <summary>
        /// Draw this object to the currently active renderer.
        /// </summary>
        auto SGL_API draw(
        ) const noexcept -> void;


    private:
        const BRP_Camera* m_pBRP_Camera;
        const BRP_Shader* m_pBRP_Shader;
        BRP_ShaderUniformManager* m_pBRP_ShaderUniformManager;
        Drawable m_Drawable;
        bool m_IsStatic;

        const Texture* m_pDiffuseMap;
        const Texture* m_pSpecularMap;

        Color m_ObjectColor;
        float m_Shininess;
    };
}

#endif

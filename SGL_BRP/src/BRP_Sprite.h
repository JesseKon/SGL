

#ifndef _SGL_BRP_SPRITE_H_
#define _SGL_BRP_SPRITE_H_

#include "SGLCore.h"

#include "Drawable.h"
#include "ShaderGLSL.h"
#include "Texture.h"
#include "Transform.h"

#include "BRP_Camera.h"
#include "BRP_Shader.h"
#include "BRP_ShaderUniformManager.h"

namespace SGL {

    class BRP_Sprite : public Transform
    {
    public:

        SGL_API BRP_Sprite(
            const BRP_Camera& camera,
            const BRP_Shader& shader,
            const Texture* texture = nullptr
        );


        SGL_API ~BRP_Sprite(
        ) noexcept;


        auto SGL_API getBRP_ShaderUniformManager(
        ) const noexcept -> BRP_ShaderUniformManager*;


        /// <summary>
        /// Draw this object to the currently active renderer.
        /// </summary>
        auto SGL_API draw(
        ) const noexcept -> void;


    private:
        const BRP_Camera* m_pCamera;
        const BRP_Shader* m_pShaderGLSL;
        BRP_ShaderUniformManager* m_pBRP_ShaderUniformManager;
        const Texture* m_pTexture;
        Drawable m_Drawable;
    };

}

#endif
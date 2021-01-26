

#ifndef _SGL_SPRITE_H_
#define _SGL_SPRITE_H_

#include "SGLCore.h"

#include "Camera.h"
#include "Drawable.h"
#include "ShaderGLSL.h"
#include "ShaderUniformManager.h"
#include "Texture.h"
#include "Transform.h"


namespace SGL {

    class Sprite : public Transform
    {
    public:

        SGL_API Sprite(
            const Camera& camera,
            const ShaderGLSL& shader,
            const Texture* texture = nullptr
        );


        SGL_API ~Sprite(
        ) noexcept;


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
        const Texture* m_pTexture;
        Drawable m_Drawable;
    };

}

#endif
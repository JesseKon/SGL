

#ifndef _SGL_SPRITE_H_
#define _SGL_SPRITE_H_

#include "SGLCore.h"

#include "Camera.h"
#include "Drawable.h"
#include "ShaderGLSL.h"
#include "Texture.h"
#include "Transform.h"


namespace SGL {

    class Sprite : public Transform
    {
    public:

        SGL_API Sprite(
            const Camera& camera,
            const ShaderGLSL& shader,
            const Texture& texture
        );


        SGL_API ~Sprite(
        ) noexcept;


        auto SGL_API draw(
        ) const noexcept -> void;


    private:
        const Camera* m_pCamera;
        const ShaderGLSL* m_pShaderGLSL;
        const Texture* m_pTexture;
        Drawable m_Drawable;
    };

}

#endif
/**
 *
 *
 *
 */

#ifndef _SGL_TEXTURE_H_
#define _SGL_TEXTURE_H_

#include "SGLCore.h"

#include "stb_image.h"


namespace SGL {

    class Texture
    {
    public:

        SGL_API Texture(
        ) noexcept;


        SGL_API ~Texture(
        ) noexcept;


        auto SGL_API load(
            const std::string& filename
        ) -> void;


        auto SGL_API use(
        ) const noexcept -> void;




    private:
        std::int32_t m_Width;
        std::int32_t m_Height;
        std::int32_t m_Channels;

        GLuint m_TextureID;
    };

}

#endif  /* _SGL_TEXTURE_H_ */
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

        /// <summary>
        /// Default constructor.
        /// </summary>
        /// 
        /// <returns></returns>
        SGL_API Texture(
        ) noexcept;


        /// <summary>
        /// Destructor.
        /// </summary>
        /// 
        /// <returns></returns>
        SGL_API ~Texture(
        ) noexcept;


        /// <summary>
        /// Load texture from file.
        /// </summary>
        /// 
        /// <param name="filename">
        /// The file where this texture will be loaded from.
        /// </param>
        /// 
        /// <exception cref="std::runtime_error">
        /// Throws if filename couldn't be opened.
        /// </exception>
        /// 
        /// 
        /// <returns></returns>
        auto SGL_API load(
            const std::string& filename
        ) -> void;


        /// <summary>
        /// Set this texture active for the following draw commands.
        /// </summary>
        /// 
        /// <param name="textureUnit">
        /// Specify which texture unit this texture should activate. The default is 0.
        /// </param>
        /// 
        /// <returns></returns>
        auto SGL_API use(
            const GLuint textureUnit = 0
        ) const noexcept -> void;


    private:
        std::int32_t m_Width;
        std::int32_t m_Height;
        std::int32_t m_Channels;

        GLuint m_TextureID;
    };

}

#endif  /* _SGL_TEXTURE_H_ */
/**
 *
 *
 *
 */

#ifndef _SGL_TEXTURE_H_
#define _SGL_TEXTURE_H_

#include "SGLCore.h"
#include "Vector2.h"
#include "Color.h"

#include "stb_image.h"
#include "TextureUnit.h"


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
        /// 
        /// </summary>
        /// <param name="size"></param>
        /// <returns></returns>
        SGL_API Texture(
            const Vector2<std::uint32_t>& size
        );


        /// <summary>
        /// 
        /// </summary>
        /// <param name="filename"></param>
        /// <returns></returns>
        SGL_API Texture(
            const std::string& filename
        );


        /// <summary>
        /// Destructor.
        /// </summary>
        /// 
        /// <returns></returns>
        SGL_API ~Texture(
        ) noexcept;


        /// <summary>
        /// Create an empty texture.
        /// </summary>
        /// 
        /// <param name="size"></param>
        /// <returns></returns>
        auto SGL_API create(
            const Vector2<std::uint32_t>& size
        ) -> void;


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
        /// <returns></returns>
        auto SGL_API load(
            const std::string& filename
        ) -> void;


        /// <summary>
        /// Destroy this texture and free its data from memory.
        /// </summary>
        /// 
        /// <returns></returns>
        auto SGL_API destroy(
        ) noexcept -> void;


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
        ) const noexcept -> void;


        auto SGL_API beginDrawing(
            const Color& color = SGL::COLOR::Black
        ) noexcept -> void;


        auto SGL_API endDrawing(
        ) noexcept -> void;


        /// <summary>
        /// 
        /// </summary>
        /// 
        /// <param name="textureUnit">
        /// 
        /// </param>
        /// 
        /// <returns></returns>
        auto SGL_API setTextureUnit(
            const TextureUnit::type textureUnit
        ) noexcept -> void;


        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        auto SGL_API getTextureUnit(
        ) const noexcept -> TextureUnit::type;


    private:
        std::int32_t m_Width;
        std::int32_t m_Height;
        std::int32_t m_Channels;

        GLuint m_Texture;
        GLuint m_Framebuffer;
        GLuint m_Renderbuffer;
        TextureUnit::type m_TextureUnit;
    };

}

#endif  /* _SGL_TEXTURE_H_ */
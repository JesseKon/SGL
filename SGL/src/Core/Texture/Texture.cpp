/**
 *
 *
 *
 */

#include "Texture.h"

namespace SGL {


    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors and destructor
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /* ***************************************************************************************** */
    Texture::Texture(
    ) noexcept {
        m_Width = m_Height = m_Channels = 0;
        m_Texture = NULL;
        m_Framebuffer = NULL;
        m_Renderbuffer = NULL;
        m_TextureUnit = TextureUnit::Texture0;

        stbi_set_flip_vertically_on_load(true);
    }


    /* ***************************************************************************************** */
    Texture::Texture(
        const Vector2<std::uint32_t>& size,
        const TextureType textureType,
        const TextureFilter textureFilter
    ) {
        create(size, textureType, textureFilter);
    }


    /* ***************************************************************************************** */
    Texture::Texture(
        const std::string& filename,
        const TextureFilter textureFilter
    ) {
        m_Width = m_Height = m_Channels = 0;
        m_Texture = NULL;
        m_Framebuffer = NULL;
        m_Renderbuffer = NULL;
        m_TextureUnit = TextureUnit::Texture0;

        stbi_set_flip_vertically_on_load(true);

        load(filename, textureFilter);
    }


    /* ***************************************************************************************** */
    Texture::~Texture(
    ) noexcept {
        destroy();
    }


    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Public methods
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /* ***************************************************************************************** */
    auto Texture::create(
        const Vector2<std::uint32_t>& size,
        const TextureType textureType,
        const TextureFilter textureFilter
    ) -> void {
        destroy();

        m_Width = size.x;
        m_Height = size.y;
        m_Channels = 4;

        // Color texture
        if (textureType == TextureType::Color) {
            glGenFramebuffers(1, &m_Framebuffer);
            glBindFramebuffer(GL_FRAMEBUFFER, m_Framebuffer);
            glGenTextures(1, &m_Texture);
            glBindTexture(GL_TEXTURE_2D, m_Texture);
            glGenRenderbuffers(1, &m_Renderbuffer);
            glBindRenderbuffer(GL_RENDERBUFFER, m_Renderbuffer);

            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, static_cast<GLint>(textureFilter));
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, static_cast<GLint>(textureFilter));
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_Texture, 0);

            glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, m_Width, m_Height);
            glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_Renderbuffer);
        }

        // Depth texture
        else if (textureType == TextureType::Depth) {
            glGenFramebuffers(1, &m_Framebuffer);
            glBindFramebuffer(GL_FRAMEBUFFER, m_Framebuffer);
            glGenTextures(1, &m_Texture);
            glBindTexture(GL_TEXTURE_2D, m_Texture);

            glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, m_Width, m_Height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, static_cast<GLint>(textureFilter));
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, static_cast<GLint>(textureFilter));
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

            glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_Texture, 0);
            glDrawBuffer(GL_NONE);
            glReadBuffer(GL_NONE);
        }



        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
            std::stringstream ss;
            ss << ">>> Error > Texture::create() > Could not create texture.\n";
            throw std::runtime_error(ss.str());
        }

        glBindFramebuffer(GL_FRAMEBUFFER, NULL);
    }


    /* ***************************************************************************************** */
    auto Texture::load(
        const std::string& filename,
        const TextureFilter textureFilter
    ) -> void {
        destroy();

        // TODO: TextureType

        glGenTextures(1, &m_Texture);
        glBindTexture(GL_TEXTURE_2D, m_Texture);

        std::uint8_t* data = stbi_load(filename.c_str(), &m_Width, &m_Height, &m_Channels, NULL);
        if (!data) {
            std::stringstream ss;
            ss << ">>> Error > Texture::load() > Could not load file \'" << filename << "\'.\n";
            throw std::runtime_error(ss.str());
        }

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, static_cast<GLint>(textureFilter));
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, static_cast<GLint>(textureFilter));
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);
    }


    /* ***************************************************************************************** */
    auto Texture::destroy(
    ) noexcept -> void {
        m_Width = m_Height = m_Channels = 0;

        if (m_Texture) {
            glBindTexture(GL_TEXTURE_2D, NULL);
            glDeleteTextures(1, &m_Texture);
            m_Texture = NULL;
        }

        if (m_Framebuffer) {
            glBindFramebuffer(GL_FRAMEBUFFER, NULL);
            glDeleteFramebuffers(1, &m_Framebuffer);
            m_Framebuffer = NULL;
        }

        if (m_Renderbuffer) {
            glBindRenderbuffer(GL_RENDERBUFFER, NULL);
            glDeleteRenderbuffers(1, &m_Renderbuffer);
            m_Renderbuffer = NULL;
        }

        m_TextureUnit = TextureUnit::Texture0;
    }


    /* ***************************************************************************************** */
    auto Texture::use(
    ) const noexcept -> void {
        glActiveTexture(m_TextureUnit);
        glBindTexture(GL_TEXTURE_2D, m_Texture);
    }


    /* ***************************************************************************************** */
    auto Texture::setFilter(
        const TextureFilter textureFilter
    ) noexcept -> void {
        glBindTexture(GL_TEXTURE_2D, m_Texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, static_cast<GLint>(textureFilter));
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, static_cast<GLint>(textureFilter));
    }


    /* ***************************************************************************************** */
    auto Texture::getSize(
    ) const noexcept -> Vector2<std::int32_t> {
        return { m_Width, m_Height };
    }


    /* ***************************************************************************************** */
    auto Texture::beginDrawing(
        const bool clearColorBuffer,
        const bool clearDepthBuffer,
        const bool clearStencilBuffer,
        const Color& color
    ) noexcept -> void {
        glViewport(0, 0, m_Width, m_Height);
        glBindFramebuffer(GL_FRAMEBUFFER, m_Framebuffer);
        glClearColor(
            color.getRedf<float>(), color.getGreenf<float>(),
            color.getBluef<float>(), color.getAlphaf<float>()
        );

        if (clearColorBuffer)
            glClear(GL_COLOR_BUFFER_BIT);
        if (clearDepthBuffer)
            glClear(GL_DEPTH_BUFFER_BIT);
        if (clearStencilBuffer)
            glClear(GL_STENCIL_BUFFER_BIT);
    }


    /* ***************************************************************************************** */
    auto Texture::endDrawing(
    ) noexcept -> void {
        glBindFramebuffer(GL_FRAMEBUFFER, NULL);
    }


    /* ***************************************************************************************** */
    auto Texture::setTextureUnit(
        const TextureUnit::type textureUnit
    ) noexcept -> void {
        m_TextureUnit = textureUnit;
    }


    /* ***************************************************************************************** */
    auto Texture::getTextureUnit(
    ) const noexcept -> TextureUnit::type {
        return m_TextureUnit;
    }

}
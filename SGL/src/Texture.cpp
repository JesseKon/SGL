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
        const Vector2<std::uint32_t>& size
    ) {
        create(size);
    }


    /* ***************************************************************************************** */
    Texture::Texture(
        const std::string& filename
    ) {
        m_Width = m_Height = m_Channels = 0;
        m_Texture = NULL;
        m_Framebuffer = NULL;
        m_Renderbuffer = NULL;
        m_TextureUnit = TextureUnit::Texture0;

        stbi_set_flip_vertically_on_load(true);

        load(filename);
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
        const Vector2<std::uint32_t>& size
    ) -> void {
        destroy();

        m_Width = size.x;
        m_Height = size.y;
        m_Channels = 4;

        glGenFramebuffers(1, &m_Framebuffer);
        glBindFramebuffer(GL_FRAMEBUFFER, m_Framebuffer);
        glGenTextures(1, &m_Texture);
        glBindTexture(GL_TEXTURE_2D, m_Texture);
        glGenRenderbuffers(1, &m_Renderbuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, m_Renderbuffer);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_Texture, 0);

        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, m_Width, m_Height);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_Renderbuffer);

        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
            std::stringstream ss;
            ss << ">>> Error > Texture::create() > Could not create texture.\n";
            throw std::runtime_error(ss.str());
        }

        glBindFramebuffer(GL_FRAMEBUFFER, NULL);
    }


    /* ***************************************************************************************** */
    auto Texture::load(
        const std::string& filename
    ) -> void {
        destroy();

        glGenTextures(1, &m_Texture);
        glBindTexture(GL_TEXTURE_2D, m_Texture);

        std::uint8_t* data = stbi_load(filename.c_str(), &m_Width, &m_Height, &m_Channels, NULL);
        if (!data) {
            std::stringstream ss;
            ss << ">>> Error > Texture::load() > Could not load file \'" << filename << "\'.\n";
            throw std::runtime_error(ss.str());
        }

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
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
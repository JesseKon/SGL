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
        m_TextureID = NULL;
        m_TextureUnit = TextureUnit::Texture0;

        stbi_set_flip_vertically_on_load(true);
    }


    Texture::Texture(
        const std::string& filename
    ) {
        m_Width = m_Height = m_Channels = 0;
        m_TextureID = NULL;
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
    auto Texture::load(
        const std::string& filename
    ) -> void {
        glGenTextures(1, &m_TextureID);
        glBindTexture(GL_TEXTURE_2D, m_TextureID);

        unsigned char* data = stbi_load(filename.c_str(), &m_Width, &m_Height, &m_Channels, NULL);
        if (!data) {
            std::stringstream ss;
            ss << ">>> Error > Texture::load() > Could not load file \'" << filename << "\'.\n";
            throw std::runtime_error(ss.str());
        }

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);
    }


    /* ***************************************************************************************** */
    auto Texture::destroy(
    ) noexcept -> void {
        m_Width = m_Height = m_Channels = 0;

        if (m_TextureID) {
            glDeleteTextures(1, &m_TextureID);
            m_TextureID = NULL;
        }

        m_TextureUnit = TextureUnit::Texture0;
    }


    /* ***************************************************************************************** */
    auto Texture::use(
    ) const noexcept -> void {
        glActiveTexture(m_TextureUnit);
        glBindTexture(GL_TEXTURE_2D, m_TextureID);
    }


    /* ***************************************************************************************** */
    auto Texture::setTextureUnit(
        const TextureUnit::type textureUnit
    ) noexcept -> void {
        m_TextureUnit = textureUnit;
    }

}
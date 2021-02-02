

#include "BRP_Sprite.h"

namespace SGL {

    BRP_Sprite::BRP_Sprite(
        const BRP_Camera& camera,
        const BRP_Shader& shader,
        const Texture* texture
    ) {
        m_pCamera = &camera;
        m_pShaderGLSL = &shader;
        m_pBRP_ShaderUniformManager = new BRP_ShaderUniformManager();
        m_pTexture = texture;

        std::vector<Drawable::BufferDataType> vertex = {
            static_cast<float>( texture->getSize().x) / 2.0f, static_cast<float>( texture->getSize().y) / 2, 0.0f,
            static_cast<float>( texture->getSize().x) / 2.0f, static_cast<float>(-texture->getSize().y) / 2, 0.0f,
            static_cast<float>(-texture->getSize().x) / 2.0f, static_cast<float>(-texture->getSize().y) / 2, 0.0f,
            static_cast<float>(-texture->getSize().x) / 2.0f, static_cast<float>( texture->getSize().y) / 2, 0.0f,
        };

        // TODO: normals etc...

        std::vector<Drawable::BufferDataType> texCoords = {
            1.0f, 1.0f,
            1.0f, 0.0f,
            0.0f, 0.0f,
            0.0f, 1.0f
        };

        std::vector<Drawable::IndicesDataType> indices = {
            0, 1, 3, 1, 2, 3
        };

        m_Drawable.setBufferData(0, 3, std::move(vertex));
        m_Drawable.setBufferData(1, 2, std::move(texCoords));
        m_Drawable.setIndices(std::move(indices));
        m_Drawable.setDrawMethod(DrawMethod::Static);
        m_Drawable.setDrawMode(DrawMode::Triangles);
        m_Drawable.configure();
    }


    BRP_Sprite::~BRP_Sprite(
    ) {
        if (m_pBRP_ShaderUniformManager) {
            delete m_pBRP_ShaderUniformManager;
            m_pBRP_ShaderUniformManager = nullptr;
        }
    }


    /* ***************************************************************************************** */
    auto BRP_Sprite::getBRP_ShaderUniformManager(
    ) const noexcept -> BRP_ShaderUniformManager* {
        return m_pBRP_ShaderUniformManager;
    }


    auto BRP_Sprite::draw(
    ) const noexcept -> void {
        m_pShaderGLSL->setActive();
        m_pShaderGLSL->setMatrix4("uTransform", m_pCamera->getMatrix4() * m_WorldMatrix4);
        m_pBRP_ShaderUniformManager->activateAll(m_pShaderGLSL);
        m_pTexture->use();
        m_Drawable.draw();
    }

}
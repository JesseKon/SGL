

#include "Sprite.h"

namespace SGL {

    Sprite::Sprite(
        const Camera& camera,
        const ShaderGLSL& shader,
        const Texture& texture
    ) {
        m_pCamera = &camera;
        m_pShaderGLSL = &shader;
        m_pTexture = &texture;

        std::vector<Drawable::BufferDataType> vertex = {
            static_cast<float>( texture.getSize().x) / 2.0f, static_cast<float>( texture.getSize().y) / 2, 0.0f,
            static_cast<float>( texture.getSize().x) / 2.0f, static_cast<float>(-texture.getSize().y) / 2, 0.0f,
            static_cast<float>(-texture.getSize().x) / 2.0f, static_cast<float>(-texture.getSize().y) / 2, 0.0f,
            static_cast<float>(-texture.getSize().x) / 2.0f, static_cast<float>( texture.getSize().y) / 2, 0.0f,
        };

        std::vector<Drawable::BufferDataType> uvcoords = {
            1.0f, 1.0f,
            1.0f, 0.0f,
            0.0f, 0.0f,
            0.0f, 1.0f
        };

        std::vector<Drawable::IndicesDataType> indices = {
            0, 1, 3, 1, 2, 3
        };

        m_Drawable.setBufferData(0, 3, std::move(vertex));
        m_Drawable.setBufferData(1, 2, std::move(uvcoords));
        m_Drawable.setIndices(std::move(indices));
        m_Drawable.setDrawMethod(DrawMethod::Static);
        m_Drawable.setDrawMode(DrawMode::Triangles);
        m_Drawable.configure();
    }


    Sprite::~Sprite(
    ) {

    }


    auto Sprite::draw(
    ) const noexcept -> void {
        m_pShaderGLSL->setActive();
        m_pShaderGLSL->setMatrix4("uTransform", m_pCamera->getMatrix4() * m_WorldMatrix4);
        m_pTexture->use();
        m_Drawable.draw();
    }

}


#include "Cube.h"

namespace SGL {

    /* ***************************************************************************************** */
    Cube::Cube(
        const Camera& camera,
        const ShaderGLSL& shader,
        const Vector3<float>& size,
        const Texture* texture,
        const bool setStatic
    ) {
        m_pCamera = &camera;
        m_pShaderGLSL = &shader;
        m_pShaderUniformManager = new ShaderUniformManager();
        m_IsStatic = setStatic;

        const float halfX = size.x / 2.0f;
        const float halfY = size.y / 2.0f;
        const float halfZ = size.z / 2.0f;

        std::vector<Drawable::BufferDataType> vertex = {
            -halfX, -halfY, -halfZ,
             halfX, -halfY, -halfZ,
             halfX,  halfY, -halfZ,
             halfX,  halfY, -halfZ,
            -halfX,  halfY, -halfZ,
            -halfX, -halfY, -halfZ,

            -halfX, -halfY,  halfZ,
             halfX, -halfY,  halfZ,
             halfX,  halfY,  halfZ,
             halfX,  halfY,  halfZ,
            -halfX,  halfY,  halfZ,
            -halfX, -halfY,  halfZ,

            -halfX,  halfY,  halfZ,
            -halfX,  halfY, -halfZ,
            -halfX, -halfY, -halfZ,
            -halfX, -halfY, -halfZ,
            -halfX, -halfY,  halfZ,
            -halfX,  halfY,  halfZ,

             halfX,  halfY,  halfZ,
             halfX,  halfY, -halfZ,
             halfX, -halfY, -halfZ,
             halfX, -halfY, -halfZ,
             halfX, -halfY,  halfZ,
             halfX,  halfY,  halfZ,

            -halfX, -halfY, -halfZ,
             halfX, -halfY, -halfZ,
             halfX, -halfY,  halfZ,
             halfX, -halfY,  halfZ,
            -halfX, -halfY,  halfZ,
            -halfX, -halfY, -halfZ,

            -halfX,  halfY, -halfZ,
             halfX,  halfY, -halfZ,
             halfX,  halfY,  halfZ,
             halfX,  halfY,  halfZ,
            -halfX,  halfY,  halfZ,
            -halfX,  halfY, -halfZ,
        };

        std::vector<Drawable::BufferDataType> normals = {
             0.0f,  0.0f, -1.0f,
             0.0f,  0.0f, -1.0f,
             0.0f,  0.0f, -1.0f,
             0.0f,  0.0f, -1.0f,
             0.0f,  0.0f, -1.0f,
             0.0f,  0.0f, -1.0f,

             0.0f,  0.0f,  1.0f,
             0.0f,  0.0f,  1.0f,
             0.0f,  0.0f,  1.0f,
             0.0f,  0.0f,  1.0f,
             0.0f,  0.0f,  1.0f,
             0.0f,  0.0f,  1.0f,

            -1.0f,  0.0f,  0.0f,
            -1.0f,  0.0f,  0.0f,
            -1.0f,  0.0f,  0.0f,
            -1.0f,  0.0f,  0.0f,
            -1.0f,  0.0f,  0.0f,
            -1.0f,  0.0f,  0.0f,

             1.0f,  0.0f,  0.0f,
             1.0f,  0.0f,  0.0f,
             1.0f,  0.0f,  0.0f,
             1.0f,  0.0f,  0.0f,
             1.0f,  0.0f,  0.0f,
             1.0f,  0.0f,  0.0f,

             0.0f, -1.0f,  0.0f,
             0.0f, -1.0f,  0.0f,
             0.0f, -1.0f,  0.0f,
             0.0f, -1.0f,  0.0f,
             0.0f, -1.0f,  0.0f,
             0.0f, -1.0f,  0.0f,

             0.0f,  1.0f,  0.0f,
             0.0f,  1.0f,  0.0f,
             0.0f,  1.0f,  0.0f,
             0.0f,  1.0f,  0.0f,
             0.0f,  1.0f,  0.0f,
             0.0f,  1.0f,  0.0f
        };

        std::vector<Drawable::BufferDataType> texCoords = {
            0.0f, 0.0f,
            1.0f, 0.0f,
            1.0f, 1.0f,
            1.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 0.0f,

            0.0f, 0.0f,
            1.0f, 0.0f,
            1.0f, 1.0f,
            1.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 0.0f,

            1.0f, 0.0f,
            1.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 0.0f,
            1.0f, 0.0f,

            1.0f, 0.0f,
            1.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 0.0f,
            1.0f, 0.0f,

            0.0f, 1.0f,
            1.0f, 1.0f,
            1.0f, 0.0f,
            1.0f, 0.0f,
            0.0f, 0.0f,
            0.0f, 1.0f,

            0.0f, 1.0f,
            1.0f, 1.0f,
            1.0f, 0.0f,
            1.0f, 0.0f,
            0.0f, 0.0f,
            0.0f, 1.0f,
        };

        std::vector<Drawable::IndicesDataType> indices = {
            0,  1,  2,  3,  4,  5,
            6,  7,  8,  9,  10, 11,
            12, 13, 14, 15, 16, 17,
            18, 19, 20, 21, 22, 23,
            24, 25, 26, 27, 28, 29,
            30, 31, 32, 33, 34, 35
        };

        m_Drawable.setBufferData(0, 3, std::move(vertex));
        m_Drawable.setBufferData(1, 3, std::move(normals));
        m_Drawable.setBufferData(2, 2, std::move(texCoords));
        m_Drawable.setIndices(std::move(indices));
        m_Drawable.setDrawMethod(m_IsStatic ? DrawMethod::Static : DrawMethod::Dynamic);
        m_Drawable.setDrawMode(DrawMode::Triangles);
        m_Drawable.configure();

        m_pTexture = texture;

        // Create placeholder texture if none was provided
        if (!texture) {
            std::cout << "eih";
            m_pTexture = new Texture(Vector2<std::uint32_t>(1, 1), TextureFilter::Point);
            const_cast<Texture*>(m_pTexture)->beginDrawing(SGL::COLOR::White);
            const_cast<Texture*>(m_pTexture)->endDrawing();
        }
        else {
            std::cout << "jooh!";
            m_pTexture = texture;
        }
    }


    /* ***************************************************************************************** */
    Cube::~Cube(
    ) noexcept {
        if (m_pShaderUniformManager) {
            delete m_pShaderUniformManager;
            m_pShaderUniformManager = nullptr;
        }

        if (m_pTexture) {
            delete m_pTexture;
            m_pTexture = nullptr;
        }
    }


    /* ***************************************************************************************** */
    auto Cube::getShaderUniformManager(
    ) const noexcept -> ShaderUniformManager* {
        return m_pShaderUniformManager;
    }


    /* ***************************************************************************************** */
    auto Cube::draw(
    ) const noexcept -> void {
        m_pShaderGLSL->setActive();
        m_pTexture->use();
        m_pShaderGLSL->setMatrix4("uTransformMatrix", m_pCamera->getMatrix4() * m_WorldMatrix4);
        m_pShaderGLSL->setMatrix4("uWorldMatrix", m_WorldMatrix4);
        m_pShaderGLSL->setMatrix4("uInversedWorldMatrix", Matrix4::inverse(m_WorldMatrix4));
        m_pShaderUniformManager->activateAll(m_pShaderGLSL);
        m_Drawable.draw();
    }

}
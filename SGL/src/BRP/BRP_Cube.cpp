

#include "BRP_Cube.h"

namespace SGL {

    /* ***************************************************************************************** */
    BRP_Cube::BRP_Cube(
        const BRP_Camera& camera,
        const BRP_Shader& shader,
        const Vector3<float>& size,
        const Texture* diffuseMap,
        const Texture* specularMap,
        const bool setStatic
    ) {
        m_pBRP_Camera = &camera;
        m_pBRP_Shader = &shader;
        m_pBRP_ShaderUniformManager = new BRP_ShaderUniformManager();
        m_IsStatic = setStatic;

        m_pDiffuseMap = nullptr;
        m_pSpecularMap = nullptr;

        m_ObjectColor = COLOR::White;
        m_Shininess = 16.0f;

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

        // Create placeholder texture if none was provided
        if (!diffuseMap) {
            m_pDiffuseMap = new Texture(Vector2<std::uint32_t>(1, 1), TextureFilter::Point);
            const_cast<Texture*>(m_pDiffuseMap)->beginDrawing(SGL::Color(255, 255, 255));
            const_cast<Texture*>(m_pDiffuseMap)->endDrawing();
        }
        else {
            m_pDiffuseMap = diffuseMap;
        }

        // Placeholder for diffuse map
        if (!specularMap) {
            m_pSpecularMap = new Texture(Vector2<std::uint32_t>(1, 1), TextureFilter::Point);
            const_cast<Texture*>(m_pSpecularMap)->beginDrawing(SGL::Color(64, 64, 64));
            const_cast<Texture*>(m_pSpecularMap)->endDrawing();
        }
        else {
            m_pSpecularMap = specularMap;
        }

        const_cast<Texture*>(m_pDiffuseMap)->setTextureUnit(TextureUnit::Texture0);
        m_pBRP_Shader->setTextureUnit("material.diffuse", TextureUnit::Texture0);
        const_cast<Texture*>(m_pSpecularMap)->setTextureUnit(TextureUnit::Texture1);
        m_pBRP_Shader->setTextureUnit("material.specular", TextureUnit::Texture1);

    }


    /* ***************************************************************************************** */
    BRP_Cube::~BRP_Cube(
    ) noexcept {
        if (m_pBRP_ShaderUniformManager) {
            delete m_pBRP_ShaderUniformManager;
            m_pBRP_ShaderUniformManager = nullptr;
        }

        if (m_pDiffuseMap) {
            m_pDiffuseMap = nullptr;  // TODO: potential memory leak
        }

        if (m_pSpecularMap) {
            m_pDiffuseMap = nullptr;  // TODO: potential memory leak
        }

    }


    /* ***************************************************************************************** */
    auto BRP_Cube::setColor(
        const Color& color
    ) noexcept -> void {
        m_ObjectColor = color;
    }


    /* ***************************************************************************************** */
    auto BRP_Cube::getColor(
    ) const noexcept -> Color {
        return m_ObjectColor;
    }


    /* ***************************************************************************************** */
    auto BRP_Cube::setShininess(
        const float shininess
    ) noexcept -> void {
        m_Shininess = shininess;
    }


    /* ***************************************************************************************** */
    auto BRP_Cube::getShininess(
    ) const noexcept -> float {
        return m_Shininess;
    }


    /* ***************************************************************************************** */
    auto BRP_Cube::getBRP_ShaderUniformManager(
    ) const noexcept -> BRP_ShaderUniformManager* {
        return m_pBRP_ShaderUniformManager;
    }


    /* ***************************************************************************************** */
    auto BRP_Cube::draw(
    ) const noexcept -> void {
        m_pBRP_Shader->setActive();

        m_pBRP_Shader->setMatrix4("matrix.transform", m_pBRP_Camera->getMatrix4() * m_WorldMatrix4);
        m_pBRP_Shader->setMatrix4("matrix.world", m_WorldMatrix4);
        m_pBRP_Shader->setMatrix4("matrix.inversedWorld", Matrix4::inverse(m_WorldMatrix4));

        m_pBRP_Shader->setVector3("material.color", glm::vec3(
            m_ObjectColor.getRedf<float>(),
            m_ObjectColor.getGreenf<float>(),
            m_ObjectColor.getBluef<float>()
        ));

        m_pBRP_Shader->setFloat("material.shininess", m_Shininess);

        m_pDiffuseMap->use();
        m_pSpecularMap->use();

        m_pBRP_ShaderUniformManager->activateAll(m_pBRP_Shader);
        m_Drawable.draw();
    }

}
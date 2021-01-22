

#include "Line.h"

namespace SGL {

    /* ***************************************************************************************** */
    Line::Line(
        const Camera& camera,
        const ShaderGLSL& shader,
        const Vector3<float>& p1,
        const Vector3<float>& p2,
        const Color& color
    ) {
        m_pCamera = &camera;
        m_pShaderGLSL = &shader;
        m_Color = color;

        std::vector<Drawable::BufferDataType> vertex = {
            p1.x, p1.y, p1.z,
            p2.x, p2.y, p2.z
        };

        std::vector<Drawable::IndicesDataType> indices = {
            0, 1
        };

        m_Drawable.setBufferData(0, 3, std::move(vertex));
        m_Drawable.setIndices(std::move(indices));
        m_Drawable.setDrawMethod(DrawMethod::Dynamic);
        m_Drawable.setDrawMode(DrawMode::Lines);
        m_Drawable.configure();
    }


    /* ***************************************************************************************** */
    auto Line::setPoints(
        const Vector3<float>& p1,
        const Vector3<float>& p2
    ) -> void {
        std::vector<Drawable::BufferDataType> vertex = {
            p1.x, p1.y, p1.z,
            p2.x, p2.y, p2.z
        };

        m_Drawable.setBufferData(0, 3, std::move(vertex));
        m_Drawable.configure();
    }


    /* ***************************************************************************************** */
    auto Line::draw(
    ) const noexcept -> void {
        m_pShaderGLSL->setActive();
        m_pShaderGLSL->setMatrix4("uTransform", m_pCamera->getMatrix4() * m_WorldMatrix4);
        m_pShaderGLSL->setVector4("uColor", m_Color.toVec4());
        m_Drawable.draw();
    }

}
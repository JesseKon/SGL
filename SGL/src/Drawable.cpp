#include "Drawable.h"

namespace SGL {

    Drawable::Drawable(
    ) {
        glGenVertexArrays(1, &m_VertexArray);
        glGenBuffers(1, &m_VertexBuffer);
        glGenBuffers(1, &m_ElementBuffer);
        m_DrawMethod = DrawMethod::Static;
        m_DrawMode = DrawMode::Points;
    }


    Drawable::~Drawable(
    ) noexcept {

        // TODO: delete only if not NULL

        glBindVertexArray(NULL);
        glBindBuffer(m_VertexBuffer, NULL);
        glBindBuffer(m_ElementBuffer, NULL);
        glDeleteVertexArrays(1, &m_VertexArray);
        glDeleteBuffers(1, &m_VertexBuffer);
        glDeleteBuffers(1, &m_ElementBuffer);
        m_VertexArray = m_VertexBuffer = m_ElementBuffer = NULL;
    }


    auto Drawable::setDrawMethod(
        const DrawMethod drawMethod
    ) noexcept -> void {
        m_DrawMethod = drawMethod;
    }


    auto Drawable::setDrawMode(
        const DrawMode drawMode
    ) noexcept -> void {
        m_DrawMode = drawMode;
    }


    auto Drawable::setData(
        const std::vector<float>& data
    ) -> void {
        m_Data.assign(data.begin(), data.end());
    }


    auto Drawable::setIndices(
        const std::vector<GLuint>& indices
    ) -> void {
        m_Indices.assign(indices.begin(), indices.end());
    }


    auto Drawable::draw(
    ) const -> void {
        glBindVertexArray(m_VertexArray);
        glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ElementBuffer);

        glBufferData(GL_ARRAY_BUFFER, m_Data.size() * sizeof(decltype(m_Data.data())),
            m_Data.data(), static_cast<GLenum>(m_DrawMethod));

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(decltype(m_Indices.data())),
            m_Indices.data(), static_cast<GLenum>(m_DrawMethod));

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
        glEnableVertexAttribArray(0);

        //glDrawArrays(static_cast<GLenum>(m_DrawMode), 0, 3);
        glDrawElements(static_cast<GLenum>(m_DrawMode), 6, GL_UNSIGNED_INT, 0);
    }

}
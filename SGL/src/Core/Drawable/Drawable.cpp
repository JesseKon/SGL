/**
 *
 *
 *
 */

#include "Drawable.h"

namespace SGL {

    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors and destructor
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /* ***************************************************************************************** */
    Drawable::Drawable(
    ) {
        create();
    }


    /* ***************************************************************************************** */
    Drawable::~Drawable(
    ) noexcept {
        destroy();
    }


    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Public methods
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /* ***************************************************************************************** */
    auto Drawable::create(
    ) -> void {
        glGenVertexArrays(1, &m_VertexArray);
        glGenBuffers(1, &m_VertexBuffer);
        glGenBuffers(1, &m_ElementBuffer);
        m_DrawMethod = DrawMethod::Static;
        m_DrawMode = DrawMode::Triangles;
    }


    /* ***************************************************************************************** */
    auto Drawable::destroy(
    ) noexcept -> void {
        glBindVertexArray(NULL);
        glBindBuffer(m_VertexBuffer, NULL);
        glBindBuffer(m_ElementBuffer, NULL);
        if (m_VertexArray) glDeleteVertexArrays(1, &m_VertexArray);
        if (m_VertexBuffer) glDeleteBuffers(1, &m_VertexBuffer);
        if (m_ElementBuffer) glDeleteBuffers(1, &m_ElementBuffer);
        m_VertexArray = m_VertexBuffer = m_ElementBuffer = NULL;
    }


    /* ***************************************************************************************** */
    auto Drawable::setDrawMethod(
        const DrawMethod drawMethod
    ) noexcept -> void {
        m_DrawMethod = drawMethod;
    }


    /* ***************************************************************************************** */
    auto Drawable::setDrawMode(
        const DrawMode drawMode
    ) noexcept -> void {
        m_DrawMode = drawMode;
    }


    /* ***************************************************************************************** */
    auto Drawable::setBufferData(
        const std::int32_t location,
        const std::int32_t size,
        const std::vector<BufferDataType>&& data
    ) -> void {
        m_BufferData.push_back({ location, size, data });
    }


    /* ***************************************************************************************** */
    auto Drawable::setIndices(
        const std::vector<IndicesDataType>&& indices
    ) -> void {
        m_Indices.assign(indices.begin(), indices.end());
    }


    /* ***************************************************************************************** */
    auto Drawable::configure(
    ) -> void {
        // TODO: throw
        assert(!m_BufferData.empty() && "m_Data is not set.");
        assert(!m_Indices.empty() && "m_Indices are not set.");

        glBindVertexArray(m_VertexArray);
        glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ElementBuffer);

        glBufferData(GL_ARRAY_BUFFER, 512 * sizeof(BufferDataType),
            nullptr, static_cast<GLenum>(m_DrawMethod));

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(BufferDataType),
            m_Indices.data(), static_cast<GLenum>(m_DrawMethod));

        std::size_t offset = 0;
        for (std::size_t i = 0; i < m_BufferData.size(); ++i) {
            glBufferSubData(
                GL_ARRAY_BUFFER,
                offset,
                m_BufferData.at(i).data.size() * sizeof(BufferDataType),
                m_BufferData.at(i).data.data()
            );

            glVertexAttribPointer(
                m_BufferData.at(i).location,
                m_BufferData.at(i).size,
                m_BufferDataGLType,
                GL_FALSE,
                m_BufferData.at(i).size * sizeof(BufferDataType),
                reinterpret_cast<void*>(offset)
            );

            glEnableVertexAttribArray(m_BufferData.at(i).location);
            offset += m_BufferData.at(i).data.size() * sizeof(BufferDataType);
        }

    }


    /* ***************************************************************************************** */
    auto Drawable::draw(
    ) const -> void {
        glBindVertexArray(m_VertexArray);
        glDrawElements(static_cast<GLenum>(m_DrawMode), m_Indices.size(), m_IndicesDataGLType, 0);
    }

}
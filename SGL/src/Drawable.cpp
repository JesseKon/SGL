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
        m_BufferDataChanged = false;
        m_IndicesDataChanged = false;
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
        m_BufferDataChanged = true;
        m_IndicesDataChanged = true;
    }


    /* ***************************************************************************************** */
    auto Drawable::setDrawMethod(
        const DrawMethod drawMethod
    ) noexcept -> void {
        if (!m_BufferDataChanged || !m_IndicesDataChanged)
            m_BufferDataChanged = m_IndicesDataChanged = (drawMethod != m_DrawMethod ? true : false);

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
        std::size_t oldSize = 0;
        std::for_each(m_BufferData.begin(), m_BufferData.end(),
            [&](const BufferData& bufferData) { oldSize += bufferData.data.size(); });

        // Something already assigned to given location?
        auto it = std::find_if(m_BufferData.begin(), m_BufferData.end(),
            [&](const BufferData& bufferData) { return bufferData.location == location; });

        if (it != m_BufferData.end())
            m_BufferData.at(std::distance(m_BufferData.begin(), it)) = { location, size, data };
        else
            m_BufferData.push_back({ location, size, data });

        std::size_t newSize = 0;
        std::for_each(m_BufferData.begin(), m_BufferData.end(),
            [&](const BufferData& bufferData) { newSize += bufferData.data.size(); });
        
        if (!m_BufferDataChanged)
            m_BufferDataChanged = (oldSize != newSize ? true : false);
    }


    /* ***************************************************************************************** */
    auto Drawable::setIndices(
        const std::vector<IndicesDataType>&& indices
    ) -> void {
        std::size_t oldSize = m_Indices.size();

        m_Indices.assign(indices.begin(), indices.end());
        std::size_t newSize = m_Indices.size();

        if (!m_IndicesDataChanged)
            m_IndicesDataChanged = (oldSize != newSize ? true : false);
    }


    /* ***************************************************************************************** */
    auto Drawable::configure(
    ) -> void {

        // TODO: throw these
        assert(!m_BufferData.empty() && "m_Data is not set.");
        assert(!m_Indices.empty() && "m_Indices are not set.");

        glBindVertexArray(m_VertexArray);
        glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ElementBuffer);

        // Update array buffer if its size or draw method was changed
        if (m_BufferDataChanged) {
            std::size_t arrayBufferSize = 0;
            std::for_each(m_BufferData.begin(), m_BufferData.end(),
                [&](const BufferData& bufferData) { arrayBufferSize += bufferData.data.size(); });

            glBufferData(GL_ARRAY_BUFFER, arrayBufferSize * sizeof(BufferDataType),
                nullptr, static_cast<GLenum>(m_DrawMethod));

            m_BufferDataChanged = false;
        }

        // Update element buffer if its size or draw method was changed
        if (m_IndicesDataChanged) {
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(BufferDataType),
                nullptr, static_cast<GLenum>(m_DrawMethod));

            m_IndicesDataChanged = false;
        }

        // Update array buffer data
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

        // Update element buffer data
        glBufferSubData(
            GL_ELEMENT_ARRAY_BUFFER,
            0,
            m_Indices.size() * sizeof(BufferDataType),
            m_Indices.data()
        );
    }


    /* ***************************************************************************************** */
    auto Drawable::draw(
    ) const -> void {
        glBindVertexArray(m_VertexArray);
        glDrawElements(static_cast<GLenum>(m_DrawMode), m_Indices.size(), m_IndicesDataGLType, 0);
    }

}
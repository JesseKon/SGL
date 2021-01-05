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
        m_DrawMode = DrawMode::Points;

        m_VertexAttributes = { };
        m_Stride = 0;
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

        m_VertexAttributes = { };
        m_Stride = 0;
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
    auto Drawable::setData(
        const std::vector<float>& data
    ) -> void {
        m_Data.assign(data.begin(), data.end());
    }


    /* ***************************************************************************************** */
    auto Drawable::setIndices(
        const std::vector<GLuint>& indices
    ) -> void {
        m_Indices.assign(indices.begin(), indices.end());
    }


    /* ***************************************************************************************** */
    auto Drawable::setVertexAttributes(
        const VertexAttributes& vertexAttributes
    ) -> void {
        m_VertexAttributes.assign(vertexAttributes.begin(), vertexAttributes.end());

        // The stride is the sum of every vertex attribute's size
        m_Stride = 0;
        std::for_each(vertexAttributes.begin(), vertexAttributes.end(),
            [&](const std::array<GLuint, 2> arr) { m_Stride += arr.at(1); });
    }


    /* ***************************************************************************************** */
    auto Drawable::configure(
    ) -> void {
        assert(!m_Data.empty() && "m_Data is not set.");
        assert(!m_Indices.empty() && "m_Indices are not set.");
        assert(!m_VertexAttributes.empty() && "m_VertexAttributes are not set.");

        glBindVertexArray(m_VertexArray);
        glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ElementBuffer);

        glBufferData(GL_ARRAY_BUFFER, m_Data.size() * sizeof(decltype(m_Data.data())),
            m_Data.data(), static_cast<GLenum>(m_DrawMethod));

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(decltype(m_Indices.data())),
            m_Indices.data(), static_cast<GLenum>(m_DrawMethod));

        std::size_t offset = 0;
        for (std::size_t i = 0; i < m_VertexAttributes.size(); ++i) {
            glVertexAttribPointer(
                m_VertexAttributes.at(i).at(0),
                m_VertexAttributes.at(i).at(1),
                GL_FLOAT,
                GL_FALSE,
                m_Stride * sizeof(decltype(m_Data.data())),
                (void*)(offset * sizeof(decltype(m_Data.data())))
            );

            glEnableVertexAttribArray(m_VertexAttributes.at(i).at(0));
            offset += m_VertexAttributes.at(i).at(1);
        }

        //// Position
        //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        //glEnableVertexAttribArray(0);

        //// Texture coord
        //glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        //glEnableVertexAttribArray(1);
    }


    /* ***************************************************************************************** */
    auto Drawable::draw(
    ) const -> void {
        glBindVertexArray(m_VertexArray);
        glDrawElements(static_cast<GLenum>(m_DrawMode), m_Indices.size(), GL_UNSIGNED_INT, 0);
    }

}
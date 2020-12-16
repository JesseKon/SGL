/**
 * 
 * 
 * 
 */

#ifndef _SGL_DRAWABLE_H_
#define _SGL_DRAWABLE_H_

#include "SGLCore.h"

namespace SGL {

    enum class DrawMethod : GLenum {
        Static = GL_STATIC_DRAW,
        Dynamic = GL_DYNAMIC_DRAW
    };


    enum class DrawMode : GLenum {
        Points = GL_POINTS,
        Lines = GL_LINES,
        Triangles = GL_TRIANGLES
    };


    class Drawable
    {
    public:

        SGL_API Drawable(
        );


        SGL_API ~Drawable(
        ) noexcept;


        auto SGL_API setDrawMethod(
            const DrawMethod drawMethod
        ) noexcept -> void;


        auto SGL_API setDrawMode(
            const DrawMode drawMode
        ) noexcept -> void;


        auto SGL_API setData(
            const std::vector<float>& data
        ) -> void;


        auto SGL_API setIndices(
            const std::vector<GLuint>& indices
        ) -> void;


        auto SGL_API draw(
        ) const -> void;


    private:
        GLuint m_VertexArray, m_VertexBuffer, m_ElementBuffer;
        std::vector<float> m_Data;
        std::vector<GLuint> m_Indices;

        DrawMethod m_DrawMethod;
        DrawMode m_DrawMode;
        std::vector<std::array<GLuint, 2>> m_VertexAttributes; // TODO: layout location and size 
    };

}

#endif  /* _SGL_DRAWABLE_H_ */
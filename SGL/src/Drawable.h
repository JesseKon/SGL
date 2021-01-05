/**
 * 
 * 
 * 
 */

#ifndef _SGL_DRAWABLE_H_
#define _SGL_DRAWABLE_H_

#include "SGLCore.h"

namespace SGL {

    /// <summary>
    /// Drawing methods. 
    /// </summary>
    enum class DrawMethod : GLenum {
        Static = GL_STATIC_DRAW,
        Dynamic = GL_DYNAMIC_DRAW
    };


    /// <summary>
    /// Drawing modes.
    /// </summary>
    enum class DrawMode : GLenum {
        Points = GL_POINTS,
        Lines = GL_LINES,
        Triangles = GL_TRIANGLES
    };


    /// <summary>
    /// The first parameter in the array specifies which vertex attribute in configures, and the
    /// second parameter specifies its size.
    /// </summary>
    using VertexAttributes = std::vector<std::array<GLuint, 2>>;


    class Drawable
    {
    public:

        /// <summary>
        /// Default constructor.
        /// </summary>
        /// 
        /// <returns></returns>
        SGL_API Drawable(
        );


        /// <summary>
        /// Destructor.
        /// </summary>
        /// 
        /// <returns></returns>
        SGL_API ~Drawable(
        ) noexcept;


        /// <summary>
        /// 
        /// </summary>
        /// 
        /// <returns></returns>
        auto SGL_API create(
        ) -> void;


        /// <summary>
        /// 
        /// </summary>
        /// 
        /// <returns></returns>
        auto SGL_API destroy(
        ) noexcept -> void;


        /// <summary>
        /// Set drawing method for this object.
        /// </summary>
        /// 
        /// <param name="drawMethod">
        /// The drawing method this object will use.
        /// </param>
        /// 
        /// <returns></returns>
        auto SGL_API setDrawMethod(
            const DrawMethod drawMethod
        ) noexcept -> void;


        /// <summary>
        /// Set drawing mode for this object.
        /// </summary>
        /// 
        /// <param name="drawMode">
        /// The drawing mode this object will use.
        /// </param>
        /// 
        /// <returns></returns>
        auto SGL_API setDrawMode(
            const DrawMode drawMode
        ) noexcept -> void;


        /// <summary>
        /// Set raw data for this object.
        /// </summary>
        /// 
        /// <param name="data">
        /// The raw data for this object.
        /// </param>
        /// 
        /// <returns></returns>
        auto SGL_API setData(
            const std::vector<float>& data
        ) -> void;


        /// <summary>
        /// Set indices for this object.
        /// </summary>
        /// 
        /// <param name="indices">
        /// Array of indices this object will use.
        /// </param>
        /// 
        /// <returns></returns>
        auto SGL_API setIndices(
            const std::vector<GLuint>& indices
        ) -> void;


        /// <summary>
        /// Set vertex attribute data for this object. 
        /// </summary>
        /// 
        /// <param name="vertexAttributes">
        /// Array of vertex attributes this object will use.
        /// </param>
        /// 
        /// <returns></returns>
        auto SGL_API setVertexAttributes(
            const VertexAttributes& vertexAttributes
        ) -> void;


        /// <summary>
        /// Configure this object. Every drawable object has to be configured before it can be 
        /// used. Note that before the object can be configured, it needs to have its data, 
        /// indices and vertex attributes set.
        /// </summary>
        /// 
        /// <returns></returns>
        auto SGL_API configure(
        ) -> void;


        /// <summary>
        /// Draw this object in renderer.
        /// </summary>
        /// 
        /// <returns></returns>
        auto SGL_API draw(
        ) const -> void;


    private:
        GLuint m_VertexArray, m_VertexBuffer, m_ElementBuffer;
        std::vector<float> m_Data;
        std::vector<GLuint> m_Indices;

        DrawMethod m_DrawMethod;
        DrawMode m_DrawMode;
        VertexAttributes m_VertexAttributes; // layout location and size 
        GLuint m_Stride;
    };

}

#endif  /* _SGL_DRAWABLE_H_ */
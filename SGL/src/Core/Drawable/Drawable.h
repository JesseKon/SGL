/**
 * 
 * 
 * 
 */

#ifndef _SGL_DRAWABLE_H_
#define _SGL_DRAWABLE_H_

#include "SGLCore.h"
#include "DrawMethod.h"
#include "DrawMode.h"

namespace SGL {

    /// <summary>
    /// Base class for creating any drawable object.
    /// </summary>
    class Drawable
    {
    public:

        using BufferDataType = GLfloat;
        using IndicesDataType = GLuint;


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
        /// 
        /// </summary>
        /// <param name="location"></param>
        /// <param name="size"></param>
        /// <param name="data"></param>
        /// <returns></returns>
        auto SGL_API setBufferData(
            const std::int32_t location,
            const std::int32_t size,
            const std::vector<BufferDataType>&& data
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
            const std::vector<IndicesDataType>&& indices
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
        std::vector<IndicesDataType> m_Indices;

        struct BufferData {
            std::int32_t location;
            std::int32_t size;
            std::vector<BufferDataType> data;
        };
        std::vector<BufferData> m_BufferData;

        DrawMethod m_DrawMethod;
        DrawMode m_DrawMode;

        bool m_BufferDataChanged;   // buffer size or draw method changed
        bool m_IndicesDataChanged;  // buffer size or draw method changed

        static constexpr auto m_BufferDataGLType = GL_FLOAT;
        static constexpr auto m_IndicesDataGLType = GL_UNSIGNED_INT;
    };

}

#endif  /* _SGL_DRAWABLE_H_ */
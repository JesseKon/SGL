/**
* 
* 
* 
*/

#ifndef _SGL_RENDERER_H_
#define _SGL_RENDERER_H_

#include "SGLCore.h"

#include "RendererType.h"
#include "Vector2.h"
#include "Color.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace SGL {

    class Renderer
    {
    public:

        /**
         * Default constructor.
         * 
         * Note: this doesn't actually create the renderer. Call create() to do so.
         */
        SGL_API Renderer(
        ) noexcept;


        /**
         * Create a new OpenGL 3.3 renderer.
         *
         * @param width Window width for this renderer, in pixels.
         * @param height Window height for this renderer, in pixels.
         * @param windowTitle Window title for this renderer.
         * @exception Throws std::runtime_error if window couldn't be created.
         */
        SGL_API Renderer(
            const Vector2<std::uint32_t>& windowSize,
            const std::string& windowTitle,
            const RendererType rendererType = RendererType::Windowed
        );


        /**
         * Destructor.
         */
        SGL_API ~Renderer(
        ) noexcept;


        /**
         * Create a new OpenGL 3.3 renderer.
         *
         * @param width Window width for this renderer, in pixels.
         * @param height Window height for this renderer, in pixels.
         * @param windowTitle Window title for this renderer.
         * @exception Throws std::runtime_error if renderer couldn't be created.
         */
        SGL_API auto create(
            const Vector2<std::uint32_t>& windowSize,
            const std::string& windowTitle,
            const RendererType rendererType = RendererType::Windowed
        ) -> void;


        /**
         * Destroy this renderer. Destructor calls it automatically.
         */
        SGL_API auto destroy(
        ) noexcept -> void;


        SGL_API auto running(
        ) const noexcept -> bool;


        /// <summary>
        /// Begin drawing to the renderer.
        /// </summary>
        /// <param name="clearColorBuffer"></param>
        /// <param name="clearDepthBuffer"></param>
        /// <param name="clearStencilBuffer"></param>
        /// <param name="color"></param>
        /// <returns></returns>
        SGL_API auto beginDrawing(
            const bool clearColorBuffer,
            const bool clearDepthBuffer,
            const bool clearStencilBuffer,
            const Color& color = COLOR::Black
        ) const noexcept -> void;


        /// <summary>
        /// Finish drawing to the renderer.
        /// </summary>
        SGL_API auto endDrawing(
        ) const noexcept -> void;


        /// <summary>
        /// Close the renderer and window.
        /// </summary>
        /// <returns></returns>
        SGL_API auto close(
        ) const noexcept -> void;


        SGL_API auto resizeWindow(
            const Vector2<std::uint32_t>& newSize
        ) noexcept -> void;


        SGL_API auto getWindowSize(
        ) const noexcept -> Vector2<std::uint32_t>;


        SGL_API auto setWindowPosition(
            const Vector2<std::int32_t>& newPosition
        ) noexcept -> void;


        SGL_API auto getWindowPosition(
        ) const noexcept -> Vector2<std::int32_t>;


        SGL_API auto setTitle(
            const std::string& newTitle
        ) noexcept -> void;


        SGL_API auto getTitle(
        ) const noexcept -> const char*;


        SGL_API auto getGLFWwindow(
        ) const noexcept -> GLFWwindow*;


    private:
        Vector2<std::uint32_t> m_WindowSize;
        std::string m_WindowTitle;
        mutable bool m_QuitRequested;

        GLFWwindow* m_pGLFWwindow;
        
    };

}  /* namespace SGL */

#endif  /* _SGL_RENDERER_H_ */
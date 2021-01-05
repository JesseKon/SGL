/**
* 
* 
* 
*/

#ifndef _SGL_RENDERER_OGL3_H_
#define _SGL_RENDERER_OGL3_H_

#include "SGLCore.h"
#include "Renderer.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace SGL {

    class RendererOGL3 : public Renderer
    {
    public:

        /**
         * Default constructor.
         * 
         * Note: this doesn't actually create the renderer. Call create() to do so.
         */
        SGL_API RendererOGL3(
        ) noexcept;


        /**
         * Create a new OpenGL 3.3 renderer.
         *
         * @param width Window width for this renderer, in pixels.
         * @param height Window height for this renderer, in pixels.
         * @param windowTitle Window title for this renderer.
         * @exception Throws std::runtime_error if window couldn't be created.
         */
        SGL_API RendererOGL3(
            const Vector2<std::uint32_t>& windowSize,
            const std::string& windowTitle
        );


        /**
         * Destructor.
         */
        SGL_API ~RendererOGL3(
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
            const std::string& windowTitle
        ) -> void override;


        /**
         * Destroy this renderer. Destructor calls it automatically.
         */
        SGL_API auto destroy(
        ) noexcept -> void override;


        SGL_API auto running(
        ) const noexcept -> bool override;


        SGL_API auto beginDrawing(
            const Color& color
        ) const noexcept -> void override;


        SGL_API auto endDrawing(
        ) const noexcept -> void override;


        SGL_API auto close(
        ) const noexcept -> void override;


        SGL_API auto resizeWindow(
            const Vector2<std::uint32_t>& newSize
        ) noexcept -> void override;


        SGL_API auto getWindowSize(
        ) const noexcept -> Vector2<std::uint32_t> override;


        SGL_API auto setWindowPosition(
            const Vector2<std::int32_t>& newPosition
        ) noexcept -> void override;


        SGL_API auto getWindowPosition(
        ) const noexcept -> Vector2<std::int32_t> override;


        SGL_API auto setTitle(
            const std::string& newTitle
        ) noexcept -> void override;


        SGL_API auto getTitle(
        ) const noexcept -> const char* override;


        SGL_API auto getGLFWwindow(
        ) const noexcept -> GLFWwindow* override;


    private:
        Vector2<std::uint32_t> m_WindowSize;
        std::string m_WindowTitle;
        mutable bool m_QuitRequested;

        
    };

}  /* namespace SGL */

#endif  /* _SGL_RENDERER_OGL3_H_ */
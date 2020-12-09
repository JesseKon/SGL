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

    class SGL_API RendererOGL3 : public Renderer
    {
    public:

        /**
         * Default constructor.
         * 
         * Note: this doesn't actually create the renderer. Call create() to do so.
         */
        RendererOGL3(
        ) noexcept;


        /**
         * Create a new OpenGL 3.3 renderer.
         *
         * @param width Window width for this renderer, in pixels.
         * @param height Window height for this renderer, in pixels.
         * @param windowTitle Window title for this renderer.
         * @exception Throws std::runtime_error if window couldn't be created.
         */
        RendererOGL3(
            const Vector2<std::uint32_t>& windowSize,
            const std::string& windowTitle
        );


        /**
         * Destructor.
         */
        ~RendererOGL3(
        );


        /**
         * Create a new OpenGL 3.3 renderer.
         *
         * @param width Window width for this renderer, in pixels.
         * @param height Window height for this renderer, in pixels.
         * @param windowTitle Window title for this renderer.
         * @exception Throws std::runtime_error if renderer couldn't be created.
         */
        auto create(
            const Vector2<std::uint32_t>& windowSize,
            const std::string& windowTitle
        ) -> void;


        /**
         * Destroy this renderer. Destructor calls it automatically.
         */
        auto destroy(
        ) noexcept -> void;


        auto running(
        ) const noexcept -> bool override;


        auto clear(
            const Color& color
        ) const noexcept -> void override;


        auto draw(
        ) const noexcept -> void override;


        auto close(
        ) const noexcept -> void override;


        auto resizeWindow(
            const Vector2<std::uint32_t>& newSize
        ) noexcept -> void override;


        auto resizeWindow(
            const Vector2<std::uint32_t>&& newSize
        ) noexcept -> void override;


        auto getWindowSize(
        ) const noexcept -> Vector2<std::uint32_t> override;


        auto setTitle(
            const std::string& newTitle
        ) noexcept -> void override;


        auto getTitle(
        ) const noexcept -> const char* override;


        auto getGLFWwindow(
        ) const noexcept -> GLFWwindow* override;


    private:
        Vector2<std::uint32_t> m_WindowSize;
        std::string m_WindowTitle;
        mutable bool m_QuitRequested;

        GLFWwindow* m_pGLFWwindow;
    };

}  /* namespace SGL */

#endif  /* _SGL_RENDERER_OGL3_H_ */
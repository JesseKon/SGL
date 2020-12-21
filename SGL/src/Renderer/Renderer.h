/**
* 
* 
* 
*/

#ifndef _SGL_RENDERER_H_
#define _SGL_RENDERER_H_

#include "SGLCore.h"

#include "Drawable.h"
#include "ShaderGLSL.h"
#include "Color.h"
#include "Vector2.h"


namespace SGL {

    enum class RendererType {
        
        /**
         * No renderer
         */
        None,

        /**
         * OpenGL 3.3
         */
        OpenGL3

    };


    class Renderer
    {
    public:

        /**
         * Destructor.
         */
        virtual ~Renderer(
        ) = 0 {};


        /**
         * Create a new renderer.
         *
         * @param width Window width for this renderer, in pixels.
         * @param height Window height for this renderer, in pixels.
         * @param windowTitle Window title for this renderer.
         * @exception Throws std::runtime_error if renderer couldn't be created.
         */
        virtual auto create(
            const Vector2<std::uint32_t>& windowSize,
            const std::string& windowTitle
        ) -> void = 0;


        /**
         * Destroy this renderer. Destructor calls it automatically.
         */
        virtual auto destroy(
        ) noexcept -> void = 0;


        /**
         * 
         */
        virtual auto running(
        ) const noexcept -> bool = 0;


        /**
         * 
         */
        virtual auto beginRendering(
            const Color& color
        ) const noexcept -> void = 0;


        /**
         * Draw content.
         */
        virtual auto draw(
            const Drawable& drawable,
            const ShaderGLSL& shader
        ) const noexcept -> void = 0;


        /**
         * 
         */
        virtual auto endRendering(
        ) const noexcept -> void = 0;


        /**
         * Close this renderer.
         */
        virtual auto close(
        ) const noexcept -> void = 0;


        /**
         *
         */
        virtual auto resizeWindow(
            const Vector2<std::uint32_t>& newSize
        ) noexcept -> void = 0;


        /**
         *
         */
        virtual auto getWindowSize(
        ) const noexcept -> Vector2<std::uint32_t> = 0;


        /**
         * 
         */
        virtual auto setWindowPosition(
            const Vector2<std::int32_t>& newPosition
        ) noexcept -> void = 0;


        /**
         * 
         */
        virtual auto getWindowPosition(
        ) const noexcept -> Vector2<std::int32_t> = 0;


        /**
         * Change the title of this renderer's window.
         *
         * @param newTitle New title for this renderer's window.
         */
        virtual auto setTitle(
            const std::string& newTitle
        ) noexcept -> void = 0;


        /**
         * Get the title of this renderer's window.
         *
         * @return Title of this renderer's window.
         */
        virtual auto getTitle(
        ) const noexcept -> const char* = 0;


        /**
         * Get pointer to the GLFW window handle.
         *
         * @return Pointer to the GLFW window handle.
         */
        virtual auto getGLFWwindow(
        ) const noexcept -> const GLFWwindow* = 0;


    protected:
        GLFWwindow* m_pGLFWwindow;

    };

}  /* namespace SGL */

#endif /* _SGL_RENDERER_H_ */
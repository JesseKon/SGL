/**
 *
 *
 *
 */

#ifndef _SGL_WINDOW_
#define _SGL_WINDOW_

#include "SGLCore.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Renderer.h"
#include "RendererOGL3.h"
#include "Color.h"
#include "Input.h"

#include "Vector2.h"


namespace SGL {

    class SGL_API Window
    {
    public:

        /**
         * Default constructor. 
         * 
         * Note: this doesn't actually create the window. Call create() to do so.
         */
        Window(
        ) noexcept;


        /**
         * Create a new window. 
         * 
         * @param rendererType RendererType for this window.
         * @param windowSize Window size in Vector2<std::uint32_t> format.
         * @param title Title for this window.
         * @exception Throws std::runtime_error if window couldn't be created.
         */
        Window(
            const RendererType rendererType,
            const Vector2<std::uint32_t>& windowSize,
            const std::string& title
        );


        /**
         * Create a new window. 
         *
         * @param rendererType RendererType for this window.
         * @param windowSize Window size in Vector2<std::uint32_t> format.
         * @param title Title for this window.
         * @exception Throws std::runtime_error if window couldn't be created.
         */
        Window(
            const RendererType rendererType,
            const Vector2<std::uint32_t>&& windowSize,
            const std::string& title
        );


        /**
         * Destructor.
         */
        ~Window(
        );


        /**
         * Create a new window. 
         * 
         * @param rendererType Renderer for this window.
         * @param windowSize Window size in Vector2<std::uint32_t> format.
         * @param title Title for this window.
         * @exception Throws std::runtime_error if window couldn't be created.
         */
        auto create(
            const RendererType rendererType,
            const Vector2<std::uint32_t>& windowSize,
            const std::string& title
        ) -> void;


        /**
         * Create a new window. 
         *
         * @param rendererType Renderer for this window.
         * @param windowSize Window size in Vector2<std::uint32_t> format.
         * @param title Title for this window.
         * @exception Throws std::runtime_error if window couldn't be created.
         */
        auto create(
            const RendererType rendererType,
            const Vector2<std::uint32_t>&& windowSize,
            const std::string& title
        ) -> void;


        /**
         * Destroy this window. Destructor calls it automatically. 
         */
        auto destroy(
        ) noexcept -> void;


        /**
         * 
         * 
         * 
         */
        auto getRenderer(
        ) const noexcept -> Renderer*;


        /**
         *
         *
         *
         */
        auto getInput(
        ) const noexcept -> Input*;


    private:
        Renderer* m_pRenderer;
        Input* m_pInput;

    };

}  /* namespace SGL */

#endif  /* _SGL_WINDOW_ */
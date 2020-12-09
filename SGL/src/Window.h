/**
 *
 *
 *
 */

#ifndef _SGL_WINDOW_
#define _SGL_WINDOW_

#include "SGLCore.h"

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
         * @param windowSize Window size in pixels.
         * @param windowTitle Title for this window.
         * @exception Throws std::runtime_error if window couldn't be created.
         */
        Window(
            const RendererType rendererType,
            const Vector2<std::uint32_t>& windowSize,
            const std::string& windowTitle = ""
        );


        /**
         * Create a new window. 
         *
         * @param rendererType RendererType for this window.
         * @param windowSize Window size in pixels.
         * @param windowTitle Title for this window.
         * @exception Throws std::runtime_error if window couldn't be created.
         */
        Window(
            const RendererType rendererType,
            const Vector2<std::uint32_t>&& windowSize,
            const std::string& windowTitle = ""
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
         * @param windowSize Window size in pixels.
         * @param windowTitle Title for this window.
         * @exception Throws std::runtime_error if window couldn't be created.
         */
        auto create(
            const RendererType rendererType,
            const Vector2<std::uint32_t>& windowSize,
            const std::string& windowTitle = ""
        ) -> void;


        /**
         * Create a new window. 
         *
         * @param rendererType Renderer for this window.
         * @param windowSize Window size in pixels.
         * @param windowTitle Title for this window.
         * @exception Throws std::runtime_error if window couldn't be created.
         */
        auto create(
            const RendererType rendererType,
            const Vector2<std::uint32_t>&& windowSize,
            const std::string& windowTitle = ""
        ) -> void;


        /**
         * Destroy this window. Destructor calls it automatically. 
         */
        auto destroy(
        ) noexcept -> void;


        /**
         * Get pointer to the renderer of this window. Use it to gain access to the renderer's 
         * methods.
         * 
         * @return Pointer to the renderer of this window.
         */
        auto getRenderer(
        ) const noexcept -> Renderer*;


        /**
         * Get pointer to the input handler of this window. Use it to gain access to the input 
         * handler's methods.
         * 
         * @return Pointer to the input handler of this window.
         */
        auto getInput(
        ) const noexcept -> Input*;


    private:
        Renderer* m_pRenderer;
        Input* m_pInput;

    };

}  /* namespace SGL */

#endif  /* _SGL_WINDOW_ */
/**
 *
 *
 *
 */

#ifndef _SGL_WINDOW_
#define _SGL_WINDOW_

#include "SGLCore.h"

#include "Renderer.h"
#include "Color.h"
#include "Input.h"

#include "Vector2.h"


namespace SGL {

    /// <summary>
    /// 
    /// </summary>
    class Window
    {
    public:

        /// <summary>
        /// Default constructor. This doesn't create a window, use create() to do so.
        /// </summary>
        SGL_API Window(
        ) noexcept;


        /**
         * Create a new window. 
         *
         * @param rendererType RendererType for this window.
         * @param windowSize Window size in pixels.
         * @param windowTitle Title for this window.
         * @exception Throws std::runtime_error if window couldn't be created.
         */

        /// <summary>
        /// Create a new window. 
        /// </summary>
        /// 
        /// <param name="rendererType"></param>
        /// <param name="windowSize"></param>
        /// <param name="windowTitle"></param>
        /// <returns></returns>
        SGL_API Window(
            const Vector2<std::uint32_t>& windowSize,
            const std::string& windowTitle = "",
            const RendererType rendererType = RendererType::Windowed
        );


        /// <summary>
        /// Destructor.
        /// </summary>
        SGL_API ~Window(
        ) noexcept;


        /**
         * Create a new window. 
         *
         * @param rendererType Renderer for this window.
         * @param windowSize 
         * @param windowTitle 
         * @exception Throws std::runtime_error if window couldn't be created.
         */

        /// <summary>
        /// Create a new window.
        /// </summary>
        /// 
        /// <param name="windowSize">
        /// Window size in pixels.
        /// </param>
        /// 
        /// <param name="windowTitle">
        /// Title for this window.
        /// </param>
        SGL_API auto create(
            const Vector2<std::uint32_t>& windowSize,
            const std::string& windowTitle = "",
            const RendererType rendererType = RendererType::Windowed
        ) -> void;


        /// <summary>
        /// Destroy this window. Destructor calls it automatically.
        /// </summary>
        SGL_API auto destroy(
        ) noexcept -> void;


        /// <summary>
        /// Get pointer to the renderer of this window. Use it to gain access to the renderer's
        /// methods.
        /// </summary>
        /// 
        /// <returns>
        /// Pointer to the renderer of this window.
        /// </returns>
        SGL_API auto getRenderer(
        ) const noexcept -> Renderer*;


        /// <summary>
        /// Get pointer to the input handler of this window. Use it to gain access to the input 
        /// handler's methods.
        /// </summary>
        /// 
        /// <returns>
        /// Pointer to the input handler of this window.
        /// </returns>
        SGL_API auto getInput(
        ) const noexcept -> Input*;


    private:
        Renderer* m_pRenderer;
        Input* m_pInput;

    };

}  /* namespace SGL */

#endif  /* _SGL_WINDOW_ */
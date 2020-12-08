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


namespace SGL {

    //class SGL_API Input;

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
         * @param width Width for this window, in pixels.
         * @param height Height for this window, in pixels.
         * @param title Title for this window.
         * @exception Throws std::runtime_error if window couldn't be created.
         */
        Window(
            const RendererType rendererType,
            const std::uint32_t width,
            const std::uint32_t height,
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
         * @param rendererType RendererType for this window.
         * @param width Width for this window, in pixels.
         * @param height Height for this window, in pixels.
         * @param title Title for this window.
         * @exception Throws std::runtime_error if window couldn't be created.
         */
        auto create(
            const RendererType rendererType,
            const std::uint32_t width,
            const std::uint32_t height,
            const std::string& title
        ) -> void;


        /**
         * Destroy this window. Destructor calls it automatically. 
         */
        auto destroy(
        ) noexcept -> void;


        /**
         * Update inputs and check whether this window should be closed. Use it in the 
         * application main loop. 
         * 
         * @return True if this window should be still running, and false if it should close. 
         */
        auto running(
        ) const noexcept -> bool;


        /**
         * Clear this window's viewport in black color. Typically used right before calling 
         * drawing commands in main loop. 
         */
        auto clear(
        ) const noexcept -> void;


        /**
         * Clear this window's viewport in given color. Typically used right before calling 
         * drawing commands in main loop. 
         * 
         * @param color Color to be used to clear this window's viewport.
         */
        auto clear(
            const Color& color
        ) const noexcept -> void;


        /**
         * Clear this window's viewport in given color. Typically used right before calling 
         * drawing commands in main loop. 
         *
         * @param color Color to be used to clear this window's viewport.
         */
        auto clear(
            const Color&& color
        ) const noexcept -> void;


        /**
         * Draw content to this window's viewport.
         */
        auto draw(
        ) const noexcept -> void;


        /**
         * Close this window.
         * 
         * @param forceQuit quits immediately before finishing the active loop.
         */
        auto close(
            const bool forceQuit = false
        ) const noexcept -> void;


        /**
         * Change the width of this window.
         * 
         * @param newWidth New width for this window, in pixels.
         */
        auto setWidth(
            const std::uint32_t newWidth
        ) noexcept -> void;


        /**
         * Get the width of this window.
         * 
         * @return Width of this window, in pixels.
         */
        auto getWidth(
        ) const noexcept -> std::uint32_t;


        /**
         * Change the height of this window.
         * 
         * @param newWidth New height for this window, in pixels.
         */
        auto setHeight(
            const std::uint32_t newHeight
        ) noexcept -> void;


        /**
         * Get the height of this window.
         * 
         * @return Height of this window, in pixels.
         */
        auto getHeight(
        ) const noexcept -> std::uint32_t;


        /**
         * Change the title of this window. 
         * 
         * @param newTitle New title for this window.
         */
        auto setTitle(
            const std::string& newTitle
        ) noexcept -> void;


        /**
         * Get the title of this window.
         * 
         * @return Title of this window.
         */
        auto getTitle(
        ) const noexcept -> const char*;


        /**
         * Get pointer to Input.
         * 
         * @return Pointer to Input.
         */
        auto getInput(
        ) const noexcept -> Input* const;


        /**
         * Get the GLFWwindow pointer to this window.
         * 
         * @return GLFWwindow pointer to this window.
         */
        auto getGLFWwindow(
        ) const noexcept -> GLFWwindow*;


    private:
        Renderer* m_pRenderer;
        Input* m_pInput;

    };

}  /* namespace SGL */

#endif  /* _SGL_WINDOW_ */
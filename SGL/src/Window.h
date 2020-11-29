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

#include "GLFW/glfw3.h"


namespace SGL {

    class SGL_API Window
    {
    public:

        /**
        * 
        */
        Window(
            const RendererType rendererType,
            const std::uint32_t width,
            const std::uint32_t height,
            const std::string& title
        );


        /**
        * 
        */
        ~Window(
        );


        /**
        * 
        */
        auto running(
        ) const noexcept -> bool;


        /**
        * 
        */
        auto clear(
        ) const noexcept -> void;


        /**
        *
        */
        auto clear(
            const Color& color
        ) const noexcept -> void;


        /**
        *
        */
        auto clear(
            const Color&& color
        ) const noexcept -> void;


        /*! @brief Draws all content to window.
        * 
        */
        auto draw(
        ) const noexcept -> void;


        /*! @brief Closes the window.
        * 
        *   @param forceQuit quits immediately before finishing the active loop.
        * 
        *   @return Nothing.
        */
        auto close(
            const bool forceQuit = false
        ) const noexcept -> void;


        /*! @brief
        * 
        */
        auto getGLFWwindow(
        ) const -> GLFWwindow*;


    private:
        Renderer* m_pRenderer;
    };

}  /* namespace SGL */

#endif  /* _SGL_WINDOW_ */
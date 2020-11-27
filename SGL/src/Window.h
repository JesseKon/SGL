/**
*
*
*
*/

#ifndef _SGL_WINDOW_
#define _SGL_WINDOW_

#include "SGLCore.h"
#include "GLFW/glfw3.h"

#include "Color.h"


namespace SGL {

    class SGL_API Window
    {
    public:

        /**
        * 
        */
        Window(
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
        ) const noexcept -> GLFWwindow*;


    private:
        std::uint32_t m_Width;
        std::uint32_t m_Height;
        std::string m_Title;

        mutable bool m_QuitRequested;

        GLFWwindow* m_GLFWwindow;
    };

}  /* namespace SGL */

#endif  /* _SGL_WINDOW_ */
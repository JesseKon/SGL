/**
* 
* 
* 
*/

#ifndef _SGL_RENDERER_OGL3_H_
#define _SGL_RENDERER_OGL3_H_

#include "SGLCore.h"
#include "Renderer.h"

#include "GLFW/glfw3.h"

namespace SGL {

    class SGL_API RendererOGL3 : public Renderer
    {
    public:

        /*! @brief
        *
        */
        RendererOGL3(
            const std::uint32_t width,
            const std::uint32_t height,
            const std::string& title
        );


        ~RendererOGL3(
        );


        /*! @brief
        *
        */
        virtual auto running(
        ) const noexcept -> bool override;


        /*! @brief
        * 
        */
        virtual auto clear(
            const Color& color
        ) const noexcept -> void override;


        /*! @brief Draws all content to window.
        *
        */
        virtual auto draw(
        ) const noexcept -> void override;


        /*! @brief Closes the window.
        *
        *   @param forceQuit quits immediately before finishing the active loop.
        *
        *   @return Nothing.
        */
        virtual auto close(
            const bool forceQuit = false
        ) const noexcept -> void override;


        /*!
        * 
        */
        virtual auto getGLFWwindow(
        ) const -> GLFWwindow* override;


    private:
        std::uint32_t m_Width;
        std::uint32_t m_Height;
        std::string m_Title;

        mutable bool m_QuitRequested;
        GLFWwindow* m_pGLFWwindow;
    };

}  /* namespace SGL */

#endif  /* _SGL_RENDERER_OGL3_H_ */
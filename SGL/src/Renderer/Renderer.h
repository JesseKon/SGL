/**
* 
* 
* 
*/

#ifndef _SGL_RENDERER_H_
#define _SGL_RENDERER_H_

#include "SGLCore.h"
#include "Color.h"

#include "GLFW/glfw3.h"


namespace SGL {

    enum class RendererType {
        None,
        OpenGL3
    };


    class SGL_API Renderer
    {
    public:
        
        /*! @brief
        * 
        */
        Renderer(
        );


        /*! @brief
        *
        */
        virtual ~Renderer(
        );


        /*! @brief
        *
        */
        virtual auto running(
        ) const noexcept -> bool = 0;


        /*! @brief
        *
        */
        virtual auto clear(
            const Color& color
        ) const noexcept -> void = 0;


        /*! @brief Draws all content to window.
        *
        */
        virtual auto draw(
        ) const noexcept -> void = 0;


        /*! @brief Closes the window.
        *
        *   @param forceQuit quits immediately before finishing the active loop.
        *
        *   @return Nothing.
        */
        virtual auto close(
            const bool forceQuit = false
        ) const noexcept -> void = 0;


        /*!
        * 
        */
        virtual auto getGLFWwindow(
        ) const -> GLFWwindow* = 0;


    private:

    };

}  /* namespace SGL */

#endif /* _SGL_RENDERER_H_ */
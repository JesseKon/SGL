/**
* 
* 
* 
*/

#ifndef _SGL_RENDERER_H_
#define _SGL_RENDERER_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "SGLCore.h"
#include "Color.h"


namespace SGL {

    enum class RendererType {
        None,
        OpenGL3
    };


    class SGL_API Renderer
    {
    public:
        
        /*! @brief Default constructor.
         * 
         *  Detailed description here.
         *  
         *  @return Nothing.
         */
        Renderer(
        );


        /*! @brief Destructor.
         *
         *  Detailed description here.
         * 
         *  @return Nothing.
         */
        virtual ~Renderer(
        );


        /*! @brief
         *
         *  Detailed description here.
         * 
         *  @return 
         */
        virtual auto running(
        ) const noexcept -> bool = 0;


        /*! @brief
         * 
         *  Detailed description here.
         * 
         *  @return Nothing.
         */
        virtual auto clear(
            const Color& color
        ) const noexcept -> void = 0;


        /*! @brief Draws all content to window.
         * 
         *  Detailed description here.
         * 
         *  @return Nothing.
         */
        virtual auto draw(
        ) const noexcept -> void = 0;


        /*! @brief Closes the window.
         * 
         *  Detailed description here.
         *
         *  @param forceQuit quits immediately before finishing the active loop.
         *
         *  @return Nothing.
         */
        virtual auto close(
            const bool forceQuit = false
        ) const noexcept -> void = 0;


        virtual auto setWidth(
            const std::uint32_t newWidth
        ) noexcept -> void = 0;


        virtual auto getWidth(
        ) const noexcept -> std::uint32_t = 0;


        virtual auto setHeight(
            const std::uint32_t newWidth
        ) noexcept -> void = 0;


        virtual auto getHeight(
        ) const noexcept -> std::uint32_t = 0;


        virtual auto setTitle(
            const std::string& newTitle
        ) noexcept -> void = 0;


        virtual auto getTitle(
        ) const noexcept -> const char* = 0;


        virtual auto getGLFWwindow(
        ) const noexcept -> const GLFWwindow* = 0;


    private:

    };

}  /* namespace SGL */

#endif /* _SGL_RENDERER_H_ */
/**
* 
* 
* 
*/

#ifndef _SGL_RENDERER_H_
#define _SGL_RENDERER_H_

#include "SGLCore.h"

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


    class SGL_API Renderer
    {
    public:
        
        /**
         * Constructor.
         */
        Renderer(
        );


        /**
         * Destructor.
         */
        virtual ~Renderer(
        );


        /**
         * 
         */
        virtual auto running(
        ) const noexcept -> bool = 0;


        /**
         * 
         */
        virtual auto clear(
            const Color& color
        ) const noexcept -> void = 0;


        /**
         * Draw content.
         */
        virtual auto draw(
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
        virtual auto resizeWindow(
            const Vector2<std::uint32_t>&& newSize
        ) noexcept -> void = 0;


        /**
         *
         */
        virtual auto getWindowSize(
        ) const noexcept -> Vector2<std::uint32_t> = 0;


        ///**
        // *
        // */
        //virtual auto resizeViewport(
        //    const Rect<std::int32_t>& newViewport
        //) noexcept -> void = 0;


        ///**
        // *
        // */
        //virtual auto resizeViewport(
        //    const Rect<std::int32_t>& newViewport
        //) noexcept -> void = 0;


        ///**
        // *
        // */
        //virtual auto getViewportSize(
        //) const noexcept -> Rect<std::int32_t> = 0;


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


    private:

    };

}  /* namespace SGL */

#endif /* _SGL_RENDERER_H_ */
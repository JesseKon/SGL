/**
*
*
*
*/

#ifndef _SGL_INPUT_H_
#define _SGL_INPUT_H_

#include "SGLCore.h"
#include "Renderer.h"

#include "GLFW/glfw3.h"


namespace SGL {

    class SGL_API Input
    {
    public:

        /**
         * Default constructor.
         */
        Input(
        ) noexcept;


        /**
         * 
         * 
         * @exception Throws std::runtime_error if window was nullptr.
         */
        Input(
            GLFWwindow* const window
        );


        /**
         * Destructor.
         */
        ~Input(
        );


        /*! @brief Returns true if the key is currently being pressed down.
        *
        */
        auto getKey(
            const std::int32_t keyCode
        ) noexcept -> bool;


        /*! @brief Returns true when the key was just pressed.
        *
        */
        auto getKeyDown(
            const std::int32_t keyCode
        ) noexcept -> bool;


        /*! @brief Returns true when the key was just released.
        *
        */
        auto getKeyUp(
            const std::int32_t keyCode
        ) noexcept -> bool;


    private:
        GLFWwindow* m_pGLFWwindow;

    };


}  /* namespace SGL */

#endif  /* _SGL_INPUT_H_ */
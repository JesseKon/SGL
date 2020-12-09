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

    using SGLKey = std::int32_t;

    class SGL_API Input
    {
    public:

        // Callback function for GLFW keys.
        friend auto GLFWKeyCallback(
            GLFWwindow*, int, int, int, int
        ) noexcept -> void;


        /**
         * Default constructor. 
         * 
         * Note: this doesn't actually initialize this object. Call create() to do so.
         */
        Input(
        ) noexcept;


        /**
         * 
         * 
         * @exception Throws std::runtime_error if window was nullptr.
         */
        Input(
            const GLFWwindow* window
        );


        /**
         * Destructor.
         */
        ~Input(
        );


        /**
         * 
         * 
         * @exception Throws std::runtime_error if window was nullptr.
         */
        auto create(
            const GLFWwindow* window
        ) -> void;


        /**
         * Nullify this instance. Destructor calls it automatically. 
         */
        auto destroy(
        ) noexcept -> void;


        /*! @brief Returns true if the key is currently being pressed down.
        *
        */
        auto getKey(
            const SGLKey key
        ) const noexcept -> bool;


        /*! @brief Returns true when the key was just pressed.
        *
        */
        auto getKeyPressed(
            const SGLKey key
        ) const noexcept -> bool;


        /*! @brief Returns true when the key was just released.
        *
        */
        auto getKeyReleased(
            const SGLKey key
        ) const noexcept -> bool;


    private:
        GLFWwindow* m_pGLFWwindow;

        static constexpr std::size_t NUM_OF_KEYS = 512;
        static std::array<bool, NUM_OF_KEYS> m_KeyStateChanged;

    };


    namespace KEYCODE {
        extern const SGL_API SGLKey KEY_A;
        extern const SGL_API SGLKey KEY_B;
        extern const SGL_API SGLKey KEY_C;
        extern const SGL_API SGLKey KEY_D;
        extern const SGL_API SGLKey KEY_E;
        extern const SGL_API SGLKey KEY_F;
        extern const SGL_API SGLKey KEY_G;
        extern const SGL_API SGLKey KEY_H;
        extern const SGL_API SGLKey KEY_I;
        extern const SGL_API SGLKey KEY_J;
        extern const SGL_API SGLKey KEY_K;
        extern const SGL_API SGLKey KEY_L;
        extern const SGL_API SGLKey KEY_M;
        extern const SGL_API SGLKey KEY_N;
        extern const SGL_API SGLKey KEY_O;
        extern const SGL_API SGLKey KEY_P;
        extern const SGL_API SGLKey KEY_Q;
        extern const SGL_API SGLKey KEY_R;
        extern const SGL_API SGLKey KEY_S;
        extern const SGL_API SGLKey KEY_T;
        extern const SGL_API SGLKey KEY_U;
        extern const SGL_API SGLKey KEY_V;
        extern const SGL_API SGLKey KEY_W;
        extern const SGL_API SGLKey KEY_X;
        extern const SGL_API SGLKey KEY_Y;
        extern const SGL_API SGLKey KEY_Z;
    }

}  /* namespace SGL */

#endif  /* _SGL_INPUT_H_ */
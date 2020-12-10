/**
*
*
*
*/

#ifndef _SGL_INPUT_H_
#define _SGL_INPUT_H_

#include "SGLCore.h"
#include "Renderer.h"



namespace SGL {

    using SGLKey = std::int32_t;

    class Input
    {
    public:

        /**
         * Callback function for GLFW keys.
         * https://www.glfw.org/docs/3.1/group__input.html#ga0192a232a41e4e82948217c8ba94fdfd
         */
        friend auto GLFWKeyCallback(
            GLFWwindow*, int, int, int, int
        ) noexcept -> void;


        /**
         * Default constructor. 
         * 
         * Note: this doesn't actually initialize input handler. Call create() to do so.
         */
        SGL_API Input(
        ) noexcept;


        /**
         * Initialize and bind input handler to the desired window. 
         * 
         * @param window The desired window.
         * @exception Throws std::runtime_error if window was nullptr.
         */
        SGL_API Input(
            const GLFWwindow* window
        );


        /**
         * Destructor.
         */
        SGL_API ~Input(
        );


        /**
         * Initialize and bind input handler to the desired window. 
         *
         * @param window The desired window.
         * @exception Throws std::runtime_error if window was nullptr.
         */
        SGL_API auto create(
            const GLFWwindow* window
        ) -> void;


        /**
         * Nullify this instance. Destructor calls it automatically. 
         */
        SGL_API auto destroy(
        ) noexcept -> void;


        /**
         * Check whether the desired keyboard key is currently being pressed down.
         * 
         * @param key The desired keyboard key.
         * @return True if the key is currently being pressed down, false otherwise.
         */
        SGL_API auto getKey(
            const SGLKey key
        ) const noexcept -> bool;


        /**
         * Check whether the desired keyboard key was just pressed down.
         *
         * @param key The desired keyboard key.
         * @return True if the key was just pressed down, false otherwise.
         */
        SGL_API auto getKeyPressed(
            const SGLKey key
        ) const noexcept -> bool;


        /**
         * Check whether the desired keyboard key was just released.
         *
         * @param key The desired keyboard key.
         * @return True if the key was just released, false otherwise.
         */
        SGL_API auto getKeyReleased(
            const SGLKey key
        ) const noexcept -> bool;


    private:
        static constexpr std::size_t NUM_OF_KEYS = 512;
        static std::array<bool, NUM_OF_KEYS> m_KeyStateChanged;

        GLFWwindow* m_pGLFWwindow;
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
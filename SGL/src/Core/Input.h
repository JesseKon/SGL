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


        /// <summary>
        /// Default constructor. This does not initialize input handler, call create() to do so.
        /// </summary>
        /// 
        /// <returns></returns>
        SGL_API Input(
        ) noexcept;


        /// <summary>
        /// Initialize and bind input handler to the desired window. 
        /// </summary>
        /// 
        /// <param name="window">
        /// The desired window.
        /// </param>
        /// 
        /// <exception cref="SGL::runtime_error">
        /// Throws if window was nullptr.
        /// </exception>
        /// 
        /// <returns></returns>
        SGL_API Input(
            const GLFWwindow* window
        );


        /// <summary>
        /// Destructor.
        /// </summary>
        /// 
        /// <returns></returns>
        SGL_API ~Input(
        );


        /// <summary>
        /// Initialize and bind input handler to the desired window. 
        /// </summary>
        /// 
        /// <param name="window">
        /// The desired window.
        /// </param>
        /// 
        /// <exception cref="SGL::runtime_error">
        /// Throws if window was nullptr.
        /// </exception>
        /// 
        /// <returns></returns>
        SGL_API auto create(
            const GLFWwindow* window
        ) -> void;


        /// <summary>
        /// Nullify this instance. Destructor calls it automatically. 
        /// </summary>
        /// 
        /// <returns></returns>
        SGL_API auto destroy(
        ) noexcept -> void;


        /// <summary>
        /// Check whether the desired keyboard key is currently being pressed down.
        /// </summary>
        /// 
        /// <param name="key">
        /// The desired keyboard key.
        /// </param>
        /// 
        /// <returns>
        /// True if the key is currently being pressed down, false otherwise.
        /// </returns>
        SGL_API auto getKey(
            const SGLKey key
        ) const noexcept -> bool;



        /// <summary>
        /// Check whether the desired keyboard key was just pressed down.
        /// </summary>
        /// 
        /// <param name="key">
        /// The desired keyboard key.
        /// </param>
        /// 
        /// <returns>
        /// True if the key was just pressed down, false otherwise.
        /// </returns>
        SGL_API auto getKeyPressed(
            const SGLKey key
        ) const noexcept -> bool;


        /// <summary>
        /// Check whether the desired keyboard key was just released.
        /// </summary>
        /// 
        /// <param name="key">
        /// The desired keyboard key.
        /// </param>
        /// 
        /// <returns>
        /// True if the key was just released, false otherwise.
        /// </returns>
        SGL_API auto getKeyReleased(
            const SGLKey key
        ) const noexcept -> bool;


    private:
        static constexpr std::size_t NUM_OF_KEYS = 512;
        static std::array<bool, NUM_OF_KEYS> m_KeyStateChanged;
        GLFWwindow* m_pGLFWwindow;
    };


    /// <summary>
    /// Key codes.
    /// </summary>
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
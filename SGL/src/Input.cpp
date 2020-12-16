/**
* 
* 
* 
*/

#include "sglpch.h"
#include "Input.h"

namespace SGL {

    std::array<bool, Input::NUM_OF_KEYS> Input::m_KeyStateChanged = { false };

    /* ***************************************************************************************** */
    auto GLFWKeyCallback(
        GLFWwindow* window, int key, int scancode, int action, int mods
    ) noexcept -> void {
        if (action == GLFW_PRESS || action == GLFW_RELEASE)
            Input::m_KeyStateChanged[key] = true;
    }


    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors and destructor
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /* ***************************************************************************************** */
    Input::Input(
    ) noexcept {
        m_pGLFWwindow = nullptr;
    }


    /* ***************************************************************************************** */
    Input::Input(
        const GLFWwindow* window
    ) {
        m_pGLFWwindow = nullptr;
        create(window);
    }


    /* ***************************************************************************************** */
    Input::~Input(
    ) noexcept {
        destroy();
    }


    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Public methods
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /* ***************************************************************************************** */
    auto Input::create(
        const GLFWwindow* window
    ) -> void {
        if (!window) {
            std::stringstream ss;
            ss << ">>> Error > Input::create() > window was nullptr.\n";
            throw std::runtime_error(ss.str());
        }

        m_pGLFWwindow = const_cast<GLFWwindow*>(window);
        glfwSetKeyCallback(m_pGLFWwindow, GLFWKeyCallback);
    }


    /* ***************************************************************************************** */
    auto Input::destroy(
    ) noexcept -> void {
        m_pGLFWwindow = nullptr;
    }


    /* ***************************************************************************************** */
    auto Input::getKey(
        const SGLKey key
    ) const noexcept -> bool {
        return glfwGetKey(m_pGLFWwindow, static_cast<int>(key)) == GLFW_PRESS;
    }


    /* ***************************************************************************************** */
    auto Input::getKeyPressed(
        const SGLKey key
    ) const noexcept -> bool {
        if (glfwGetKey(m_pGLFWwindow, key) == GLFW_PRESS && m_KeyStateChanged[key]) {
            m_KeyStateChanged[key] = false;
            return true;
        }
        return false;
    }


    /* ***************************************************************************************** */
    auto Input::getKeyReleased(
        const SGLKey key
    ) const noexcept -> bool {
        if (glfwGetKey(m_pGLFWwindow, key) == GLFW_RELEASE && m_KeyStateChanged[key]) {
            m_KeyStateChanged[key] = false;
            return true;
        }
        return false;
    }


    /* ***************************************************************************************** */
    // Keycodes
    // TODO: more keycodes
    namespace KEYCODE {
        const SGLKey KEY_A = 65;
        const SGLKey KEY_B = 66;
        const SGLKey KEY_C = 67;
        const SGLKey KEY_D = 68;
        const SGLKey KEY_E = 69;
        const SGLKey KEY_F = 70;
        const SGLKey KEY_G = 71;
        const SGLKey KEY_H = 72;
        const SGLKey KEY_I = 73;
        const SGLKey KEY_J = 74;
        const SGLKey KEY_K = 75;
        const SGLKey KEY_L = 76;
        const SGLKey KEY_M = 77;
        const SGLKey KEY_N = 78;
        const SGLKey KEY_O = 79;
        const SGLKey KEY_P = 80;
        const SGLKey KEY_Q = 81;
        const SGLKey KEY_R = 82;
        const SGLKey KEY_S = 83;
        const SGLKey KEY_T = 84;
        const SGLKey KEY_U = 85;
        const SGLKey KEY_V = 86;
        const SGLKey KEY_W = 87;
        const SGLKey KEY_X = 88;
        const SGLKey KEY_Y = 89;
        const SGLKey KEY_Z = 90;
    }


}  /* namespace SGL */
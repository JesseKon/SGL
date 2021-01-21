/**
* 
* 
* 
*/

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
            throw runtimeError(ss.str());
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

}  /* namespace SGL */
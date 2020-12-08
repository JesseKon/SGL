/**
* 
* 
* 
*/

#include "sglpch.h"
#include "Input.h"

namespace SGL {

    /* ***************************************************************************************** */
    Input::Input(
    ) noexcept {
        m_pGLFWwindow = nullptr;
    }


    /* ***************************************************************************************** */
    Input::Input(
        GLFWwindow* const window
    ) {
        if (!window) {
            std::stringstream ss;
            ss << ">>> Error > Input::Input() > window was nullptr.\n";
            throw std::runtime_error(ss.str());
        }

        m_pGLFWwindow = window;
    }


    /* ***************************************************************************************** */
    Input::~Input()
    {
        m_pGLFWwindow = nullptr;
    }


    /* ***************************************************************************************** */
    auto Input::getKey(
        const std::int32_t keyCode
    ) noexcept -> bool {
        return glfwGetKey(m_pGLFWwindow, static_cast<int>(keyCode)) == GLFW_PRESS;
    }


    /* ***************************************************************************************** */
    auto Input::getKeyDown(
        const std::int32_t keyCode
    ) noexcept -> bool {
        return false;  // TODO: !
    }


    /* ***************************************************************************************** */
    auto Input::getKeyUp(
        const std::int32_t keyCode
    ) noexcept -> bool {
        return false;  // TODO: !
    }


}  /* namespace SGL */
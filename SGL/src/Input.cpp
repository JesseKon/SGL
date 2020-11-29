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
        const Window& window
    ) noexcept {
        m_GLFWwindow = window.getGLFWwindow();
    }


    /* ***************************************************************************************** */
    Input::~Input()
    {
        m_GLFWwindow = nullptr;
    }


    /* ***************************************************************************************** */
    auto Input::getKey(
        const std::int32_t keyCode
    ) noexcept -> bool {
        return glfwGetKey(m_GLFWwindow, static_cast<int>(keyCode)) == GLFW_PRESS;
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
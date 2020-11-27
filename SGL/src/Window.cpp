/**
*
*
*
*/

#include "sglpch.h"
#include "Window.h"

namespace SGL {

    /* ***************************************************************************************** */
    Window::Window(
        const std::uint32_t width,
        const std::uint32_t height,
        const std::string& title
    ) {
        m_Width = width;
        m_Height = height;
        m_Title = title;
        m_QuitRequested = false;
        m_GLFWwindow = nullptr;

        if (!glfwInit()) {
            std::stringstream ss;
            ss << ">>> Error > Window::Window() > Could not init GLFW.\n";
            throw std::runtime_error(ss.str());
        }

        m_GLFWwindow = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);
        if (!m_GLFWwindow) {
            glfwTerminate();
            std::stringstream ss;
            ss << ">>> Error > Window::Window() > Could not create window ";
            ss << "[width=" << std::to_string(m_Width) << " height=" << std::to_string(m_Height);
            ss << " title=\"" << m_Title << "\"].\n";
            throw std::runtime_error(ss.str());
        }

        glfwMakeContextCurrent(m_GLFWwindow);
    }


    /* ***************************************************************************************** */
    Window::~Window()
    {
        glfwTerminate();
        m_GLFWwindow = nullptr;
    }


    /* ***************************************************************************************** */
    auto Window::running(
    ) const noexcept -> bool {
        glfwPollEvents();
        if (glfwWindowShouldClose(m_GLFWwindow) || m_QuitRequested)
            return false;

        return true;
    }


    /* ***************************************************************************************** */
    auto Window::clear(
    ) const noexcept -> void {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }


    /* ***************************************************************************************** */
    auto Window::clear(
        const Color& color
    ) const noexcept -> void {
        glClearColor(
            color.getRedf<float>(), color.getGreenf<float>(),
            color.getBluef<float>(), color.getAlphaf<float>()
        );

        glClear(GL_COLOR_BUFFER_BIT);
    }


    /* ***************************************************************************************** */
    auto Window::clear(
        const Color&& color
    ) const noexcept -> void {
        glClearColor(
            color.getRedf<float>(), color.getGreenf<float>(),
            color.getBluef<float>(), color.getAlphaf<float>()
        );

        glClear(GL_COLOR_BUFFER_BIT);
    }


    /* ***************************************************************************************** */
    auto Window::draw(
    ) const noexcept -> void {
        glfwSwapBuffers(m_GLFWwindow);
    }


    /* ***************************************************************************************** */
    auto Window::close(
        const bool forceQuit
    ) const noexcept -> void {
        m_QuitRequested = true;

        if (forceQuit)
            running();  // Skip rest of the current loop
    }


    /* ***************************************************************************************** */
    auto Window::getGLFWwindow(
    ) const noexcept -> GLFWwindow* {
        return m_GLFWwindow;
    }


}  /* namespace SGL */
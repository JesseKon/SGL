

#include "sglpch.h"
#include "Window.h"

namespace SGL {

    //auto SGL_API TestiFunktio() -> void {

    //    throw std::runtime_error("Ei toimi!");
    //    
    //    GLFWwindow* window;
    //    if (!glfwInit()) return;

    //    window = glfwCreateWindow(640, 480, "Moi vain!", nullptr, nullptr);
    //    glfwMakeContextCurrent(window);

    //    while (!glfwWindowShouldClose(window)) {
    //        glClearColor(0.7f, 0.2f, 0.0f, 0.5f);
    //        glClear(GL_COLOR_BUFFER_BIT);
    //        glfwSwapBuffers(window);
    //        glfwPollEvents();
    //    }
    //        
    //    glfwTerminate();

    //}

    /* ***************************************************************************************** */
    Window::Window(
        const std::uint32_t width,
        const std::uint32_t height,
        const std::string& title
    ) {
        m_Width = width;
        m_Height = height;
        m_Title = title;
        m_GLFWwindow = nullptr;

        if (!glfwInit())
            throw std::runtime_error("Could not init GLFW");

        m_GLFWwindow = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);
        if (!m_GLFWwindow) {
            glfwTerminate();
            throw std::runtime_error("Could not create window");
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
        return !glfwWindowShouldClose(m_GLFWwindow);
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
        glClearColor(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
        glClear(GL_COLOR_BUFFER_BIT);
    }


    /* ***************************************************************************************** */
    auto Window::clear(
        const Color&& color
    ) const noexcept -> void {
        glClearColor(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
        glClear(GL_COLOR_BUFFER_BIT);
    }


    /* ***************************************************************************************** */
    auto Window::draw(
    ) const noexcept -> void {
        glfwSwapBuffers(m_GLFWwindow);
    }


}  /* namespace SGL */
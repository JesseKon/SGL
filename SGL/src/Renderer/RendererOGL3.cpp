

#include "sglpch.h"
#include "RendererOGL3.h"

namespace SGL {

    /* ***************************************************************************************** */
    RendererOGL3::RendererOGL3(
        const std::uint32_t width,
        const std::uint32_t height,
        const std::string& title
    ) {
        m_Width = width;
        m_Height = height;
        m_Title = title;
        m_QuitRequested = false;
        m_pGLFWwindow = nullptr;

        if (!glfwInit()) {
            std::stringstream ss;
            ss << ">>> Error > RendererOGL3::RendererOGL3() > Could not init GLFW.\n";
            throw std::runtime_error(ss.str());
        }

        m_pGLFWwindow = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);
        if (!m_pGLFWwindow) {
            glfwTerminate();
            std::stringstream ss;
            ss << ">>> Error > RendererOGL3::RendererOGL3() > Could not create window ";
            ss << "[width=" << std::to_string(m_Width) << " height=" << std::to_string(m_Height);
            ss << " title=\"" << m_Title << "\"].\n";
            throw std::runtime_error(ss.str());
        }

        glfwMakeContextCurrent(m_pGLFWwindow);
    }


    /* ***************************************************************************************** */
    RendererOGL3::~RendererOGL3()
    {
        glfwTerminate();
        m_pGLFWwindow = nullptr;
    }


    /* ***************************************************************************************** */
    auto RendererOGL3::running(
    ) const noexcept -> bool {
        glfwPollEvents();
        if (glfwWindowShouldClose(m_pGLFWwindow) || m_QuitRequested)
            return false;

        return true;
    }


    /* ***************************************************************************************** */
    auto RendererOGL3::clear(
        const Color& color
    ) const noexcept -> void {
        glClearColor(
            color.getRedf<float>(), color.getGreenf<float>(),
            color.getBluef<float>(), color.getAlphaf<float>()
        );
        glClear(GL_COLOR_BUFFER_BIT);
    }


    /* ***************************************************************************************** */
    auto RendererOGL3::draw(
    ) const noexcept -> void {
        glfwSwapBuffers(m_pGLFWwindow);
    };


    /* ***************************************************************************************** */
    auto RendererOGL3::close(
        const bool forceQuit
    ) const noexcept -> void {
        m_QuitRequested = true;

        if (forceQuit)
            running();  // Skip rest of the current loop
    };


    /* ***************************************************************************************** */
    auto RendererOGL3::getGLFWwindow(
    ) const -> GLFWwindow* {
        if (!m_pGLFWwindow) {
            std::stringstream ss;
            ss << ">>> Error > RendererOGL3::getGLFWwindow() > m_pGLFWwindow was nullptr.\n";
            throw std::runtime_error(ss.str());
        }

        return m_pGLFWwindow;
    };



}  /* namespace SGL */
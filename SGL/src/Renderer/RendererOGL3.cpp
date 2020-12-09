/**
*
*
*
*/

#include "sglpch.h"
#include "RendererOGL3.h"

namespace SGL {

    /* ***************************************************************************************** */
    RendererOGL3::RendererOGL3(
    ) noexcept {
        m_Width = m_Height = 0;
        m_Title = "";
        m_QuitRequested = false;
        m_pGLFWwindow = nullptr;
    }


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

        create(m_Width, m_Height, m_Title);
    }


    /* ***************************************************************************************** */
    RendererOGL3::~RendererOGL3()
    {
        destroy();
    }


    /* ***************************************************************************************** */
    auto RendererOGL3::create(
        const std::uint32_t width,
        const std::uint32_t height,
        const std::string& title
    ) -> void {
        if (!glfwInit()) {
            std::stringstream ss;
            ss << ">>> Error > RendererOGL3::RendererOGL3() > Could not init GLFW.\n";
            throw std::runtime_error(ss.str());
        }

        // OpenGL 3.3 Core
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_pGLFWwindow = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);
        if (!m_pGLFWwindow) {
            std::stringstream ss;
            ss << ">>> Error > RendererOGL3::RendererOGL3() > Could not create window ";
            ss << "[width=" << std::to_string(m_Width) << " height=" << std::to_string(m_Height);
            ss << " title=\"" << m_Title << "\"].\n";
            throw std::runtime_error(ss.str());
        }

        glfwMakeContextCurrent(m_pGLFWwindow);

        // Init GLAD
        if (!gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress))) {
            std::stringstream ss;
            ss << ">>> Error > RendererOGL3::RendererOGL3() > Could not init GLAD.";
            throw std::runtime_error(ss.str());
        }

        glViewport(0, 0, m_Width, m_Height);
    }


    /* ***************************************************************************************** */
    auto RendererOGL3::destroy(
    ) noexcept -> void {
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
    auto RendererOGL3::setWidth(
        const std::uint32_t newWidth
    ) noexcept -> void {
        m_Width = newWidth;
    }


    /* ***************************************************************************************** */
    auto RendererOGL3::getWidth(
    ) const noexcept -> std::uint32_t {
        return m_Width;
    }


    /* ***************************************************************************************** */
    auto RendererOGL3::setHeight(
        const std::uint32_t newHeight
    ) noexcept -> void {
        m_Height = newHeight;
    }


    /* ***************************************************************************************** */
    auto RendererOGL3::getHeight(
    ) const noexcept -> std::uint32_t {
        return m_Height;
    }


    /* ***************************************************************************************** */
    auto RendererOGL3::setTitle(
        const std::string& newTitle
    ) noexcept -> void {
        m_Title = newTitle;
        glfwSetWindowTitle(m_pGLFWwindow, m_Title.c_str());
    }


    /* ***************************************************************************************** */
    auto RendererOGL3::getTitle(
    ) const noexcept -> const char* {
        return m_Title.c_str();
    }


    /* ***************************************************************************************** */
    auto RendererOGL3::getGLFWwindow(
    ) const noexcept -> GLFWwindow* {
        //if (!m_pGLFWwindow) {
        //    std::stringstream ss;
        //    ss << ">>> Error > RendererOGL3::getGLFWwindow() > m_pGLFWwindow was nullptr.\n";
        //    throw std::runtime_error(ss.str());
        //}

        return m_pGLFWwindow;
    };


}  /* namespace SGL */
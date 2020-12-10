/**
*
*
*
*/

#include "sglpch.h"
#include "RendererOGL3.h"

namespace SGL {

    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors and destructor
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /* ***************************************************************************************** */
    RendererOGL3::RendererOGL3(
    ) noexcept {
        m_WindowSize = { 0, 0 };
        m_WindowTitle = "";
        m_QuitRequested = false;
        m_pGLFWwindow = nullptr;
    }


    /* ***************************************************************************************** */
    RendererOGL3::RendererOGL3(
        const Vector2<std::uint32_t>& windowSize,
        const std::string& windowTitle
    ) {
        m_WindowSize = windowSize;
        m_WindowTitle = windowTitle;
        m_QuitRequested = false;
        m_pGLFWwindow = nullptr;

        create(m_WindowSize, m_WindowTitle);
    }


    /* ***************************************************************************************** */
    RendererOGL3::~RendererOGL3()
    {
        destroy();
    }


    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Public methods
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /* ***************************************************************************************** */
    auto RendererOGL3::create(
        const Vector2<std::uint32_t>& windowSize,
        const std::string& windowTitle
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

        m_pGLFWwindow = glfwCreateWindow(
            static_cast<int>(m_WindowSize.x), static_cast<int>(m_WindowSize.y),
            m_WindowTitle.c_str(), nullptr, nullptr);

        if (!m_pGLFWwindow) {
            std::stringstream ss;
            ss << ">>> Error > RendererOGL3::RendererOGL3() > Could not create window ";
            ss << "[width=" << std::to_string(m_WindowSize.x) << " height=" << std::to_string(m_WindowSize.y);
            ss << " title=\"" << m_WindowTitle << "\"].\n";
            throw std::runtime_error(ss.str());
        }

        glfwMakeContextCurrent(m_pGLFWwindow);

        // Init GLAD
        if (!gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress))) {
            std::stringstream ss;
            ss << ">>> Error > RendererOGL3::RendererOGL3() > Could not init GLAD.";
            throw std::runtime_error(ss.str());
        }

        glViewport(0, 0, static_cast<int>(m_WindowSize.x), static_cast<int>(m_WindowSize.y));
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
    ) const noexcept -> void {
        m_QuitRequested = true;
    };


    /* ***************************************************************************************** */
    auto RendererOGL3::resizeWindow(
        const Vector2<std::uint32_t>& newSize
    ) noexcept -> void {
        m_WindowSize = newSize;
        glfwSetWindowSize(m_pGLFWwindow,
            static_cast<int>(m_WindowSize.x), static_cast<int>(m_WindowSize.y));

        glViewport(0, 0, static_cast<int>(m_WindowSize.x), static_cast<int>(m_WindowSize.y));
    }


    /* ***************************************************************************************** */
    auto RendererOGL3::getWindowSize(
    ) const noexcept -> Vector2<std::uint32_t> {
        return m_WindowSize;
    }


    /* ***************************************************************************************** */
    auto RendererOGL3::setWindowPosition(
        const Vector2<std::int32_t>& newPosition
    ) noexcept -> void {
        glfwSetWindowPos(m_pGLFWwindow,
            static_cast<int>(newPosition.x), static_cast<int>(newPosition.y));
    }


    /* ***************************************************************************************** */
    auto RendererOGL3::getWindowPosition(
    ) const noexcept -> Vector2<std::int32_t> {
        int posX, posY; glfwGetWindowPos(m_pGLFWwindow, &posX, &posY);
        return { static_cast<std::int32_t>(posX), static_cast<int32_t>(posY) };
    }


    /* ***************************************************************************************** */
    auto RendererOGL3::setTitle(
        const std::string& newTitle
    ) noexcept -> void {
        m_WindowTitle = newTitle;
        glfwSetWindowTitle(m_pGLFWwindow, m_WindowTitle.c_str());
    }


    /* ***************************************************************************************** */
    auto RendererOGL3::getTitle(
    ) const noexcept -> const char* {
        return m_WindowTitle.c_str();
    }


    /* ***************************************************************************************** */
    auto RendererOGL3::getGLFWwindow(
    ) const noexcept -> GLFWwindow* {
        return m_pGLFWwindow;
    };


}  /* namespace SGL */
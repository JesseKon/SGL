/**
*
*
*
*/

#include "Renderer.h"

namespace SGL {

    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors and destructor
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /* ***************************************************************************************** */
    Renderer::Renderer(
    ) noexcept {
        m_WindowSize = { 0, 0 };
        m_WindowTitle = "";
        m_QuitRequested = false;
        m_pGLFWwindow = nullptr;
    }


    /* ***************************************************************************************** */
    Renderer::Renderer(
        const Vector2<std::uint32_t>& windowSize,
        const std::string& windowTitle,
        const RendererType rendererType
    ) {
        m_WindowSize = windowSize;
        m_WindowTitle = windowTitle;
        m_QuitRequested = false;
        m_pGLFWwindow = nullptr;

        create(m_WindowSize, m_WindowTitle, rendererType);
    }


    /* ***************************************************************************************** */
    Renderer::~Renderer()
    {
        destroy();
    }


    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Public methods
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /* ***************************************************************************************** */
    auto Renderer::create(
        const Vector2<std::uint32_t>& windowSize,
        const std::string& windowTitle,
        const RendererType rendererType
    ) -> void {
        if (!glfwInit()) {
            std::stringstream ss;
            ss << ">>> Error > RendererOGL3::Renderer() > Could not init GLFW.\n";
            throw runtimeError(ss.str());
        }

        // OpenGL 3.3 Core
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        switch (rendererType) {
        case RendererType::Windowed:
            m_pGLFWwindow = glfwCreateWindow(
                static_cast<int>(m_WindowSize.x),
                static_cast<int>(m_WindowSize.y),
                m_WindowTitle.c_str(),
                nullptr,
                nullptr
            ); break;

        case RendererType::WindowedFullscreen:
            glfwWindowHint(GLFW_RED_BITS, mode->redBits);
            glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
            glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
            glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
            m_pGLFWwindow = glfwCreateWindow(
                mode->width,
                mode->height,
                m_WindowTitle.c_str(),
                glfwGetPrimaryMonitor(),
                nullptr
            ); break;

        case RendererType::Fullscreen:
            m_pGLFWwindow = glfwCreateWindow(
                static_cast<int>(m_WindowSize.x),
                static_cast<int>(m_WindowSize.y),
                m_WindowTitle.c_str(),
                glfwGetPrimaryMonitor(),
                nullptr
            ); break;
        }



        if (!m_pGLFWwindow) {
            std::stringstream ss;
            ss << ">>> Error > RendererOGL3::RendererOGL3() > Could not create window ";
            ss << "[width=" << std::to_string(m_WindowSize.x) << " height=" << std::to_string(m_WindowSize.y);
            ss << " title=\"" << m_WindowTitle << "\"].\n";
            throw runtimeError(ss.str());
        }

        glfwMakeContextCurrent(m_pGLFWwindow);

        // Init GLAD
        if (!gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress))) {
            std::stringstream ss;
            ss << ">>> Error > RendererOGL3::RendererOGL3() > Could not init GLAD.";
            throw runtimeError(ss.str());
        }

        glViewport(0, 0, static_cast<int>(m_WindowSize.x), static_cast<int>(m_WindowSize.y));
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_STENCIL_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }


    /* ***************************************************************************************** */
    auto Renderer::destroy(
    ) noexcept -> void {
        glfwTerminate();
        m_pGLFWwindow = nullptr;
    }


    /* ***************************************************************************************** */
    auto Renderer::running(
    ) const noexcept -> bool {
        glfwPollEvents();
        if (glfwWindowShouldClose(m_pGLFWwindow) || m_QuitRequested)
            return false;

        return true;
    }


    /* ***************************************************************************************** */
    auto Renderer::beginDrawing(
        const bool clearColorBuffer,
        const bool clearDepthBuffer,
        const bool clearStencilBuffer,
        const Color& color
    ) const noexcept -> void {
        glClearColor(
            color.getRedf<float>(), color.getGreenf<float>(),
            color.getBluef<float>(), color.getAlphaf<float>()
        );
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }


    /* ***************************************************************************************** */
    auto Renderer::endDrawing(
    ) const noexcept -> void {
        glfwSwapBuffers(m_pGLFWwindow);
    };


    /* ***************************************************************************************** */
    auto Renderer::close(
    ) const noexcept -> void {
        m_QuitRequested = true;
    };


    /* ***************************************************************************************** */
    auto Renderer::resizeWindow(
        const Vector2<std::uint32_t>& newSize
    ) noexcept -> void {
        m_WindowSize = newSize;
        glfwSetWindowSize(m_pGLFWwindow,
            static_cast<int>(m_WindowSize.x), static_cast<int>(m_WindowSize.y));

        glViewport(0, 0, static_cast<int>(m_WindowSize.x), static_cast<int>(m_WindowSize.y));
    }


    /* ***************************************************************************************** */
    auto Renderer::getWindowSize(
    ) const noexcept -> Vector2<std::uint32_t> {
        return m_WindowSize;
    }


    /* ***************************************************************************************** */
    auto Renderer::setWindowPosition(
        const Vector2<std::int32_t>& newPosition
    ) noexcept -> void {
        glfwSetWindowPos(m_pGLFWwindow,
            static_cast<int>(newPosition.x), static_cast<int>(newPosition.y));
    }


    /* ***************************************************************************************** */
    auto Renderer::getWindowPosition(
    ) const noexcept -> Vector2<std::int32_t> {
        int posX, posY; glfwGetWindowPos(m_pGLFWwindow, &posX, &posY);
        return { static_cast<std::int32_t>(posX), static_cast<int32_t>(posY) };
    }


    /* ***************************************************************************************** */
    auto Renderer::setTitle(
        const std::string& newTitle
    ) noexcept -> void {
        m_WindowTitle = newTitle;
        glfwSetWindowTitle(m_pGLFWwindow, m_WindowTitle.c_str());
    }


    /* ***************************************************************************************** */
    auto Renderer::getTitle(
    ) const noexcept -> const char* {
        return m_WindowTitle.c_str();
    }


    /* ***************************************************************************************** */
    auto Renderer::getGLFWwindow(
    ) const noexcept -> GLFWwindow* {
        return m_pGLFWwindow;
    };


}  /* namespace SGL */
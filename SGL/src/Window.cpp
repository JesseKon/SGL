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
        const RendererType rendererType,
        const std::uint32_t width,
        const std::uint32_t height,
        const std::string& title
    ) {
        m_pRenderer = nullptr;
        if (rendererType == RendererType::OpenGL3) {
            m_pRenderer = new RendererOGL3(width, height, title);
        }
        else {
            std::stringstream ss;
            ss << ">>> Error > Window::Window() > No renderer type selected.\n";
            throw std::runtime_error(ss.str());
        }
            
    }


    /* ***************************************************************************************** */
    Window::~Window()
    {
        if (m_pRenderer) {
            delete m_pRenderer;
            m_pRenderer = nullptr;
        }
    }


    /* ***************************************************************************************** */
    auto Window::running(
    ) const noexcept -> bool {
        return m_pRenderer->running();
    }


    /* ***************************************************************************************** */
    auto Window::clear(
    ) const noexcept -> void {
        m_pRenderer->clear(SGL::COLOR::Black);
    }


    /* ***************************************************************************************** */
    auto Window::clear(
        const Color& color
    ) const noexcept -> void {
        m_pRenderer->clear(color);
    }


    /* ***************************************************************************************** */
    auto Window::clear(
        const Color&& color
    ) const noexcept -> void {
        m_pRenderer->clear(color);
    }


    /* ***************************************************************************************** */
    auto Window::draw(
    ) const noexcept -> void {
        m_pRenderer->draw();
    }


    /* ***************************************************************************************** */
    auto Window::close(
        const bool forceQuit
    ) const noexcept -> void {
        m_pRenderer->close(forceQuit);
    }


    /* ***************************************************************************************** */
    auto Window::getGLFWwindow(
    ) const -> GLFWwindow* {
        if (!m_pRenderer) {
            std::stringstream ss;
            ss << ">>> Error > Window::getGLFWwindow() > GLFWwindow was nullptr.\n";
            throw std::runtime_error(ss.str());
        }

        return m_pRenderer->getGLFWwindow();
    }


}  /* namespace SGL */
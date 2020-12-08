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
    ) noexcept {
        m_pRenderer = nullptr;
        m_pInput = nullptr;
    }


    /* ***************************************************************************************** */
    Window::Window(
        const RendererType rendererType,
        const std::uint32_t width,
        const std::uint32_t height,
        const std::string& title
    ) {
        m_pRenderer = nullptr;
        create(rendererType, width, height, title);

        m_pInput = new Input(getGLFWwindow());
    }


    /* ***************************************************************************************** */
    Window::~Window()
    {
        destroy();
    }


    /* ***************************************************************************************** */
    auto Window::create(
        const RendererType rendererType,
        const std::uint32_t width,
        const std::uint32_t height,
        const std::string& title
    ) -> void {
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
    auto Window::destroy(
    ) noexcept -> void {
        if (m_pRenderer) {
            delete m_pRenderer;
            m_pRenderer = nullptr;
        }
        if (m_pInput) {
            delete m_pInput;
            m_pInput = nullptr;
        }
    }


    /* ***************************************************************************************** */
    auto Window::running(
    ) const noexcept -> bool {
        assert(m_pRenderer && "Window::running() > m_pRenderer is nullptr.");
        return m_pRenderer->running();
    }


    /* ***************************************************************************************** */
    auto Window::clear(
    ) const noexcept -> void {
        assert(m_pRenderer && "Window::clear() > m_pRenderer is nullptr.");
        m_pRenderer->clear(SGL::COLOR::Black);
    }


    /* ***************************************************************************************** */
    auto Window::clear(
        const Color& color
    ) const noexcept -> void {
        assert(m_pRenderer && "Window::clear() > m_pRenderer is nullptr.");
        m_pRenderer->clear(color);
    }


    /* ***************************************************************************************** */
    auto Window::clear(
        const Color&& color
    ) const noexcept -> void {
        assert(m_pRenderer && "Window::clear() > m_pRenderer is nullptr.");
        m_pRenderer->clear(color);
    }


    /* ***************************************************************************************** */
    auto Window::draw(
    ) const noexcept -> void {
        assert(m_pRenderer && "Window::draw() > m_pRenderer is nullptr.");
        m_pRenderer->draw();
    }


    /* ***************************************************************************************** */
    auto Window::close(
        const bool forceQuit
    ) const noexcept -> void {
        assert(m_pRenderer && "Window::close() > m_pRenderer is nullptr.");
        m_pRenderer->close(forceQuit);
    }


    /* ***************************************************************************************** */
    auto Window::setWidth(
        const std::uint32_t newWidth
    ) noexcept -> void {
        assert(m_pRenderer && "Window::setWidth() > m_pRenderer is nullptr.");
        m_pRenderer->setWidth(newWidth);
    }


    /* ***************************************************************************************** */
    auto Window::getWidth(
    ) const noexcept -> std::uint32_t {
        assert(m_pRenderer && "Window::getWidth() > m_pRenderer is nullptr.");
        return m_pRenderer->getWidth();
    }


    /* ***************************************************************************************** */
    auto Window::setHeight(
        const std::uint32_t newHeight
    ) noexcept -> void {
        assert(m_pRenderer && "Window::setHeight() > m_pRenderer is nullptr.");
        m_pRenderer->setHeight(newHeight);
    }


    /* ***************************************************************************************** */
    auto Window::getHeight(
    ) const noexcept -> std::uint32_t {
        assert(m_pRenderer && "Window::getHeight() > m_pRenderer is nullptr.");
        return m_pRenderer->getHeight();
    }


    /* ***************************************************************************************** */
    auto Window::setTitle(
        const std::string& newTitle
    ) noexcept -> void {
        assert(m_pRenderer && "Window::setTitle() > m_pRenderer is nullptr.");
        m_pRenderer->setTitle(newTitle);
    }


    /* ***************************************************************************************** */
    auto Window::getTitle(
    ) const noexcept -> const char* {
        assert(m_pRenderer && "Window::getTitle() > m_pRenderer is nullptr.");
        return m_pRenderer->getTitle();
    }


    /* ***************************************************************************************** */
    auto Window::getInput(
    ) const noexcept -> Input* const {
        return m_pInput;
    }


    /* ***************************************************************************************** */
    auto Window::getGLFWwindow(
    ) const noexcept -> GLFWwindow* {
        assert(m_pRenderer && "Window::getGLFWwindow() > m_pRenderer is nullptr.");
        return dynamic_cast<RendererOGL3*>(m_pRenderer)->getGLFWwindow();
    }


}  /* namespace SGL */
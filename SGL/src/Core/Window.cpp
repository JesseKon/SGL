/**
 *
 *
 *
 */

#include "Window.h"

namespace SGL {

    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors and destructor
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /* ***************************************************************************************** */
    Window::Window(
    ) noexcept {
        m_pRenderer = nullptr;
        m_pInput = nullptr;
    }


    /* ***************************************************************************************** */
    Window::Window(
        const Vector2<std::uint32_t>& windowSize,
        const std::string& title,
        const RendererType rendererType
    ) {
        m_pRenderer = nullptr;
        m_pInput = nullptr;
        create(windowSize, title, rendererType);
    }


    /* ***************************************************************************************** */
    Window::~Window(
    ) noexcept {
        destroy();
    }


    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Public methods
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /* ***************************************************************************************** */
    auto Window::create(
        const Vector2<std::uint32_t>& windowSize,
        const std::string& title,
        const RendererType rendererType
    ) -> void {
        m_pRenderer = new Renderer(windowSize, title, rendererType);
        m_pInput = new Input(m_pRenderer->getGLFWwindow());
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
    auto Window::getRenderer(
    ) const noexcept -> Renderer* {
        assert(m_pRenderer && "Window::getRenderer() > m_pRenderer is nullptr.");
        return m_pRenderer;
    }


    /* ***************************************************************************************** */
    auto Window::getInput(
    ) const noexcept -> Input* {
        assert(m_pInput && "Window::getInput() > m_pInput is nullptr.");
        return m_pInput;
    }

}  /* namespace SGL */
/**
 * This is a test project suitable for testing SGL functionality.
 *
 *
 */

#include "SGL.h"

auto main(int argc, char** argv) -> int try {
    SGL::Window window(SGL::RendererType::OpenGL3, 640, 480, "Hei maailma!");

    while (window.running()) {
        window.clear(SGL::COLOR::Gray);
        window.draw();

        if (window.getInput()->getKey(GLFW_KEY_M))
            window.setTitle("Uusi otsikko!");
    }

    return EXIT_SUCCESS;
}

catch (const std::runtime_error& e) {
    std::cerr << e.what();
    return EXIT_FAILURE;
}

catch (...) {
    std::cerr << "Unknown error!";
    return EXIT_FAILURE;
}
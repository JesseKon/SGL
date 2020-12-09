/**
 * This is a test project suitable for testing SGL functionality.
 *
 *
 */

#include "SGL.h"

auto main(int argc, char** argv) -> int try {
    SGL::Window window(SGL::RendererType::OpenGL3, { 640, 480 }, "Otsikko!");

    while (window.getRenderer()->running()) {
        window.getRenderer()->clear(SGL::COLOR::Red);
        window.getRenderer()->draw();

        if (window.getInput()->getKeyPressed(SGL::KEYCODE::KEY_A))
            std::cout << "Hei!";

        if (window.getInput()->getKeyReleased(SGL::KEYCODE::KEY_A))
            std::cout << "Moi!";
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
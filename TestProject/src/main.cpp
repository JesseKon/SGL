/**
 * This is a test project suitable for testing SGL functionality.
 *
 *
 */

#include <SGL.h>

auto main(int argc, char** argv) -> int try {

    SGL::Window window(SGL::Vector2<std::uint32_t>(640, 480), "Otsikko");

    while (window.getRenderer()->running()) {
        window.getRenderer()->beginDrawing(true, true, true);

        window.getRenderer()->endDrawing();
    }

}

// Check for errors
catch (const SGL::runtimeError& e) {
    std::cerr << e.what();
    return EXIT_FAILURE;
}

catch (...) {
    std::cerr << "Unknown error!";
    return EXIT_FAILURE;
}
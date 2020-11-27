#include "SGL.h"

auto main(int argc, char** argv) -> int try {

    SGL::Window window(640, 480, "Moi vain!");

    while (window.running()) {
        window.clear(SGL::COLOR::Lime);
        window.draw();
    }



    return EXIT_SUCCESS;
}
catch (const std::runtime_error& e) {
    std::cerr << e.what();
    return EXIT_FAILURE;
}
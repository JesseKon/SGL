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
        
        //SGL::Transform transform({ 0, 0, 0 });
        //SGL::Shader shader("simpleVertex.glsl", "simpleFragment.glsl");

        //SGL::Drawable triangle;
        //triangle.setVertices(
        //    { -0.5, 0.5, 0.5 },
        //    { 0.5, 0.5, -0.5 },
        //    { -0.5, 0.5, 0.5 }
        //);


        //window.getRenderer()->draw(triangle, shader, transform);
        //window.getRenderer()->drawAll();

        if (window.getInput()->getKeyPressed(SGL::KEYCODE::KEY_A))
            window.getRenderer()->setWindowPosition(
                window.getRenderer()->getWindowPosition() + SGL::Vector2<std::int32_t>::right()
            );

        window.getRenderer()->draw();
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
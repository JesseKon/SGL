/**
 * This is a test project suitable for testing SGL functionality.
 *
 *
 */

#include "SGL.h"

auto main(int argc, char** argv) -> int try {

    SGL::Window window(SGL::RendererType::OpenGL3, { 640, 480 }, "Otsikko!");

    // TODO: SGL::Matrix4 matrix;
    SGL::ShaderGLSL shader("../assets/shaders/simpleVertexShader.glsl", "../assets/shaders/simpleFragmentShader.glsl");

    SGL::Drawable triangle;
    triangle.setDrawMethod(SGL::DrawMethod::Dynamic);
    triangle.setDrawMode(SGL::DrawMode::Triangles);
    
    triangle.setData({
         0.5f,  0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
    });

    triangle.setIndices({ 0, 1, 3, 1, 2, 3 });


    while (window.getRenderer()->running()) {
        window.getRenderer()->beginRender(SGL::COLOR::Black);
        window.getRenderer()->draw(triangle, shader);
        window.getRenderer()->endRender();
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
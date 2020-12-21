/**
 * This is a test project suitable for testing SGL functionality.
 *
 *
 */

#include "SGL.h"

auto main(int argc, char** argv) -> int try {

    SGL::Window window(SGL::RendererType::OpenGL3, { 640, 480 }, "Otsikko!");

    SGL::ShaderGLSL shader("../assets/shaders/ColoredShader.vert", "../assets/shaders/ColoredShader.frag");
    SGL::Texture texture;
    texture.load("../assets/textures/test256x256.png");

    SGL::Drawable triangle;
    triangle.setDrawMethod(SGL::DrawMethod::Dynamic);
    triangle.setDrawMode(SGL::DrawMode::Triangles);
    
    triangle.setData({
         0.5f,  0.5f, 0.0f, 1.0f, 1.0f,   // top right
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,   // bottom left
        -0.5f,  0.5f, 0.0f, 0.0f, 1.0f    // top left 
    });

    triangle.setIndices({ 0, 1, 3, 1, 2, 3 });
    triangle.setVertexAttributes({ {0, 3}, { 1 ,2 } });
    triangle.configure();

    shader.setVector4("uFragColor", SGL::COLOR::Navy.toVector4());

    SGL::Transform transform, camera;
    transform.translate({ 200.0f, 200.0f, 0.0f });
    transform.scale({ 100, 100, 1.0f });
    camera.createOrthoProjection({ 640, 480 }, -0.1f, 100.0f);

    while (window.getRenderer()->running()) {
        window.getRenderer()->beginRendering(SGL::COLOR::Black);
        transform.translate({ 1.0f, 0.0f, 0.0f });
        transform.rotate({ 0.0f, 0.0f, 0.5f });
        transform.translate({ -1.0f, 0.0f, 0.0f });

        shader.setMatrix4("uTransform", camera.toMatrix4() * transform.toMatrix4());

        texture.use();
        shader.use();
        triangle.draw();
        window.getRenderer()->endRendering();
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
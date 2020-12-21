/**
 * This is a test project suitable for testing SGL functionality.
 *
 *
 */

#include "SGL.h"

auto main(int argc, char** argv) -> int try {

    SGL::Window window(SGL::RendererType::OpenGL3, { 640, 480 }, "Otsikko!");

    SGL::Transform transform, camera;
    SGL::ShaderGLSL shader("../assets/shaders/ColoredShader.vert", "../assets/shaders/ColoredShader.frag");

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
    triangle.setVertexAttributes({ {0, 3} });
    triangle.configure();

    glm::mat4 matrix(1.0f);

    shader.setVector4("uFragColor", SGL::COLOR::Navy.toVector4());
    transform.translate({ 200.0f, 200.0f, 0.0f });
    transform.scale({ 100, 100, 1.0f });

    camera.createOrthoProjection({ 640, 480 }, -0.1f, 100.0f);

    while (window.getRenderer()->running()) {
        window.getRenderer()->beginRendering(SGL::COLOR::Black);
        transform.translate({ 1.0f, 0.0f, 0.0f });
        transform.rotate({ 0.0f, 0.0f, 0.5f });
        transform.translate({ -1.0f, 0.0f, 0.0f });

        shader.setMatrix4("uTransform", camera.toMatrix4() * transform.toMatrix4());

        window.getRenderer()->draw(triangle, shader);
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
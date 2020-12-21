/**
 * This is a test project suitable for testing SGL functionality.
 *
 *
 */

#include "SGL.h"

auto main(int argc, char** argv) -> int try {

    SGL::Window window(SGL::RendererType::OpenGL3, { 640, 480 }, "Otsikko!");

    SGL::ShaderGLSL shader("../assets/shaders/ColoredShader.vert", "../assets/shaders/ColoredShader.frag");
    SGL::Texture texture0, texture1;
    texture0.load("../assets/textures/test256x256_0.png");
    texture1.load("../assets/textures/test256x256_1.png");

    SGL::Drawable triangle;
    triangle.setData({
        //  vertex              tex coords
            0.5f,  0.5f, 0.0f,  1.0f, 1.0f,   // top right
            0.5f, -0.5f, 0.0f,  1.0f, 0.0f,   // bottom right
           -0.5f, -0.5f, 0.0f,  0.0f, 0.0f,   // bottom left
           -0.5f,  0.5f, 0.0f,  0.0f, 1.0f    // top left 
    });

    triangle.setVertexAttributes({
        //  vertex      tex coords
            {0, 3},     { 1, 2 } 
    });

    triangle.setIndices({ 0, 1, 3, 1, 2, 3 });

    triangle.setDrawMethod(SGL::DrawMethod::Static);
    triangle.setDrawMode(SGL::DrawMode::Triangles);
    triangle.configure();

    shader.setVector4("uFragColor", SGL::COLOR::Navy.toVector4());

    SGL::Transform transform, camera;
    transform.translate({ 200.0f, 200.0f, 0.0f });
    transform.scale({ 300, 300, 1.0f });
    camera.createOrthoProjection({ 640, 480 }, -0.1f, 100.0f);

    shader.setInt("uTexture0", 0);
    shader.setInt("uTexture1", 1);

    while (window.getRenderer()->running()) {
        window.getRenderer()->beginRendering(SGL::COLOR::Yellow);

        transform.rotate({ 0.0f, 0.0f, 0.5f });
        
        shader.setMatrix4("uTransform", camera.toMatrix4() * transform.toMatrix4());

        shader.use();
        texture0.use(0);
        texture1.use(1);
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
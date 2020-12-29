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
    texture0.setTextureUnit(SGL::TextureUnit::Texture0);
    shader.setTextureUnit("uTexture0", texture0.getTextureUnit());

    texture1.load("../assets/textures/test256x256_1.png");
    texture1.setTextureUnit(SGL::TextureUnit::Texture1);
    shader.setTextureUnit("uTexture1", texture1.getTextureUnit());

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

    SGL::Matrix4 transform, camera;
    transform.translate({ 200.0f, 200.0f, 0.0f });
    transform.scale({ 300, 300, 1.0f });
    camera.createOrthoProjection({ 640, 480 }, -0.1f, 100.0f);

    while (window.getRenderer()->running()) {
        window.getRenderer()->beginRendering(SGL::COLOR::Yellow);

        transform.rotate({ 0.0f, 0.0f, 0.5f });
        
        shader.setMatrix4("uTransform", (camera * transform).toMat4());

        shader.use();
        texture0.use();
        texture1.use();
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
/**
 * This is a test project suitable for testing SGL functionality.
 *
 *
 */

#include "SGL.h"

auto main(int argc, char** argv) -> int try {

    SGL::Window window(SGL::RendererType::OpenGL3, { 640, 480 }, u8"Otsikkö!");

    SGL::ShaderGLSL shaderSingleTexture("../assets/shaders/SingleTexture.vert", "../assets/shaders/SingleTexture.frag");
    SGL::ShaderGLSL shaderMultiTexture("../assets/shaders/MultiTexture.vert", "../assets/shaders/MultiTexture.frag");
    
    SGL::Texture texture0, texture1;
    
    // Textures loaded from disk
    texture0.load("../assets/textures/test256x256_0.png");
    texture0.setTextureUnit(SGL::TextureUnit::Texture0);
    shaderMultiTexture.setTextureUnit("uTexture0", texture0.getTextureUnit());

    texture1.load("../assets/textures/test256x256_1.png");
    texture1.setTextureUnit(SGL::TextureUnit::Texture1);
    shaderMultiTexture.setTextureUnit("uTexture1", texture1.getTextureUnit());

    // Drawable texture
    SGL::Texture texture3;
    texture3.create(SGL::Vector2<std::uint32_t>(640, 480));
    texture3.setTextureUnit(SGL::TextureUnit::Texture0);
    shaderSingleTexture.setTextureUnit("uTexture", texture3.getTextureUnit());

    SGL::Drawable quad1, quad2;

    // Quad1
    quad1.setData({
        //  vertex              tex coords
            0.5f,  0.5f, 0.0f,  1.0f, 1.0f,   // top right
            0.5f, -0.5f, 0.0f,  1.0f, 0.0f,   // bottom right
           -0.5f, -0.5f, 0.0f,  0.0f, 0.0f,   // bottom left
           -0.5f,  0.5f, 0.0f,  0.0f, 1.0f    // top left 
    });

    quad1.setVertexAttributes({
        //  vertex      tex coords
            {0, 3},     { 1, 2 } 
    });

    quad1.setIndices({ 0, 1, 3, 1, 2, 3 });
    quad1.setDrawMethod(SGL::DrawMethod::Static);
    quad1.setDrawMode(SGL::DrawMode::Triangles);
    quad1.configure();

    // Quad2
    quad2.setData({
        //  vertex              tex coords
            0.5f,  0.5f, 0.0f,  1.0f, 1.0f,   // top right
            0.5f, -0.5f, 0.0f,  1.0f, 0.0f,   // bottom right
           -0.5f, -0.5f, 0.0f,  0.0f, 0.0f,   // bottom left
           -0.5f,  0.5f, 0.0f,  0.0f, 1.0f    // top left 
        });

    quad2.setVertexAttributes({
        //  vertex      tex coords
            {0, 3},     { 1, 2 }
        });

    quad2.setIndices({ 0, 1, 3, 1, 2, 3 });
    quad2.setDrawMethod(SGL::DrawMethod::Static);
    quad2.setDrawMode(SGL::DrawMode::Triangles);
    quad2.configure();

    // Create matrices
    SGL::Matrix4 transform1, transform2, camera;
    transform1.translate({ 640.0f / 2.0f, 480.0f / 2.0f, -2.0f });
    transform1.scale({ 256.0f, 256.0f, 1.0f });

    transform2.translate({ 640.0f / 2.0f, 480.0f / 2.0f, -1.0f });
    transform2.scale({ 640.0f * 0.9f, 480.0f * 0.9f, 1.0f });

    camera.createOrthoProjection({ 640u, 480u }, -0.1f, 100.0f);

    while (window.getRenderer()->running()) {

        // Draw to texture
        texture3.beginDrawing(SGL::COLOR::Lime);

        // First quad
        transform1.rotate({ 0.0f, 0.0f,  0.5f });
        shaderMultiTexture.setActive();
        shaderMultiTexture.setMatrix4("uTransform", (camera * transform1).toMat4());
        texture0.use();
        texture1.use();
        quad1.draw();

        texture3.endDrawing();


        // Draw to screen
        window.getRenderer()->beginDrawing(SGL::COLOR::Yellow);

        // Second quad whose texture contains the first quad
        shaderSingleTexture.setActive();
        shaderSingleTexture.setMatrix4("uTransform", (camera * transform2).toMat4());
        texture3.use();
        quad2.draw();

        window.getRenderer()->endDrawing();
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
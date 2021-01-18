/**
 * This is a test project suitable for testing SGL functionality.
 *
 *
 */

#include "SGL.h"

auto main(int argc, char** argv) -> int try {

    // Create window
    SGL::Window window(SGL::RendererType::OpenGL3, { 640, 480 }, u8"Otsikkö!");

    // Load shaders
    SGL::ShaderGLSL shaderSingleTexture("../assets/shaders/SingleTexture.vert", "../assets/shaders/SingleTexture.frag");
    SGL::ShaderGLSL shaderMultiTexture("../assets/shaders/MultiTexture.vert", "../assets/shaders/MultiTexture.frag");
    
    // Load some textures from disk
    SGL::Texture texture0;
    texture0.load("../assets/textures/test256x256_0.png");
    texture0.setTextureUnit(SGL::TextureUnit::Texture0);
    shaderMultiTexture.setTextureUnit("uTexture0", texture0.getTextureUnit());

    SGL::Texture texture1;
    texture1.load("../assets/textures/test256x256_1.png");
    texture1.setTextureUnit(SGL::TextureUnit::Texture1);
    shaderMultiTexture.setTextureUnit("uTexture1", texture1.getTextureUnit());

    // Create a drawable texture
    SGL::Texture texture3;
    texture3.create(SGL::Vector2<std::uint32_t>(640, 480));
    texture3.setTextureUnit(SGL::TextureUnit::Texture0);
    shaderSingleTexture.setTextureUnit("uTexture", texture3.getTextureUnit());

    // Create drawable quad1
    SGL::Drawable quad1;
    {
        std::vector<SGL::Drawable::BufferDataType> vertex = {
             0.5f,  0.5f,  0.0f,
             0.5f, -0.5f,  0.0f,
            -0.5f, -0.5f,  0.0f,
            -0.5f,  0.5f,  0.0f
        };

        std::vector<SGL::Drawable::BufferDataType> texCoord = {
            1.0f, 1.0f,
            1.0f, 0.0f,
            0.0f, 0.0f,
            0.0f, 1.0f
        };

        quad1.setBufferData(0, 3, std::move(vertex));
        quad1.setBufferData(1, 2, std::move(texCoord));
    }
    quad1.setIndices({ 0, 1, 3, 1, 2, 3 });
    quad1.setDrawMethod(SGL::DrawMethod::Static);
    quad1.setDrawMode(SGL::DrawMode::Triangles);
    quad1.configure();

    // Create drawable quad2
    SGL::Drawable quad2;
    {
        std::vector<SGL::Drawable::BufferDataType> vertex = {
             0.5f,  0.5f,  0.0f,
             0.5f, -0.5f,  0.0f,
            -0.5f, -0.5f,  0.0f,
            -0.5f,  0.5f,  0.0f
        };

        std::vector<SGL::Drawable::BufferDataType> texCoord = {
            1.0f, 1.0f,
            1.0f, 0.0f,
            0.0f, 0.0f,
            0.0f, 1.0f
        };

        quad2.setBufferData(0, 3, std::move(vertex));
        quad2.setBufferData(1, 2, std::move(texCoord));
    }
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

    // Main loop
    while (window.getRenderer()->running()) {

        if (window.getInput()->getKeyPressed(SGL::KEYCODE::KEY_F))
            break;

        if (window.getInput()->getKeyPressed(SGL::KEYCODE::KEY_A)) {
            texture0.setFilter(SGL::TextureFilter::Point);
            texture1.setFilter(SGL::TextureFilter::Point);
        }

        if (window.getInput()->getKeyPressed(SGL::KEYCODE::KEY_S)) {
            texture0.setFilter(SGL::TextureFilter::Bilinear);
            texture1.setFilter(SGL::TextureFilter::Bilinear);
        }

        // Draw quad1 to texture3
        texture3.beginDrawing(SGL::COLOR::Lime);

        transform1.rotate({ 0.0f, 0.0f,  0.5f });
        shaderMultiTexture.setActive();
        shaderMultiTexture.setMatrix4("uTransform", (camera * transform1).toMat4());

        texture0.use();
        texture1.use();
        quad1.draw();

        texture3.endDrawing();

        // Set drawing to screen and draw quad2 which texture contains quad1
        window.getRenderer()->beginDrawing(true, true, true, SGL::COLOR::Blue);

        shaderSingleTexture.setActive();
        shaderSingleTexture.setMatrix4("uTransform", (camera * transform2).toMat4());

        texture3.use();
        quad2.draw();

        window.getRenderer()->endDrawing();
    }

    return EXIT_SUCCESS;
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
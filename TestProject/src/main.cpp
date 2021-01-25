/**
 * This is a test project suitable for testing SGL functionality.
 *
 *
 */

#include "SGL.h"

auto main(int argc, char** argv) -> int try {

    // Create window and camera
    SGL::Window window({ 640u, 480u }, u8"Otsikko", SGL::RendererType::Windowed);
    SGL::Camera camera(window, SGL::CameraType::Orthographic);

    // Load primitive shader
    SGL::ShaderGLSL primitiveShader(
        "../assets/shaders/default/PrimitiveShader.vert",
        "../assets/shaders/default/PrimitiveShader.frag"
    );

    // Load texture shader
    SGL::ShaderGLSL textureShader(
        "../assets/shaders/default/TextureShader.vert",
        "../assets/shaders/default/TextureShader.frag"
    );

    // Load texture and create a sprite
    SGL::Texture tex1("../assets/textures/test256x256_0.png");
    SGL::Sprite sprite(camera, textureShader, tex1);
    sprite.setPosition({ 130.0f, 130.0f, 0.0f });

    // Create another texture and bind texture to it
    SGL::Texture tex2(SGL::Vector2<std::uint32_t>(300, 300));
    SGL::Sprite sprite2(camera, textureShader, tex2);
    sprite2.setPosition({ 400.0f, 300.0f, 0.0f });

    // Draw to tex2
    tex2.beginDrawing();
    SGL::Triangle triangle(
        camera,
        primitiveShader,
        { 100.0f, 100.0f, 0.0f },
        { 300.0f, 100.0f, 0.0f },
        { 200.0f, 300.0f, 0.0f },
        SGL::COLOR::Yellow
    );
    triangle.draw();
    tex2.endDrawing();

    // Main loop
    while (window.getRenderer()->running()) {
        window.getRenderer()->beginDrawing(true, true, true, SGL::COLOR::Blue);
        sprite.draw();
        sprite2.draw();
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
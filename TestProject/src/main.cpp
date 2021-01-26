/**
 * This is a test project suitable for testing SGL functionality.
 *
 *
 */

#include "SGL.h"

auto main(int argc, char** argv) -> int try {

    // Create window and camera
    SGL::Window window({ 640u, 480u }, u8"Otsikko", SGL::RendererType::Windowed);
    SGL::Camera camera(window, SGL::CameraType::Perspective);
    camera.setPosition(SGL::Vector3<float>::forward() * 3.0f);

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

    // Create cube and set its color to red
    SGL::Cube cube(camera, primitiveShader, SGL::Vector3<float>::one());
    cube.getShaderUniformManager()->setVector4("uColor", SGL::COLOR::Red.toVec4());

    // Main loop
    while (window.getRenderer()->running()) {

        // Rotate cube
        cube.rotate(SGL::Vector3<float>::left() * 0.5f);
        cube.rotate(SGL::Vector3<float>::up() * 0.5f);

        // Draw cube
        window.getRenderer()->beginDrawing(true, false, false, SGL::COLOR::Black);
        cube.draw();
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
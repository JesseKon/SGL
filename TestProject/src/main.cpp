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

    // Load solid color shader (represents light source)
    SGL::ShaderGLSL solidColorShader(
        "../assets/shaders/SolidColor.vert",
        "../assets/shaders/SolidColor.frag"
    );

    // Load lit shader
    SGL::ShaderGLSL litShader(
        "../assets/shaders/LitShader.vert",
        "../assets/shaders/LitShader.frag"
    );

    SGL::Texture texture("../assets/textures/test256x256_0.png");

    // Create light source
    SGL::Cube light(camera, solidColorShader, SGL::Vector3<float>::one() * 0.2f);
    light.setPosition({ 3.0f, 3.0f, 4.0f });

    // Create illuminated cube
    SGL::Cube illuminatedCube(camera, litShader, SGL::Vector3<float>::one());
    illuminatedCube.setPosition({ 0.0f, 0.0f, 0.0f });
    illuminatedCube.getShaderUniformManager()->setVector4("uObjectColor", SGL::Color(255, 0, 0, 255).toVec4());
    illuminatedCube.getShaderUniformManager()->setVector4("uAmbientColor", SGL::Color(16, 16, 16, 255).toVec4());
    illuminatedCube.getShaderUniformManager()->setVector4("uLightPos", glm::vec4(1.0f, 0.0f, 3.0f, 0.0f));
    illuminatedCube.getShaderUniformManager()->setVector4("uLightColor", SGL::Color(255, 255, 255, 255).toVec4());
    illuminatedCube.getShaderUniformManager()->setVector4("uViewPos", glm::vec4(0.0f, 0.0f, 3.0f, 0.0f));

    // Main loop
    while (window.getRenderer()->running()) {

        illuminatedCube.rotate(SGL::Vector3<float>::up() * 0.5f);
        illuminatedCube.rotate(SGL::Vector3<float>::right() * 0.5f);

        // Draw to renderer
        window.getRenderer()->beginDrawing(true, true, true, SGL::COLOR::Black);
        light.draw();
        illuminatedCube.draw();
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
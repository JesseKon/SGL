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

    SGL::Texture diffuseMap("../assets/textures/container2.png");
    SGL::Texture specularMap("../assets/textures/container2_specular.png");


    // Create illuminated cube
    SGL::Cube illuminatedCube(camera, litShader, SGL::Vector3<float>::one(), &diffuseMap, &specularMap);
    illuminatedCube.setPosition({ 0.0f, 0.0f, 0.0f });
    illuminatedCube.getShaderUniformManager()->setVector4("uAmbientColor", glm::vec4(0.1f, 0.1f, 0.1f, 0.1f));
    illuminatedCube.getShaderUniformManager()->setVector4("uLightPos", glm::vec4(4.0f, 0.0f, 3.0f, 0.0f));
    illuminatedCube.getShaderUniformManager()->setVector4("uLightColor", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    illuminatedCube.getShaderUniformManager()->setVector4("uViewPos", glm::vec4(0.0f, 0.0f, 3.0f, 0.0f));

    //illuminatedCube.getShaderUniformManager()->setVector3("material.ambient", glm::vec3(1.0f, 0.5f, 0.31f));
    //illuminatedCube.getShaderUniformManager()->setVector3("material.diffuse", glm::vec3(1.0f, 0.5f, 0.31f));
    //illuminatedCube.getShaderUniformManager()->setVector3("material.specular", glm::vec3(0.5f, 0.5f, 0.5f));
    illuminatedCube.getShaderUniformManager()->setFloat("material.shininess", 32.0f);

    illuminatedCube.getShaderUniformManager()->setVector3("light.position", glm::vec3(1.f, 0.2f, 4.0f));
    illuminatedCube.getShaderUniformManager()->setVector3("light.ambient", glm::vec3(0.1f, 0.1f, 0.1f));
    illuminatedCube.getShaderUniformManager()->setVector3("light.diffuse", glm::vec3(0.5f, 0.5f, 0.5f)); // darken diffuse light a bit
    illuminatedCube.getShaderUniformManager()->setVector3("light.specular", glm::vec3(1.0f, 1.0f, 1.0f));


    // Main loop
    while (window.getRenderer()->running()) {

        illuminatedCube.rotate(SGL::Vector3<float>::up() * 0.2f);
        //illuminatedCube.rotate(SGL::Vector3<float>::right() * 0.2f);

        // Draw to renderer
        window.getRenderer()->beginDrawing(true, true, true, SGL::COLOR::Black);
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
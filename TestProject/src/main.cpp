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
    camera.setPosition(SGL::Vector3<float>::forward() * 10.0f);

    // Load lit shader
    SGL::ShaderGLSL litShader(
        "../assets/shaders/LitShaderSpotlight.vert",
        "../assets/shaders/LitShaderSpotlight.frag"
    );

    SGL::Texture diffuseMap("../assets/textures/container2.png");
    SGL::Texture specularMap("../assets/textures/container2_specular.png");


    // Create illuminated cube
    SGL::Cube illuminatedCube(camera, litShader, SGL::Vector3<float>::one() * 2.0f, &diffuseMap, &specularMap);
    illuminatedCube.setPosition({ 0.0f, 0.0f, 0.0f });
    //illuminatedCube.getShaderUniformManager()->setVector4("uAmbientColor", glm::vec4(0.1f, 0.1f, 0.1f, 0.1f));
    //illuminatedCube.getShaderUniformManager()->setVector4("uLightColor", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    illuminatedCube.getShaderUniformManager()->setVector4("uLightPos", glm::vec4(4.0f, 0.0f, 3.0f, 0.0f));
    illuminatedCube.getShaderUniformManager()->setVector4("uViewPos", glm::vec4(0.0f, 0.0f, 3.0f, 0.0f));

    illuminatedCube.getShaderUniformManager()->setFloat("material.shininess", 32.0f);

    illuminatedCube.getShaderUniformManager()->setVector3("light.position", glm::vec3(0.0f, 0.0f, 3.0f));
    illuminatedCube.getShaderUniformManager()->setVector3("light.direction", glm::vec3(0.0f, 0.0f, -1.0f));
    illuminatedCube.getShaderUniformManager()->setFloat("light.cutOff", glm::cos(glm::radians(12.5f)));
    illuminatedCube.getShaderUniformManager()->setFloat("light.outerCutOff", glm::cos(glm::radians(17.5f)));
    illuminatedCube.getShaderUniformManager()->setVector3("light.ambient", glm::vec3(0.1f, 0.1f, 0.1f));
    illuminatedCube.getShaderUniformManager()->setVector3("light.diffuse", glm::vec3(0.5f, 0.5f, 0.5f)); // darken diffuse light a bit
    illuminatedCube.getShaderUniformManager()->setVector3("light.specular", glm::vec3(1.0f, 1.0f, 1.0f));

    illuminatedCube.getShaderUniformManager()->setFloat("light.constant", 1.0f);
    illuminatedCube.getShaderUniformManager()->setFloat("light.linear", 0.09f);
    illuminatedCube.getShaderUniformManager()->setFloat("light.quadratic", 0.032f);


    // Main loop
    while (window.getRenderer()->running()) {

        //illuminatedCube.rotate(SGL::Vector3<float>::up() * 0.2f);
        //illuminatedCube.rotate(SGL::Vector3<float>::right() * 0.2f);
        illuminatedCube.translate(SGL::Vector3<float>::left() * -0.003f);

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
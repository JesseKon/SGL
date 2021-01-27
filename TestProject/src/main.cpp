/**
 * This is a test project suitable for testing SGL functionality.
 *
 *
 */

#include "SGL.h"

auto main(int argc, char** argv) -> int try {

    // Create window and camera
    SGL::Window window({ 640u, 480u }, u8"Otsikko", SGL::RendererType::Windowed);

    // Create basic renderer camera
    SGL::BRP_Camera camera(
        window,
        SGL::BRP_CameraType::Perspective
    );

    // Load basic renderer shader
    SGL::BRP_Shader litShader(
        "../assets/shaders/BRP/BRP_Lit.vert",
        "../assets/shaders/BRP/BRP_Lit.frag"
    );

    litShader.setAmbientLight(glm::vec3(1.0f, 1.0f, 1.0f), 0.1f);

    camera.setPosition(SGL::Vector3<float>::forward() * 7.0f);

    SGL::Texture diffuseMap("../assets/textures/container2.png");
    SGL::Texture specularMap("../assets/textures/container2_specular.png");

    // Create illuminated cube
    SGL::BRP_Cube illuminatedCube(camera, litShader, SGL::Vector3<float>::one() * 2.0f, &diffuseMap, &specularMap);
    illuminatedCube.setPosition({ 0.5f, 0.0f, 0.0f });
    illuminatedCube.getBRP_ShaderUniformManager()->setVector4("uLightPos", glm::vec4(4.0f, 0.0f, 3.0f, 0.0f));
    illuminatedCube.getBRP_ShaderUniformManager()->setVector4("uViewPos", glm::vec4(0.0f, 0.0f, 3.0f, 0.0f));

    illuminatedCube.getBRP_ShaderUniformManager()->setVector3("light.position", glm::vec3(0.0f, 0.0f, 3.0f));
    illuminatedCube.getBRP_ShaderUniformManager()->setVector3("light.direction", glm::vec3(0.0f, 0.0f, -1.0f));
    illuminatedCube.getBRP_ShaderUniformManager()->setFloat("light.cutOff", glm::cos(glm::radians(12.5f)));
    illuminatedCube.getBRP_ShaderUniformManager()->setFloat("light.outerCutOff", glm::cos(glm::radians(17.5f)));
    illuminatedCube.getBRP_ShaderUniformManager()->setVector3("light.ambient", glm::vec3(0.1f, 0.1f, 0.1f));
    illuminatedCube.getBRP_ShaderUniformManager()->setVector3("light.diffuse", glm::vec3(0.5f, 0.5f, 0.5f)); // darken diffuse light a bit
    illuminatedCube.getBRP_ShaderUniformManager()->setVector3("light.specular", glm::vec3(1.0f, 1.0f, 1.0f));

    illuminatedCube.getBRP_ShaderUniformManager()->setFloat("light.constant", 1.0f);
    illuminatedCube.getBRP_ShaderUniformManager()->setFloat("light.linear", 0.09f);
    illuminatedCube.getBRP_ShaderUniformManager()->setFloat("light.quadratic", 0.032f);

    // Main loop
    while (window.getRenderer()->running()) {

        illuminatedCube.rotate(SGL::Vector3<float>::up() * 0.2f);
        illuminatedCube.rotate(SGL::Vector3<float>::right() * 0.2f);

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
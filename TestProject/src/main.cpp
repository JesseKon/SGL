/**
 * This is a test project suitable for testing SGL functionality.
 *
 *
 */

#include <SGL.h>
#include <chrono>

auto main(int argc, char** argv) -> int try {

    // Create window
    SGL::Window window({ 640u, 480u }, u8"Otsikko", SGL::RendererType::Windowed);

    // Load "basic renderer pipeline" shader
    SGL::BRP_Shader litShader(
        "../assets/shaders/BRP/BRP_Lit.vert",
        "../assets/shaders/BRP/BRP_Lit.frag"
    );

    // Create "basic renderer pipeline" camera
    SGL::BRP_Camera camera(
        window,
        litShader,
        SGL::BRP_CameraType::Perspective
    );

    // Create "basic renderer pipeline" scene
    //SGL::BRP_Scene scene (
    //    camera,
    //    litShader
    //);

    //// Set directional light
    //litShader.setDirectionalLight(
    //    0,
    //    glm::vec3(-0.3f, -0.4f, 0.3f),
    //    glm::vec3(0.08f, 0.08f, 0.08f),
    //    glm::vec3(0.4f, 0.4f, 0.4f),
    //    glm::vec3(0.8f, 0.8f, 0.8f)
    //);

    //SGL::BRP_Light light(scene, SGL::BRP_LightType::Point);

    camera.setPosition(SGL::Vector3<float>::forward() * 7.0f);

    SGL::Texture diffuseMap("../assets/textures/container2.png");
    SGL::Texture specularMap("../assets/textures/container2_specular.png");

    // Create floor
    SGL::BRP_Cube floor(camera, litShader, SGL::Vector3<float>(10.0f, 0.1f, 10.0f));
    floor.translate(SGL::Vector3<float>::down() * 3.0f);

    // Create illuminated cube
    SGL::BRP_Cube illuminatedCube(camera, litShader, SGL::Vector3<float>::one() *2.f, &diffuseMap, &specularMap);
    illuminatedCube.setPosition({ 0.0f, 0.0f, 0.0f });

    // Directional light which also sets global ambient light
    illuminatedCube.getBRP_ShaderUniformManager()->setInt("directionalLight[0].active", 1);
    illuminatedCube.getBRP_ShaderUniformManager()->setVector3("directionalLight[0].direction", glm::vec3(0.2f, -1.0f, -1.0f));
    illuminatedCube.getBRP_ShaderUniformManager()->setVector3("directionalLight[0].ambient", glm::vec3(0.03f, 0.03f, 0.08f));
    illuminatedCube.getBRP_ShaderUniformManager()->setVector3("directionalLight[0].diffuse", glm::vec3(0.0f, 0.0f, 0.0f));
    illuminatedCube.getBRP_ShaderUniformManager()->setVector3("directionalLight[0].specular", glm::vec3(0.0f, 0.0f, 0.0f));

    illuminatedCube.getBRP_ShaderUniformManager()->setInt("pointLight[0].active", 1);
    illuminatedCube.getBRP_ShaderUniformManager()->setFloat("pointLight[0].constant", 1.0f);
    illuminatedCube.getBRP_ShaderUniformManager()->setFloat("pointLight[0].linear", 4.5f / 200.0f);
    illuminatedCube.getBRP_ShaderUniformManager()->setFloat("pointLight[0].quadratic", 75.0f / (200.0f * 200.0f));
    illuminatedCube.getBRP_ShaderUniformManager()->setVector3("pointLight[0].position", glm::vec3(2.0f, -10.0f, 7.0f));
    illuminatedCube.getBRP_ShaderUniformManager()->setVector3("pointLight[0].ambient", glm::vec3(0.0f, 0.0f, 0.0f));
    illuminatedCube.getBRP_ShaderUniformManager()->setVector3("pointLight[0].diffuse", glm::vec3(0.2f, 0.4f, 0.8f));
    illuminatedCube.getBRP_ShaderUniformManager()->setVector3("pointLight[0].specular", glm::vec3(0.2f, 0.4f, 0.8f));

    illuminatedCube.getBRP_ShaderUniformManager()->setInt("spotLight[0].active", 1);
    illuminatedCube.getBRP_ShaderUniformManager()->setFloat("spotLight[0].constant", 1.0f);
    illuminatedCube.getBRP_ShaderUniformManager()->setFloat("spotLight[0].linear", 0.09f);
    illuminatedCube.getBRP_ShaderUniformManager()->setFloat("spotLight[0].quadratic", 0.032f);
    illuminatedCube.getBRP_ShaderUniformManager()->setFloat("spotLight[0].cutOff", glm::cos(glm::radians(12.0f)));
    illuminatedCube.getBRP_ShaderUniformManager()->setFloat("spotLight[0].outerCutOff", glm::cos(glm::radians(16.0f)));
    illuminatedCube.getBRP_ShaderUniformManager()->setVector3("spotLight[0].position", glm::vec3(0.0f, 0.0f, 3.0f));
    illuminatedCube.getBRP_ShaderUniformManager()->setVector3("spotLight[0].direction", glm::vec3(0.0f, 0.0f, -1.0f));
    illuminatedCube.getBRP_ShaderUniformManager()->setVector3("spotLight[0].ambient", glm::vec3(0.0f, 0.0f, 0.0f));
    illuminatedCube.getBRP_ShaderUniformManager()->setVector3("spotLight[0].diffuse", glm::vec3(0.9f, 0.9f, 0.9f));
    illuminatedCube.getBRP_ShaderUniformManager()->setVector3("spotLight[0].specular", glm::vec3(0.9f, 0.9f, 0.9f));


    // Main loop
    while (window.getRenderer()->running()) {

        if (window.getInput()->getKeyPressed(SGL::Keycode::Key_I))
            illuminatedCube.getBRP_ShaderUniformManager()->setInt("pointLight[0].active", 1);

        if (window.getInput()->getKeyPressed(SGL::Keycode::Key_J))
            illuminatedCube.getBRP_ShaderUniformManager()->setInt("pointLight[0].active", 0);

        illuminatedCube.rotate(SGL::Vector3<float>::up() * 0.2f);
        illuminatedCube.rotate(SGL::Vector3<float>::right() * 0.2f);
        //illuminatedCube.translate(SGL::Vector3<float>::right() * 0.002f);

        // Draw to renderer
        window.getRenderer()->beginDrawing(true, true, true, SGL::COLOR::Black);
        floor.draw();
        illuminatedCube.draw();
        //scene.draw();
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
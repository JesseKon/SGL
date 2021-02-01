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

    // Load "basic renderer pipeline" lit shader
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
    camera.setPosition(SGL::Vector3<float>::forward() * 7.0f);

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

    SGL::Texture diffuseMap("../assets/textures/container2.png");
    SGL::Texture specularMap("../assets/textures/container2_specular.png");

    SGL::Texture depthMap(SGL::Vector2<std::uint32_t>(1024, 1024), SGL::TextureType::Depth);
    SGL::ShaderGLSL depthShader(
        "../assets/shaders/DepthShader.vert",
        "../assets/shaders/DepthShader.frag"
    );


    // Create floor
    SGL::BRP_Cube floor(camera, litShader, SGL::Vector3<float>(10.0f, 0.1f, 10.0f));
    floor.setShininess(1.0f);
    floor.translate(SGL::Vector3<float>::down() * 3.0f);

    // Create illuminated cube
    SGL::BRP_Cube illuminatedCube(camera, litShader, SGL::Vector3<float>::one() * 2.f, &diffuseMap, &specularMap);
    illuminatedCube.setPosition({ 0.0f, 0.0f, 0.0f });

    // Create directional light which also sets global ambient light
    SGL::DirectionalLight directionalLight;
    directionalLight.id = 0;
    directionalLight.isActive = true;
    directionalLight.direction = glm::vec3(0.2f, -1.0f, -1.0f);
    directionalLight.ambientColor = glm::vec3(0.08f, 0.08f, 0.08f);
    directionalLight.diffuseColor = glm::vec3(0.0f, 0.0f, 0.0f);
    directionalLight.specularColor = glm::vec3(0.0f, 0.0f, 0.0f);
    litShader.setDirectionalLight(&directionalLight);

    // Create point light
    SGL::PointLight pointLight;
    pointLight.id = 0;
    pointLight.isActive = true;
    pointLight.position = glm::vec3(0.0f, -2.0f, 0.0f);
    pointLight.ambientColor = glm::vec3(0.0f, 0.0f, 0.0f);
    pointLight.diffuseColor = glm::vec3(0.4f, 0.4f, 0.4f);
    pointLight.specularColor = glm::vec3(0.8f, 0.8f, 0.8f);
    pointLight.distance = 20.0f;
    litShader.setPointLight(&pointLight);

    // Create spotlight
    SGL::SpotLight spotLight;
    spotLight.id = 0;
    spotLight.isActive = true;
    spotLight.position = glm::vec3(0.0f, 0.0f, 3.0f);
    spotLight.direction = glm::vec3(0.0f, 0.0f, -1.0f);
    spotLight.ambientColor = glm::vec3(0.0f, 0.0f, 0.0f);
    spotLight.diffuseColor = glm::vec3(0.4f, 0.4f, 0.4f);
    spotLight.specularColor = glm::vec3(0.8f, 0.8f, 0.8f);
    spotLight.innerCutOff = 15.0f;
    spotLight.outerCutOff = 20.0f;
    spotLight.distance = 50.0f;
    litShader.setSpotLight(&spotLight);

    // Main loop
    while (window.getRenderer()->running()) {

        if (window.getInput()->getKeyPressed(SGL::Keycode::Key_Space))
            spotLight.isActive = !spotLight.isActive;

        illuminatedCube.rotate(SGL::Vector3<float>::up() * 0.2f);
        illuminatedCube.rotate(SGL::Vector3<float>::right() * 0.2f);
    
        // Draw to renderer
        window.getRenderer()->beginDrawing(true, true, true, SGL::COLOR::Black);
        litShader.updateLights();
        illuminatedCube.draw();
        floor.draw();
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
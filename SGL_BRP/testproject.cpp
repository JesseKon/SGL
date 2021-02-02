#include <SGL.h>

auto main(int argc, char** argv) -> int try {

    // Create window
    SGL::Window window({ 640u, 480u }, u8"Otsikko", SGL::RendererType::Windowed);

    // Load "basic renderer pipeline" lit shader
    SGL::BRP_Shader litShader(
        "../assets/shaders/BRP/BRP_Lit.vert",
        "../assets/shaders/BRP/BRP_Lit.frag"
    );

    SGL::BRP_Shader unlitShader(
        "../assets/shaders/BRP/BRP_Unlit.vert",
        "../assets/shaders/BRP/BRP_Unlit.frag"
    );

    // Create "basic renderer pipeline" camera
    SGL::BRP_Camera camera(
        window,
        litShader,
        SGL::BRP_CameraType::Perspective
    );
    camera.setPosition(SGL::Vector3<float>::forward() * 7.0f);

    // Load a couple of textures
    SGL::Texture diffuseMap("../assets/textures/container2.png");
    SGL::Texture specularMap("../assets/textures/container2_specular.png");


    SGL::Texture testTexture(SGL::Vector2<std::uint32_t>(1024, 1024), SGL::TextureType::Color);
    SGL::BRP_Cube testCube(camera, litShader, SGL::Vector3<float>::one() * 3.0f, &testTexture);

    ////////////////////////

    //// Create depthmap
    //SGL::BRP_Shader depthShader(
    //    "../assets/shaders/BRP/BRP_DepthShader.vert",
    //    "../assets/shaders/BRP/BRP_DepthShader.frag"
    //);
    //SGL::Texture depthMap(SGL::Vector2<std::uint32_t>(1024, 1024), SGL::TextureType::Depth);
    SGL::Texture depthMap(SGL::Vector2<std::uint32_t>(1024, 1024), SGL::TextureType::Color);

    //// Create debug to visualize depthmap
    //SGL::BRP_Shader depthShaderDebug(
    //    "../assets/shaders/BRP/BRP_DepthShaderDebug.vert",
    //    "../assets/shaders/BRP/BRP_DepthShaderDebug.frag"
    //);
    SGL::BRP_Cube depthMapDebugCube(camera, litShader, SGL::Vector3<float>::one() * 3.0f, &depthMap);




    ////////////////////////



    // Create floor
    SGL::BRP_Cube floor(camera, litShader, SGL::Vector3<float>(10.0f, 0.05f, 10.0f));
    floor.setShininess(1.0f);
    floor.translate(SGL::Vector3<float>::down() * 3.0f);

    // Create cube
    SGL::BRP_Cube cube(camera, litShader, SGL::Vector3<float>::one() * 2.f, &diffuseMap, &specularMap);
    cube.setPosition({ 0.0f, 0.0f, 0.0f });

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

        cube.rotate(SGL::Vector3<float>::up() * 0.2f);
        cube.rotate(SGL::Vector3<float>::right() * 0.2f);

        testTexture.beginDrawing(true, true, true);
        litShader.updateLights();
        cube.draw();
        floor.draw();
        testTexture.endDrawing();


        // Draw to renderer (this is working)
        window.getRenderer()->beginDrawing(true, true, true, SGL::COLOR::Black);
        testCube.draw();
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
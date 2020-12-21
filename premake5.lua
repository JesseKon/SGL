workspace "SGL"
    startproject "TestProject"

    configurations {
        "Debug",
        "Release",
    }

    platforms {
        "x86",
        "x86_64"
    }

    filter "configurations:Debug"
        symbols "On"
        defines { "SGL_DEBUG" }
    
    filter "configurations:Release"
        optimize "On"
        defines { "SGL_RELEASE", "NDEBUG" }
    
    filter "platforms:x86"
        architecture "x86"
    
    filter "platforms:x86_64"
        architecture "x86_64"



-----------------------------------------------------------------------------------
project "SGL"
    location "SGL"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/SGL")
    objdir ("bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/SGL")

    files {
		"SGL/src/**.h",
        "SGL/src/**.cpp",
        "SGL/src/Renderer/**.h",
        "SGL/src/Renderer/**.cpp",
        "SGL/src/Shader/**.h",
        "SGL/src/Shader/**.cpp",
        "dependencies/glad/src/**.c",
    }

    ----------------
    filter { "system:windows" }
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        includedirs {
            "SGL/src",
            "SGL/src/Renderer/",
            "SGL/src/Shader/",
        }

        links {
            "glfw3dll.lib",
            "opengl32.lib",
        }

        defines {
            "SGL_PLATFORM_WINDOWS",
            "SGL_BUILD_DLL",
        }

        -- Copy SGL.dll to TestProject
        postbuildcommands {(
            "{COPY} %{cfg.buildtarget.relpath} ../bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/TestProject"
        )}

    ----------------
    filter { "system:windows", "platforms:x86" }
        includedirs {
            "dependencies/windows/glfw-3.3.2.bin.WIN32/include",
            "dependencies/glad/include",
            "dependencies/glm",
        }

        libdirs {
            "dependencies/windows/glfw-3.3.2.bin.WIN32/lib-vc2019",
        }

    ----------------
    filter { "system:windows", "platforms:x86_64" }
        includedirs {
            "dependencies/windows/glfw-3.3.2.bin.WIN64/include",
            "dependencies/glad/include",
            "dependencies/glm",
        }

        libdirs {
            "dependencies/windows/glfw-3.3.2.bin.WIN64/lib-vc2019",
        }
        

-----------------------------------------------------------------------------------
project "TestProject"
    location "TestProject"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/TestProject")
    objdir ("bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/TestProject")

    files {
        "TestProject/src/**.h",
        "TestProject/src/**.cpp",
    }

    includedirs {
        "SGL/src",
        "SGL/src/Renderer/",
        "SGL/src/Shader/"
    }

    links {
        "SGL",
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "SGL_PLATFORM_WINDOWS",
        }
    
    ----------------
    filter { "system:windows", "platforms:x86" }
        includedirs {
            "dependencies/windows/glfw-3.3.2.bin.WIN32/include",
            "dependencies/glad/include",
            "dependencies/glm",
        }

    ----------------
    filter { "system:windows", "platforms:x86_64" }
        includedirs {
            "dependencies/windows/glfw-3.3.2.bin.WIN64/include",
            "dependencies/glad/include",
            "dependencies/glm",
        }

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
		"SGL/src/Core/**.h",
        "SGL/src/Core/**.cpp",
        "SGL/src/Core/Drawable/**.h",
        "SGL/src/Core/Drawable/**.cpp",
        "SGL/src/Core/Renderer/**.h",
        "SGL/src/Core/Renderer/**.cpp",
        "SGL/src/Core/Shader/**.h",
        "SGL/src/Core/Shader/**.cpp",
        "SGL/src/Core/Texture/**.h",
        "SGL/src/Core/Texture/**.cpp",
        "dependencies/glad/src/**.c",
        "dependencies/stb_image/*.h",
        "dependencies/stb_image/**.cpp",
    }

    includedirs {
        "SGL/src/",
        "SGL/src/Core/",
        "SGL/src/Core/Drawable/",
        "SGL/src/Core/Renderer/",
        "SGL/src/Core/Shader/",
        "SGL/src/Core/Texture/",
        "dependencies/glfw/include",
        "dependencies/glad/include",
        "dependencies/glm",
        "dependencies/stb_image",
    }

    ----------------
    filter { "system:windows" }
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

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
    filter { "system:linux" }
        cppdialect "C++17"

        links {
            "glfw",
            "GL",
            "X11",
            "pthread",
            "Xrandr",
            "Xi",
            "dl",
        }

        defines {
            "SGL_PLATFORM_LINUX",
            "SGL_BUILD_DLL",
        }

    ----------------
    filter { "system:windows", "platforms:x86" }
        libdirs {
            "dependencies/glfw/lib-win32",
        }
    
    filter { "system:windows", "platforms:x86_64" }
        libdirs {
            "dependencies/glfw/lib-win64",
        }

    ----------------
    filter { "system:linux", "platforms:x86"}
        libdirs {
            "dependencies/glfw/lib-linux32"
        }
    
    filter { "system:linux", "platforms:x86_64" }
        libdirs {
            "dependencies/glfw/lib-linux64"
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
        "SGL/src/",
        "SGL/src/Core/",
        "SGL/src/Core/Drawable/",
        "SGL/src/Core/Renderer/",
        "SGL/src/Core/Shader/",
        "SGL/src/Core/Texture/",
        "dependencies/glfw/include",
        "dependencies/glad/include",
        "dependencies/glm",
        "dependencies/stb_image",
    }

    links {
        "SGL",
    }

    ----------------
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "SGL_PLATFORM_WINDOWS",
        }
    
    ----------------
    filter "system:linux"
        cppdialect "C++17"

        defines {
            "SGL_PLATFORM_LINUX",
        }
    

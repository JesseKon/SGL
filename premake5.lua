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
        defines { "SGL_RELEASE" }
    
    filter "platforms:x86"
        architecture "x86"
    
    filter "platforms:x86_64"
        architecture "x86_64"



-----------------------------------------------------------------------------------
project "SGL"
    location "SGL"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")
    objdir ("bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")

    pchheader "sglpch.h"
    pchsource "SGL/src/sglpch.cpp"

    files {
		"%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/Renderer/**.h",
		"%{prj.name}/src/Renderer/**.cpp",
    }

    ----------------
    filter { "system:windows" }
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        includedirs {
            "%{prj.name}/src",
            "%{prj.name}/src/Renderer/",
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
        }

        libdirs {
            "dependencies/windows/glfw-3.3.2.bin.WIN32/lib-vc2019",
        }

    ----------------
    filter { "system:windows", "platforms:x86_64" }
        includedirs {
            "dependencies/windows/glfw-3.3.2.bin.WIN64/include",
        }

        libdirs {
            "dependencies/windows/glfw-3.3.2.bin.WIN64/lib-vc2019",
        }
        

-----------------------------------------------------------------------------------
project "TestProject"
    location "TestProject"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")
    objdir ("bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs {
        "SGL/src",
        "SGL/src/Renderer/",
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
        }

    ----------------
    filter { "system:windows", "platforms:x86_64" }
        includedirs {
            "dependencies/windows/glfw-3.3.2.bin.WIN64/include",
        }

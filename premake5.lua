workspace "Masita"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Masita/vendor/GLFW/include"

include "Masita/vendor/GLFW"

project "Masita"
    location "Masita"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "mapch.h"
    pchsource "Masita/src/mapch.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "MA_PLATFORM_WINDOWS",
            "MA_BUILD_DLL"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "MA_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "MA_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "MA_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Masita/vendor/spdlog/include",
        "Masita/src"
    }

    links {
        "Masita"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "MA_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "MA_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "MA_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "MA_DIST"
        optimize "On"
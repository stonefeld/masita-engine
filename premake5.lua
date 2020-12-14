workspace "Masita"
    architecture "x64"
    startproject "Sandbox"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Masita/vendor/GLFW/include"
IncludeDir["Glad"] = "Masita/vendor/Glad/include"
IncludeDir["ImGui"] = "Masita/vendor/imgui"

include "Masita/vendor/GLFW"
include "Masita/vendor/Glad"
include "Masita/vendor/imgui"


project "Masita"
    location "Masita"
    kind "SharedLib"
    language "C++"
    staticruntime "off"

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
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links {
        "GLFW",
        "GLAD",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines {
            "MA_PLATFORM_WINDOWS",
            "MA_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
        }

    filter "configurations:Debug"
        defines "MA_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "MA_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "MA_DIST"
        runtime "Release"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

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
        systemversion "latest"

        defines {
            "MA_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "MA_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "MA_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "MA_DIST"
        runtime "Release"
        optimize "On"
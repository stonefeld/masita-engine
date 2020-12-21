workspace "Masita"
    architecture "x64"
    startproject "Sandbox"

    configurations {
        "Debug",
        "Release",
        "Dist",
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Masita/vendor/GLFW/include"
IncludeDir["Glad"] = "Masita/vendor/Glad/include"
IncludeDir["ImGui"] = "Masita/vendor/imgui"
IncludeDir["glm"] = "Masita/vendor/glm"

include "Masita/vendor/GLFW"
include "Masita/vendor/Glad"
include "Masita/vendor/imgui"

project "Masita"
    location "Masita"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "mapch.h"
    pchsource "Masita/src/mapch.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl",
    }

    defines {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
    }

    links {
        "GLFW",
        "GLAD",
        "ImGui",
        "opengl32.lib",
    }

    filter "system:windows"
        systemversion "latest"

        defines {
            "MA_PLATFORM_WINDOWS",
            "MA_BUILD_DLL",
            "GLFW_INCLUDE_NONE",
        }

    filter "configurations:Debug"
        defines "MA_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "MA_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "MA_DIST"
        runtime "Release"
        optimize "on"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    cppdialect "C++17"
    language "C++"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs {
        "Masita/vendor/spdlog/include",
        "Masita/src",
        "Masita/vendor",
        "%{IncludeDir.glm}",
    }

    links {
        "Masita"
    }

    filter "system:windows"
        systemversion "latest"

        defines {
            "MA_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "MA_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "MA_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "MA_DIST"
        runtime "Release"
        optimize "on"

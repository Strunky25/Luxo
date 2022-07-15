workspace "Luxo"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"

project "Luxo"
	location "Luxo"
	kind "SharedLib"
	language "c++"

	targetdir  ("bin/" .. outputdir .. "/%{prj.name}")
	objdir  ("int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"LX_PLATFORM_WINDOWS",
			"LX_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "LX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "LX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "LX_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "c++"

	targetdir  ("bin/" .. outputdir .. "/%{prj.name}")
	objdir  ("int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Luxo/vendor/spdlog/include",
		"Luxo/src"
	}

	links
	{
		"Luxo"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"LX_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "LX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "LX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "LX_DIST"
		optimize "On" 
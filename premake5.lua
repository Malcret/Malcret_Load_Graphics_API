workspace "Malcret_Load_Graphics_API"
	architecture "x86_64"
	configurations {
		"Debug",
		"Release"
	}

cversion = "C11"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
_targetdir = "bin/" .. outputdir .. "/%{prj.name}"
_objdir = _targetdir .. "/obj"

project "MLGA"
	kind "StaticLib"
	language "C"

	targetdir (_targetdir)
	objdir (_objdir)

	files {
		"%{prj.location}/inc/**.h",
		"%{prj.location}/src/**.c"
	}

	includedirs {
		"%{prj.location}/inc"
	}

	links {
		"opengl32.lib"
	}

	filter "system:windows"
		cdialect (cversion)
		staticruntime "On"
		systemversion "latest"

	filter "system:linux"
		cdialect (cversion)

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"
-- A solution contains projects, and defines the available configurations
solution "2D Pong"
   configurations { "Debug", "Release"}

   flags { "Unicode" , "NoPCH"}

   projectName = "2d_Pong"
   projectSourcePath = "src/"
   projectBuildPath = "bin/"

    -- A project defines one build target
    project (projectName)
       kind "ConsoleApp"
       location (projectSourcePath)
       language "C++"
       targetdir (projectBuildPath)

       configuration { "windows" }
          buildoptions ""
          linkoptions { "/NODEFAULTLIB:msvcrt" } -- https://github.com/yuriks/robotic/blob/master/premake5.lua
       configuration { "linux" }
          buildoptions "-std=c++11" --http://industriousone.com/topic/xcode4-c11-build-option
          toolset "gcc"
       configuration {}

       files { path.join(projectSourcePath, "**.h"), path.join(projectSourcePath, "**.cpp") } -- build all .h and .cpp files recursively
       excludes { "./graphics_dependencies/**" }  -- don't build files in graphics_dependencies/


       -- where are header files?
       -- tag::headers[]
       configuration "windows"
       includedirs {
                     "./graphics_dependencies/SDL2/include",
                     "./graphics_dependencies/SDL2/include/SDL2",
                     "./graphics_dependencies/glew/include",
                     "./graphics_dependencies/glm",
                     "./graphics_dependencies/SDL2_image/include",

                   }
       configuration { "linux" }
       includedirs {
                -- should be installed as in ./graphics_dependencies/README.asciidoc
                   }
       configuration {}
       -- end::headers[]


       -- what libraries need linking to
       -- tag::libraries[]
       configuration "windows"
          links { "SDL2", "SDL2main", "opengl32", "glew32", "SDL2_image" }
       configuration "linux"
          links { "SDL2", "SDL2main", "GL", "GLEW", "SDL2_image" }
       configuration {}
       -- end::libraries[]

       -- where are libraries?
       -- tag::librariesDirs[]
       configuration "windows"
       libdirs {
                 "./graphics_dependencies/glew/lib/Release/Win32",
                 "./graphics_dependencies/SDL2/lib/win32",
                 "./graphics_dependencies/SDL2_image/lib/x86/",
               }
       configuration "linux"
                -- should be installed as in ./graphics_dependencies/README.asciidoc
       configuration {}
       -- end::librariesDirs[]


       configuration "*Debug"
          defines { "DEBUG" }
          flags { "Symbols" }
          optimize "Off"
          targetsuffix "-debug"


       configuration "*Release"
          defines { "NDEBUG" }
          optimize "On"
          targetsuffix "-release"

       -- tag::copyAssets
       assetsPaths = { "shaders", "textures"}
       for i, assetPath in ipairs(assetsPaths) do
          assetSourcePath = path.join(projectSourcePath, "assets", assetPath)
          assetBuildPath = path.join(projectBuildPath, "assets", assetPath)
          os.mkdir(assetBuildPath)
          os.copyfile(path.join(assetSourcePath, "*") , assetBuildPath)
       end
       -- end::copyAssets

	   -- copy dlls on windows
       -- tag::windowsDLLCopy[]
       if os.get() == "windows" then
          os.copyfile("./graphics_dependencies/glew/bin/Release/Win32/glew32.dll", path.join(projectBuildPath, "glew32.dll"))
          os.copyfile("./graphics_dependencies/SDL2/lib/win32/SDL2.dll", path.join(projectBuildPath, "SDL2.dll"))
          os.copyfile("./graphics_dependencies/SDL2_image/lib/x86/SDL2_image.dll", path.join(projectBuildPath, "SDL2_image.dll"))
          os.copyfile("./graphics_dependencies/SDL2_image/lib/x86/libjpeg-9.dll", path.join(projectBuildPath, "libjpeg-9.dll"))
          os.copyfile("./graphics_dependencies/SDL2_image/lib/x86/libpng16-16.dll", path.join(projectBuildPath, "libpng16-16.dll"))
          os.copyfile("./graphics_dependencies/SDL2_image/lib/x86/libtiff-5.dll", path.join(projectBuildPath, "libtiff-5.dll"))
          os.copyfile("./graphics_dependencies/SDL2_image/lib/x86/libwebp-4.dll", path.join(projectBuildPath, "libwebp-4.dll"))
          os.copyfile("./graphics_dependencies/SDL2_image/lib/x86/zlib1.dll", path.join(projectBuildPath, "zlib1.dll"))
       end
       -- end::windowsDLLCopy[]

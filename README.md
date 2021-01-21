# SGL - Simple Graphics Library

SGL is an object-oriented C++17 graphics library for Windows and Linux. It uses GLFW for window creation and input handling, and OpenGL 3.3 for graphics. Support for both 32-bit and 64-bit OS.

Libraries and tools used:
- glad
- glfw
- glm
- premake
- stb_image

Build for Windows (Visual Studio):
```
dependencies\premake\windows\premake5.exe vs2019
```

Build for Linux (g++ makefile):
```
dependencies/premake/linux/premake gmake
```
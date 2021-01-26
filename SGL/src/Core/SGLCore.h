/**
*
*
*
*/

// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// Precompiled header stuff
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <exception>
#include <cassert>
#include <array>
#include <vector>
#include <map>
#include <variant>
#include <cmath>
#include <algorithm>
#include <type_traits>
// Precompiled header stuff
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#ifndef _SGL_CORE_H_
#define _SGL_CORE_H_

#if defined SGL_PLATFORM_WINDOWS
    #if defined SGL_BUILD_DLL
        #define SGL_API __declspec(dllexport)
    #else
        #define SGL_API __declspec(dllimport)
#endif

#elif defined SGL_PLATFORM_LINUX
    #define SGL_API

#else
    #error Not valid operating system!

#endif

namespace SGL {
    using runtimeError = std::runtime_error;
}


#endif  /* _SGL_CORE_H_ */

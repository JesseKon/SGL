/**
*
*
*
*/

// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// Precompiled header stuff
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <cassert>
#include <array>
#include <vector>
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
    #error No Linux support yet!

#else
    #error Not valid operating system!

#endif

#endif  /* _SGL_CORE_H_ */
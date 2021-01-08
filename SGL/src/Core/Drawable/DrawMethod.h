

#ifndef _SGL_DRAWMETHOD_H_
#define _SGL_DRAWMETHOD_H_

#include "SGLCore.h"

namespace SGL {

    /// <summary>
    /// Drawing methods. 
    /// </summary>
    enum class DrawMethod : GLenum {
        Static = GL_STATIC_DRAW,
        Dynamic = GL_DYNAMIC_DRAW
    };

}

#endif


#ifndef _SGL_DRAWMODE_H_
#define _SGL_DRAWMODE_H_

#include "SGLCore.h"

namespace SGL {

    /// <summary>
    /// Drawing modes.
    /// </summary>
    enum class DrawMode : GLenum {
        Points = GL_POINTS,
        Lines = GL_LINES,
        Triangles = GL_TRIANGLES
    };

}

#endif
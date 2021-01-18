

#ifndef _SGL_DRAWMODE_H_
#define _SGL_DRAWMODE_H_

#include "SGLCore.h"

namespace SGL {

    /// <summary>
    /// Drawing modes.
    /// </summary>
    enum class DrawMode : GLenum {

        /// <summary>
        /// 
        /// </summary>
        Points = GL_POINTS,

        /// <summary>
        /// 
        /// </summary>
        Lines = GL_LINES,

        /// <summary>
        /// 
        /// </summary>
        Triangles = GL_TRIANGLES
    };

}

#endif
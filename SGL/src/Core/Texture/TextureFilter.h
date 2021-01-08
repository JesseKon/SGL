

#ifndef _SGL_TEXTUREFILTER_H_
#define _SGL_TEXTUREFILTER_H_

#include "SGLCore.h"

namespace SGL {

    /// <summary>
    /// 
    /// </summary>
    enum class TextureFilter : GLint {
        Nearest = GL_NEAREST,
        Linear = GL_LINEAR
    };

}

#endif
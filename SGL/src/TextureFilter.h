

#ifndef _SGL_TEXTUREFILTER_H_
#define _SGL_TEXTUREFILTER_H_

#include "SGLCore.h"

namespace SGL {

    /// <summary>
    /// Texture filtering type.
    /// </summary>
    enum class TextureFilter : GLint {

        /// <summary>
        /// Point filtering results in pixelated texture when zoomed in.
        /// </summary>
        Point = GL_NEAREST,

        /// <summary>
        /// Bilinear filtering results in smooth texture when zoomed in.
        /// </summary>
        Bilinear = GL_LINEAR,

        /// <summary>
        /// Trilinear filtering results in bilinear interpolation between mipmaps.
        /// </summary>
        Trilinear = GL_LINEAR_MIPMAP_LINEAR
    };

}

#endif
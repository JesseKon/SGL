

#ifndef _SGL_TEXTUREUNIT_H_
#define _SGL_TEXTUREUNIT_H_

#include "SGLCore.h"

namespace SGL {

    struct TextureUnit {
        SGL_API static const decltype(GL_TEXTURE0) Texture0;
        SGL_API static const decltype(GL_TEXTURE1) Texture1;
        SGL_API static const decltype(GL_TEXTURE2) Texture2;
        SGL_API static const decltype(GL_TEXTURE3) Texture3;
        SGL_API static const decltype(GL_TEXTURE4) Texture4;
        SGL_API static const decltype(GL_TEXTURE5) Texture5;
        SGL_API static const decltype(GL_TEXTURE6) Texture6;
        SGL_API static const decltype(GL_TEXTURE7) Texture7;
        SGL_API static const decltype(GL_TEXTURE8) Texture8;
        SGL_API static const decltype(GL_TEXTURE9) Texture9;
        SGL_API static const decltype(GL_TEXTURE10) Texture10;
        SGL_API static const decltype(GL_TEXTURE11) Texture11;
        SGL_API static const decltype(GL_TEXTURE12) Texture12;
        SGL_API static const decltype(GL_TEXTURE13) Texture13;
        SGL_API static const decltype(GL_TEXTURE14) Texture14;
        SGL_API static const decltype(GL_TEXTURE15) Texture15;

        using type = decltype(GL_TEXTURE0);
    };

}  /* namespace SGL */

#endif  /* _SGL_TEXTUREUNIT_H_ */
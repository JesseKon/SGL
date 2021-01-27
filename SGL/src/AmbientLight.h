

#ifndef _SGL_AMBIENT_LIGHT_H_
#define _SGL_AMBIENT_LIGHT_H_

#include "SGLCore.h"
#include "Camera.h"

namespace SGL {

    class AmbientLight
    {
    public:

        SGL_API AmbientLight(
            const Color& color
        );


        SGL_API ~AmbientLight(
        ) noexcept;


        auto SGL_API getAmbientLightColor(
        ) const noexcept -> const Color&;


    private:
        Color m_AmbientLightColor;
    };

}

#endif

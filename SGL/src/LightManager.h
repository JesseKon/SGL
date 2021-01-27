

#ifndef _SGL_LIGHT_MANAGER_H_
#define _SGL_LIGHT_MANAGER_H_

#include "SGLCore.h"
#include "Color.h"
#include "AmbientLight.h"

namespace SGL {

    class LightManager
    {
    public:

        SGL_API LightManager(
        );


        SGL_API ~LightManager(
        ) noexcept;


        auto SGL_API addAmbientLight(
            const AmbientLight* ambientLight
        ) noexcept -> void;


        auto SGL_API getAmbientLightColor(
        ) const noexcept -> const Color&;

    private:
        const AmbientLight* m_pAmbientLight;

    };

}

#endif
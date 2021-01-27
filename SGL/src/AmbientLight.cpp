

#include "AmbientLight.h"

namespace SGL {

    AmbientLight::AmbientLight(
        const Color& color
    ) {
        m_AmbientLightColor = color;
    }


    AmbientLight::~AmbientLight(
    ) noexcept {
        
    }


    auto AmbientLight::getAmbientLightColor(
    ) const noexcept -> const Color& {
        return m_AmbientLightColor;
    }


}
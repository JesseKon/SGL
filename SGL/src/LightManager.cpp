

#include "LightManager.h"

namespace SGL {

    LightManager::LightManager(
    ) {
        
    }


    LightManager::~LightManager(
    ) noexcept {

    }


    auto LightManager::addAmbientLight(
        const AmbientLight* ambientLight
    ) noexcept -> void {
        // TODO: placeholder if there is no ambient light
        m_pAmbientLight = ambientLight;
    }


    auto LightManager::getAmbientLightColor(
    ) const noexcept -> const Color& {
        return m_pAmbientLight->getAmbientLightColor();
    }

}
/**
*
*
*
*/

#include "sglpch.h"
#include "Color.h"

namespace SGL {

    /* ***************************************************************************************** */
    Color::Color() noexcept
    {
        m_Red = m_Green = m_Blue = 0;
        m_Alpha = 255;
    }


    /* ***************************************************************************************** */
    Color::Color(
        const std::uint8_t red,
        const std::uint8_t green,
        const std::uint8_t blue,
        const std::uint8_t alpha
    ) noexcept {
        m_Red = red;
        m_Green = green;
        m_Blue = blue;
        m_Alpha = alpha;
    };


    /* ***************************************************************************************** */
    Color::Color(
        const Color& param
    ) noexcept {
        m_Red = param.getRed();
        m_Green = param.getGreen();
        m_Blue = param.getBlue();
        m_Alpha = param.getAlpha();
    }


    /* ***************************************************************************************** */
    Color::~Color()
    {

    }


    /* ***************************************************************************************** */
    // Some predefined colors
    namespace COLOR {
        const Color Black(0, 0, 0, 255);
        const Color White(255, 255, 255, 255);
        const Color Red(255, 0, 0, 255);
        const Color Lime(0, 255, 0, 255);
        const Color Blue(0, 0, 255, 255);
        const Color Yellow(255, 255, 0, 255);
        const Color Cyan(0, 255, 255, 255);
        const Color Magenta(255, 0, 255, 255);
        const Color Silver(192, 192, 192, 255);
        const Color Gray(128, 128, 128, 255);
        const Color Maroon(128, 0, 0, 255);
        const Color Olive(128, 128, 0, 255);
        const Color Green(0, 128, 0, 255);
        const Color Purple(128, 0, 128, 255);
        const Color Teal(0, 128, 128, 255);
        const Color Navy(0, 0, 128, 255);
    }

}
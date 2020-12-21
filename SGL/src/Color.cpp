/**
*
*
*
*/

#include "sglpch.h"
#include "Color.h"

namespace SGL {

    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors and destructor
    ///////////////////////////////////////////////////////////////////////////////////////////////

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


    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Predefined colors
    ///////////////////////////////////////////////////////////////////////////////////////////////

    namespace COLOR {
        Color Black(0, 0, 0, 255);
        Color White(255, 255, 255, 255);
        Color Red(255, 0, 0, 255);
        Color Lime(0, 255, 0, 255);
        Color Blue(0, 0, 255, 255);
        Color Yellow(255, 255, 0, 255);
        Color Cyan(0, 255, 255, 255);
        Color Magenta(255, 0, 255, 255);
        Color Silver(192, 192, 192, 255);
        Color Gray(128, 128, 128, 255);
        Color Maroon(128, 0, 0, 255);
        Color Olive(128, 128, 0, 255);
        Color Green(0, 128, 0, 255);
        Color Purple(128, 0, 128, 255);
        Color Teal(0, 128, 128, 255);
        Color Navy(0, 0, 128, 255);
    }

}
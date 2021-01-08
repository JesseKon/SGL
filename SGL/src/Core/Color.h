/**
 *
 *
 *
 */

#ifndef _SGL_COLOR_
#define _SGL_COLOR_

#include <SGLCore.h>
#include <limits>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


namespace SGL {

    class Color
    {
    public:

        /*! @brief Default constructor that creates black color.
        * 
        */
        SGL_API Color(
        ) noexcept;


        /*! @brief Creates new color with given color components.
        *
        */
        SGL_API Color(
            const std::uint8_t red,
            const std::uint8_t green,
            const std::uint8_t blue,
            const std::uint8_t alpha = 255
        ) noexcept;


        /*! @brief Copy constructor that copies the Color given as param.
        * 
        */
        SGL_API Color(
            const Color& param
        ) noexcept;


        /**
         * Destructor.
         */
        SGL_API ~Color(
        );


        /*! @brief Sets the red component of the color.
        * 
        *   @param newRed The new red component value.
        * 
        *   @return Nothing.
        */
        SGL_API inline auto setRed(
            const std::uint8_t newRed
        ) noexcept -> void {
            m_Red = newRed;
        }


        /*! @brief Returns the red component of the color.
        * 
        *   @return The red component.
        */
        SGL_API inline auto getRed(
        ) const noexcept -> std::uint8_t {
            return m_Red;
        }


        /*! @brief Returns the red component of the color normalized to type T.
        * 
        *   @return The red component normalized to type T.
        */
        template <typename T>
        SGL_API inline auto getRedf(
        ) const noexcept -> T {
            return static_cast<T>(m_Red) / std::numeric_limits<decltype(m_Red)>::max();
        }


        /*! @brief Sets the green component of the color.
        *
        *   @param newRed The new red component value.
        *
        *   @return Nothing.
        */
        SGL_API inline auto setGreen(
            const std::uint8_t newGreen
        ) noexcept -> void {
            m_Green = newGreen;
        }


        /*! @brief Returns the green component of the color.
        *
        *   @return The green component.
        */
        SGL_API inline auto getGreen(
        ) const noexcept -> std::uint8_t {
            return m_Green;
        }


        /*! @brief Returns the green component of the color normalized to type T.
        *
        *   @return The green component normalized to type T.
        */
        template <typename T>
        SGL_API inline auto getGreenf(
        ) const noexcept -> T {
            return static_cast<T>(m_Green) / std::numeric_limits<decltype(m_Green)>::max();
        }


        /*! @brief Sets the blue component of the color.
        *
        *   @param newRed The new blue component value.
        *
        *   @return Nothing.
        */
        SGL_API inline auto setBlue(
            const std::uint8_t newBlue
        ) noexcept -> void {
            m_Blue = newBlue;
        }

        /*! @brief Returns the blue component of the color.
        *
        *   @return The blue component.
        */
        SGL_API inline auto getBlue(
        ) const noexcept -> std::uint8_t {
            return m_Blue;
        }


        /*! @brief Returns the blue component of the color normalized to type T.
        *
        *   @return The blue component normalized to type T.
        */
        template <typename T>
        SGL_API inline auto getBluef(
        ) const noexcept -> T {
            return static_cast<T>(m_Blue) / std::numeric_limits<decltype(m_Blue)>::max();
        }


        /*! @brief Sets the alpha component of the color.
        *
        *   @param newRed The new alpha component value.
        *
        *   @return Nothing.
        */
        SGL_API inline auto setAlpha(
            const std::uint8_t newAlpha
        ) noexcept -> void {
            m_Alpha = newAlpha;
        }


        /*! @brief Returns the alpha component of the color.
        *
        *   @return The alpha component.
        */
        SGL_API inline auto getAlpha(
        ) const noexcept -> std::uint8_t {
            return m_Alpha;
        }


        /*! @brief Returns the alpha component of the color normalized to type T.
        *
        *   @return The alpha component normalized to type T.
        */
        template <typename T>
        SGL_API inline auto getAlphaf(
        ) const noexcept -> T {
            return static_cast<T>(m_Alpha) / std::numeric_limits<decltype(m_Alpha)>::max();
        }


        SGL_API inline auto toVec4(
        ) noexcept -> glm::vec4 {
            glm::vec4 vector = { getRedf<float>(), getGreenf<float>(), getBluef<float>(), getAlphaf<float>() };
            return vector;
        };


    private:
        std::uint8_t m_Red, m_Green, m_Blue, m_Alpha;

    };


    // Predefined colors
    namespace COLOR {
        extern SGL_API Color Black;
        extern SGL_API Color White;
        extern SGL_API Color Red;
        extern SGL_API Color Lime;
        extern SGL_API Color Blue;
        extern SGL_API Color Yellow;
        extern SGL_API Color Cyan;
        extern SGL_API Color Magenta;
        extern SGL_API Color Silver;
        extern SGL_API Color Gray;
        extern SGL_API Color Maroon;
        extern SGL_API Color Olive;
        extern SGL_API Color Green;
        extern SGL_API Color Purple;
        extern SGL_API Color Teal;
        extern SGL_API Color Navy;
    }

}  /* namespace SGL */

#endif  /* _SGL_COLOR_ */
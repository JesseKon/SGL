/**
*
*
*
*/

#ifndef _SGL_COLOR_
#define _SGL_COLOR_

#include <SGLCore.h>
#include <limits>

namespace SGL {

    class SGL_API Color
    {
    public:

        /*! @brief Default constructor that creates black color.
        * 
        */
        Color(
        ) noexcept;


        /*! @brief Creates new color with given color components.
        *
        */
        Color(
            const std::uint8_t red,
            const std::uint8_t green,
            const std::uint8_t blue,
            const std::uint8_t alpha = 255
        ) noexcept;


        /*! @brief Copy constructor that copies the Color given as param.
        * 
        */
        Color(
            const Color& param
        ) noexcept;


        ~Color(
        );


        /*! @brief Sets the red component of the color.
        * 
        *   @param newRed The new red component value.
        * 
        *   @return Nothing.
        */
        inline auto setRed(
            const std::uint8_t newRed
        ) noexcept -> void {
            m_Red = newRed;
        }


        /*! @brief Returns the red component of the color.
        * 
        *   @return The red component.
        */
        inline auto getRed(
        ) const noexcept -> std::uint8_t {
            return m_Red;
        }


        /*! @brief Returns the red component of the color normalized to type T.
        * 
        *   @return The red component normalized to type T.
        */
        template <typename T>
        inline auto getRedf(
        ) const noexcept -> T {
            return static_cast<T>(m_Red) / std::numeric_limits<decltype(m_Red)>::max();
        }


        /*! @brief Sets the green component of the color.
        *
        *   @param newRed The new red component value.
        *
        *   @return Nothing.
        */
        inline auto setGreen(
            const std::uint8_t newGreen
        ) noexcept -> void {
            m_Green = newGreen;
        }


        /*! @brief Returns the green component of the color.
        *
        *   @return The green component.
        */
        inline auto getGreen(
        ) const noexcept -> std::uint8_t {
            return m_Green;
        }


        /*! @brief Returns the green component of the color normalized to type T.
        *
        *   @return The green component normalized to type T.
        */
        template <typename T>
        inline auto getGreenf(
        ) const noexcept -> T {
            return static_cast<T>(m_Green) / std::numeric_limits<decltype(m_Green)>::max();
        }


        /*! @brief Sets the blue component of the color.
        *
        *   @param newRed The new blue component value.
        *
        *   @return Nothing.
        */
        inline auto setBlue(
            const std::uint8_t newBlue
        ) noexcept -> void {
            m_Blue = newBlue;
        }

        /*! @brief Returns the blue component of the color.
        *
        *   @return The blue component.
        */
        inline auto getBlue(
        ) const noexcept -> std::uint8_t {
            return m_Blue;
        }


        /*! @brief Returns the blue component of the color normalized to type T.
        *
        *   @return The blue component normalized to type T.
        */
        template <typename T>
        inline auto getBluef(
        ) const noexcept -> T {
            return static_cast<T>(m_Blue) / std::numeric_limits<decltype(m_Blue)>::max();
        }


        /*! @brief Sets the alpha component of the color.
        *
        *   @param newRed The new alpha component value.
        *
        *   @return Nothing.
        */
        inline auto setAlpha(
            const std::uint8_t newAlpha
        ) noexcept -> void {
            m_Alpha = newAlpha;
        }


        /*! @brief Returns the alpha component of the color.
        *
        *   @return The alpha component.
        */
        inline auto getAlpha(
        ) const noexcept -> std::uint8_t {
            return m_Alpha;
        }


        /*! @brief Returns the alpha component of the color normalized to type T.
        *
        *   @return The alpha component normalized to type T.
        */
        template <typename T>
        inline auto getAlphaf(
        ) const noexcept -> T {
            return static_cast<T>(m_Alpha) / std::numeric_limits<decltype(m_Alpha)>::max();
        }


    private:
        std::uint8_t m_Red, m_Green, m_Blue, m_Alpha;

    };


    // Some predefined colors
    namespace COLOR {
        extern const SGL_API Color Black;
        extern const SGL_API Color White;
        extern const SGL_API Color Red;
        extern const SGL_API Color Lime;
        extern const SGL_API Color Blue;
        extern const SGL_API Color Yellow;
        extern const SGL_API Color Cyan;
        extern const SGL_API Color Magenta;
        extern const SGL_API Color Silver;
        extern const SGL_API Color Gray;
        extern const SGL_API Color Maroon;
        extern const SGL_API Color Olive;
        extern const SGL_API Color Green;
        extern const SGL_API Color Purple;
        extern const SGL_API Color Teal;
        extern const SGL_API Color Navy;
    }

}  /* namespace SGL */

#endif  /* _SGL_COLOR_ */
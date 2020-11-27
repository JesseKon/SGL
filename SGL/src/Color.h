

#ifndef _SGL_COLOR_
#define _SGL_COLOR_

#include <SGLCore.h>


namespace SGL {

    class SGL_API Color
    {
    public:

        /**
        * 
        */
        Color(
        );


        /**
        *
        */
        Color(
            const std::uint8_t red,
            const std::uint8_t green,
            const std::uint8_t blue,
            const std::uint8_t alpha
        );


        /**
        *
        */
        ~Color(
        );


        /**
        *
        */
        inline auto setRed(const std::uint8_t newRed) noexcept -> void {
            m_Red = newRed;
        }


        /**
        * 
        */
        inline auto getRed() const noexcept -> std::uint8_t {
            return m_Red;
        }


        /**
        *
        */
        inline auto setGreen(const std::uint8_t newGreen) noexcept -> void {
            m_Green = newGreen;
        }


        /**
        *
        */
        inline auto getGreen() const noexcept -> std::uint8_t {
            return m_Green;
        }


        /**
        *
        */
        inline auto setBlue(const std::uint8_t newBlue) noexcept -> void {
            m_Blue = newBlue;
        }

        /**
        *
        */
        inline auto getBlue() const noexcept -> std::uint8_t {
            return m_Blue;
        }


        /**
        *
        */
        inline auto setAlpha(const std::uint8_t newAlpha) noexcept -> void {
            m_Alpha = newAlpha;
        }


        /**
        *
        */
        inline auto getAlpha() const noexcept -> std::uint8_t {
            return m_Alpha;
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
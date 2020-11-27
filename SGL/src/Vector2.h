/**
*
*
*
*/

#ifndef _SGL_VECTOR2_H_
#define _SGL_VECTOR2_H_

#include <type_traits>
#include <string>


namespace SGL {

    template <typename T>
    class Vector2 
    {
        static_assert(std::is_arithmetic<T>::value, "Vector2 has to be an arithmetic type.");

    public:

        /*! @brief Default constructor that creates Vector2<T>(0, 0).
        *
        */
        Vector2(
        ) noexcept : m_X(0), m_Y(0) {}


        /*! @brief Constructor that creates Vector2<T>(x, y).
        *
        */
        Vector2(
            T x,
            T y
        ) noexcept : m_X(x), m_Y(y) {}


        /*! @brief Copy constructor that copies the Vector2<T> given as param.
        *
        */
        Vector2(
            const Vector2<T>& param
        ) noexcept : m_X(param.m_X), m_Y(param.m_Y) {}


        ~Vector2(
        ) {}


        /*! @brief Static Vector2 method that returns Vector2<T>(0, 0).
        *
        *   @return Vector2<T>(0, 0)
        */
        auto static zero(
        ) noexcept -> Vector2<T> {
            static Vector2 v(0, 0);
            return v;
        }


        /*! @brief Static Vector2 method that returns Vector2<T>(1, 1).
        *
        *   @return Vector2<T>(1, 1)
        */
        auto static one(
        ) noexcept -> Vector2<T> {
            static Vector2 v(1, 1);
            return v;
        }


        /*! @brief Static Vector2 method that returns Vector2<T>(-1, 0).
        *
        *   @return Vector2<T>(-1, 0)
        */
        auto static left(
        ) noexcept -> Vector2<T> {
            static Vector2 v(-1, 0);
            return v;
        }


        /*! @brief Static Vector2 method that returns Vector2<T>(1, 0).
        *
        *   @return Vector2<T>(1, 0)
        */
        auto static right(
        ) noexcept -> Vector2<T> {
            static Vector2 v(1, 0);
            return v;
        }


        /*! @brief Static Vector2 method that returns Vector2<T>(0, 1).
        *
        *   @return Vector2<T>(0, 1)
        */
        auto static up(
        ) noexcept -> Vector2<T> {
            static Vector2 v(0, 1);
            return v;
        }


        /*! @brief Static Vector2 method that returns Vector2<T>(0, -1).
        *
        *   @return Vector2<T>(0, -1)
        */
        auto static down(
        ) noexcept -> Vector2<T> {
            static Vector2 v(0, -1);
            return v;
        }


        /*! @brief
        *
        */
        auto operator=(
            const Vector2<T>& param
        ) noexcept -> Vector2<T> {
            m_X = param.m_X; m_Y = param.m_Y;
            return *this;
        }


        /*! @brief
        *
        */
        auto operator+(
            const Vector2<T>& param
        ) noexcept -> Vector2<T> {
            Vector2<T> temp(m_X + param.m_X, m_Y + param.m_Y);
            return temp;
        }


        /*! @brief
        *
        */
        auto operator+=(
            const Vector2<T>& param
        ) noexcept -> Vector2<T> {
            m_X += param.m_X; m_Y += param.m_Y;
            return *this;
        }


        /*! @brief
        *
        */
        auto operator-(
            const Vector2<T>& param
        ) noexcept -> Vector2<T> {
            Vector2<T> temp(m_X - param.m_X, m_Y - param.m_Y);
            return temp;
        }


        /*! @brief
        *
        */
        auto operator-=(
            const Vector2<T>& param
        ) noexcept -> Vector2<T> {
            m_X -= param.m_X; m_Y -= param.m_Y;
            return *this;
        }


        /*! @brief
        *
        */
        auto operator*(
            const T param
        ) noexcept -> Vector2<T> {
            Vector2 temp(m_X * param, m_Y * param);
            return temp;
        }


        /*! @brief
        *
        */
        auto operator*=(
            const T param
        ) noexcept -> Vector2<T> {
            m_X *= param; m_Y *= param;
            return *this;
        }


        /*! @brief
        *
        */
        auto operator/(
            const T param
        ) noexcept -> Vector2<T> {
            Vector2 temp(m_X / param, m_Y / param);
            return temp;
        }


        /*! @brief
        *
        */
        auto operator/=(
            const T param
        ) noexcept -> Vector2<T> {
            m_X /= param; m_Y /= param;
            return *this;
        }


        /*! @brief
        *
        */
        auto friend operator==(
            const Vector2<T>& lhs,
            const Vector2<T>& rhs
        ) noexcept -> bool {
            return lhs.m_X == rhs.m_Y && lhs.m_Y == rhs.m_Y;
        }


        /*! @brief
        *
        */
        auto friend operator!=(
            const Vector2<T>& lhs,
            const Vector2<T>& rhs
        ) noexcept -> bool {
            return !(lhs.m_X == rhs.m_Y && lhs.m_Y == rhs.m_Y);
        }


        /*! @brief
        *
        */
        auto setX(
            T newX
        ) noexcept -> void {
            m_X = newX;
        }


        /*! @brief
        *
        */
        auto getX(
        ) const noexcept -> T {
            return m_X;
        }


        /*! @brief
        *
        */
        auto setY(
            T newY
        ) noexcept -> void {
            m_Y = newY;
        }


        /*! @brief
        *
        */
        auto getY(
        ) const noexcept -> T {
            return m_Y;
        }


        /*! @brief
        *
        */
        auto magnitude(
        ) const noexcept -> T {
            return static_cast<T>(std::sqrt(m_X * m_X + m_Y * m_Y));
        }


        /*! @brief
        *
        */
        auto normalize(
        ) noexcept -> void {
            m_X /= magnitude();
            m_Y /= magnitude();
        }


        /*! @brief
        *
        */
        auto normalized(
        ) const noexcept -> Vector2<T> {
            Vector2<T> temp(m_X / magnitude(), m_Y / magnitude());
            return temp;
        }


        /*! @brief
        *
        */
        auto distance(
            const Vector2<T>& param
        ) const noexcept -> T {
            return (*this - param).magnitude();
        }


        /*! @brief
        *
        */
        auto toString(
        ) -> std::string {
            std::string str;
            str.append("[");
            str.append(std::to_string(m_X));
            str.append(", ");
            str.append(std::to_string(m_Y));
            str.append("]");
            return str;
        }


    private:
        T m_X, m_Y;

    };

}  /* namespace SGL */

#endif  /* SGL_VECTOR2_H_ */
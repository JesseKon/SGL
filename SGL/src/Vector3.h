/**
*
*
*
*/

#ifndef _SGL_VECTOR3_H_
#define _SGL_VECTOR3_H_

#include <type_traits>
#include <string>


namespace SGL {

    template <typename T>
    class Vector3
    {
        static_assert(std::is_arithmetic<T>::value, "Vector3 has to be an arithmetic type.");

    public:

        /*! @brief Default constructor that creates Vector3<T>(0, 0, 0).
        *
        */
        Vector3(
        ) noexcept : m_X(0), m_Y(0), m_Z(0) {}


        /*! @brief Constructor that creates Vector3<T>(x, y, z).
        *
        */
        Vector3(
            T x,
            T y,
            T z
        ) noexcept : m_X(x), m_Y(y), m_Z(z) {}


        /*! @brief Copy constructor that copies the Vector3<T> given as param.
        *
        */
        Vector3(
            const Vector3<T>& param
        ) noexcept : m_X(param.m_X), m_Y(param.m_Y), m_Z(param.m_Z) {}


        ~Vector3(
        ) {}


        /*! @brief Static Vector3 method that returns Vector3<T>(0, 0, 0).
        *
        *   @return Vector3<T>(0, 0, 0)
        */
        auto static zero(
        ) noexcept -> Vector3<T> {
            static Vector3 v(static_cast<T>(0), static_cast<T>(0), static_cast<T>(0));
            return v;
        }


        /*! @brief Static Vector3 method that returns Vector3<T>(1, 1, 1).
        *
        *   @return Vector3<T>(1, 1, 1)
        */
        auto static one(
        ) noexcept -> Vector3<T> {
            static Vector3 v(static_cast<T>(1), static_cast<T>(1), static_cast<T>(1));
            return v;
        }


        /*! @brief Static Vector3 method that returns Vector3<T>(-1, 0, 0).
        *
        *   @return Vector3<T>(-1, 0, 0)
        */
        auto static left(
        ) noexcept -> Vector3<T> {
            static Vector3 v(static_cast<T>(-1), static_cast<T>(0), static_cast<T>(0));
            return v;
        }


        /*! @brief Static Vector3 method that returns Vector3<T>(1, 0, 0).
        *
        *   @return Vector3<T>(1, 0, 0)
        */
        auto static right(
        ) noexcept -> Vector3<T> {
            static Vector3 v(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0));
            return v;
        }


        /*! @brief Static Vector3 method that returns Vector3<T>(0, 1, 0).
        *
        *   @return Vector3<T>(0, 1, 0)
        */
        auto static up(
        ) noexcept -> Vector3<T> {
            static Vector3 v(static_cast<T>(0), static_cast<T>(1), static_cast<T>(0));
            return v;
        }


        /*! @brief Static Vector3 method that returns Vector3<T>(0, -1, 0).
        *
        *   @return Vector3<T>(1, 1, 1)
        */
        auto static down(
        ) noexcept -> Vector3<T> {
            static Vector3 v(static_cast<T>(0), static_cast<T>(-1), static_cast<T>(0));
            return v;
        }


        /*! @brief Static Vector3 method that returns Vector3<T>(0, 0, 1).
        *
        *   @return Vector3<T>(0, 0, 1)
        */
        auto static forward(
        ) noexcept -> Vector3<T> {
            static Vector3 v(static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));
            return v;
        }


        /*! @brief Static Vector3 method that returns Vector3<T>(0, 0, -1).
        *
        *   @return Vector3<T>(0, 0, -1)
        */
        auto static back(
        ) noexcept -> Vector3<T> {
            static Vector3 v(static_cast<T>(0), static_cast<T>(0), static_cast<T>(-1));
            return v;
        }


        /*! @brief
        * 
        */
        auto operator=(
            const Vector3<T>& param
        ) noexcept -> Vector3<T> {
            m_X = param.m_X; m_Y = param.m_Y; m_Z = param.m_Z;
            return *this;
        }


        /*! @brief
        *
        */
        auto operator+(
            const Vector3<T>& param
        ) noexcept -> Vector3<T> {
            Vector3<T> temp(m_X + param.m_X, m_Y + param.m_Y, m_Z + param.m_Z);
            return temp;
        }


        /*! @brief
        *
        */
        auto operator+=(
            const Vector3<T>& param
        ) noexcept -> Vector3<T> {
            m_X += param.m_X; m_Y += param.m_Y; m_Z += param.m_Z;
            return *this;
        }


        /*! @brief
        *
        */
        auto operator-(
            const Vector3<T>& param
        ) noexcept -> Vector3<T> {
            Vector3<T> temp(m_X - param.m_X, m_Y - param.m_Y, m_Z - param.m_Z);
            return temp;
        }


        /*! @brief
        *
        */
        auto operator-=(
            const Vector3<T>& param
        ) noexcept -> Vector3<T> {
            m_X -= param.m_X; m_Y -= param.m_Y; m_Z -= param.m_Z;
            return *this;
        }


        /*! @brief
        *
        */
        auto operator*(
            const T param
        ) noexcept -> Vector3<T> {
            Vector3 temp(m_X * param, m_Y * param, m_Z * param);
            return temp;
        }

        
        /*! @brief
        *
        */
        auto operator*=(
            const T param
        ) noexcept -> Vector3<T> {
            m_X *= param; m_Y *= param; m_Z *= param;
            return *this;
        }


        /*! @brief
        *
        */
        auto operator/(
            const T param
        ) noexcept -> Vector3<T> {
            Vector3 temp(m_X / param, m_Y / param, m_Z / param);
            return temp;
        }


        /*! @brief
        *
        */
        auto operator/=(
            const T param
        ) noexcept -> Vector3<T> {
            m_X /= param; m_Y /= param; m_Z /= param;
            return *this;
        }


        /*! @brief
        *
        */
        auto friend operator==(
            const Vector3<T>& lhs,
            const Vector3<T>& rhs
        ) noexcept -> bool {
            return lhs.m_X == rhs.m_X && lhs.m_Y == rhs.m_Y && lhs.m_Z == rhs.m_Z;
        }


        /*! @brief
        *
        */
        auto friend operator!=(
            const Vector3<T>& lhs,
            const Vector3<T>& rhs
        ) noexcept -> bool {
            return !(lhs.m_X == rhs.m_X && lhs.m_Y == rhs.m_Y && lhs.m_Z == rhs.m_Z);
        }


        /*! @brief
        *
        */
        auto setX(
            T newX
        ) noexcept -> void{
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
        auto setZ(
            T newZ
        ) noexcept -> void {
            m_Z = newZ;
        }


        /*! @brief
        *
        */
        auto getZ(
        ) const noexcept -> T {
            return m_Z;
        }


        /*! @brief
        *
        */
        auto magnitude(
        ) noexcept -> T {
            return static_cast<T>(std::sqrt(m_X * m_X + m_Y * m_Y + m_Z * m_Z));
        }


        /*! @brief
        *
        */
        auto normalize(
        ) noexcept -> void {
            m_X /= magnitude();
            m_Y /= magnitude();
            m_Z /= magnitude();
        }


        /*! @brief
        *
        */
        auto normalized(
        ) const noexcept -> Vector3<T> {
            Vector3<T> temp(m_X / magnitude(), m_Y / magnitude(), m_Z / magnitude());
            return temp;
        }


        /*! @brief
        *
        */
        auto distance(
            const Vector3<T>& param
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
            str.append(", ");
            str.append(std::to_string(m_Z));
            str.append("]");
            return str;
        }


    private:
        T m_X, m_Y, m_Z;

    };

}  /* namespace SGL */

#endif  /* _SGL_VECTOR3_H_ */
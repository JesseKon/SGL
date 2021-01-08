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

        T x, y, z;

        /*! @brief Default constructor that creates Vector3<T>(0, 0, 0).
        *
        */
        Vector3(
        ) noexcept : x(0), y(0), z(0) {}


        /*! @brief Constructor that creates Vector3<T>(x, y, z).
        *
        */
        Vector3(
            T x_,
            T y_,
            T z_
        ) noexcept : x(x_), y(y_), z(z_) {}


        /*! @brief Copy constructor.
        *
        */
        Vector3(
            const Vector3<T>& param
        ) noexcept : x(param.x), y(param.y), z(param.z) {}


        /**
         * Destructor.
         */
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
            x = param.x; y = param.y; z = param.z;
            return *this;
        }


        /*! @brief
        *
        */
        auto operator+(
            const Vector3<T>& param
        ) noexcept -> Vector3<T> {
            Vector3<T> temp(x + param.x, y + param.y, z + param.z);
            return temp;
        }


        /*! @brief
        *
        */
        auto operator+=(
            const Vector3<T>& param
        ) noexcept -> Vector3<T> {
            x += param.x; y += param.y; z += param.z;
            return *this;
        }


        /*! @brief
        *
        */
        auto operator-(
            const Vector3<T>& param
        ) noexcept -> Vector3<T> {
            Vector3<T> temp(x - param.x, y - param.y, z - param.z);
            return temp;
        }


        /*! @brief
        *
        */
        auto operator-=(
            const Vector3<T>& param
        ) noexcept -> Vector3<T> {
            x -= param.x; y -= param.y; z -= param.z;
            return *this;
        }


        /*! @brief
        *
        */
        auto operator*(
            const T param
        ) noexcept -> Vector3<T> {
            Vector3 temp(x * param, y * param, z * param);
            return temp;
        }

        
        /*! @brief
        *
        */
        auto operator*=(
            const T param
        ) noexcept -> Vector3<T> {
            x *= param; y *= param; z *= param;
            return *this;
        }


        /*! @brief
        *
        */
        auto operator/(
            const T param
        ) noexcept -> Vector3<T> {
            Vector3 temp(x / param, y / param, z / param);
            return temp;
        }


        /*! @brief
        *
        */
        auto operator/=(
            const T param
        ) noexcept -> Vector3<T> {
            x /= param; y /= param; z /= param;
            return *this;
        }


        /*! @brief
        *
        */
        auto friend operator==(
            const Vector3<T>& lhs,
            const Vector3<T>& rhs
        ) noexcept -> bool {
            return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
        }


        /*! @brief
        *
        */
        auto friend operator!=(
            const Vector3<T>& lhs,
            const Vector3<T>& rhs
        ) noexcept -> bool {
            return !(lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z);
        }


        /*! @brief
        *
        */
        auto magnitude(
        ) noexcept -> T {
            return static_cast<T>(std::sqrt(x * x + y * y + z * z));
        }


        /*! @brief
        *
        */
        auto normalize(
        ) noexcept -> void {
            x /= magnitude();
            y /= magnitude();
            z /= magnitude();
        }


        /*! @brief
        *
        */
        auto normalized(
        ) const noexcept -> Vector3<T> {
            Vector3<T> temp(x / magnitude(), y / magnitude(), z / magnitude());
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
            str.append(std::to_string(x));
            str.append(", ");
            str.append(std::to_string(y));
            str.append(", ");
            str.append(std::to_string(z));
            str.append("]");
            return str;
        }

    };

}  /* namespace SGL */

#endif  /* _SGL_VECTOR3_H_ */
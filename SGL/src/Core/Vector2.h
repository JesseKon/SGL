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

        T x, y;

        /*! @brief Default constructor that creates Vector2<T>(0, 0).
        *
        */
        Vector2(
        ) noexcept : x(0), y(0) {}


        /*! @brief Constructor that creates Vector2<T>(x, y).
        *
        */
        Vector2(
            T x_,
            T y_
        ) noexcept : x(x_), y(y_) {}


        /*! @brief Copy constructor.
        *
        */
        Vector2(
            const Vector2<T>& param
        ) noexcept : x(param.x), y(param.y) {}


        /**
         * Destructor.
         */
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
            x = param.x; y = param.y;
            return *this;
        }


        /*! @brief
        *
        */
        auto operator+(
            const Vector2<T>& param
        ) noexcept -> Vector2<T> {
            Vector2<T> temp(x + param.x, y + param.y);
            return temp;
        }


        /*! @brief
        *
        */
        auto operator+=(
            const Vector2<T>& param
        ) noexcept -> Vector2<T> {
            x += param.x; y += param.y;
            return *this;
        }


        /*! @brief
        *
        */
        auto operator-(
            const Vector2<T>& param
        ) noexcept -> Vector2<T> {
            Vector2<T> temp(x - param.x, y - param.y);
            return temp;
        }


        /*! @brief
        *
        */
        auto operator-=(
            const Vector2<T>& param
        ) noexcept -> Vector2<T> {
            x -= param.x; y -= param.y;
            return *this;
        }


        /*! @brief
        *
        */
        auto operator*(
            const T param
        ) noexcept -> Vector2<T> {
            Vector2 temp(x * param, y * param);
            return temp;
        }


        /*! @brief
        *
        */
        auto operator*=(
            const T param
        ) noexcept -> Vector2<T> {
            x *= param; y *= param;
            return *this;
        }


        /*! @brief
        *
        */
        auto operator/(
            const T param
        ) noexcept -> Vector2<T> {
            Vector2 temp(x / param, y / param);
            return temp;
        }


        /*! @brief
        *
        */
        auto operator/=(
            const T param
        ) noexcept -> Vector2<T> {
            x /= param; y /= param;
            return *this;
        }


        /*! @brief
        *
        */
        auto friend operator==(
            const Vector2<T>& lhs,
            const Vector2<T>& rhs
        ) noexcept -> bool {
            return lhs.x == rhs.x && lhs.y == rhs.y;
        }


        /*! @brief
        *
        */
        auto friend operator!=(
            const Vector2<T>& lhs,
            const Vector2<T>& rhs
        ) noexcept -> bool {
            return !(lhs.x == rhs.x && lhs.y == rhs.y);
        }


        /*! @brief
        *
        */
        auto magnitude(
        ) const noexcept -> T {
            return static_cast<T>(std::sqrt(x * x + y * y));
        }


        /*! @brief
        *
        */
        auto normalize(
        ) noexcept -> void {
            x /= magnitude();
            y /= magnitude();
        }


        /*! @brief
        *
        */
        auto normalized(
        ) const noexcept -> Vector2<T> {
            Vector2<T> temp(x / magnitude(), y / magnitude());
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
            str.append(std::to_string(x));
            str.append(", ");
            str.append(std::to_string(y));
            str.append("]");
            return str;
        }

    };

}  /* namespace SGL */

#endif  /* SGL_VECTOR2_H_ */
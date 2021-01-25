

#ifndef _SGL_LINE_H_
#define _SGL_LINE_H_

#include "SGLCore.h"

#include "Camera.h"
#include "Drawable.h"
#include "ShaderGLSL.h"
#include "Color.h"
#include "Vector3.h"
#include "Transform.h"


namespace SGL {

    class Line
    {
    public:

        /// <summary>
        /// Construct a new line.
        /// </summary>
        /// 
        /// <param name="camera">
        /// The desired camera this object should use.
        /// </param>
        /// 
        /// <param name="shader">
        /// The desired shader this object should use.
        /// </param>
        /// 
        /// <param name="p1">
        /// First point location in pixels.
        /// </param>
        /// 
        /// <param name="p2">
        /// Second point location in pixels.
        /// </param>
        /// 
        /// <param name="color">
        /// The desired color in which this object should be drawn.
        /// </param>
        /// 
        /// <param name="setStatic">
        /// Set this line as static. Static objects can not be altered after constructed.
        /// </param>
        SGL_API Line(
            const Camera& camera,
            const ShaderGLSL& shader,
            const Vector3<float>& p1,
            const Vector3<float>& p2,
            const Color& color,
            const bool setStatic = false
        );


        SGL_API ~Line(
        ) noexcept;


        auto SGL_API setPoints(
            const Vector3<float>& p1,
            const Vector3<float>& p2
        ) -> void;


        auto SGL_API draw(
        ) const noexcept -> void;


    private:
        const Camera* m_pCamera;
        const ShaderGLSL* m_pShaderGLSL;
        Drawable m_Drawable;
        Color m_Color;
        bool m_IsStatic;
    };

}

#endif
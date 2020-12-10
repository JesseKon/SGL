/**
*
*
*
*/

#ifndef _SGL_RENDERER_H_
#define _SGL_RENDERER_H_

#include "SGLCore.h"


namespace SGL {

    class Shader
    {
    public:

        /**
         * 
         */
        virtual ~Shader(
        ) = 0 {};


        /**
         * 
         */
        virtual auto setBool(
            const std::string& name,
            const bool value
        ) noexcept -> void = 0;


        /**
         *
         */
        virtual auto setInt32(
            const std::string& name,
            const bool value
        ) noexcept -> void = 0;


        /**
         *
         */
        virtual auto setFloat(
            const std::string& name,
            const bool value
        ) noexcept -> void = 0;



    protected:
        GLuint m_ProgramID;

    };

}  /* namespace SGL */

#endif  /* _SGL_RENDERER_H_ */
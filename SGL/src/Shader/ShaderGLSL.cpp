/**
 *
 *
 *
 */

#include "sglpch.h"
#include "ShaderGLSL.h"

namespace SGL {

    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors and destructor
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /* ***************************************************************************************** */
    ShaderGLSL::ShaderGLSL(
    ) noexcept {
        m_ProgramID = NULL;
    };


    /* ***************************************************************************************** */
    ShaderGLSL::ShaderGLSL(
        const std::string& vertexShaderFile,
        const std::string& fragmentShaderFile
    ) {
        m_ProgramID = NULL;
        create(vertexShaderFile, fragmentShaderFile);
    };


    /* ***************************************************************************************** */
    ShaderGLSL::~ShaderGLSL(
    ) noexcept {
        destroy();
    };


    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Public methods
    ///////////////////////////////////////////////////////////////////////////////////////////////

    /* ***************************************************************************************** */
    auto ShaderGLSL::create(
        const std::string& vertexShaderFile,
        const std::string& fragmentShaderFile
    ) -> void {
        std::ifstream vertexFile, fragmentFile;
        std::stringstream vertexFileBuffer, fragmentFileBuffer;
        std::string vertexCode, fragmentCode;

        // Load GLSL source files
        vertexFile.open(vertexShaderFile);
        if (!vertexFile.is_open()) {
            std::stringstream ss;
            ss << ">>> Error > ShaderGLSL::create() > Could not open file \'" << vertexShaderFile << "\'.\n";
            throw std::runtime_error(ss.str());
        }

        fragmentFile.open(fragmentShaderFile);
        if (!fragmentFile.is_open()) {
            std::stringstream ss;
            ss << ">>> Error > ShaderGLSL::create() > Could not open file \'" << fragmentShaderFile << "\'.\n";
            throw std::runtime_error(ss.str());
        }

        vertexFileBuffer << vertexFile.rdbuf();
        fragmentFileBuffer << fragmentFile.rdbuf();

        vertexFile.close();
        fragmentFile.close();

        vertexCode = vertexFileBuffer.str();
        fragmentCode = fragmentFileBuffer.str();

        // Compile shaders
        GLint success;
        const std::uint32_t LOG_BUFFER_SIZE = 512;
        char infoLog[LOG_BUFFER_SIZE];

        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        const GLchar* cVertexCode = vertexCode.c_str();
        glShaderSource(vertexShader, 1, &cVertexCode, nullptr);
        glCompileShader(vertexShader);
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexShader, LOG_BUFFER_SIZE, nullptr, infoLog);
            std::stringstream ss;
            ss << ">>> Error > ShaderGLSL::create() > Could not compile vertex shader: \'" << infoLog << "\'.\n";
            throw std::runtime_error(ss.str());
        }

        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        const GLchar* cFragmentCode = fragmentCode.c_str();
        glShaderSource(fragmentShader, 1, &cFragmentCode, nullptr);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(fragmentShader, LOG_BUFFER_SIZE, nullptr, infoLog);
            std::stringstream ss;
            ss << ">>> Error > ShaderGLSL::create() > Could not compile fragment shader: \'" << infoLog << "\'.\n";
            throw std::runtime_error(ss.str());
        }

        // Create shader program
        m_ProgramID = glCreateProgram();
        glAttachShader(m_ProgramID, vertexShader);
        glAttachShader(m_ProgramID, fragmentShader);
        glLinkProgram(m_ProgramID);
        glGetProgramiv(m_ProgramID, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(fragmentShader, LOG_BUFFER_SIZE, nullptr, infoLog);
            std::stringstream ss;
            ss << ">>> Error > ShaderGLSL::create() > Could not link shader: \'" << infoLog << "\'.\n";
            throw std::runtime_error(ss.str());
        }

        // Cleanup
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

    };


    /* ***************************************************************************************** */
    auto ShaderGLSL::destroy(
    ) noexcept -> void {
        if (m_ProgramID) {
            glDeleteProgram(m_ProgramID);
            m_ProgramID = NULL;
        }
    };


    /* ***************************************************************************************** */
    auto ShaderGLSL::use(
    ) const noexcept -> void {
        glUseProgram(m_ProgramID);
    }
}
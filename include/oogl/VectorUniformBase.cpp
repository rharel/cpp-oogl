#include <oogl/VectorUniformBase.hpp>


namespace oogl
{
    template <unsigned int D, GLsizei N>
    inline void VectorUniformBase<GLint, D, N>::set(const GLint* value)
    {
        switch (D)
        {
            case 1:
                glUniform1iv(location(), N, value);
                break;
            case 2:
                glUniform2iv(location(), N, value);
                break;
            case 3:
                glUniform3iv(location(), N, value);
                break;
            case 4:
                glUniform4iv(location(), N, value);
                break;
            default:
                glUniform1iv(location(), N, value);
                break;
        }
    }
    template <unsigned int D, GLsizei N>
    inline void VectorUniformBase<GLuint, D, N>::set(const GLuint* value)
    {
        switch (D)
        {
            case 1:
                glUniform1uiv(location(), N, value);
                break;
            case 2:
                glUniform2uiv(location(), N, value);
                break;
            case 3:
                glUniform3uiv(location(), N, value);
                break;
            case 4:
                glUniform4uiv(location(), N, value);
                break;
            default:
                glUniform1uiv(location(), N, value);
                break;
        }
    }
    template <unsigned int D, GLsizei N>
    inline void VectorUniformBase<GLfloat, D, N>::set(const GLfloat* value)
    {
        switch (D)
        {
            case 1:
                glUniform1fv(location(), N, value);
                break;
            case 2:
                glUniform2fv(location(), N, value);
                break;
            case 3:
                glUniform3fv(location(), N, value);
                break;
            case 4:
                glUniform4fv(location(), N, value);
                break;
            default:
                glUniform1fv(location(), N, value);
                break;
        }
    }
    template <unsigned int D, GLsizei N>
    inline void VectorUniformBase<GLdouble, D, N>::set(const GLdouble* value)
    {
        switch (D)
        {
            case 1:
                glUniform1dv(location(), N, value);
                break;
            case 2:
                glUniform2dv(location(), N, value);
                break;
            case 3:
                glUniform3dv(location(), N, value);
                break;
            case 4:
                glUniform4dv(location(), N, value);
                break;
            default:
                glUniform1dv(location(), N, value);
                break;
        }
    }
}

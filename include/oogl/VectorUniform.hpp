/**
 * Vector uniforms.
 *
 * @author Raoul Harel
 * @url github/rharel/cpp-oogl
 */


#pragma once

#include <glew/glew.h>

#include <oogl/VectorUniformBase.hpp>


namespace oogl
{
    template <typename T, unsigned int D, GLsizei N>
    class VectorUniform : public VectorUniformBase<T, D, N>
    {
        public:
        using VectorUniformBase<T, D, N>::VectorUniformBase;
    };
    template <typename T>
    class VectorUniform<T, 1, 1> : public VectorUniformBase<T, 1, 1>
    {
        public:
        using VectorUniformBase<T, 1, 1>::VectorUniformBase;

        void set(T v0);
    };
    template <typename T>
    class VectorUniform<T, 2, 1> : public VectorUniformBase<T, 2, 1>
    {
        public:
        using VectorUniformBase<T, 2, 1>::VectorUniformBase;

        void set(T v0, T v1);
    };
    template <typename T>
    class VectorUniform<T, 3, 1> : public VectorUniformBase<T, 3, 1>
    {
        public:
        using VectorUniformBase<T, 3, 1>::VectorUniformBase;

        void set(T v0, T v1, T v2);
    };
    template <typename T>
    class VectorUniform<T, 4, 1> : public VectorUniformBase<T, 4, 1>
    {
        public:
        using VectorUniformBase<T, 4, 1>::VectorUniformBase;

        void set(T v0, T v1, T v2, T v3);
    };

    typedef VectorUniform<GLint, 1, 1> Uniform1i;
    typedef VectorUniform<GLint, 2, 1> Uniform2i;
    typedef VectorUniform<GLint, 3, 1> Uniform3i;
    typedef VectorUniform<GLint, 4, 1> Uniform4i;

    typedef VectorUniform<GLuint, 1, 1> Uniform1u;
    typedef VectorUniform<GLuint, 2, 1> Uniform2u;
    typedef VectorUniform<GLuint, 3, 1> Uniform3u;
    typedef VectorUniform<GLuint, 4, 1> Uniform4u;

    typedef VectorUniform<GLfloat, 1, 1> Uniform1f;
    typedef VectorUniform<GLfloat, 2, 1> Uniform2f;
    typedef VectorUniform<GLfloat, 3, 1> Uniform3f;
    typedef VectorUniform<GLfloat, 4, 1> Uniform4f;

    typedef VectorUniform<GLdouble, 1, 1> Uniform1d;
    typedef VectorUniform<GLdouble, 2, 1> Uniform2d;
    typedef VectorUniform<GLdouble, 3, 1> Uniform3d;
    typedef VectorUniform<GLdouble, 4, 1> Uniform4d;
}

#include <oogl/VectorUniform.cpp>

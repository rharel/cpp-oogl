/**
 * Vector uniform base class.
 *
 * @author Raoul Harel
 * @url github/rharel/cpp-oogl
 */

#pragma once

#include <glew/glew.h>

#include <oogl/UniformBase.hpp>


namespace oogl
{
    template <typename T, unsigned int D, GLsizei N>
    class VectorUniformBase : public UniformBase<T, N>
    {
        public:
        using UniformBase<T, N>::UniformBase;
    };
    template <unsigned int D, GLsizei N>
    class VectorUniformBase<GLint, D, N> : public UniformBase<GLint, N>
    {
        public:
        using UniformBase<GLint, N>::UniformBase;

        void set(const GLint* value) override;
    };
    template <unsigned int D, GLsizei N>
    class VectorUniformBase<GLuint, D, N> : public UniformBase<GLuint, N>
    {
        public:
        using UniformBase<GLuint, N>::UniformBase;

        void set(const GLuint* value) override;
    };
    template <unsigned int D, GLsizei N>
    class VectorUniformBase<GLfloat, D, N> : public UniformBase<GLfloat, N>
    {
        public:
        using UniformBase<GLfloat, N>::UniformBase;

        void set(const GLfloat* value) override;
    };
    template <unsigned int D, GLsizei N>
    class VectorUniformBase<GLdouble, D, N> : public UniformBase<GLdouble, N>
    {
        public:
        using UniformBase<GLdouble, N>::UniformBase;

        void set(const GLdouble* value) override;
    };
}

#include <oogl/VectorUniformBase.cpp>

#include <oogl/VertexArray.hpp>


namespace oogl
{
    inline VertexArray::VertexArray()
    {
        GLuint handle;
        glGenVertexArrays(1, &handle);
        Initialize(handle);
    }
    inline VertexArray::~VertexArray()
    {
        const GLuint object = handle();
        glDeleteVertexArrays(1, &object);
    }

    inline void VertexArray::Bind()
    {
        glBindVertexArray(handle());
    }

    inline void VertexArray::EnableAttribute(const GLuint index)
    {
        glEnableVertexAttribArray(index);
    }
    inline void VertexArray::DisableAttribute(const GLuint index)
    {
        glDisableVertexAttribArray(index);
    }

    inline void VertexArray::EnableAttributeRange
    (
        const GLuint begin,
        const GLuint count
    )
    {
        const GLuint end = begin + count;
        for (GLuint i = begin; i < end; ++i)
        {
            EnableAttribute(i);
        }
    }
    inline void VertexArray::DisableAttributeRange
    (
        const GLuint begin,
        const GLuint count
    )
    {
        const GLuint end = begin + count;
        for (GLuint i = begin; i < end; ++i)
        {
            DisableAttribute(i);
        }
    }
}

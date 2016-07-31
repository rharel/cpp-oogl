#include <oogl/RenderBuffer.hpp>


namespace oogl
{
    inline RenderBuffer::RenderBuffer()
        : GLObject()
    {
        GLuint handle;
        glGenRenderbuffers(1, &handle);
        Initialize(handle);
        set_binding_target(GL_RENDERBUFFER);
    }

    inline RenderBuffer::~RenderBuffer()
    {
        const GLuint object = handle();
        glDeleteRenderbuffers(1, &object);
    }
    
    inline void RenderBuffer::Bind()
    {
        glBindRenderbuffer(binding_target(), handle());
    }

    inline void RenderBuffer::DefineStorage
    (
        const GLenum internal_format,
        const GLsizei width, 
        const GLsizei height
    )
    {
        glRenderbufferStorage
        (
            GL_RENDERBUFFER, 
            internal_format, 
            width, height
        );
    }
}

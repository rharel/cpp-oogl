#include <oogl/VertexBuffer.hpp>


namespace oogl
{
    inline VertexBuffer::VertexBuffer()
        : VertexBuffer(Binding::Array) {}
    inline VertexBuffer::VertexBuffer(const Binding target)
        : VertexBuffer(target, Usage::StaticDraw) {}
    inline VertexBuffer::VertexBuffer
    (
        const Binding target,
        const Usage usage
    )
        : usage_(usage)
    {
        GLuint handle;
        glGenBuffers(1, &handle);
        Initialize(handle);
        set_binding_target(target);
    }

    inline VertexBuffer::~VertexBuffer()
    {
        const GLuint object = handle();
        glDeleteBuffers(1, &object);
    }
    
    inline void VertexBuffer::Bind()
    {
        glBindBuffer(binding_target(), handle());
    }

    inline void VertexBuffer::BindToTarget(const Binding target)
    {
        set_binding_target(target);
        Bind();
    }

    inline void VertexBuffer::UploadData
    (
        const GLsizeiptr byte_count,
        const GLvoid* data
    )
    {
        glBufferData
        (
            binding_target(),
            byte_count, data,
            static_cast<GLenum>(usage_)
        );
    }

    inline void VertexBuffer::set_binding_target(const Binding value)
    {
        GLObject::set_binding_target(static_cast<GLenum>(value));
    }

    inline VertexBuffer::Usage VertexBuffer::usage() const
    {
        return usage_;
    }
    inline void VertexBuffer::set_usage(const Usage value)
    {
        usage_ = value;
    }
}

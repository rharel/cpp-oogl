#include <oogl/FrameBuffer.hpp>


namespace oogl
{
    inline FrameBuffer::FrameBuffer()
        : FrameBuffer(Binding::Dual) {}
    inline FrameBuffer::FrameBuffer(const Binding target)
    {
        GLuint handle;
        glGenFramebuffers(1, &handle);
        Initialize(handle);
        set_binding_target(target);
    }

    inline FrameBuffer::~FrameBuffer()
    {
        const GLuint object = handle();
        glDeleteFramebuffers(1, &object);
    }

    inline void FrameBuffer::Bind()
    {
        glBindFramebuffer(binding_target(), handle());
    }
    inline void FrameBuffer::BindToTarget(const Binding target)
    {
        set_binding_target(target);
        Bind();
    }

    inline void FrameBuffer::AttachRenderBuffer
    (
        const RenderBuffer& buffer,
        const GLenum attachment_point
    )
    {
        glFramebufferRenderbuffer
        (
            binding_target(),
            attachment_point,
            GL_RENDERBUFFER,
            buffer.handle()
        );
    }
    inline void FrameBuffer::AttachTexture
    (
        const Texture& texture,
        const GLenum attachment_point,
        const GLint level
    )
    {
        glFramebufferTexture
        (
            binding_target(),
            attachment_point,
            texture.handle(),
            level
        );
    }

    inline void FrameBuffer::set_binding_target(const Binding value)
    {
        GLObject::set_binding_target(static_cast<GLenum>(value));
    }

    inline bool FrameBuffer::is_complete(GLenum& status) const
    {
        status = glCheckFramebufferStatus(binding_target());
        return status == GL_FRAMEBUFFER_COMPLETE;
    }
    inline bool FrameBuffer::is_complete(std::string& status_message) const
    {
        GLenum status;
        const bool success = is_complete(status);
        
        if (!success)
        {
            switch (status)
            {
                case GL_FRAMEBUFFER_UNDEFINED: 
                    status_message = "Buffer undefined"; break;
                case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
                    status_message = "Incomplete attachment"; break;
                case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
                    status_message = "Incomplete missing attachment"; break;
                case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:
                    status_message = "Incomplete draw buffer"; break;
                case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:
                    status_message = "Incomplete read buffer"; break;
                case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE:
                    status_message = "Incomplete multisample"; break;
                case GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS:
                    status_message = "Incomplete layer targets"; break;
                default:
                    status_message = "Unknown"; break;
            }
        }
        else { status_message = "Success"; }

        return success;
    }
    inline bool FrameBuffer::is_complete() const
    {
        GLenum status;
        return is_complete(status);
    }
}

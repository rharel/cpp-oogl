/**
 * Frame Buffer Object.
 *
 * @author Raoul Harel
 * @url github/rharel/cpp-oogl
 */


#pragma once

#include <string>

#include <glew/glew.h>

#include <oogl/GLObject.hpp>
#include <oogl/RenderBuffer.hpp>
#include <oogl/Texture.hpp>


namespace oogl
{
    /**
     * This class wraps around OpenGL frame buffer objects.
     * Frame buffers are used to render to off-screen locations.
     */
    class FrameBuffer : public GLObject
    {
        public:
        enum class Binding : GLenum
        {
            Read = GL_READ_FRAMEBUFFER,
            Draw = GL_DRAW_FRAMEBUFFER,
            Dual = GL_FRAMEBUFFER
        };
        
        /**
         * Creates a new buffer with binding target set to 'dual' - 
         * i.e. both read and write access.
         */
        FrameBuffer();
        /**
         * Creates a new buffer with given binding target.
         */
        FrameBuffer(Binding target);
        
        /**
         * Deletes buffer.
         */
        ~FrameBuffer() override;

        /**
         * Binds to context.
         */
        void Bind() override;

        /**
         * Binds to the context at given target.
         */
        void BindToTarget(Binding target);

        /**
         * Attaches a render buffer to given point on this.
         */
        void AttachRenderBuffer
        (
            const RenderBuffer& buffer,
            GLenum attachment_point
        );
        /**
         * Attaches a texture to given point on this.
         */
        void AttachTexture
        (
            const Texture& texture,
            GLenum attachment_point,
            GLint level = 0
        );

        /**
         * Sets binding target.
         */
        void set_binding_target(Binding value);

        /**
         * Checks whether this buffer is complete.
         *
         * @param[out] status Status code.
         */
        bool is_complete(GLenum& status) const;
        /**
         * Checks whether this buffer is complete.
         *
         * @param[out] status_message Debug status message.
         */
        bool is_complete(std::string& status_message) const;
        /**
         * Checks whether this buffer is complete.
         */
        bool is_complete() const;
    };
}

#include <oogl/FrameBuffer.cpp>

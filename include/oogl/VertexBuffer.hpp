/**
 * Vertex Buffer Object.
 *
 * @author Raoul Harel
 * @url github/rharel/cpp-oogl
 */


#pragma once

#include <glew/glew.h>

#include <oogl/GLObject.hpp>


namespace oogl
{
    /**
     * This class wraps around OpenGL vertex buffer objects.
     * Vertex buffers store vertex data to be used in the rendering pipeline.
     */
    class VertexBuffer : public GLObject
    {
        public:
        enum class Binding : GLenum
        {
            Array = GL_ARRAY_BUFFER,
            AtomicCounter = GL_ATOMIC_COUNTER_BUFFER,
            CopyRead = GL_COPY_READ_BUFFER,
            CopyWrite = GL_COPY_WRITE_BUFFER,
            DispatchIndirect = GL_DISPATCH_INDIRECT_BUFFER,
            DrawIndirect = GL_DRAW_INDIRECT_BUFFER,
            ElementArray = GL_ELEMENT_ARRAY_BUFFER,
            PixelPack = GL_PIXEL_PACK_BUFFER,
            PixelUnpack = GL_PIXEL_UNPACK_BUFFER,
            Query = GL_QUERY_BUFFER,
            ShaderStorage = GL_SHADER_STORAGE_BUFFER,
            Texture = GL_TEXTURE_BUFFER,
            TransformFeedback = GL_TRANSFORM_FEEDBACK_BUFFER,
            Uniform = GL_UNIFORM_BUFFER
        };
        enum class Usage : GLenum
        {
            StaticDraw = GL_STATIC_DRAW,
            StaticRead = GL_STATIC_READ,
            StaticCopy = GL_STATIC_COPY,

            DynamicDraw = GL_DYNAMIC_DRAW,
            DynamicRead = GL_DYNAMIC_READ,
            DynamicCopy = GL_DYNAMIC_COPY,

            StreamDraw = GL_STREAM_DRAW,
            StreamRead = GL_STREAM_READ,
            StreamCopy = GL_STREAM_COPY
        };

        /**
         * Creates a new buffer.
         * Default binding target is the array buffer.
         * Default usage is static-draw.
         */
        VertexBuffer();
        /**
         * Creates a new buffer with given binding target.
         * Default usage is static-draw.
         */
        VertexBuffer(Binding target);
        /**
         * Creates a new buffer with given binding target and usage.
         */
        VertexBuffer(Binding target, Usage usage);

        /**
         * Deletes buffer.
         */
        ~VertexBuffer() override;

        /**
         * Binds to context.
         */
        void Bind() override;

        /**
         * Binds to the context at given target.
         */
        void BindToTarget(Binding target);

        /**
         * Uploads data to the buffer.
         */
        void UploadData
        (
            GLsizeiptr byte_count,
            const GLvoid* data
        );

        /**
         * Sets the binding target.
         */
        void set_binding_target(Binding value);

        /**
         * Gets usage policy.
         */
        Usage usage() const;
        /**
         * Sets usage policy.
         */
        void set_usage(Usage value);

        private:
        Usage usage_;
    };
}

#include <oogl/VertexBuffer.cpp>

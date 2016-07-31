/**
 * Render Buffer Object.
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
     * This class wraps around OpenGL render buffer objects.
     * Render buffers are used as render targets and are used together
     * with frame buffers.
     */
    class RenderBuffer : public GLObject
    {
        public:
        /**
         * Defines the storage structure of the currently bound buffer.
         */
        static void DefineStorage
        (
            GLenum internal_format,
            GLsizei width, GLsizei height
        );

        /**
         * Creates a new buffer.
         */
        RenderBuffer();
        /**
         * Deletes buffer.
         */
        ~RenderBuffer() override;

        /**
         * Binds to context.
         */
        void Bind() override;
    };
}

#include <oogl/RenderBuffer.cpp>

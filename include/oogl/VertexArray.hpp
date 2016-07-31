/**
 * Vertex Array Object.
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
     * This class wraps around OpenGL vertex array objects.
     * Vertex arrays group together buffers containing data related to
     * each vertex.
     */
    class VertexArray : public GLObject
    {
        public:
        /**
         * Enable attribute at index.
         */
        static void EnableAttribute(GLuint index);
        /**
         * Disable attribute at index.
         */
        static void DisableAttribute(GLuint index);
        /**
         * Enable attribute range.
         *
         * @param begin Start index.
         * @param count Range size.
         */
        static void EnableAttributeRange(GLuint begin, GLuint count);
        /**
         * Disable attribute range.
         *
         * @param begin Start index.
         * @param count Range size.
         */
        static void DisableAttributeRange(GLuint begin, GLuint count);

        /**
         * Creates a new vertex array.
         */
        VertexArray();
        /**
         * Deletes array.
         */
        ~VertexArray() override;

        void Bind() override;
    };
}

#include <oogl/VertexArray.cpp>

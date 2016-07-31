/**
 * OpenGL Object wrapper.
 *
 * @author Raoul Harel
 * @url github/rharel/cpp-oogl
 */


#pragma once

#include <type_traits>

#include <glew/glew.h>


namespace oogl
{
    /**
     * This is an abstract wrapper class for an OpenGL object.
     * OpenGL objects are resources that can be created, deleted, bound and 
     * unbound to the context. This class wraps these semantics using 
     * appropriate C++ constructs.
     */
    class GLObject
    {
        public:
        /**
         * Creates a new object.
         */
        GLObject();
        /**
         * Deletes this object.
         */
        virtual ~GLObject() = 0;
        
        /**
         * Binds to the context at last used target.
         */
        virtual void Bind() = 0;
        /**
         * Binds to the context at given target.
         */
        void BindToTarget(GLenum target);

        /**
         * Checks whether this object's name is non-zero.
         */
        bool is_valid() const;
        /**
         * Gets underlying object name.
         */
        GLuint handle() const;
        
        /**
         * Gets binding target.
         */
        GLenum binding_target() const;
        /**
         * Sets binding target.
         */
        void set_binding_target(GLenum target);

        GLObject(const GLObject&) = delete;
        GLObject& operator=(const GLObject&) = delete;
        
        protected:
        /**
         * Initializes object handle.
         */
        void Initialize(GLuint handle);

        private:
        GLuint handle_ = 0;
        GLenum binding_target_ = 0;
    };
}

#include <oogl/GLObject.cpp>
